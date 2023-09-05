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


int main() {
    string s;
    map<char, int> M;
    M['s'] = 0, M['h'] = 0, M['e'] = 0, M['r'] = 0, M['i'] = 0, M['f'] = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 's') 
            M[s[i]]++;
        if (s[i] == 'h') 
            M[s[i]]++;
        if (s[i] == 'e') 
            M[s[i]]++;
        if (s[i] == 'r') 
            M[s[i]]++;
        if (s[i] == 'i') 
            M[s[i]]++;
        if (s[i] == 'f') 
            M[s[i]]++;
    }
    string t = "sherif";
    int ans = 100000000;
    for (int i = 0; i < t.size(); ++i) {
        if (M[t[i]] < ans)
            ans = M[t[i]];
    }
    cout << ans;

    return 0;
}
