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

bool cmp(int a, int b){
	return a > b;
}

int main() 
{
	int n, m;
	cin >> n >> m;
	int maxL = min(n, m);
	vector<int> a(n);
	vector<int> b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), cmp);
	vector<long long> sumBuy(maxL);
	vector<long long> sumSell(maxL);
	sumBuy[0] = a[0];
	sumSell[0] = b[0];
	for (int i = 1; i < maxL; ++i) {
		sumBuy[i] = sumBuy[i - 1] + a[i];
		sumSell[i] = sumSell[i - 1] + b[i];
	}
	long long ans = 0;
	for (int i = 0; i < maxL; ++i) 
		if (sumSell[i] - sumBuy[i] > ans)
			ans = sumSell[i] - sumBuy[i];
	cout << ans;

	return 0;
}
