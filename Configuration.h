//
//  Configuration.h
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

using namespace std;

#include <string>
#include <list>


class Placement{
public:
    int row, column, tileLength;
    bool isHorizontal;
};



class Configuration
{
public:
    Configuration(int rr, int cc);
    Configuration(string fileName);
    bool placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength);
    void forbid(int r, int c);
    void dumpToScreen( );
    list<Placement> getPossiblePlacements(int tileLength);
    void setChars(char a, char b);
    int rows, cols;


    
    
private:
    char emptySpace = '.';
    char forbidSpace = 'X';
    Square **board;
    int countOfTiles;
    char countOfLetters;
    list<Placement> tilesOnBoard;
    Placement tempPlacement;
    
    friend ostream &operator<<(ostream &os, const Placement& place);

    
    

};