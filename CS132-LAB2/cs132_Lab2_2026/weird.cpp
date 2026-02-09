

#include "weird.h"
int main()
{
    float z = 0.10;

//TODO: declare object 'a' of class weird

    weird<float> a;

    for (int i = 0; i <= 5; i++)
        {
            a.write();
            a%z;
        }
    return 0;
}
//TODO: what is the output of the above program

/* 
The above program outputs a range of numbers all divided by .1.
It starts at 10000 as declared in the definition of the variable T.
The for loop runs six times, and each time the variable x is divided by .1.
*/

