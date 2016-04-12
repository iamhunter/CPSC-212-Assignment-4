//
//  Square.h
//  
//
//  Created by Andrew Marion Hunter on 4/12/16.
//
//

class Square
{
public:
    Square(int st8, int covernumber);
    
private:
    int state; // 0 = open, 1 = covered, 2 = forbidden
    int IfCoveredNumber;
};