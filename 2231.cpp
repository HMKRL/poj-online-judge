#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Cows {
public:
	Cows() {
		N = 0;
	}
	void add_cow(long long int position) {
		v.push_back(position);
		++N;
	}
	long long int MOO() {
		sort_cows();
		int i;
		long long int MOO = 0, temp = 0;
		for(i = 0;i < N;++i) {
			MOO += v[i] - v[0];
		}
		temp = MOO;
		for(i = 1;i < N;++i) {
			temp -= (v[i] - v[i - 1]) * (N - i);
			temp += (i - 0) * (v[i] - v[i - 1]);
			MOO += temp;
		}
		return MOO;
	}
private:
	void sort_cows() {
		sort(v.begin(), v.begin() + N);
	}
	vector<long long int> v;
	int N;//number of cows
};

int main()
{
	long long int N, pos, i;
	Cows C;
	scanf("%lld", &N);
	for(i = 0;i < N;++i) {
		scanf("%lld", &pos);
		C.add_cow(pos);
	}
	cout << C.MOO() << endl;

	return 0;
}
