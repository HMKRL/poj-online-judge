#include<cstdio>
#include<algorithm>
using namespace std;

struct Road {
	int east_city;
	int west_city;
} road[1000000], sorted[1000000];

long long int cnt;

void merge(int low, int high, int mid)
{
	int l = low, h = mid + 1, s = 0;
	while(l <= mid || h <= high) {
		if(l > mid) sorted[s++] = road[h++];
		else if(h > high) sorted[s++] = road[l++];
		else if(road[h].east_city < road[l].east_city) {
			sorted[s++] = road[h++];
			cnt += mid - l + 1;
		}
		else sorted[s++] = road[l++];
	}
	s = 0;
	for(l = low;l <= high;++l) {
		road[l] = sorted[s++];
	}
	return;
}

void mergesort(int low, int high)
{
	int mid = (low + high) / 2;
	if(high > low) {
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, high, mid);
	}
	return;
}

bool cmp(Road a, Road b)
{
	if(a.west_city != b.west_city) return a.west_city < b.west_city;
	else return a.east_city < b.east_city;
}

int main()
{
	long long int tests, count = 0, N, M, K, i;
	scanf("%lld", &tests);
	while(count++ < tests) {
		scanf("%lld %lld %lld", &N, &M, &K);
		for(i = 0;i < K;++i) {
			scanf("%d %d", &road[i].west_city, &road[i].east_city);
		}
		sort(road, road + K, cmp);
		cnt = 0;
		mergesort(0, K - 1);
		printf("Test case %lld: %lld\n", count, cnt);
	}
}
