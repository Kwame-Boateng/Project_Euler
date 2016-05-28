#include <iostream>
using namespace std;

int SumOfMultiples (int upperLimit)
{
    int sum = 0;
    for (int index = 0; index < upperLimit; index++)
    {
      if ((index % 3 == 0) || (index % 5 == 0))
      {
          sum += index;
      }
    }
    return sum;
}


int main ()
{
    cout << SumOfMultiples(1000) << endl;
    return 0;
}
