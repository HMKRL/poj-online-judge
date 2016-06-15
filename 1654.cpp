#include<cstdio>
#include<cmath>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Vector
{
public:
	Vector():x(0), y(0){};
	Vector(int x, int y):x(x), y(y){};
	Vector operator-(Vector &B) {
		return Vector(x - B.x, y - B.y);
	};
	static int Cross(Vector A,Vector B) {
		return A.x * B.y - A.y * B.x;
	};
	int x;
	int y;
};

int dir[10][2] = {{0,0},{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};
//for direction

int main()
{
	int num;
	Vector pre, now, origin(0, 0);
	string s;
	scanf("%d",&num);
		while(num--)
		{
			s = "";
			long long int v = 0;
			cin >> s;
			pre.x = dir[s[0] - '0'][0];
			pre.y = dir[s[0] - '0'][1];
			
			for(int i = 1;i < s.length();++i)
			{
				now.x = pre.x + dir[s[i] - '0'][0];
				now.y = pre.y + dir[s[i] - '0'][1];
				v += (Vector::Cross(now - origin, pre - origin));
				pre = now;
			}
			v = v > 0 ? v : -v;
			
			printf("%lld", v / 2);
			if(v % 2) puts(".5");
			else puts("");
		}
	return 0;
}
