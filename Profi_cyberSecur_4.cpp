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
//#include <json.hpp>


using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");



int main()
{
	unsigned long long n = 2022;
	for (int i = 0; i < 2024; ++i) {
		n *= 2022;
		n = n % 10000000000000;
	}
	cout << n;
	
	return 0;
}
