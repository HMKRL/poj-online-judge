#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int C[20001], i, j;
	int cows, length, total = 0;
	cin >> cows >> length;
	for(i = 0;i < cows;++i) {
		cin >> C[i];
	}
	sort(C, C + cows);
	for(i = 1;i < cows;++i) {
		if(C[i] + C[i - 1] > length) break;
	}
	total += (i * (i - 1)) / 2;
	//cout << total << endl;
	for(;i < cows;++i) {
		for(j = 0;C[j] + C[i] <= length;++j) total++;
	}
	cout << total << endl;
}

