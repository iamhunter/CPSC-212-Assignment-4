//
//  Filler.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/18/16.
//
//

#include "Filler.h"

void Filler::greedyFill(int tileLength)
{
    for(int a = 1; a <= rows; a++)
    {
        for(int b = 1; b <= cols; b++)
        {
            placeTileAtFiller(a,b,true,tileLength);
            placeTileAtFiller(a,b,false,tileLength);

        }
    }
}