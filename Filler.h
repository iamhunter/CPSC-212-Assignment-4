//
//  Filler.hpp
//  
//
//  Created by Andrew Marion Hunter on 4/18/16.
//
//



#include <stdio.h>

class Filler : public Configuration
{
    
public:
    Filler(string fileName) : Configuration(fileName){};
    void greedyFill(int tileLength);
    void betterFill(int tileLength);
};