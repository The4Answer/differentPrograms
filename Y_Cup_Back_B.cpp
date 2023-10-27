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

string s;
int findY(int ind){
	int replaces = 0;
	string tmp = "Yandex";
	for (int i = 0; i < 6; ++i) {
		if (s[ind + i] != tmp[i])
			replaces++;
	}
	return replaces;
}

int findC(int ind) {
	int replaces = 0;
	string tmp = "Cup";
	for (int i = 0; i < 3; ++i) {
		if (s[ind + i] != tmp[i])
			replaces++;
	}
	return replaces;
}

string changeTo(string t, string tmp, int ind) {
	for (int i = 0; i < tmp.size(); ++i)
		t[ind + i] = tmp[i];
	return t;
}

int main() {
	cin >> s;

	/*
	1. Check if everything is good? Yes -> cout
	2. Find best(left) place for "Yandex" and AFTER that find place for "Cup" -> save string and count for it			|		0 < s.size() - 8
	3. Find best(right) place for "Cup" and repeat everything that we did in step 2 -> save string and count			|		s.size() - 3 > 5
	4. Compare counts and cout best string
	*/
	int minY = 1000000, minC = 1000000;
	int mid = 0;
	for (int i = 0; i < s.size()-5; ++i) {
		int find = findY(i);
		if (find < minY) {
			minY = find;
			mid = i;
		}
		if (minY == 0)
			break;
	}
	if (minY == 0) {
		for (int i = mid+6; i < s.size() - 2; ++i) {
			int find = findC(i);
			if (find < minC) {
				minC = find;
				mid = i;
			}
			if (minC == 0)
				break;
		}
		if (minC == 0) {
			cout << s;
			return 0;
		}
	}

	// part 2
	string ans1 = s;
	int Count1 = 0;
	minY = 1000000, minC = 1000000;
	int iY = -1, iC = -1;
	for (int i = 0; i < s.size() - 8; ++i) {
		int find = findY(i);
		if (find < minY) {
			minY = find;
			iY = i;
		}
		if (minY == 0)
			break;
	}
	for (int i = iY + 6; i < s.size() - 2; ++i) {
		int find = findC(i);
		if (find < minC) {
			minC = find;
			iC = i;
		}
		if (minC == 0)
			break;
	}
	ans1 = changeTo(s, "Yandex", iY);
	ans1 = changeTo(ans1, "Cup", iC);
	Count1 = minY + minC;
	//result part 2 = string ans1 and Count1

	//part 3
	string ans2 = s;
	int Count2 = 0;
	minY = 1000000, minC = 1000000;
	iY = -1, iC = -1;
	for (int i = s.size() - 3; i > 5; --i) {
		int find = findC(i);
		if (find < minC) {
			minC = find;
			iC = i;
		}
		if (minC == 0)
			break;
		
	}
	for (int i = 0; i < iC - 5; ++i) {
		int find = findY(i);
		if (find < minY) {
			minY = find;
			iY = i;
		}
		if (minY == 0)
			break;
	}
	ans2 = changeTo(s, "Yandex", iY);
	ans2 = changeTo(ans2, "Cup", iC);
	Count2 = minY + minC;
	//result part 3 = string ans2 and Count2

	//part 4
	if (Count1 < Count2)
		cout << ans1;
	else
		cout << ans2;

	return 0;											// total: ~O()
}
