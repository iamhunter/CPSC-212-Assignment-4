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

bool Filler::placeTileAtFiller(int rStart, int cStart, bool isHorizontal, int tileLength)
{
    if(rStart <= 0 || cStart <= 0)
    {
        //cout <<"Tiles cannot be in negative space" << endl;
        return false;
    }
    
    else if(((cStart + tileLength - 1) > cols) || ((rStart + tileLength-1) > rows))
    {
        //cout << "This goes off the board" << endl;
        return false;
    }
    
    else if(tileLength <= 0)
    {
        //cout << "Tiles cannot have negative length" << endl;
        return false;
    }
    
    if(isHorizontal){
        for(int a = 0; a < tileLength; a++)
        {
            if(board[rStart-1][cStart+a-1].state != 0)
            {
                //cout << "At least one required square is covered/forbidden" << endl;
                return false;
            }
            
        }
    }
    else{
        for(int a = 0; a < tileLength; a++)
        {
            if(board[rStart-1+a][cStart-1].state != 0)
            {
                //cout << "At least one required square is covered/forbidden" << endl;
                return false;
            }
        }
    }
    
    
    
    
    
    
    if(isHorizontal){
        for(int a = 0; a < tileLength; a++)
        {
            board[rStart-1][cStart+a-1].state = 1;
            board[rStart-1][cStart+a-1].IfCoveredNumber = countOfTiles;
        }
    }
    else{
        for(int a = 0; a < tileLength; a++)
        {
            board[rStart-1+a][cStart-1].state = 1;
            board[rStart-1+a][cStart-1].IfCoveredNumber = countOfTiles;
        }
    }
    
    
    countOfTiles++;
    return true;
}
