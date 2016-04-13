//
//  Square.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

#include <stdio.h>
#include "Square.h"

Square::Square(int st8, int covernumber)
{
    state = st8;
    if(st8 == 1)
    {
        IfCoveredNumber = covernumber;
    }
    
}

Square::Square(int stupid)
{
    state = 0;
}

Square::Square()
{
    state = 0;
}