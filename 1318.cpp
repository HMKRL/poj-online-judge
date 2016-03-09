#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

struct src {
	char origin[7];
	char sorted[7];
};

src dic[100];

bool cmp(src a, src b)
{
	int A = strlen(a.origin), B = strlen(b.origin);
	if(A > B)A = B;
	for(int i = 0;i < A;++i) {
		if(a.origin[i] != b.origin[i]) return a.origin[i] < b.origin[i];
	}
	return true;
}

int main()
{
	bool find = false;
	int c = 0;
	char temp[7];
	while(1) {
		scanf("%s", temp);
		if(!strcmp(temp, "XXXXXX")) break;
		strcpy(dic[c].origin, temp);
		sort(temp, temp + strlen(temp));
		strcpy(dic[c].sorted, temp);
		++c;
	}
	sort(dic, dic + c, cmp);
	while(1) {
		find = false;
		scanf("%s",  temp);
		if(!strcmp(temp, "XXXXXX")) break;
		sort(temp, temp + strlen(temp));
		for(int i = 0;i <= c;++i) {
			if(!strcmp(temp, dic[i].sorted)) {
				printf("%s\n", dic[i].origin);
				find = true;
			}
		}
		if(!find) puts("NOT A VALID WORD");
		puts("******");
	}

	return 0;
}
