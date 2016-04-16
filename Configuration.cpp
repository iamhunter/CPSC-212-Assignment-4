//
//  Configuration.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <list>
#include "Configuration.h"

using namespace std;




Configuration::Configuration(int rr, int cc)
{
    board = new Square*[rr];
    for(int i = 0; i<rr; i++)
    {
        board[i] = new Square[cc];
    }
    
    rows = rr;
    cols = cc;
    countOfTiles = 1;
    
}


bool Configuration::placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength)
{
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


void Configuration::forbid(int r, int c)
{
    board[r-1][c-1].state = 2;
}


void Configuration::dumpToScreen( ) const
{
    for(int a = 0; a < rows; a++)
    {
        for(int b = 0; b < cols; b++)
        {
            if(board[a][b].state == 0){
                cout << '.';
            }
            else if(board[a][b].state == 1){
                cout << board[a][b].IfCoveredNumber;
            }
            else if(board[a][b].state == 2){
                cout << 'X';
            }
        }
        cout << endl;
    }
}

list<Placement> Configuration::getPossiblePlacements(int tileLength)
{
    int tempcounter = 0;
    
    for(int a = 0; a < rows; a++)
    {
        for(int b = 0; b < cols; b++)
        {
            for(int c = 0; c < tileLength; c++)
            {
                if(board[a][b].state == 0)
                    tempcounter++;
            }
            if(tempcounter == tileLength)
            {
                tempPlacement.row = a+1;
                tempPlacement.column = b+1;
                tempPlacement.tileLength = tileLength;
                tempPlacement.isHorizontal = true;
                
                tilesOnBoard.push_back(tempPlacement);

            }
            tempcounter = 0;
        }
    }
    
    
    
    return tilesOnBoard;
}

ostream &operator<<(ostream &out, const Placement& P)
{
    out << "uplft=" << '('<< P.row << ',' << P.column << ')' << ' ' << P.isHorizontal << " len=" << P.tileLength;
    return out;
}

