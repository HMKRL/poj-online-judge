#include<map>
#include<iostream>
using namespace std;

int main()
{
	map<string, int> Map;
	cout << Map["abc"] << ' ' << Map["sss"] << endl;
	Map["abc"] = 1;
}
