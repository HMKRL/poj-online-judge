#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct DNA {
	char dna[51];
	long long int inver;
} D[100];

char to_sort[51], sorted[51];
long long int c;

bool cmp(DNA a, DNA b)
{
	return a.inver < b.inver;
}

void merge(int low, int high, int mid)
{
	int l = low, h = mid + 1, s = 0;
	while(l <= mid || h <= high) {
		if(l > mid) sorted[s++] = to_sort[h++];
		else if(h > high) sorted[s++] = to_sort[l++];
		else if(to_sort[l] <= to_sort[h]) sorted[s++] = to_sort[l++];
		else {
			sorted[s++] = to_sort[h++];
			c += mid - l + 1;
		}
	}
	s = 0;
	for(l = low;l <= high;++l) {
		to_sort[l] = sorted[s++];
	}

	return;
}

void mergesort(int low, int high)
{
	if(high > low) {
		int mid = (high + low) / 2;
		mergesort(low, mid);
		mergesort(mid + 1, high);
		merge(low, high, mid);
	}
	return;
}

int main()
{
	int a, b, i;
	scanf("%d %d", &a, &b);
	for(i = 0;i < b;++i) {
		scanf("%s", D[i].dna);
		strcpy(to_sort, D[i].dna);
		c = 0;
		mergesort(0, a - 1);
		D[i].inver = c;
	}
	
	sort(D, D + b, cmp);
	for(i = 0;i < b;++i) {
		printf("%s\n", D[i].dna);
	}
}
