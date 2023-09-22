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



using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");



int main() {
	long long n, m;
	cin >> n >> m;
	long long c1, c2;
	cin >> c1 >> c2;
	
	if (m <= n)
	{
		cout << 0;
		return 0;
	}

	long long comp1 = c1 * 4;
	long long comp2 = c2 * 1;
	if (comp1 < comp2)
	{
		long long ans = m - n;
		cout << ans * c1;
	}
	else {
		long long ans = m - n;
		long long sumC1 = 0, sumC2 = 0;
		if (ans % 4 == 0) 
			sumC2 = ans / 4;
		else {
			sumC2 = ans / 4;
			int left = ans % 4;
			if (left * c1 < c2)
				sumC1 = left;
			else
				sumC2++;
		}
		cout << sumC1 * c1 + sumC2 * c2;
	}

	return 0;											// total: O()
}
