//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>
#include <iomanip>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");


int main() 
{
  int a, b, c;
  cin >> a >> b >> c;
  int minSum = min(a + b, min(b + c, a + c));
  if (minSum > max(a, max(b, c)))
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
