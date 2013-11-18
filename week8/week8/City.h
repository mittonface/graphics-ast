//
//  City.h
//  week8
//
//  Created by Brent Mitton on 11/12/2013.
//
//


#include "W_BufferManager.h"
#include "W_VertexDeclaration.h"
#include "W_ProgramManager.h"
#include "W_MaterialManager.h"
#include "TieredBuilding.h"

struct CityPosition{
    GLfloat x, y ;
};
class City{
    public:
        void initCity();
        void renderCity();
    
    private:
        CityPosition* position_grid;
    
};
