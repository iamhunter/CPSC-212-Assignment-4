//
//  Runner.cpp
//  
//
//  Created by Andrew Marion Hunter on 4/18/16.
//
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "Square.cpp"
#include "Configuration.cpp"
#include "Filler.cpp"


int main()
{

    int w, x, z;
    string y;
    bool boolean;
    
 
    cout << "Enter number of rows ands cols for board:";
    cin >> w >> x;
    Configuration C(w,x);
    
    cout << "Enter forbiden square:";
    cin >> w >> x;
    C.forbid(w,x);
    
    cout << "Enter tile info:";
    cin >> w >> x >> y >> z;
    if(y == "true")
    {
        boolean = true;
    }
    else
    {
        boolean = false;
    }
    C.placeTileAt(w, x, boolean, z);
    
    cout << "Enter tile info:";
    cin >> w >> x >> y >> z;
    if(y == "true")
    {
        boolean = true;
    }
    else
    {
        boolean = false;
    }
    C.placeTileAt(w, x, boolean, z);
    
    cout << "Enter tile info:";
    cin >> w >> x >> y >> z;
    if(y == "true")
    {
        boolean = true;
    }
    else
    {
        boolean = false;
    }
    C.placeTileAt(w, x, boolean, z);
    
    C.dumpToScreen();
    

 
}