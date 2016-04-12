//
//  Configuration.h
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//




class Configuration
{
public:
    Configuration(int rr, int cc);
    bool placeTileAt(int rStart, int cStart, bool isHorizontal, int tileLength);
    void forbit(int r, int c);
    void dumpToScreen( ) const;
    
private:
    int rows, cols;
    Square **board;
    int countOfTiles;
};
