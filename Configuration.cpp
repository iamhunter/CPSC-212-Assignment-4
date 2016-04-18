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
#include <fstream>
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
    countOfTiles = 1;
    
}

Configuration::Configuration(string fileName){
    
    ifstream file;
    file.open (fileName);

    for(int i = 0; i < 1; i++)
    {
        file >> rows;
    }
    
    for (int i = 1; i < 2; i++)
    {
        file >> cols;
    }
    
    for(int i = 2; i < 3; i++)
    {
        file >> emptySpace;
    }
    
    for(int i = 3; i < 4; i++)
    {
        file >> forbidSpace;
    }
    

    board = new Square*[rows];
    for(int i = 0; i<rows; i++)
    {
        board[i] = new Square[cols];
    }

    
    char spaces[rows*cols];
    int spacesCounter = 0;
    
    for(int a = 4; a < rows*cols + 4; a++)
    {
        file >> spaces[spacesCounter];
        spacesCounter++;
    }

    spacesCounter = 0;
    
    for(int a  = 0; a < rows; a++)
    {
        for(int b = 0; b < cols; b++)
        {
            if(spaces[spacesCounter] == forbidSpace)
            {
                board[a][b].state = 2;
            }
            else{
                board[a][b].state = 0;
            }
            
            spacesCounter++;
        }
    }
}



bool Configuration::placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength)
{
    if(rStart <= 0 || cStart <= 0)
    {
        cout <<"Tiles cannot be in negative space" << endl;
        return false;
    }
    
    else if(((cStart + tileLength - 1) > cols) || ((rStart + tileLength-1) > rows))
    {
        cout << "This goes off the board" << endl;
        return false;
    }
    
    else if(tileLength <= 0)
    {
        cout << "Tiles cannot have negative length" << endl;
        return false;
    }
    
    if(isHorizontal){
        for(int a = 0; a < tileLength; a++)
        {
            if(board[rStart-1][cStart+a-1].state != 0)
            {
                cout << "At least one required square is covered/forbidden" << endl;
                return false;
            }
                
        }
    }
    else{
        for(int a = 0; a < tileLength; a++)
        {
            if(board[rStart-1+a][cStart-1].state != 0)
            {
                cout << "At least one required square is covered/forbidden" << endl;
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
                cout << emptySpace;
            }
            else if(board[a][b].state == 1){
                cout << board[a][b].IfCoveredNumber;
            }
            else if(board[a][b].state == 2){
                cout << forbidSpace;
            }
        }
        cout << endl;
    }
}

list<Placement> Configuration::getPossiblePlacements(int tileLength)
{
    int tempcounter = 0;
    //Horizontal
    for(int a = 0; a < rows; a++)
    {
        for(int b = 0; b < cols-tileLength+1; b++)
        {
            for(int c = 0; c < tileLength; c++)
            {
                if(board[a][b+c].state == 0)
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
    
    //Vertical
    for(int a = 0; a < rows-tileLength+1; a++)
    {
        for(int b = 0; b < cols; b++)
        {
            for(int c = 0; c < tileLength; c++)
            {
                if(board[a+c][b].state == 0)
                    tempcounter++;
            }
            if(tempcounter == tileLength)
            {
                tempPlacement.row = a+1;
                tempPlacement.column = b+1;
                tempPlacement.tileLength = tileLength;
                tempPlacement.isHorizontal = false;
                
                tilesOnBoard.push_back(tempPlacement);
                
            }
            tempcounter = 0;
        }
    }
    
    
    return tilesOnBoard;
}

void Configuration::setChars(char a, char b)
{
    emptySpace = a;
    forbidSpace = b;
}

ostream &operator<<(ostream &out, const Placement& P)
{
    out << "uplft=" << '('<< P.row << ',' << P.column << ')' << ' ' << P.isHorizontal << " len=" << P.tileLength;
    return out;
}

