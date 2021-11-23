#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>

using namespace std;

int ave(vector<int> v) {
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	//평균값이 -1.7의 경우 -2를 나타내고 싶고
	//1.7의 경우 2를 나타내고 싶음
	if (sum>0)
		return (int)double(sum / v.size() + 0.5);
	else
		return (int)double(sum / v.size() - 0.5);
}

int mid(vector<int> v) {
	int m = v.size() / 2;
	return v[m];
}

//pair를 이용해서 최빈값 저장
bool my_sort(const pair<int,int> &a, const pair<int, int> &b) {
	//빈도수가 같으면 숫자 작은 순으로
	if (a.second == b.second)
		return a.first < b.first;
	//빈도수가 다르면 빈도수 큰 순으로
	else
		return a.second > b.second;
}

int mode(vector<int> v) {
	//입력값이 하나일 경우 자기자신 리턴
	if (v.size() == 1)
		return v[0];

	vector<pair<int, int>> p;
	for (int i = 0; i < v.size(); i++) {
		//페어에 첫 값 넣기
		if (p.empty())
			p.push_back(make_pair(v[i], 1));
		
		//중복된 숫자면 빈도수 second만 ++
		else if (v[i] == p.back().first)
			p.back().second++;

		//중복되지 않으면 make_pair
		else
			p.push_back(make_pair(v[i], 1));
	}

	//빈도수 순으로 정렬
	sort(p.begin(), p.end(), my_sort);

	//빈도수 같은게 있으면 두번째 작은 수 리턴
	if (p[0].second == p[1].second)
		return p[1].first;
	else return p[0].first;
}

int range(vector<int> v) {
	int r;
	//벡터 요소가 하나면 범위는 0
	if (v.size() == 1) {
		return 0;
	}
	r = (v[0] - v[v.size() - 1]);
	//범위는 양수로 출력
	return abs(r);
}

int main() {
	int n, temp, k;
	vector<int> v;

	cin >> n;
	temp = n;
	while (temp--) {
		cin >> k;
		v.push_back(k);
	}

	sort(v.begin(), v.end());

	cout << fixed;
	cout.precision(1);

	cout << ave(v) << '\n';
	cout << mid(v) << '\n';
	cout << mode(v) << '\n';
	cout << range(v) << '\n';

}
