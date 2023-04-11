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
	int inf = 10000000;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<int> dp(n);
	dp[0] = inf;
	dp[1] = a[1] - a[0];
	for (int i = 2; i < n; ++i) {
		dp[i] = min(dp[i - 2], dp[i - 1]) + (a[i] - a[i - 1]);
	}
	cout << dp[n - 1];
	return 0;
}
