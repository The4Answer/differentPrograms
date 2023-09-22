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
	int rank;
	int pos;
	int countS;
	vector <int> S;
};

bool cmp(st f, st s) {
	return f.rank < s.rank;
}

int main() {
	int n, k;
	//										read
	cin >> n >> k;
	vector <int> p(k + 1);
	for (int i = 1; i <= k; ++i)
		cin >> p[i];

	vector<st> a;
	for (int i = 0; i < n; ++i) {
		st tmp;
		cin >> tmp.rank >> tmp.countS;
		tmp.pos = i;
		for (int j = 0; j < tmp.countS; ++j){
			int t;
			cin >> t;
			tmp.S.push_back(t);
		}
		a.push_back(tmp);
	}
	//										solve
	sort(a.begin(), a.end(), cmp);
	vector<int> answers(n, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < a[i].countS; ++j) {
			int sub = a[i].S[j];
			if (p[sub] > 0) {
				p[sub]--;
				answers[a[i].pos] = sub;
				break;
			}
		}
	}

	for (int i = 0; i < answers.size(); ++i)
		cout << answers[i] << " ";

	return 0;											// total: O()
}
