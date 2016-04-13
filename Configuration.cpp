//
//  Configuration.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

#include <stdio.h>
#include "Configuration.h"




Configuration::Configuration(int rr, int cc)
{
    board = new Square*[rr];
    for(int i = 0; i<rr; i++)
    {
        board[i] = *new Square*[cc];
    }
    
}
bool Configuration::placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength)
{
    return true;
}
void Configuration::forbit(int r, int c)
{
    
}
void Configuration::dumpToScreen( ) const
{
    
}


/*
private:
int rows, cols;
Square **board;
int countOfTiles;
*/