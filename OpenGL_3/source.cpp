#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

const char* vertexShaderSource = "#version 330 core\n"
								"layout (location = 0) in vec3 aPos;\n"
								"void main(){\n"
								"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
								"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
								"out vec4 FragColor;\n"
								"void main(){\n"
								"	FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
								"}\0";

int main() {
	if (!glfwInit()) {
		std::cerr << "GLFW initialization failed" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "window", NULL, NULL);
	if (window == NULL) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to initiize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	// shader compilation error check
	int success;
	char infoLog[512];

	// vertex shader compilation
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	// fragment shader compilation
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	while (!glfwWindowShouldClose(window)) {

	}

	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}