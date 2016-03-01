#include<cstdio>

int main()
{
	int tests, a, b, count = 1;
	scanf("%d", &tests);
	while(tests-- > 0) {
		scanf("%d %d", &a, &b);
		printf("Scenario #%d:\n", count++);
		if(a % 2 == 1 && b % 2 == 1) {
			printf("%.2f\n\n", a * b - 1 + 1.41);
		}
		else printf("%.2f\n\n",(float)a * b);
	}
}
