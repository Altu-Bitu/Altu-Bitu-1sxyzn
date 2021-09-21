#include<iostream>
#include<queue>

using namespace std;

int main() {
	//카드 값이 1000000까지 가능하므로 long long으로 선언
	priority_queue<long long, vector<long long>, greater<long long>> q;

	int card, num;
	cin >> card >> num;

	while (card--) {
		long long c;
		cin >> c;
		q.push(c);
	}

	long long a, b, c;
	while (num--) {
		a = q.top();
		q.pop();
		b = q.top();
		q.pop();
		c = a + b;
		q.push(c);
		q.push(c);
	}

	//최소 합을 구하려면 최솟값끼리 합체하면 된다!
	long long sum = 0;
	while (!q.empty()) {
		sum += q.top();
		q.pop();
	}
	cout << sum << '\n';
}
