//
//  Building.cpp
//  week8
//
//  Created by Brent Mitton on 11/9/2013.
//
//

#include "Building.h"

int Building::building_x = 0;
int Building::building_y = 0;

Building::Building():
length(0.0f), width(0.0f), height(0.0f),
vertices(new BuildingVertex[36])
{
    if (building_x % 20 == 0){
        building_x = 0;
        building_y = building_y + 4;
    }
    building_x = building_x+4;

    // time to randomly generate a length width and height for this building.
    // ideally I want to generate these dimensions along a normal distribution,
    // but for right now I'm just going to do random numbers
    length = rand() % 2 + 2; // random number between 2 and 4
    width = rand() % 2 + 2;
    height = rand() % 10 + 3; // random number between 3 and 13
    
    AtlassedTexture a_texture;
    
    // building side texture 1 [0]
    a_texture.addCoord(0.0f, 1.0f, 0.3340f, 0.5713f);
    
    // building roof texture 1 [1]
    a_texture.addCoord(0.3340f, 1.0f, 0.4883f, 0.8457f);
    
    // building side texture 2 [2]
    a_texture.addCoord(0.49f, 1.0f, 0.734f, 0.572f);
    
    // roof texture 2 [3]
    a_texture.addCoord(0.335f, 0.885f, 0.488f, 0.734f);
    
    
    // tex1
    AtlassCoords t1 = a_texture.getCoords(0);
    AtlassCoords t2 = a_texture.getCoords(3);
    
    BuildingVertex temp[] = {
        
        // front face
        {0.0f+building_x, 0.0f, 0.0f+building_y, t1.l_bottomx, t1.l_bottomy},
        {0.0f+building_x, height, 0.0f+building_y, t1.l_topx, t1.l_topy},
        {length+building_x, height, 0.0f+building_y, t1.r_topx, t1.r_topy},
        
        {0.0f+building_x, 0.0f, 0.0f+building_y, t1.l_bottomx, t1.l_bottomy},
        {length+building_x, height, 0.0f+building_y, t1.r_topx, t1.r_topy},
        {length+building_x, 0.0f, 0.0f+building_y, t1.r_bottomx, t1.r_bottomy},
        
        // right face
        {length+building_x, 0.0f, 0.0f+building_y, t1.l_bottomx, t1.l_bottomy},
        {length+building_x, height, 0.0f+building_y, t1.l_topx, t1.l_topy},
        {length+building_x, height, width+building_y, t1.r_topx, t1.r_topy},
        
        {length+building_x, 0.0f, 0.0f+building_y, t1.l_bottomx, t1.l_bottomy},
        {length+building_x, height, width+building_y, t1.r_topx, t1.r_topy},
        {length+building_x, 0.0f, width+building_y, t1.r_bottomx, t1.r_bottomy},
        
        // back face
        {length+building_x, 0.0f, width+building_y, t1.l_bottomx, t1.l_bottomy},
        {length+building_x, height, width+building_y, t1.l_topx, t1.l_topy},
        {0.0f+building_x, height, width+building_y,  t1.r_topx, t1.r_topy},
        
        {length+building_x, 0.0f, width+building_y, t1.l_bottomx, t1.l_bottomy},
        {0.0f+building_x, height, width+building_y, t1.r_topx, t1.r_topy},
        {0.0f+building_x, 0.0f, width+building_y, t1.r_bottomx, t1.r_bottomy},
        
        // left face
        {0.0f+building_x, 0.0f, width+building_y, t1.l_bottomx, t1.l_bottomy},
        {0.0f+building_x, height, width+building_y, t1.l_topx, t1.l_topy},
        {0.0f+building_x, height, 0.0f+building_y, t1.r_topx, t1.r_topy},
        
        {0.0f+building_x, 0.0f, width+building_y, t1.l_bottomx, t1.l_bottomy},
        {0.0f+building_x, height, 0.0f+building_y, t1.r_topx, t1.r_topy},
        {0.0f+building_x, 0.0f, 0.0f+building_y, t1.r_bottomx, t1.r_bottomy},
        
        // top face
        {0.0f+building_x, height, 0.0f+building_y, t2.l_bottomx, t2.l_bottomy},
        {0.0f+building_x, height, width+building_y, t2.l_topx, t2.l_topy},
        {length+building_x, height, width+building_y, t2.r_topx, t2.r_topy},
        
        {0.0f+building_x, height, 0.0f+building_y, t2.l_bottomx, t2.l_bottomy},
        {length+building_x, height, width+building_y, t2.r_topx, t2.r_topy},
        {length+building_x, height, 0.0f+building_y, t2.r_bottomx, t2.r_bottomy},
        
        // bottom face
        {0.0f+building_x, 0.0f, width+building_y, 0.0f, 0.0f},
        {0.0f+building_x, 0.0f, 0.0f+building_y , 0.0f, 1.0f},
        {length+building_x, 0.0f, 0.0f+building_y, 1.0f, 1.0f},
        
        {0.0f+building_x, 0.0f, width+building_y, 0.0f,0.0f},
        {length+building_x, 0.0f, 0.0f+building_y, 1.0f, 1.0f},
        {length+building_x, 0.0f, width+building_y, 1.0f, 0.0f},
        
        
    };
    
    memcpy(vertices, &temp, sizeof(BuildingVertex)*36);

    
}

// building constructor will generate the vertices and the indices for a simple
// rectangular prism-y building. This allows you to specify the l w h. Really only used
// for testing
Building::Building(GLfloat l, GLfloat w, GLfloat h):
    length(l), width(w), height(h),
    vertices(new BuildingVertex[36])
{
    
    AtlassedTexture a_texture;

    // building side texture 1 [0]
    a_texture.addCoord(0.0f, 1.0f, 0.3340f, 0.5713f);
        
    // building roof texture 1 [1]
    a_texture.addCoord(0.3340f, 1.0f, 0.4883f, 0.8457f);
    
    // building side texture 2 [2]
    a_texture.addCoord(0.49f, 1.0f, 0.734f, 0.572f);
    
    // roof texture 2 [3]
    a_texture.addCoord(0.335f, 0.885f, 0.488f, 0.734f);
    
    
    // tex1
    AtlassCoords t1 = a_texture.getCoords(2);
    AtlassCoords t2 = a_texture.getCoords(3);
    
    BuildingVertex temp[] = {
        
        // front face
        {0.0f, 0.0f, 0.0f, t1.l_bottomx, t1.l_bottomy},
        {0.0f, height, 0.0f, t1.l_topx, t1.l_topy},
        {length, height, 0.0f, t1.r_topx, t1.r_topy},
        
        {0.0f, 0.0f, 0.0f, t1.l_bottomx, t1.l_bottomy},
        {length, height, 0.0f, t1.r_topx, t1.r_topy},
        {length, 0.0f, 0.0f, t1.r_bottomx, t1.r_bottomy},
        
        // right face
        {length, 0.0f, 0.0f, t1.l_bottomx, t1.l_bottomy},
        {length, height, 0.0f, t1.l_topx, t1.l_topy},
        {length, height, width, t1.r_topx, t1.r_topy},
        
        {length, 0.0f, 0.0f, t1.l_bottomx, t1.l_bottomy},
        {length, height, width, t1.r_topx, t1.r_topy},
        {length, 0.0f, width, t1.r_bottomx, t1.r_bottomy},
        
        // back face
        {length, 0.0f, width, t1.l_bottomx, t1.l_bottomy},
        {length, height, width, t1.l_topx, t1.l_topy},
        {0.0f, height, width,  t1.r_topx, t1.r_topy},
        
        {length, 0.0f, width, t1.l_bottomx, t1.l_bottomy},
        {0.0f, height, width, t1.r_topx, t1.r_topy},
        {0.0f, 0.0f, width, t1.r_bottomx, t1.r_bottomy},
        
        // left face
        {0.0f, 0.0f, width, t1.l_bottomx, t1.l_bottomy},
        {0.0f, height, width, t1.l_topx, t1.l_topy},
        {0.0f, height, 0.0f, t1.r_topx, t1.r_topy},
        
        {0.0f, 0.0f, width, t1.l_bottomx, t1.l_bottomy},
        {0.0f, height, 0.0f, t1.r_topx, t1.r_topy},
        {0.0f, 0.0f, 0.0f, t1.r_bottomx, t1.r_bottomy},
        
        // top face
        {0.0f, height, 0.0f, t2.l_bottomx, t2.l_bottomy},
        {0.0f, height, width, t2.l_topx, t2.l_topy},
        {length, height, width, t2.r_topx, t2.r_topy},
        
        {0.0f, height, 0.0f, t2.l_bottomx, t2.l_bottomy},
        {length, height, width, t2.r_topx, t2.r_topy},
        {length, height, 0.0f, t2.r_bottomx, t2.r_bottomy},
        
        // bottom face
        {0.0f, 0.0f, width, 0.0f, 0.0f},
        {0.0f, 0.0f, 0.0f , 0.0f, 1.0f},
        {length, 0.0f, 0.0f, 1.0f, 1.0f},
        
        {0.0f, 0.0f, width, 0.0f,0.0f},
        {length, 0.0f, 0.0f, 1.0f, 1.0f},
        {length, 0.0f, width, 1.0f, 0.0f},


    };
    
    memcpy(vertices, &temp, sizeof(BuildingVertex)*36);

    

}

BuildingVertex* Building::getVertices(){
    return vertices;
}

