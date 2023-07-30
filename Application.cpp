#include <SDL.h>
#include <glad.h>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "Programs.h"

using namespace std;

GLuint gVertexArrayObject = 0;
GLuint gVertexBufferObject = 0;
GLuint gGraphicsPipelineShaderProgram = 0;

SDL_Window* window = nullptr;
SDL_GLContext gOpenGLContext = nullptr;
int gHEIGHT = 480, gWIDTH = 640;
bool quit = false; // true -> quit

string ReadFile(string path) {
	FILE* t = fopen(path.c_str(), "r");
	fseek(t, 0, SEEK_END);

	uint32_t len = ftell(t);
	char* a = new char[len + 1];
	rewind(t);
	fread(a, len, 1, t);
	a[len] = '\0';
	string result(a);
	delete[] a;
	return result;
}

// Shaders
GLuint CompileShader(GLuint type, const string& source) {
	GLuint shaderObject{};
	if (type == GL_VERTEX_SHADER) shaderObject = glCreateShader(GL_VERTEX_SHADER);
	else if (type == GL_FRAGMENT_SHADER) shaderObject = glCreateShader(GL_FRAGMENT_SHADER);

	const char* src = source.c_str();
	glShaderSource(shaderObject, 1, &src, nullptr);
	glCompileShader(shaderObject);

	return shaderObject;
}

GLuint CreateShaderProgram(const string& vs, const string& fs) {
	GLuint programObject = glCreateProgram();

	GLuint myVertexShader = CompileShader(GL_VERTEX_SHADER, vs);
	GLuint myGragmentShader = CompileShader(GL_FRAGMENT_SHADER, fs);

	glAttachShader(programObject, myVertexShader);
	glAttachShader(programObject, myGragmentShader);
	glLinkProgram(programObject);
	glValidateProgram(programObject);

	return programObject;
}
void CreateGraphicsPipeline() {
	string vertexSrc = ReadFile("Shaders/vert.glsl"), fragmentSrc = ReadFile("Shaders/frag.glsl");
	//cout << vertexSrc << endl << fragmentSrc;
	gGraphicsPipelineShaderProgram = CreateShaderProgram(vertexSrc, fragmentSrc);
}
void GetOpenGLVersionInfo() {
	cout << "Vendor: " << glGetString(GL_VENDOR) << endl;
	cout << "Version: " << glGetString(GL_VERSION) << endl;
	cout << "Renderer: " << glGetString(GL_RENDERER) << endl;
	cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}

void VertexSpecification() {
	// CPU
	vector <GLfloat> vertexPos{
		0, 0, 0, 1, 1, 0, 1, 0, 0,
	};

	// GPU
	glGenVertexArrays(1, &gVertexArrayObject);
	glBindVertexArray(gVertexArrayObject);

	glGenBuffers(1, &gVertexBufferObject);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

	glBufferData(GL_ARRAY_BUFFER, vertexPos.size() * sizeof(GLfloat), vertexPos.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glBindVertexArray(0);
	glDisableVertexAttribArray(0);
}

void Init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gWIDTH, gHEIGHT, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
	if (!window) {
		cout << SDL_GetError();
		exit(1);
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	gOpenGLContext = SDL_GL_CreateContext(window);

	if (!gOpenGLContext) {
		cout << SDL_GetError();
		exit(1);
	}
	if (!gladLoadGLLoader(SDL_GL_GetProcAddress)) {
		cout << SDL_GetError();
		exit(1);
	}
	GetOpenGLVersionInfo();
}
void Input() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) if (e.type == SDL_QUIT) quit = true;
}
void PreDraw() {
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glViewport(0, 0, gWIDTH, gHEIGHT);
	glClearColor(0, 0, 0.1f, 1);

	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glUseProgram(gGraphicsPipelineShaderProgram);
}
void Draw() {
	glBindVertexArray(gVertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void MainLoop() {
	while (!quit) {
		Input();
		PreDraw();
		Draw();
		// upadte window
		SDL_GL_SwapWindow(window);
	}
}
void CleanUp() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void _main2(int __a, char* __b[]) {
	// Set up program
	Init();

	// set up geometry
	VertexSpecification();

	// create graphic pipeline
	CreateGraphicsPipeline();

	// call mainloop
	MainLoop();

	// cleanup
	CleanUp();
}


int main(int __a, char* __b[]) {
	srand((uint32_t)time(0)); // generate Random

	_main2(__a, __b);
	return 0;
}