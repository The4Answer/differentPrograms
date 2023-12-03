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

int takeChange(string algo)
{
    char ans = algo[0];
    int an = ans - '0';
    return an;
}

char takeDo(string algo)
{
    char ans = algo[1];
    return ans;
}
char takeCondition(string algo)
{
    char ans = algo[2];
    return ans;
}


int main()
{
	vector<map<char, string>> algo(2);
	int n = 10;
	string t;
	//A
	cin >> t;
	algo[0]['A'] = t;
	cin >> t;
	algo[1]['A'] = t;
	cin >> t;
	algo[0]['B'] = t;
	cin >> t;
	algo[1]['B'] = t;
	cin >> t;
	algo[0]['C'] = t;
	cin >> t;
	algo[1]['C'] = t;
	cin >> t;
	algo[0]['D'] = t;
	cin >> t;
	algo[1]['D'] = t;
	cin >> t;
	algo[0]['E'] = t;
	cin >> t;
	algo[1]['E'] = t;
    
    char condition = 'A';
    vector<int> lenta(1000000, 0);
    int id = 50000;
    int toChange = -1;
    char toDo = ' ';

    int counter = 0;
    while (true)
    {
        if (condition == 'H') {
            cout << "halt";
            return 0;
        }
        /*осталось дописать 3 функции для получения :
        toChange = takeChange(algo[lenta[id]][condition]);
        toDo = takeDo(algo[lenta[id]][condition]);;
        condition = takeCondition(algo[lenta[id]][condition]);;*/
        toChange = takeChange(algo[lenta[id]][condition]);
        toDo = takeDo(algo[lenta[id]][condition]);
        condition = takeCondition(algo[lenta[id]][condition]);
        ///
        //toDo:
        lenta[id] = toChange;
        if (toDo == 'R')
        {
            id++;
            if (id >= lenta.size())
            {
                cout << "loop";
                return 0;
            }
        }
        else if (toDo == 'L')
        {
            id--;
            if (id < 0)
            {
                cout << "loop";
                return 0;
            }

        }
        counter++;
        if (counter > 1000000)
        {
            cout << "loop";
            return 0;
        }
    }

	
	return 0;
}
