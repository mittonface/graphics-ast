//
//  TieredBuilding.cpp
//  week8
//
//  Created by Brent Mitton on 11/15/2013.
//
//

#include "TieredBuilding.h"

TieredBuilding::TieredBuilding(int tiers, float l, float w, float h):
    length(l), width(w), height(h), tiers(tiers), vertices(new TieredBuildingVertex[tiers*36])
{
    
    AtlassedTexture a_textures;
    // building side texture 1 [0]
    a_textures.addCoord(0.0f, 1.0f, 0.3340f, 0.5713f);
    
    // building roof texture 1 [1]
    a_textures.addCoord(0.3340f, 1.0f, 0.4883f, 0.8457f);
    
    // building side texture 2 [2]
    a_textures.addCoord(0.49f, 1.0f, 0.734f, 0.572f);
    
    // roof texture 2 [3]
    a_textures.addCoord(0.335f, 0.885f, 0.488f, 0.734f);
    
    AtlassCoords t1 = a_textures.getCoords(0);
    AtlassCoords t2 = a_textures.getCoords(1);

    for(int i=0; i<tiers; i++){
        
        //front
        
        vertices[0+(36*i)] = genVertex(i, false, false, false, t1.l_bottomx, t1.l_bottomy); //1
        vertices[1+(36*i)] = genVertex(i, false, true, false, t1.l_topx, t1.l_topy);
        vertices[2+(36*i)] = genVertex(i, true, true, false, t1.r_topx, t1.r_topy);
        
        vertices[3+(36*i)] = genVertex(i, false, false, false, t1.l_bottomx, t1.l_bottomy); //2
        vertices[4+(36*i)] = genVertex(i, true, true, false, t1.r_topx, t1.r_topy);
        vertices[5+(36*i)] = genVertex(i, true, false, false, t1.r_bottomx, t1.r_bottomy);
    
        
        //right
        vertices[6+(36*i)] = genVertex(i, true, false, false, t1.l_bottomx, t1.l_bottomy); //3
        vertices[7+(36*i)] = genVertex(i, true, true, false, t1.l_topx, t1.l_topy);
        vertices[8+(36*i)] = genVertex(i, true, true, true, t1.r_topx, t1.r_topy);
        
        vertices[9+(36*i)] = genVertex(i, true, false, false, t1.l_bottomx, t1.l_bottomy); //4
        vertices[10+(36*i)] = genVertex(i, true, true, true, t1.r_topx, t1.r_topy);
        vertices[11+(36*i)] = genVertex(i, true, false, true, t1.r_bottomx, t1.r_bottomy);
        
        // back
        vertices[12+(36*i)] = genVertex(i, true, false, true, t1.l_bottomx, t1.l_bottomy); //5
        vertices[13+(36*i)] = genVertex(i, true, true, true, t1.l_topx, t1.l_topy);
        vertices[14+(36*i)] = genVertex(i, false, true, true, t1.r_topx, t1.r_topy);
        
        vertices[15+(36*i)] = genVertex(i, true, false, true, t1.l_bottomx, t1.l_bottomy); //6
        vertices[16+(36*i)] = genVertex(i, false, true, true, t1.r_topx, t1.r_topy);
        vertices[17+(36*i)] = genVertex(i, false, false, true, t1.r_bottomx, t1.r_bottomy);
        
        //left
        vertices[18+(36*i)] = genVertex(i, false, false, true, t1.l_bottomx, t1.l_bottomy); //7
        vertices[19+(36*i)] = genVertex(i, false, true, true, t1.l_topx, t1.l_topy);
        vertices[20+(36*i)] = genVertex(i, false, true, false, t1.r_topx, t1.r_topy);
        
        vertices[21+(36*i)] = genVertex(i, false, false, true, t1.l_bottomx, t1.l_bottomy); //8
        vertices[22+(36*i)] = genVertex(i, false, true, false, t1.r_topx, t1.r_topy);
        vertices[23+(36*i)] = genVertex(i, false, false, false, t1.r_bottomx, t1.r_bottomy);
        
        //top
        vertices[24+(36*i)] = genVertex(i, false, true, false, t2.l_bottomx, t2.l_bottomy); //9
        vertices[25+(36*i)] = genVertex(i, false, true, true, t2.l_topx, t2.l_topy);
        vertices[26+(36*i)] = genVertex(i, true, true, true, t2.r_topx, t2.r_topy);
        
        vertices[27+(36*i)] = genVertex(i, false, true, false, t2.l_bottomx, t2.l_bottomy); //10
        vertices[28+(36*i)] = genVertex(i, true, true, true, t2.r_topx, t2.r_topy);
        vertices[29+(36*i)] = genVertex(i, true, true, false, t2.r_bottomx, t2.r_bottomy);
        
        
        
        // bottom
        
        vertices[30+(36*i)] = genVertex(i, false, false, true, t2.l_bottomx, t2.l_bottomy); //11
        vertices[31+(36*i)] = genVertex(i, false, false, false, t2.l_topx, t2.l_topy);
        vertices[32+(36*i)] = genVertex(i, true, false, false, t2.r_topx, t2.r_topy);
        
        vertices[33+(36*i)] = genVertex(i, false, false, true, t2.l_bottomx, t2.l_bottomy); //12
        vertices[34+(36*i)] = genVertex(i, true, false, false, t2.l_topx, t2.l_topy);
        vertices[35+(36*i)] = genVertex(i, true, false, true, t2.r_bottomx, t2.r_bottomy);
                                                  
    }
}

// TODO:
// ADD A COMMENT
// For now I'm just going to pass in the texture coordinates, but I could probably
// do something a bit more clever.
TieredBuildingVertex TieredBuilding::genVertex(int tier, bool l, bool h, bool w, GLfloat x_coord, GLfloat y_coord){
    
    // this is how much a tier will reduce its length and width on each
    // subsequent layer
    GLfloat width_reduction = (width/2)/tiers;
    GLfloat length_reduction = (length/2)/tiers;
    
    // this will get the actual length and width of the current tier
    GLfloat tier_width = width - (width_reduction * tier);
    GLfloat tier_length = length - (length_reduction * tier);
    
    // for now, the height of a tier is just total_height / num_tiers
    GLfloat tier_height = height/tiers;
    
    // now we will decide what the value of each component will be, a value of false for
    // a given component will mean that the component value will be "zero" (although it's
    // a bit more complicated then that)
    
    GLfloat length_component = (l) ? tier_length+(tier*(length_reduction/2)):0.0f+(tier*(length_reduction/2));
    GLfloat height_component = (h) ? tier_height+(tier*tier_height):(tier*tier_height);
    GLfloat width_component = (w) ? tier_width+(tier*(width_reduction/2)):0.0f+(tier*(width_reduction/2));
 
    return TieredBuildingVertex(length_component, height_component, width_component, x_coord, y_coord);
}

TieredBuildingVertex* TieredBuilding::getVertices(){
    return vertices;
}

unsigned int TieredBuilding::numTiers(){
    return tiers;
}