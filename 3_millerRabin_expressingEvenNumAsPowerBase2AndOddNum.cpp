#include <iostream>
#include <math.h>

using namespace std;


// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

//This cpp is a test to see if this function can convert any even number into 2^s x d, where d is an odd number
//evennumber/d = 2^s
//logeven - logd = s

//the argument, long int num, should be an odd number
void convertEvenNumberIntoPowerOfBase2TimesAnotherOddNumber(long int num)
{
  int s = 0;
  int d = num - 1;

  while (d % 2 == 0)
  {
      d /= 2;
      s++;
  }

  cout << "s " << s << endl;
  cout << "d " << d << endl; 
  cout << (pow(2,s) * d) << endl; //should output 320
  cout << (num-1) << endl; //outputs 320
}

int main()
{
  convertEvenNumberIntoPowerOfBase2TimesAnotherOddNumber(321);

  return 0;
}