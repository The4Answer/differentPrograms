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

int parent[200007];
int Rank[200007];
vector<int> visited(200007, 1);

void make_set(int v) {
	parent[v] = v;
	Rank[v] = 0;
}

int find_set(int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}


void union_sets(int a, int b) {
	a = find_set(a);
	b = find_set(b);
	visited[a]++;
	visited[b]++;
	if (a != b) {
		if (Rank[a] < Rank[b])
			swap(a, b);
		parent[b] = a;
		if (Rank[a] == Rank[b])
			++Rank[a];
	}
}

int main() {
    int n, m;
    cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		make_set(i);
	}
	for (int i = 0; i < m; ++i) {
		int t, x, y;
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			union_sets(x, y);
		}
		else if (t == 2) {
			cin >> x >> y;
			x = find_set(x);
			y = find_set(y);
			if (x == y)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
		else {
			cin >> x;
			int ans = visited[find_set(x)];
			cout << ans << "\n";
		}
	}


    return 0;											// total: O()
}
