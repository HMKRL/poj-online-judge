#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	vector<int> v;
	int num, input, i;
	cin >> num;
	for(i = 0;i < num;++i) {
		cin >> input;
		v.push_back(input);
	}
	getchar();getchar();getchar();getchar();
	sort(v.begin(), v.begin() + num);
	cin >> i;
	while(i-- > 0) {
		cin >> input;
		cout << v[input - 1] << endl;
	}

	return 0;
}
