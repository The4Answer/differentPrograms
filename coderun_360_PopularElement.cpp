#include <iostream>
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

/*ifstream cin("input.txt");
ofstream cout("output.txt");*/


int main() {
	int n;
	cin >> n;
	map <long long, int> M;
	long long best = 0;
	int countB = 0;
	for (int i = 0; i < n; ++i) {
		long long tmp;
		cin >> tmp;
		M[tmp]++;
		if (countB < M[tmp]) {
			countB = M[tmp];
			best = tmp;
		}
		else if (countB == M[tmp] && best < tmp) {
			countB = M[tmp];
			best = tmp;
		}
	}
	cout << best;
	return 0;
}
