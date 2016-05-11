#include<iostream>
#include<queue>
using namespace std;

int main()
{
	long long int n, temp, total = 0;
	priority_queue<long long int> pq;
	cin >> n;
	while(n--) {
		cin >> temp;
		pq.push(0-temp);
	}
	while(pq.size() > 1) {
		temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		total += (0-temp);
		pq.push(temp);
	}
	cout << total << endl;
	return 0;
}
