#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int i, strlen;
	char temp;
	string INPUT;
	while(1) {
		getline(cin,INPUT);
		if(INPUT == "ENDOFINPUT") break;
		else if(INPUT == "START" || INPUT == "END") continue;
		else {
			strlen = INPUT.length();
			for(i = 0;i < strlen;++i) {
				temp = INPUT[i];
				if(temp >= 'A' && temp <= 'Z') {
					temp -= 5;
					if(temp < 'A') temp += 'Z' - 'A' + 1;
				}
				printf("%c", (char)temp);
			}
			printf("\n");
		}
	}
}
