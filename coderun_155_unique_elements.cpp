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
	int n;
	cin >> n;
	map <int, int> M;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		M[a[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (M[a[i]] < 2)
			ans++;
	}
	cout << ans;

	return 0;
}
