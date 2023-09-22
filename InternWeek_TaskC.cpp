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

vector <int> Rank(100007, 0);

int main() {
	int n;
	cin >> n;
	Rank[0] = 1;
 	for (int i = 1; i <= n; ++i) {
		int tmp;
		cin >> tmp;
		Rank[i] = Rank[tmp] + 1;
	}
	int ans = 0;
	for (int i = 0; i < Rank.size(); ++i) {
		if (Rank[i] > Rank[ans])
			ans = i;
	}
	cout << ans;
	return 0;											// total: O()
}
