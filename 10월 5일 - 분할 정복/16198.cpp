#include<iostream>
#include<vector>

using namespace std;

/*
int main() {
	vector<int> v;
	int n, e;
	cin >> n;

	while (n--) {
		cin >> e;
		v.push_back(e);
	}
	
	int sum = 0;
	while (v.size() > 2) {
		int temp = v[0] * v[2];
		int index = 1;
		for (int i = 1; i < v.size() - 2; i++) {
			if (temp < v[i] * v[i + 2]) {
				temp = v[i] * v[i + 2];
				index = i + 1;
			}
		}
		sum += temp;
		v.erase(v.begin() + index);
	}

	cout << sum << '\n';
	}

	위와 같이 풀었고 예제도 맞게 나왔지만
	틀렸습니다가 떠서 구글링 한 결과
	https://transferhwang.tistory.com/432
	이 게시글에서, 저와 같은 실수를 하신 분을 찾았고 반례를 발견하여
	dfs로 풀이하신 코드를 참고했습니다
	*/

int sum = 0;

void dfs(vector<int> v, int temp) {
	if (v.size() < 3) {
		if (sum < temp)
			sum = temp;
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {
		vector<int> v2 = v;
		v2.erase(v2.begin() + i);
		dfs(v2, temp + v[i - 1] * v[i + 1]);
	}	
}

int main() {
	vector<int> v;
	int n, e;
	cin >> n;

	while (n--) {
		cin >> e;
		v.push_back(e);
	}

	dfs(v, sum);
	
	cout << sum << '\n';
}
