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
	
	vector <char> a(n+1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	stack<st> q;
	for (int i = 0; i < 2 * (n + 1); ++i) {
		st tmp;
		cin >> tmp.val;
		tmp.A = 0, tmp.B = 0;
		if (q.empty())
			q.push(tmp);
		else {
			if (tmp.val == 0)
				return 0;
			st prev = q.top();
			if (prev.val == tmp.val) {
				q.pop();
				continue;
			}
			if (prev.A == 0 && a[tmp.val] == 'A') {
				cout << 0 << " ";
				tmp.B = prev.B + 1;
			}
			else if (prev.B == 0 && a[tmp.val] == 'A') {
				cout << prev.A << " ";
				tmp.B = 1;
			}
			else if (prev.A == 0 && a[tmp.val] == 'B') {
				cout << prev.B << " ";
				tmp.A = 1;
			}
			else if (prev.B == 0 && a[tmp.val] == 'B') {
				cout << 0 << " ";
				tmp.A = prev.A + 1;
			}
			q.push(tmp);
		}
	}


	return 0;											// total: ~O()
}
