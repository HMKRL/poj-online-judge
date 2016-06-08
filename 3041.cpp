#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int llink[501], rlink[501];
bool used[501];
int m, n;
vector<int> path[501];

bool DFS(int cur)
{
	for(int i = 0;i < path[cur].size();++i) {
		int nxt = path[cur][i];
		if(!used[nxt]) {
			used[nxt] = true;
			if(rlink[nxt] == -1 || DFS(rlink[nxt])) {
				rlink[nxt] = cur;
				llink[cur] = nxt;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int cnt;
	while(scanf("%d %d", &n, &m) != EOF) {
		cnt = 0;
		fill(llink, llink + 501, -1);
		fill(rlink, rlink + 501, -1);
		for(int i = 0;i < 501;++i) path[i].clear();

		int a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &a, &b);
			path[a - 1].push_back(b - 1);
		}
		
		for(int i = 0;i < n;++i) {
			fill(used, used + 501, false);
			if(DFS(i)) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
