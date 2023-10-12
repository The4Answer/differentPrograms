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

/*
В одном году 365 дней. Год делится на 12 месяцев, количество дней в каждом месяце: 
[31, 28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31]. В одном дне 24 часа (от 0 до 23), 
в одном часу 60 минут (от 0 до 59), в одной минуте 60 секунд (от 0 до 59).
*/

int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int year1, month1, day1, hour1, min1, sec1;
	int year2, month2, day2, hour2, min2, sec2;
	cin >> year1 >> month1 >> day1 >> hour1 >> min1 >> sec1;
	cin >> year2 >> month2 >> day2 >> hour2 >> min2 >> sec2;

	int ans_sec = 0;
	bool taken = false;

	ans_sec += (sec2 - sec1);
	if (ans_sec < 0) {
		taken = true;
		ans_sec += 60;
	}

	int ans_min = 0;
	ans_min += (min2 - min1);
	if (taken) {
		ans_min--;
		taken = false;
	}
	if (ans_min < 0) {
		taken = true;
		ans_min += 60;
	}

	int ans_hour = 0;
	ans_hour += (hour2 - hour1);
	if (taken) {
		ans_hour--;
		taken = false;
	}
	if (ans_hour < 0) {
		taken = true;
		ans_hour += 24;
	}
	ans_sec = ans_hour * 60 * 60 + ans_min * 60 + ans_sec;

	/// <summary>
	/// done sec
	/// </summary>
	/// <returns></returns>

	int ans_day = day2;
	if (taken) {
		ans_day--;
		taken = false;
	}
	for (int i = 1; i < month2; ++i) 
		ans_day += month_days[i];
	

	ans_day -= day1;
	for (int i = 1; i < month1; ++i) 
		ans_day -= month_days[i];
	
	if (ans_day < 0) {
		taken = true;
		ans_day += 365;
	}

	int ans_year = 0;
	if (taken) {
		ans_year--;
		taken = false;
	}
	ans_year += (year2 - year1);

	int ans_days = ans_year * 365 + ans_day;

	cout << ans_days << " " << ans_sec;
	return 0;											// total: O()
}
