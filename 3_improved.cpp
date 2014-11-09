#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

//Question:
// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?

//implementation using Miller-Rabin test

void convertEvenNumberIntoPowerOfBase2TimesAnotherOddNumber(long int num, long int & s, long int & d)
{
  s = 0;
  d = num - 1;

  while (d % 2 == 0)
  {
      d /= 2;
      s++;
  }
  //now, pow(2,s) * d == num-1
}

long int getRandomNumberBetween2AndNum(long int num)
{
  srand(time(0));
  return rand() % ((num-1) - 2) + 10;
}

bool ifOddNumIsPrime(long int num)
{
  long int s, d;

  //changes s and d and assigns them into a value which will make it so that pow(2,s) * d == num-1
  convertEvenNumberIntoPowerOfBase2TimesAnotherOddNumber(num, s, d);

  //get random num between 2 and the num-1
  long int a = getRandomNumberBetween2AndNum(num);

  //compute a^d mod n. if result is 1 or -1, probablyprime. if result is not those, compute a^(2d), a^(4d)... and so on to a^(d*2^(s-1))
  long int tempS = 0;
  while (tempS <= (s-1))
  {
    if ( ((int)pow(a, d*pow(2,tempS)) % num) == 1 || ((int)pow(a, d*pow(2,tempS)) % num) == -1)
    {
      return true; //probably is prime
    }

    tempS++;
  }

  return false;
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