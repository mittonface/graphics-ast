//
//  TieredBuilding.h
//  week8
//
//  Created by Brent Mitton on 11/15/2013.
//
//

#include "Building.h"


// at this point I don't see a reason for this to extend from the
// Building class.


// yeah... This doesnt really make any sense.
// I'm using initializer syntax for buildings and then the the compiler can pick up
// that I'm trying to specifiy buildingvertices when I provide it values in curly braces.
// but I'm not using initializer syntax for tierd buildings, so I need to use explicit
// constructors.

struct TieredBuildingVertex : BuildingVertex{
    TieredBuildingVertex(){
        
    };
    TieredBuildingVertex(GLfloat xt, GLfloat yt, GLfloat zt, GLfloat ut, GLfloat vt){
        x = xt; y=yt; z=zt; u=ut; v=vt;
    }
};

class TieredBuilding{
    protected:
        GLfloat length, width, height;
        unsigned int tiers;
        TieredBuildingVertex* vertices;
    
    
    public:
        TieredBuilding(int, float, float, float);
        TieredBuildingVertex* getVertices();
        unsigned int numTiers();    
    
    private:
        TieredBuildingVertex genVertex (int, bool, bool, bool, GLfloat, GLfloat);
    
    
};