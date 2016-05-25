#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#define INF 200000000
using namespace std;

enum size{S = 1, M, L, X, T};
int cap[32][32];
int flow[32][32];
int prenode[32];
bool visited[32];

int nodecnt, pathcnt, source, target, a, b, temp;

int convert(char c)
{
	switch(c) {
	case 'S':
		return S;
		break;
	case 'M':
		return M;
		break;
	case 'L':
		return L;
		break;
	case 'X':
		return X;
		break;
	case 'T':
		return T;
		break;
	}
}

bool DFS(int from, int to, int n)
{
	visited[from] = true;
	if(from == to) return true;
	for(int i = 0;i < n;++i) {
		if(visited[i]) continue;
		if(cap[from][i] - flow[from][i] > 0) {
			prenode[i] = from;
			if(DFS(i, to, n)) return true;
		}
	}
	return false;
}

int Findflow(int from, int to)
{
	int f = INF, pre;
	for(int i = to;i != from;i = prenode[i]) {
		pre = prenode[i];
		f = min(f, cap[pre][i] - flow[pre][i]);
	}
	
	for(int i = to;i != from;i = prenode[i]) {
		pre = prenode[i];
		flow[pre][i] += f;
		flow[i][pre] -= f;
	}
	return f;
}



int Maxflow(int nodecnt)
{
	int res = 0;
	while(1) {
		memset(visited, false, sizeof(visited));
		if(!DFS(0, nodecnt + 6, nodecnt + 7)) break;
		res += Findflow(0, nodecnt + 6);
	}
	return res;
}

int main()
{
	string str;
	while(cin >> str && str != "ENDOFINPUT") {
		scanf("%d", &nodecnt);
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));

		for(int i = 1;i <= nodecnt;++i) {
			cap[0][i] = 1;
			cin >> str;
			for(int j = convert(str[0]);j <= convert(str[1]);++j) {
				cap[i][nodecnt + j] = 1;
			}
		}
		for(int i = 1;i <= 5;++i) {
			cin >> temp;
			cap[nodecnt + i][nodecnt + 6] = temp;
		}
		cin >> str;
//		cout << Maxflow(nodecnt) << ' ' << nodecnt << endl;
		if(Maxflow(nodecnt) - nodecnt == 0) puts("T-shirts rock!");
		else puts("I'd rather not wear a shirt anyway...");
	}
	
	return 0;
}
