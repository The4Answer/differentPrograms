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
	int k;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(a.begin(), a.end());
	int ind1 = 0;
	int ind2 = n - k - 1;
	int ans = 1000000003;
	while (ind2 < n) {
		if (a[ind2] - a[ind1] < ans)
			ans = a[ind2] - a[ind1];
		ind1++; ind2++;
	}
	cout << ans;
	return 0;											// total: O()
}
