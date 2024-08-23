#include "WindowManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int width;
int height;

int WindowManager::Start()
{
	glfwInit();
	createWindow();

	return 0;
}

void WindowManager::Stop()
{
}

WindowManager& WindowManager::getInstance()
{
	static WindowManager single;
	return single;
}

GLFWwindow* WindowManager::getWindow()
{
	if (window == nullptr)
		createWindow();
	return window;
}

int WindowManager::getWidth()
{
	return width;
}

int WindowManager::getHeight()
{
	return height;
}

void WindowManager::Clear()
{
	//rendering commands 
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void WindowManager::Swap()
{
	glfwSwapBuffers(window); 
	glfwPollEvents(); 
}

WindowManager::WindowManager()
{
}

int WindowManager::createWindow()
{
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();

	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	width = mode->width; 
	height = mode->height; 

	window = glfwCreateWindow(width, height, "Game Engine", NULL, NULL);

	if (window == NULL)
	{
		cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return 0;
	}
	glfwMakeContextCurrent(window);

	//NOTE: Init GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return 0;
	}

	//NOTE: Set OpenGL Viewport
	glViewport(0, 0, width, height);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int _width, int _height)
{
	width = _width;
	height = _height;
	glViewport(0, 0, _width, _height);
}