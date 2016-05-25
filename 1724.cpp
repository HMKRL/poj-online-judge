#include <cstdio>
using namespace std;

int K, N, R;
int path[100][100] = {{0}};
int cost[100][100] = {{0}};
bool vis[100] = {false};


int DFS(int city)
{
	static int ans = 0, coin = 0;
	for(int i = 1;i <= N;++i) {
		if(!vis[])
	}
}

int main()
{
	int S, D, L, T;
	scanf("%d %d %d", &K, &N, &R);
	for(int i = 0;i < R;++i) {
		scanf("%d %d %d %d", &S, &D, &L, &T);
		if(path[S][D]) = L;
		cost[S][D] = T;
	}
	printf("%d\n", DFS(1));
}
