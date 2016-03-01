#include<cstdio>
#include<algorithm>
using namespace std;

struct Road {
	int east_city;
	int west_city;
};

bool cmp(Road a, Road b)
{
	if(a.east_city != b.east_city) return a.east_city < b.east_city;
	else return a.west_city < b.west_city;
}

int main()
{
	int tests, count = 0, N, M, K, i, j, cross = 0;
	Road road[1000000];
	scanf("%d", &tests);
	while(count++ < tests) {
		scanf("%d %d %d", &N, &M, &K);
		for(j = 0;j < K;++j) {
			scanf("%d %d", &road[j].east_city, &road[j].west_city);
		}
		sort(road, road + K, cmp);
		for(i = 0;i < K;++i) {
			for(j = i;j < K;++j) {
				if(road[i].east_city == road[j].east_city) continue;
				if(road[j].west_city < road[i].west_city) ++cross;
			}
		}
		printf("Test case %d: %d\n", count, cross);
	}
}
