//========================================================================
// Week 8 - Pixel Tests and Blending
//========================================================================
#define GLFW_INCLUDE_GL3
#define GLFW_NO_GLU
#include <stdio.h>
#include <stdlib.h>
#ifndef __APPLE__
#include <GL/glew.h>
#endif
#include <GL/glfw.h>
#include "W_Common.h"
#include "City.h"
#include <glm/glm.hpp>


int main(void){
    int width, height;
    City city;
    
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 2);
    glfwOpenWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // Open a window and create its OpenGL context
    if( !glfwOpenWindow( 640, 480, 0,0,0,0, 32,0, GLFW_WINDOW ) )
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        
        glfwTerminate();
        exit( EXIT_FAILURE );
    }
    
#ifndef __APPLE__
	glewExperimental = GL_TRUE;
	glewInit();
#endif
	// Leave this here! On windows machines in Lab, glewInit is generating some mysterious, but apparently
	// harmless, error - and we need it gone.
	glGetError();
    
    glfwSetWindowTitle( "Cityscape" );
    
    // Ensure we can capture the escape key being pressed below
    glfwEnable( GLFW_STICKY_KEYS );
    
	glfwSetMousePos(640/2, 480/2);
    // Enable vertical sync (on cards that support it)
    glfwSwapInterval( 1 );

    city.initCity();
    
    
    do{
        
        // Get window size (may be different than the requested size)
        glfwGetWindowSize( &width, &height );
        
        // Special case: avoid division by zero below
        height = height > 0 ? height : 1;
        
        glViewport( 0, 0, width, height );
        
        // Clear color buffer to black
        glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        

        city.renderCity();
        
        // Swap buffers
        glfwSwapBuffers();
        
    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
          glfwGetWindowParam( GLFW_OPENED ) );
    
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    
    exit( EXIT_SUCCESS );

}


