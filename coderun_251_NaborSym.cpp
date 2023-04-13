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

	int minL = 1000000;
	for (int i = 0; i < s.size(); ++i) { //O(262600)O(n*n*m)
		set<char> used;
		int  cur = 0;
		for (int j = i; j < s.size(); ++j) {
			cur++;
			used.insert(s[j]);
			bool isGood = true;
			for (int k = 0; k < c.size(); ++k) {
				if (used.find(c[k]) == used.end()) 
					isGood = false;
			}
			if (isGood) {
				minL = min(minL, cur);
			}
		}
	}
	if (minL < 1000000)
		cout << minL;
	else
		cout << 0;
	return 0;
}
