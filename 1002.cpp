#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

struct phone {
	int num;
	int times;
} P[100000];

bool cmp(phone a, phone b)
{
	int i;
	for(i = 0;i < 8;++i) {
		if(a.num[i] != b.num[i]) return a.num[i] < b.num[i];
	}
	return false;
}

int main()
{
	int i, j, num, l, c = 1, mapped = 0;
	map<string, int> Map;
	string origin;
	scanf("%d", &num);
	for(i = 0;i < num;++i) {
		cin >> origin;
		l = origin.length();
		for(j = 0;j < l;++j) {
			if(origin[j] == '-') 
				continue;
			else if(origin[j] >= '0' && origin[j] <= '9')
				mapped *= 10;
				mapped += origin[j] - '0';
			else if(origin[j] >= 'A' && origin[j] <= 'C')
				mapped[k++] = '2';
			else if(origin[j] >= 'D' && origin[j] <= 'F')
				mapped[k++] = '3';
			else if(origin[j] >= 'G' && origin[j] <= 'I')
				mapped[k++] = '4';
			else if(origin[j] >= 'J' && origin[j] <= 'L')
				mapped[k++] = '5';
			else if(origin[j] >= 'M' && origin[j] <= 'O')
				mapped[k++] = '6';
			else if(origin[j] >= 'P' && origin[j] <= 'S')
				mapped[k++] = '7';
			else if(origin[j] >= 'T' && origin[j] <= 'V')
				mapped[k++] = '8';
			else if(origin[j] >= 'W' && origin[j] <= 'Y')
				mapped[k++] = '9';
		}
		if(Map[mapped]) {
			P[Map[mapped] - 1].times++;
		}
		else {
			Map[mapped] = c;
			P[c - 1].num = mapped;
			P[c - 1].times = 1;
			++c;
		}
	}
	sort(P, P + c, cmp);
	for(i = 1;i < c;++i) {
		if(P[i].times > 1)
			cout << P[i].num << ' ' << P[i].times << endl;
	}

	return 0;
}
