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
#include <iomanip>
#include <json.hpp>


using namespace std;

	ifstream cin("input.txt");
ofstream cout("output.txt");



int main() 
{
	long long n, m, q;
	cin >> n >> m >> q;
	vector <long long> working(n + 1, m);
	vector<long long> resets(n + 1, 0);		
	vector <map<long long, long long>> M(n + 1);
	set <pair<long long, long long>> rXwMin;		//first - num of r * w // second - id of datacentre
	set <pair<long long, long long>> rXwMax;		//first - num of r * w // second - id of datacentre
	for (long long i = 1; i <= n; ++i)
		rXwMin.insert(make_pair(0, i));
	rXwMax = rXwMin;
	for (long long z = 0; z < q; ++z) {
		string s;
		cin >> s;
		if (s == "DISABLE") {
			long long dataC, serverId;
			cin >> dataC >> serverId;
			if (M[dataC][serverId] < 1) {
				M[dataC][serverId] = 1;
				long long work = working[dataC], res = resets[dataC];
				working[dataC]--;
				rXwMin.erase(rXwMin.find(make_pair(work * res, dataC)));
				rXwMin.insert(make_pair(working[dataC] * resets[dataC], dataC));

				rXwMax.erase(rXwMax.find(make_pair(-work * res, dataC)));
				rXwMax.insert(make_pair(-working[dataC] * resets[dataC], dataC));
			}
		}
		else if (s == "GETMAX") {
			pair<long long, long long> ans = *rXwMax.begin();
			cout << ans.second << "\n";
		}
		else if (s == "GETMIN") {
			pair<long long, long long> ans = *rXwMin.begin();
			cout << ans.second << "\n";
		}
		else if (s == "RESET") {
			long long dataC;
			cin >> dataC;
			M[dataC].clear();
			long long work = working[dataC], res = resets[dataC];
			resets[dataC]++;
			working[dataC] = m;
			rXwMin.erase(rXwMin.find(make_pair(work * res, dataC)));
			rXwMin.insert(make_pair(working[dataC] * resets[dataC], dataC));
			rXwMax.erase(rXwMax.find(make_pair(-work * res, dataC)));
			rXwMax.insert(make_pair(-working[dataC] * resets[dataC], dataC));
		}
	}

	return 0;
}
