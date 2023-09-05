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
    long long n, s;
    long long ans = 0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        long long tmp;
        cin >> tmp;
        if (tmp <= s) {
            if (ans < tmp)
                ans = tmp;
        }
    }
    cout << ans;
    return 0;
}
