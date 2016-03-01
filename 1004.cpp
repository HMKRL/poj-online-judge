#include<cstdio>

int main()
{
	float money = 0, now;
	int i;
	for(i = 0;i < 12;++i) {
		scanf("%f", &now);
		money += now;
	}
	printf("$%.2f\n", money / 12.0);

	return 0;
}
