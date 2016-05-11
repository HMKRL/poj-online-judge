#include <cstdio>
#include <cstring>

int Tree[1030][1030];
int scale;

inline int lowzeros(int n)
{
	return n & (-n);
}

void add(int x, int y, int change)
{
	for(int i = x;i <= scale;i += lowzeros(i)) {
		for(int j = y;j <= scale;j += lowzeros(j)) {
			Tree[i][j] += change;
		}
	}
}

int query(int x, int y)
{
	int ans = 0;
	for(int i = x;i > 0;i -= lowzeros(i)) {
		for(int j = y;j > 0;j -= lowzeros(j)) {
			ans += Tree[i][j];
		}
	}
	return ans;
}

int main()
{
	int cases, tests, x1, y1, x2, y2;
	char type;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%d%d", &scale, &tests);
		memset(Tree, 0, sizeof(Tree));
		while(tests--) {
			getchar();
			scanf("%c", &type);
			if(type == 'Q') {
				scanf("%d%d", &x1, &y1);
				printf("%d\n", query(x1, y1) & 1);
			}
			else if(type == 'C') {
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				++x2; ++y2; //include boarder
				add(x2, y2, 1);
				add(x2, y1, -1);
				add(x1, y2, -1);
				add(x1, y1, 1);
			}
		}
		if(cases) puts("");
	}
	return 0;
}
