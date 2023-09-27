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



int main() {
	long long n;
	cin >> n;
	int i = 0;
	while (i < 1000000) {
		n++;
		long long N = n * n;
		string s1 = to_string(n);
		string s2 = to_string(N);
		int ind = 0;
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[ind] == s2[j]) {
				ind++;
			}
			if (ind >= s1.size())
			{
				cout << n;
				return 0;
			}
		}
		i++;
	}

	return 0;											// total: O()
}
