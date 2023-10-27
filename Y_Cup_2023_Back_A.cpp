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

struct st {
	int val;
	int A;
	int B;
};

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector <int> a(m);
	for (int i = 0; i < m; ++i)
		cin >> a[i];

	vector <unsigned long long> noZ;
	for (int i = 0; i < m; ++i)
		if (a[i] > 0)
			noZ.push_back(a[i]);
	if (noZ.size() == 0) {
		cout << 0;
		return 0;
	}
	vector <unsigned long long> sum;
	sum.push_back(noZ[0]);
	for (int i = 1; i < noZ.size(); ++i) {
		sum.push_back(noZ[i] + sum[i - 1]);
	}
	unsigned long long ans = 0;
	for (int i = 0; i < noZ.size(); ++i) {
		ans += noZ[i] * noZ[i];
		if (i + noZ[i] < noZ.size()) {
			ans += (sum[i + noZ[i]] - sum[i]);
		}
		else {
			ans += (sum[noZ.size() - 1] - sum[i]);
		}
	}
	cout << ans;

	return 0;											// total: ~O()
}
