#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
  int a[6] = {1, 1, 2, 2, 2, 8};
  int b[6];

  for (int i = 0; i < 6; ++i)
  {
    cin >> b[i];
    cout << (b[i] - a[i]) * -1 << " ";
  }
  cout << endl;

  return 0;
}