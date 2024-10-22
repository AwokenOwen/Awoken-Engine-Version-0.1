#include "WindowManager.h"
#include "InputManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos);

int width;
int height;

//Initialize the Window manager and call the create window function
int WindowManager::Initialize()
{
	glfwInit();
	createWindow();

	return 0;
}

//free any data on the heap
void WindowManager::Terminate()
{
}

//Singleton get function
WindowManager& WindowManager::getInstance()
{
	static WindowManager single;
	return single;
}

//get function for the private window variable
GLFWwindow* WindowManager::getWindow()
{
	if (window == nullptr)
		createWindow();
	return window;
}

//get functions for the width and height of the screen
int WindowManager::getWidth()
{
	return width;
}
int WindowManager::getHeight()
{
	return height;
}

//Clear the color and depth buffers
void WindowManager::Clear()
{
	//rendering commands 
	glClearColor(0.4f, 0.4f, 1.0f, 0.8f); 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

//Swap buffers and pollevents
void WindowManager::Swap()
{
	glfwSwapBuffers(window); 
	glfwPollEvents(); 
}

//Private contructor for singleton functionallity
WindowManager::WindowManager()
{
}

//creates the window by grabbing the primary monitor setting the window to be 
//"windowed fullscreen", then initializing glad, then finally creating the window
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

	window = glfwCreateWindow(width, height, "Game Engine", monitor, NULL);

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
	glfwSetCursorPosCallback(window, mouse_cursor_callback);

	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int _width, int _height)
{
	width = _width;
	height = _height;
	glViewport(0, 0, _width, _height);
}

void mouse_cursor_callback(GLFWwindow* window, double xpos, double ypos)
{
	Input.mouseMove(float(xpos), float(ypos));
}
