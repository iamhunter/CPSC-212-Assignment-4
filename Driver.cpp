//
//  Driver.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

#include <iostream>
#include <stdio.h>
#include "Square.cpp"
#include "Configuration.cpp"
#include "Filler.cpp"

int main ()
{
    
    Configuration C("tileTest.txt");
    C.forbid(4,2);
    list<Placement> canDo = C.getPossiblePlacements(3);
    for( Placement P : canDo ) cout << P << endl;
    C.placeTileAt( 2, 3 , true, 3 );
    C.setChars('-','+');
    C.dumpToScreen( );
    Filler F("tileTest.txt");
    F.greedyFill(3);
    F.dumpToScreen( );
    cout << endl;
    Filler G("tileTest.txt");
    G.betterFill(3);
    G.dumpToScreen( );
    
    
    
    
}