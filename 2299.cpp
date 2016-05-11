#include<cstdio>
#include<cstdlib>

//global variable
long long int count = 0;
long long int sorted[500001];
long long int list[500001];
void merge(long long int *list, long long int low, long long int high)
{
	long long int mid = (low + high) / 2;
	//h = head, l = left, r = right
	long long int sh = 0, lh = low, rh = mid + 1;
	while(lh <= mid || rh <= high) {
		if(lh > mid) sorted[sh++] = list[rh++];
		else if(rh > high) sorted[sh++] = list[lh++];
		else if(list[rh] < list[lh]) {
			sorted[sh++] = list[rh++];
			count += mid - lh + 1;
		}
		else sorted[sh++] = list[lh++];
	}
	sh = 0;
	for(lh = low;lh <= high;lh++)
		list[lh] = sorted[sh++];
	return;
}

void mergesort(long long int *list, long long int low, long long int high)
{
	if(high > low) {
		mergesort(list, low, (low + high) / 2);
		mergesort(list, (low + high) / 2 + 1, high);
		merge(list, low, high);
	}
	return;
}

int main()
{
	long long int i, n;
	while(scanf("%lld", &n) != EOF) {
		if(n == 0) break;
		for(i = 0;i < n;i++) {
			scanf("%lld", &list[i]);
		}
		count = 0;
		mergesort(list, 0, n - 1);
		printf("%lld\n", count);
	}

	return 0;
}
