#include<iostream>
#include<algorithm>
using namespace std;

struct para {
	float xd;
	float yd;
};

bool cmp(para a, para b)
{
	if(a.xd != b.xd) return a.xd < b.xd;
	return a.yd < b.yd;
}

para P[10001], Div[10000001];

int main()
{
	long long int cases, datas, i, j, dI = 0;
	long long int total, count;
	cin >> cases;
	while(cases-- > 0) {
		total = 0;
		count = 0;
		dI = 0;
		cin >> datas;
		for(i = 0;i < datas;++i) {
			cin >> P[i].xd >> P[i].yd;
		}
		for(i = 0;i < datas;++i) {
			for(j = i + 1;j < datas;++j) {
				Div[dI].xd = (P[i].xd + P[j].xd) / 2.0;
				Div[dI].yd = (P[i].yd + P[j].yd) / 2.0;
				++dI;
			}
		}
		sort(Div, Div + dI, cmp);
//		for(i = 0;i < 20;++i) cout << Div[i].xd << ' ' << Div[i].yd << endl;
		for(i = 1;i < dI;++i) {
			if(Div[i].xd == Div[i - 1].xd && Div[i].yd == Div[i - 1].yd) ++count;
			else {
				total += (count * (count + 1)) / 2;
				count = 0;
			}
		}
		cout << total << endl;
	}
}
