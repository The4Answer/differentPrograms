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
//#include <json.hpp>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");




int main()
{
	long double L, R;
	cin >> L >> R;
	long double l = sqrt(L);
	long double r = sqrt(R);
	long long il = l + 0.5;
	if (il < l)
		il++;
	long long ir = r;
	if (ir - il >= 0)
		cout << il << " " << ir;
	else
		cout << 0 << " " << 0;

    return 0;
}
