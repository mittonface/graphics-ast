//
//  AtlassedTexture.cpp
//  week8
//
//  Created by Brent Mitton on 11/14/2013.
//
//

#include "AtlassedTexture.h"

// Takes the top left coordinate of a texture and a bottom right coordinate of a
// a texture and then adds all of the coordinates we need to a coord vector
void AtlassedTexture::addCoord(GLfloat tlx, GLfloat tly, GLfloat brx, GLfloat bry)
{
    AtlassCoords temp = {tlx, bry, tlx, tly, brx, bry, brx, tly};
    coords.push_back(temp);
}

AtlassCoords AtlassedTexture::getCoords(int n){
    if(n>=coords.size()){
        fprintf(stderr, "Outside of Atlas bounds.");
        return coords[0]; // maybe add in an error texture.
    }else{
        return coords[n];
    }
    
}