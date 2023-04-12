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


int main() {
	cout << fixed;
	int n;
	cin >> n;
	vector<double> p(n);
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		double a, b;
		cin >> a >> b;
		p[i] = a * b;
		sum += p[i];
	}
	for (int i = 0; i < n; ++i) {
		cout << setprecision(12) << p[i] / sum << "\n";
	}

	return 0;
}
