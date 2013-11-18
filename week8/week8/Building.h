//
//  Building.h
//  week8
//
//  Created by Brent Mitton on 11/9/2013.
//
//

#include <gl/glfw.h>
#include <string>
#include "AtlassedTexture.h"
#include <cstdlib>

struct BuildingVertex{
    GLfloat x, y, z;
    GLfloat u, v;
};

struct TexCoords {
    GLfloat x, y;
};

class Building{
    
protected:
    // depth is width
    int width, height, length;
    BuildingVertex* vertices;
    static int building_x;
    static int building_y;
    
    
public:
    Building(GLfloat, GLfloat, GLfloat);
    Building();
    BuildingVertex* getVertices();
};