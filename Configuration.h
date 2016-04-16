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
    void dumpToScreen( ) const;
    list<Placement> getPossiblePlacements(int tileLength);
    
    
private:
    int rows, cols;
    Square **board;
    int countOfTiles;
    list<Placement> tilesOnBoard;
    Placement tempPlacement;
    
    friend ostream &operator<<(ostream &os, const Placement& place);
    

};