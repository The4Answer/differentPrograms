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
	int i, j;
};

int n, m;
vector <vector<int>> a;		// 1 = white, -1 = black, 0 = empty
vector <st> Whites;
vector <st> Blacks;

bool checkW(int i, int j) {
	if (i - 2 > 0 && j - 2 > 0) {
		if (a[i - 1][j - 1] == -1 && a[i - 2][j - 2] == 0)
			return true;
	}
	if (i - 2 > 0 && j + 2 <= m) {
		if (a[i - 1][j + 1] == -1 && a[i - 2][j + 2] == 0)
			return true;
	}
	if (i + 2 <= n && j - 2 > 0) {
		if (a[i + 1][j - 1] == -1 && a[i + 2][j - 2] == 0)
			return true;
	}
	if (i + 2 <= n && j + 2 <= m) {
		if (a[i + 1][j + 1] == -1 && a[i + 2][j + 2] == 0)
			return true;
	}
	return false;
}

bool checkB(int i, int j) {
	if (i - 2 > 0 && j - 2 > 0) {
		if (a[i - 1][j - 1] == 1 && a[i - 2][j - 2] == 0)
			return true;
	}
	if (i - 2 > 0 && j + 2 <= m) {
		if (a[i - 1][j + 1] == 1 && a[i - 2][j + 2] == 0)
			return true;
	}
	if (i + 2 <= n && j - 2 > 0) {
		if (a[i + 1][j - 1] == 1 && a[i + 2][j - 2] == 0)
			return true;
	}
	if (i + 2 <= n && j + 2 <= m) {
		if (a[i + 1][j + 1] == 1 && a[i + 2][j + 2] == 0)
			return true;
	}
	return false;
}

int main() {
	//read all info
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 0; i <= n; ++i)
		a[i].resize(m + 1, 0);

	int w, b;
	cin >> w;
	Whites.resize(w);
	for (int i = 0; i < w; ++i) {
		cin >> Whites[i].i >> Whites[i].j;
		a[Whites[i].i][Whites[i].j] = 1;
	}
	cin >> b;
	Blacks.resize(b);
	for (int i = 0; i < b; ++i) {
		cin >> Blacks[i].i >> Blacks[i].j;
		a[Blacks[i].i][Blacks[i].j] = -1;
	}

	//solution
	string whoseMove;
	cin >> whoseMove;
	if (whoseMove == "white") {
		for (int i = 0; i < w; ++i) 
			if (checkW(Whites[i].i, Whites[i].j)) {
				cout << "Yes";
				return 0;
			}
	}
	else if (whoseMove == "black") {
		for (int i = 0; i < b; ++i)
			if (checkB(Blacks[i].i, Blacks[i].j)) {
				cout << "Yes";
				return 0;
			}
	}
	else {
		cout << "Oooopppssss ERROR!!!";
		return 0;
	}
	cout << "No";
	return 0;
}
