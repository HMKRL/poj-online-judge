#include<cstdio>
#include<utility>
#include<vector>
using namespace std;

int dis[2501][2501];
int PATH[2501];

int main()
{
	int cases, N, M, W, j, k;
	int a, b, DIS;
	bool test;
	vector<pair<int, int> > V;
	vector<pair<int, int> >::iterator Vit;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%d %d %d", &N, &M, &W);
		V.clear();
		for(int i = 0;i <= N + 1;++i) {
			for(int j = 0;j <= N + 1;++j) {
				dis[i][j] = 0;
			}
			PATH[i] = 2147483647;
		}
		PATH[N] = 0;
		for(int i = 0;i < M;++i) {
			scanf("%d %d %d", &a, &b, &DIS);
			if(dis[a][b]) dis[a][b] = dis[a][b] < DIS ? dis[a][b] : DIS;
			else dis[a][b] = DIS;
			dis[b][a] = dis[a][b];
			V.push_back(make_pair(a, b));
			V.push_back(make_pair(b, a));
		}
		for(int i = 0;i < W;++i) {
			scanf("%d %d %d", &a, &b, &DIS);
			if(dis[a][b]) dis[a][b] = dis[a][b] < DIS ? dis[a][b] : DIS;
			else dis[a][b] = -DIS;
			V.push_back(make_pair(a, b));
		}
		for(int i = 1;i < N;++i) {
			for(Vit = V.begin();Vit != V.end();++Vit) {
				j = Vit -> first;
				k = Vit -> second;
				if(PATH[j] != 2147483647) {
					PATH[k] = PATH[k] < PATH[j] + dis[j][k] ? PATH[k] : PATH[j] + dis[j][k];
				}
			}
		}
		test = false;
		for(Vit = V.begin();Vit != V.end();++Vit) {
			j = Vit -> first;
			k = Vit -> second;
			if(PATH[j] != 2147483647) {
				if(PATH[k] < PATH[j] + dis[j][k]) {
					test = true;
					break;
				}
			}
		}
		if(!test) puts("YES");
		else puts("NO");
	}
}
