#include <iostream>
#include <math.h>

using namespace std;


// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

//implementation: using trial division... the runtime so long... 
//as I'm typing this, it's still running
//will update with faster algorithm later.

bool ifOddNumIsPrime(long int num)
{
    int forLoopConstraint = ceil(sqrt((double)num));
    
    //test only odd numbers because even numbers are not prime
    for (int i = 3; i < forLoopConstraint; i+=2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
   long int number = 600851475143; //original number
   
   //test starting with the next smaller odd number, only testing odd numbers
   //cuz even numbers are not prime at all
   for (long int i = 600851475141; i > 0; i-=2) 
   {
        if (number % i == 0)
        {
          if (ifOddNumIsPrime(i))
          {
            cout << i << endl;
            break;
          }
        }
   }
   
   return 0;
}
