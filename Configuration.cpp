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
    
}
bool Configuration::placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength)
{
    return true;
}
void Configuration::forbid(int r, int c)
{
    board[r][c].state = 2;
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
                
            }
            else if(board[a][b].state == 2){
                cout << 'X';
            }
        }
        cout << endl;
    }
    
}


/*
private:
int rows, cols;
Square **board;
int countOfTiles;
*/