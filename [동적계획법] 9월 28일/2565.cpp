#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector<int> dp(101);
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;
	v.push_back(make_pair(0, 0));

	int temp = n;
	int a, b;
	while (temp--) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	//a 전봇대 번호 기준으로 정렬
	sort(v.begin(), v.end());

	//bottom up 방식
	int total; //연결 가능한 전깃줄의 최댓값
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (v[i].second > v[j].second) {
				if (dp[i] <= dp[j])
					dp[i] = dp[j] + 1;
			}
		}
		total = max(total, dp[i]);
	}

	//제거할 전깃줄의 최솟값 = 전체 전깃줄 - 연결 가능한 전깃줄의 최댓값
	int del_line = n - total;
	cout << del_line << '\n';

}
