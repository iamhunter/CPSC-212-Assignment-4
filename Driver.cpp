//
//  Driver.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

#include <stdio.h>
#include "Square.cpp"
#include "Configuration.cpp"

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
    
    
    C.dumpToScreen();
    
}