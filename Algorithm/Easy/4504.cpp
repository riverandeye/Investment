#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
  int n;
  int num;

  cin >> n;

  while (1)
  {
    cin >> num;

    if (num == 0)
    {
      break;
    }

    if (num % n == 0)
    {
      cout << num << " is a multiple of " << n << ".\n";
    }
    else
    {
      cout << num << " is NOT a multiple of " << n << ".\n";
    }
  }

  return 0;
}