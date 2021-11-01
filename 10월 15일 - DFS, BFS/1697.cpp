#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

vector<bool>visited(100001, false);

int bfs(int n, int k) {
	queue<pair <int, int>> q;
	
	visited[n] = true;
	q.push(make_pair(n, 0));
	

	while (!q.empty()) {
		int i, ans;
		i = q.front().first;
		ans = q.front().second;
		
		q.pop();
		if (i == k)	return ans;

		if (i + 1 < 100001 && i + 1 >= 0 && visited[i + 1] == false) {
			q.push(make_pair(i + 1, ans + 1));
			visited[i + 1] = true;
		}
		if (i - 1 < 100001 && i - 1 >= 0 && visited[i - 1] == false) {
			q.push(make_pair(i - 1, ans + 1));
			visited[i - 1] = true;
		}
		if (i * 2 < 100001 && i * 2 >=0 && visited[i * 2] == false) { // 순간이동
			q.push(make_pair(i * 2, ans + 1));
			visited[i * 2] = true;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << bfs(n, k) <<'\n';

	return 0;
}
