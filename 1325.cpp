#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int llink[105], rlink[105];
bool used[105];
int m, n, job;
vector<int> path[105];

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
	while(scanf("%d", &n) != EOF) {
		if(!n) break;
		scanf("%d%d", &m, &job);
		cnt = 0;
		fill(llink, llink + 105, -1);
		fill(rlink, rlink + 105, -1);
		for(int i = 0;i < 105;++i) path[i].clear();
		int a, b;
		for(int i = 0; i < job; i++) {
			scanf("%*d%d%d", &a, &b);
			if(a && b) path[a].push_back(b);
		}
		for(int i = 0;i < n;++i) {
			fill(used, used + 105, false);
			if(DFS(i)) ++cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
