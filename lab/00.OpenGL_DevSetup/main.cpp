///// main.cpp
///// OpenGL 3+, GLEW, GLFW3

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
  GLFWwindow* window;

  // Initialize GLFW library
  if (!glfwInit())
    return -1;

  // Create a GLFW window containing a OpenGL context
  // window = glfwCreateWindow(500, 500, "Hello OpenGL", NULL, NULL);
  // TODO 1 : Change Window size to 800x800
  // TODO 2 : Write my English name in window title bar
  window = glfwCreateWindow(800, 800, "Jimin Kim", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  // Make the current OpenGL context as one in the window
  glfwMakeContextCurrent(window);

  // Initialize GLEW library
  if (glewInit() != GLEW_OK)
    std::cout << "GLEW Init Error!" << std::endl;

  // Print out the OpenGL version supported by the graphics card in my PC
  std::cout << glGetString(GL_VERSION) << std::endl;

  // Init OpenGL
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  // TODO 3 : Change internal color of Window from white to gray
  // glClearColor(1.0, 1.0, 1.0, 1.0);
  glClearColor(0.5, 0.5, 0.5, 1.0);


  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window))
  {
    // Render here
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  glfwTerminate();

  return 0;
}
