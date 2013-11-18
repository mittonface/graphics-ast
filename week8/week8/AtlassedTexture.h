//
//  AtlassedTexture.h
//  week8
//
//  Created by Brent Mitton on 11/14/2013.
//
//

#include <vector>
#include <GL/glfw.h>

struct AtlassCoords{
   
    GLfloat l_bottomx, l_bottomy;
    GLfloat l_topx, l_topy;
    GLfloat r_bottomx, r_bottomy;
    GLfloat r_topx, r_topy;

};

class AtlassedTexture{
    public:
        void addCoord(GLfloat, GLfloat, GLfloat, GLfloat);
        AtlassCoords getCoords(int);
    private:
        std::vector<AtlassCoords> coords;
    
};