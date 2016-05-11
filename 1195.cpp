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
	int type, x1, y1, x2, y2, change;
	while(1) {
		scanf("%d", &type);
		if(type == 0) {
			scanf("%d", &scale);
			memset(Tree, 0, sizeof(Tree));
		}
		else if(type == 1) {
			scanf("%d%d%d", &x1, &y1, &change);
			++x1; ++y1;
			add(x1, y1, change);
		}
		else if(type == 2) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			++x2; ++y2; //include boarder
			printf("%d\n", query(x2, y2) - query(x2, y1) - query(x1, y2) + query(x1, y1));
		}
		else break;
	}
	return 0;
}
