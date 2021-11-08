/*
문제 하단 알고리즘 분류를 통해 0-1 너비 우선 탐색을 알게되었다

0-1 너비 우선 탐색이란?
가중치가 0 또는 1인 그래프에서 최단경로를 찾는 방법. 덱을 사용한다.
이 문제에선 가중치 0인 경로의 우선순위를 높이기 위해 push_front를,
가중치 1인 경로는 push_back 하였다
*/

#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>

using namespace std;

vector<bool>visited(100001, false);

int bfs(int n, int k) {
	deque<pair<int, int>> q;

	visited[n] = true;
	q.push_front(make_pair(n, 0));


	while (!q.empty()) {
		int i, ans;
		i = q.front().first;
		ans = q.front().second;

		q.pop_front();
		if (i == k)	return ans;

		if (i * 2 < 100001 && visited[i * 2] == false) { // 순간이동
			q.push_front(make_pair(i * 2, ans));
			visited[i * 2] = true;
		}
		if (i - 1 >= 0 && visited[i - 1] == false) {
			q.push_back(make_pair(i - 1, ans + 1));
			visited[i - 1] = true;
		}
		if (i + 1 < 100001 && visited[i + 1] == false) {
			q.push_back(make_pair(i + 1, ans + 1));
			visited[i + 1] = true;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) << '\n';

	return 0;
}
