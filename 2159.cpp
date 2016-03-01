#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	char a[101], b[101];
	int i, s, al[26] = {0}, bl[26] = {0};
	bool flag = true;
	while(scanf("%s%s", a, b) != EOF) {
		for(i = 0;i < 26;++i) {
			al[i] = 0;
			bl[i] = 0;
		}
		flag = true;
		s = strlen(a);
		for(i = 0;i < s;++i) {
			al[a[i] - 'A']++;
			bl[b[i] - 'A']++;
		}
		sort(al, al + 26);
		sort(bl, bl + 26);
		for(i = 0;i < 26;++i) {
			if(al[i] != bl[i]) {
				flag = false;
				break;
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}
