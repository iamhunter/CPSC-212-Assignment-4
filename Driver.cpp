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
    //Square P(2, 3);
    
    /*int x, y;

    cout << "Enter number of rows ands cols for board:";
    cin >> x >> y;
    Configuration C(x,y);
    cout << "Enter forbiden square:";
    cin >> x >> y;
    C.forbid(x,y);
*/
    
    Configuration C(4,5);
    C.forbid(2,4);
    C.placeTileAt(1,1,true,3);
    C.placeTileAt(2,2,false,2);
    list<Placement> canDo = C.getPossiblePlacements(3);
    for( Placement P : canDo ) cout << P << endl;
    
    C.setChars('-', '+');
    C.dumpToScreen();
    
    Configuration Z("betterTest.txt");

    Z.dumpToScreen();
    
    Filler F("tileTest.txt");
    
    F.greedyFill(5);

    
    F.dumpToScreen();
    
    char testchar = 'A';
    testchar++;
    cout << testchar;
    
    
    
}