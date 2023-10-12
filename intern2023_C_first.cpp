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
	int left;
	int right;
};

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	map <string, st> M;
	vector<string> names;
	for (int i = 0; i < m; ++i) {
		string tmp;
		cin >> tmp;
		names.push_back(tmp);
		st t;
		t.left = -1000000007, t.right = 1000000007;
		M[tmp] = t;
	}
	//cant be improved:
	vector <vector<int>> val(n);
	for (int i = 0; i < n; ++i)
		val[i].resize(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> val[i][j];

	// part1 done 3*10**5 * log(3*10**5) + 3*10**5 = 6.3 * 10**6

	//cant be improved:
	for (int k = 0; k < q; ++k) {
		string name; char s; int v;
		cin >> name >> s >> v;
		if (s == '>') {
			if (M[name].left < v)
				M[name].left = v;
		}
		else {
			if (M[name].right > v)
				M[name].right = v;
		}
	}
	// part2 done 10**5 * 2*log(3*10**5) = 4 * 10**6
	

	//can be improved:  (changed it)
	vector<int> goodOnes(n, 1);
	for (int j = 0; j < m; ++j) {
		//string name = names[j];
		st tmp = M[names[j]];
		for (int i = 0; i < n; ++i) {
			if (val[i][j] > tmp.left && val[i][j] < tmp.right) {
				continue;
			}
			else {
				goodOnes[i] = -1;
			}
		}
	}
	// part3 done  3*10**5 * log(3*10**5) = 6 * 10**6


	//cant be improved:
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		if (goodOnes[i] > 0)
			for (int j = 0; j < m; ++j)
				ans += val[i][j];
			
	cout << ans;

	return 0;											// total: ~O(1.7 * 10**7)
}
