#include <iostream>

using namespace std;

int main()
{
   int sum = 0;
   
   int lastTerm = 1;
   int lastLastTerm = 1;
   
   while (true)
   {
       int current = lastTerm + lastLastTerm;
       lastLastTerm = lastTerm;
       lastTerm = current;
       if (current >= 4000000)
       {
           break;
       }
       else if (current % 2 == 0)
       {
           sum += current;
       }
   }
   
   cout << sum;
   return 0;
}