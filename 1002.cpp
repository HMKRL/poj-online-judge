#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
using namespace std;

struct phone {
	int num;
	int times;
} P[100000];

bool cmp(phone a, phone b)
{
	return a.num < b.num;
}

int main()
{
	int i, j, num, l, c = 1, mapped = 0;
	map<int, int> Map;
//	string origin;
	char origin[390];
	scanf("%d", &num);
	for(i = 0;i < num;++i) {
		scanf("%s", origin);
//		l = origin.length();
		l = strlen(origin);
		mapped = 0;
		for(j = 0;j < l;++j) {
			if(origin[j] == '-') 
				continue;
			else if(origin[j] >= '0' && origin[j] <= '9') {
				mapped *= 10;
				mapped += origin[j] - '0';
			}
			else if(origin[j] >= 'A' && origin[j] <= 'C') {
				mapped *= 10;
				mapped += 2;
			}
			else if(origin[j] >= 'D' && origin[j] <= 'F') {
				mapped *= 10;
				mapped += 3;
			}
			else if(origin[j] >= 'G' && origin[j] <= 'I') {
				mapped *= 10;
				mapped += 4;
			}
			else if(origin[j] >= 'J' && origin[j] <= 'L') {
				mapped *= 10;
				mapped += 5;
			}
			else if(origin[j] >= 'M' && origin[j] <= 'O') {
				mapped *= 10;
				mapped += 6;
			}
			else if(origin[j] >= 'P' && origin[j] <= 'S') {
				mapped *= 10;
				mapped += 7;
			}
			else if(origin[j] >= 'T' && origin[j] <= 'V') {
				mapped *= 10;
				mapped += 8;
			}
			else if(origin[j] >= 'W' && origin[j] <= 'Y') {
				mapped *= 10;
				mapped += 9;
			}
			else continue;
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
	int printed = 0;
	for(i = 1;i < c;++i) {
		if(P[i].times > 1) {
//			cout << P[i].num / 10000 << '-' << P[i].num % 10000 << ' ' << P[i].times << endl;
			printf("%03d-%04d %d\n", P[i].num / 10000, P[i].num % 10000, P[i].times);
			++printed;
		}
	}
	if(!printed) puts("No duplicates.");

	return 0;
}
