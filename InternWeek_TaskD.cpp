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
	int k, n, m;
	cin >> k >> n >> m;
	vector<int> totalR;
	vector<int> timeForFix;
	map<int, bool> was;

	vector <vector<int>> breaks(1001);
	for (int i = 0; i < n; ++i) {
		int day, road;
		cin >> day >> road;
		if (!was[road]) {
			totalR.push_back(road);
			was[road] = true;
		}
		breaks[road].push_back(day);
		if (breaks[road].size() > 1) {
			int del = breaks[road][breaks[road].size() - 1] - breaks[road][breaks[road].size() - 2];
			timeForFix.push_back(del);
		}
	}
	if (totalR.size() > m) {
		cout << -1;
		return 0;
	}
	m -= totalR.size();
	sort(timeForFix.begin(), timeForFix.end());
	long long sum = 0;
	for (int i = 0; i < timeForFix.size() - m; ++i) {
		sum += timeForFix[i];
	}
	cout << sum;
	return 0;											// total: O()
}
