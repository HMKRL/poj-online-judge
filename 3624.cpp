#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int w[34100];
int v[34100];
int c[34100];
int N, W;


int main()
{
	cin >> N >> W;
	for(int i = 0;i < N;++i) {
		cin >> w[i] >> v[i];
	}
	memset(c, 0, sizeof(c));
	for(int i = 0;i < N;++i) {
		for(int m = W;m - w[i] >= 0;--m) {
			c[m] = max(c[m], c[m - w[i]] + v[i]);
		}
	}
	sort(c, c + W);
	cout << c[W] << endl;
}
