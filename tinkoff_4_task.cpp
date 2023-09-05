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

vector <int> all;
vector <int> ansNumb;
bool found = false;

void find_sum(int target, int current, int ind) {
	if (found)
		return;
	if (target == current) {
		cout << ansNumb.size() << "\n";
		for (int i = 0; i < ansNumb.size(); ++i)
			cout << ansNumb[i] << " ";
		found = true;
		return;
	}

	if (ind == all.size() || current > target)
		return;

	ansNumb.push_back(all[ind]);
	find_sum(target, current + all[ind], ind + 1);
	ansNumb.pop_back();
	find_sum(target, current, ind + 1);
	
}

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(m);
	for (int i = 0; i < m; ++i)
		cin >> a[i];
	
	for (int i = 0; i < m; ++i) {
		all.push_back(a[i]);
		all.push_back(a[i]);
	}
	find_sum(n, 0, 0);
	if(!found)
		cout << -1;
    return 0;											// total: O()
}
