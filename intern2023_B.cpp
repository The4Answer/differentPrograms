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
	int A;
	int B;
};

int main() {
	vector <int> all;
	map <int, st> M;
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		M[tmp].A++;
	}
	for (int i = 0; i < m; ++i) {
		int tmp;
		cin >> tmp;
		M[tmp].B++;
	}
	int answer = 0;
	for (auto i = M.begin(); i != M.end(); ++i) {	
		st tmp =  i->second;
		answer += abs(tmp.A - tmp.B);
	}

	// first part done


	for (int i = 0; i < q; ++i) {
		int t, c;
		char p;
		cin >> t >> p >> c;
		int a = M[c].A;
		int b = M[c].B;
		answer -= abs(M[c].A - M[c].B);

		if (t == 1) {
			if (p == 'A')
				M[c].A++;
			else
				M[c].B++;
		}
		else {
			if (p == 'A')
				M[c].A--;
			else
				M[c].B--;
		}
		answer += abs(M[c].A - M[c].B);
		cout << answer << " ";
	}

	return 0;											// total: O()
}
