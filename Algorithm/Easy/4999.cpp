#include <iostream>

using namespace std;
int main()
{
  string a, b;
  cin >> a >> b;
  printf("%s\n", a.size() < b.size() ? "no" : "go");
}