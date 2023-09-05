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

struct st {
	int f;
	int s;
	int cost;
};

int n;
int color = 1;
vector<int> g[200007];
bool used[200007];
int allComps[200007];
vector<int> comp;

void dfs(int v) {
	used[v] = true;
	comp.push_back(v);
	allComps[v] = color;
	for (size_t i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs(to);
	}
}

void find_comps() {
	for (int i = 0; i < n; ++i)
		used[i] = false;
	for (int i = 0; i < n; ++i)
		if (!used[i]) {
			comp.clear();
			dfs(i);
			color++;
			/*cout << "Component:";
			for (size_t j = 0; j < comp.size(); ++j)
				cout << ' ' << comp[j];
			cout << endl;*/
		}
}

bool cmp(st f, st s) {
	return f.cost > s.cost;
}

int main() {
	int m;
	cin >> n >> m;
	vector <st> edge(m);
	for (int i = 0; i < m; ++i) {						//m
		cin >> edge[i].f >> edge[i].s >> edge[i].cost;
		edge[i].f--, edge[i].s--;
		g[edge[i].f].push_back(edge[i].s);
	}
	find_comps();										// n + m
	sort(edge.begin(), edge.end(), cmp);				// mlogm

	vector <st> ansEdges;
	vector<bool> added(n, false);
	for (int i = 0; i < m; ++i) {						// m
		if (!added[edge[i].f] || !added[edge[i].s]) {
			ansEdges.push_back(edge[i]);
			added[edge[i].f] = true;
			added[edge[i].s] = true;
		}
	}
	int ans = 1000000000;
	for (int i = 0; i < ansEdges.size(); ++i) {
		if (ansEdges[i].cost < ans)
			ans = ansEdges[i].cost;
	}
	cout << ans - 1;
	
    return 0;											// total: O(n + 4*m + m*logm)
}
