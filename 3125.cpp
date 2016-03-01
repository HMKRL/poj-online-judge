#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

int main()
{
	int tests, jobs, mypos, i, temp, min;
	queue<int> Q;
	priority_queue<int> PQ;
	cin >> tests;
	while(tests-- > 0) {
		min = 0;
		cin >> jobs >> mypos;
		for(i = 0;i < jobs;++i) {
			cin >> temp;
			Q.push(temp);
			PQ.push(temp);
		}
		while(1) {
			if(mypos == 0 && Q.front() >= PQ.top()) {
				++min;
				while(!Q.empty()) Q.pop();
				while(!PQ.empty()) PQ.pop();
				break;
			}
			else if(mypos == 0 && Q.front() < PQ.top()) {
				mypos = jobs - 1;
				temp = Q.front();
				Q.pop();
				Q.push(temp);
			}
			else if(Q.front() >= PQ.top()) {
				--jobs;
				++min;
				--mypos;
				Q.pop();
				PQ.pop();
			}
			else {
				--mypos;
				temp = Q.front();
				Q.pop();
				Q.push(temp);
			}
		}
		cout << min << endl;
	}
}
