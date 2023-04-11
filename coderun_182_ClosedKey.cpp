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
	long long x, y;
	cin >> x >> y;
	if (y % x != 0) {
		cout << 0;
		return 0;
	}
	y /= x;
	long long n = y;
	int ans = 1;
	for (int i = 2; i < sqrt(double(n)); ++i) {
		if (y % i == 0) {
			long long tmp = i;
			while (y % (tmp*i) == 0) {
				tmp *= i;
			}
			if (tmp < sqrt(double(n))) {
				ans++;
				y /= tmp;
			}
		}
	}
	cout << ans * 2;
	return 0;
}
