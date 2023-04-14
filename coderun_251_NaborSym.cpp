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


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");


int main() {
	string s;
	cin >> s;
	string c;
	cin >> c;
	set<char> checker;
	for (int i = 0; i < c.size(); ++i) 
		checker.insert(c[i]);

	int minL = 1000000;
	for (int i = 0; i < s.size(); ++i) { //O(262600)O(n*n*m)
		set<char> used;
		int  cur = 0;
		for (int j = i; j < s.size(); ++j) {
			cur++;
			used.insert(s[j]);
			if (used == checker) {
				minL = min(minL, cur);
				break;
			}
		}
	}
	if (minL < 1000000)
		cout << minL;
	else
		cout << 0;
	return 0;
}
