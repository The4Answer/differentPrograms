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
    int n;
    cin >> n;
    vector<int> a(n);
    vector <int> good(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> good[i];

    auto first = a.begin();
    auto second = a.end()-1;
    for (auto gFirst = good.begin(); first < a.end(); first++, gFirst++) {
        if (*first != *gFirst)
            break;
    }
    for (auto gSec = good.end()-1; second > a.begin(); second--, gSec--) {
        if (*second != *gSec)
            break;
    }
    if (first <= second) {
        sort(first, second+1);
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != good[i]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
