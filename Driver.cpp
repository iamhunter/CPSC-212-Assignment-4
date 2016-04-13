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
    
    int x, y;

    cout << "Enter number of rows ands cols for board:";
    cin >> x >> y;
    Configuration C(x,y);
    cout << "Enter forbiden square:";
    cin >> x >> y;
    C.forbid(x,y);

    
    
    C.dumpToScreen();
    
}