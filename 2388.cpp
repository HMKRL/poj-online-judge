#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n[10000];
	int N;
	cin >> N;
	for(int i = 0;i < N;++i) {
		cin >> n[i];
	}
	sort(n, n + N);
	cout << n[N / 2] << endl;
}
