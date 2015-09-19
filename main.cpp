#include <Graphic.hpp>
#include <iostream>

GLFWwindow		*window;

/*
**	Initialise both glfw and opengl for further rendering
*/

static int		graphic_init(void)
{
		// Initialise GLFW
	if( !glfwInit() )
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return 0;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // We want OpenGL 4.1
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

	window = glfwCreateWindow( 1024, 768, "Bomberman", NULL, NULL); 
	if( window == NULL )
	{
		std::cerr << "Failed to open GLFW window." << std::endl;
		glfwTerminate();
		return 0;
	}

	glfwMakeContextCurrent(window); // Initialize GLEW 
			// glewExperimental=true; // Needed in core profile 
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
	// glfwSetKeyCallback(window, key_callback);
	// glfwSetCursorPosCallback(window, (GLFWcursorposfun)mouse_callback);
	glEnable(GL_DEPTH_TEST);
	// glEnable(GL_CULL_FACE);
	// glDepthFunc(GL_LESS);
	return (1);
}

int				main(void)
{
	if (!graphic_init())
		return (-1);


	do {
		glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);



		glfwSwapBuffers(window);
		glfwPollEvents();
		// entity->increaseRotation(.1, .005, 0);
		// entity->increasePosition(.005, .001, -.01);
		// check_opengl_error();
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(window) == 0 );

	return (0);
}