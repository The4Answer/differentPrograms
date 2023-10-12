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

struct str {
	string name;
	int l;
	int r;
};

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	vector <str> Name;
	map<string, int> find;
	for (int i = 0; i < m; ++i) {
		str tmp;
		cin >> tmp.name;
		tmp.l = - 1000000007, tmp.r = 1000000007;
		Name.push_back(tmp);
		find[tmp.name] = i;
	}
	//cant be improved:
	vector <vector<int>> val(n);
	for (int i = 0; i < n; ++i)
		val[i].resize(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> val[i][j];
	// part1 done  OLD: 3*10**5 * log(3*10**5) + 3*10**5 = 6.3 * 10**6		NEW: 

	//cant be improved:
	for (int k = 0; k < q; ++k) {
		string name; char s; int v;
		cin >> name >> s >> v;
		int id = find[name];
		if (s == '>') {
			if (Name[id].l < v)
				Name[id].l = v;
		}
		else {
			if (Name[id].r > v)
				Name[id].r = v;
		}
	}
	// part2 done OLD:  10**5 * 2*log(3*10**5) = 4 * 10**6		NEW: 10**5 * log(3*10**5) = 2 * 10**6
	

	//can be improved:  (changed it)
	vector<int> goodOnes(n, 1);
	for (int j = 0; j < m; ++j) {
		//string name = names[j];
		str tmp = Name[j];
		for (int i = 0; i < n; ++i) {
			if (val[i][j] > tmp.l && val[i][j] < tmp.r) {
				continue;
			}
			else {
				goodOnes[i] = -1;
			}
		}
	}
	// part3 done  OLD:  3*10**5 * log(3*10**5) = 6 * 10**6		NEW: 3*10**5 = 3 * 10**6


	//cant be improved:
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		if (goodOnes[i] > 0)
			for (int j = 0; j < m; ++j)
				ans += val[i][j];
			
	cout << ans;

	return 0;											// total: ~O(1.7 * 10**7) NEW: ~O(1.13 * 10**7)
}
