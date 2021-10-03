#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int coin[101];

	int n, k, temp, i;
	cin >> n >> k;

	//동전 가치 입력
	for (i = 1; i <= n; i++) {
		cin >> temp;
		coin[i] = temp;
	}

	vector<int> dp(100001, 100001);
	//dp[0] 인덱스는 사용 안함
	dp[0] = 0;

	//bottom up 방식
	for (i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++)
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
	}

	//동전 가치 합 계산이 불가능 할 경우
	if (dp[k] == 100001)
		dp[k] = -1;

	cout << dp[k] << '\n';

}
