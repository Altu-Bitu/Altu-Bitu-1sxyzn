#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int SIZE = 100001; // 입력으로 주어지는 수는 10000보다 작거나 같음
int n, m;
vector<int> num, v;

void backtracking(int cnt) {
	if (cnt == m) { //cnt는 인덱스
		for (int i = 0; i < m; i++)
			cout << v[i] << " ";
		cout << '\n';
		return;
	}
	bool check[SIZE] = { false }; //false로 초기화
	for (int i = 0; i < n; i++) {
		if (!check[num[i]]) {
			check[num[i]] = true;
			v.push_back(num[i]);
			backtracking(cnt + 1); //다음수 체크
			v.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	int temp = n;
	while (temp--) {
		int k;
		cin >> k;
		num.push_back(k);
	}
	sort(num.begin(), num.end()); //사전순으로 정렬
	backtracking(0);
}
