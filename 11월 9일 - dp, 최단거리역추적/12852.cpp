#include <iostream>
#include <vector>

using namespace std;

vector<int>dp(1000001); //dp
vector<int>temp(1000001); //i 전의 숫자 저장

int ans(int n) {
	dp[1] = 0; //숫자 1은 그대로. 연산 0번
	int i;
	for (i = 2; i <= n; i++) {
		//일단 1을 뺀다 (2로도 3으로도 안나눠질때)
		dp[i] = dp[i - 1] + 1;
		temp[i] = i - 1;

		//i가 3으로 나누어 떨어지면 3으로 나눔
		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
				temp[i] = i / 3;
			}
		}
		//2로 나누어 떨어지면 2로 나눔
		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
				temp[i] = i / 2;
			}
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;

	cout << ans(n) << '\n';

	while (n != 0) {
		cout << n << " ";
		n = temp[n];
	}
	return 0;
}
