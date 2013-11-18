//
//  City.cpp
//  week8
//
//  Created by Brent Mitton on 11/12/2013.
//
//

#include "City.h"


static wolf::VertexBuffer* g_pVB = 0;
static wolf::VertexDeclaration* g_pDecl = 0;
static wolf::Program* g_pProgram = 0;
static wolf::Material* g_pMat = 0;
static wolf::Texture* g_pTexture = 0;

// /set our initial position
glm::vec3 position = glm::vec3( 0, 0, 8 );
// horizontal angle : toward -Z
float horizontalAngle = 3.14f;
// vertical angle : 0, look at the horizon
float verticalAngle = 0.0f;
// Initial Field of View
float fov = 45.0f;

float speed = 5.0f; // 3 units / second
float mouseSpeed = .1f;
static double lastTime = glfwGetTime();


void City::initCity(){
    
    glEnable(GL_DEPTH_TEST);
    glfwDisable(GLFW_MOUSE_CURSOR);
    
    
    
    
    
    BuildingVertex* city_array = new BuildingVertex[30*36];
    
    // generate an array of 30 buildings
    Building* building_array = new Building[30];
    
    for (int i=0; i<30; i++){
        
        memcpy(&city_array[i*36], building_array[i].getVertices(), sizeof(BuildingVertex)*36);
    }
    
    Building b(1.0f, 1.0f, 2.0f);
    TieredBuilding t(4, 1.0f, 1.0f, 9.0f);
    g_pProgram = wolf::ProgramManager::CreateProgram("/Users/brentmitton/Downloads/Downloads Oct 29/Week8Samples/week8/week8/building_shader.vsh", "/Users/brentmitton/Downloads/Downloads Oct 29/Week8Samples/week8/week8/building_shader.fsh");
    
    g_pVB = wolf::BufferManager::CreateVertexBuffer(city_array, sizeof(BuildingVertex) * 36 * 30 );
    

    
    
	g_pDecl = new wolf::VertexDeclaration();
	g_pDecl->Begin();
	g_pDecl->AppendAttribute(wolf::AT_Position, 3, wolf::CT_Float);
    g_pDecl->AppendAttribute(wolf::AT_TexCoord1, 2, wolf::CT_Float);
	g_pDecl->SetVertexBuffer(g_pVB);
	g_pDecl->End();
    
    g_pTexture = wolf::TextureManager::CreateTexture("/Users/brentmitton/Downloads/Downloads Oct 29/Week8Samples/week8/week8/buildingtex.tga");



    
    
}

void City::renderCity(){

    
    // get the mouse position
    int xpos, ypos;
    glfwGetMousePos(&xpos, &ypos);
    
    // get the window size, because we'll want to put
    // the mouse back into the center on each frame
    int w_width, w_height;
    glfwGetWindowSize(&w_width, &w_height);
    
    // set the mouse position back
    glfwSetMousePos(w_width/2, w_height/2);

    
    
    double currentTime = glfwGetTime();
    float timeDelta = (currentTime - lastTime);
    lastTime = glfwGetTime();
    
    // calculate our viewing angle
    horizontalAngle += mouseSpeed * timeDelta * float(w_width/2 - xpos);
    verticalAngle += mouseSpeed * timeDelta * float(w_height/2 - ypos);
    

    // figure out which direction we are looking in world space
    glm::vec3 direction(
            cos(verticalAngle) * sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle) * cos(horizontalAngle)
            );

    // this vector will tell us which way is to the right
    glm::vec3 right = glm::vec3(
                                sin(horizontalAngle - 3.14f/2.0f),
                                0,
                                cos(horizontalAngle - 3.14f/2.0f)
                                );
    
    
    
    
    // the up vector is the vector that is perpindicular to both the right
    // vector and the direction vector
    // Up vector : perpendicular to both direction and right
    glm::vec3 up = glm::cross( right, direction );
    
    
    // Keyboard movement!
    // Move forward
    if (glfwGetKey( 87 ) == GLFW_PRESS){
        position += direction * timeDelta * speed;
    }
    // Move backward
    if (glfwGetKey( 83 ) == GLFW_PRESS){
        position -= direction * timeDelta * speed;
    }
    // Strafe right
    if (glfwGetKey( 68 ) == GLFW_PRESS){
        position += right * timeDelta * speed;
    }
    // Strafe left
    if (glfwGetKey( 65 ) == GLFW_PRESS){
        position -= right * timeDelta * speed;
    }
    
    
    // Use shader program.
	g_pProgram->Bind();
    
	glm::mat4 mProj = glm::perspective(fov, float(w_width) / w_height, 0.1f, 100.0f);
    glm::mat4 mView = glm::lookAt(
                position,           // Camera is here
                position+direction, // and looks here : at the same position, plus "direction"
                up                  // Head is up (set to 0,-1,0 to look upside-down)
                );	glm::mat4 mWorld = glm::mat4(1.0f);
	// Bind Uniforms
    g_pProgram->SetUniform("projection", mProj);
    g_pProgram->SetUniform("view", mView);
    g_pProgram->SetUniform("world", mWorld);
    g_pProgram->SetUniform("tex", 0);
	// Set up source data
	g_pDecl->Bind();
    
    // Draw!
    glDrawArrays(GL_TRIANGLES, 0, 6*3*2*30);


}