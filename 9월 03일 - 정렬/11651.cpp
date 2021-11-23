#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {
	int n, temp;
	cin >> n;
	temp = n;

	vector<pair<int, int>> v;
	while (temp != 0) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
		temp--;
	}

	sort(v.begin(), v.end(), cmp);

	int i;
	for (i = 0; i < n; i++) {
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
}
