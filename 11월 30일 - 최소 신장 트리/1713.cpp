#include<iostream>
#include<vector>
#include<utility> //pair
#include<algorithm>

using namespace std;

vector<pair<int, int>> s;
int n, total;

void del() { //사진 틀에서 지우는 함수
	int min = 1001;
	int idx = n + 1;
	for (int i = 0; i < n; i++) {
		//추천수 가장 적은 학생이 또 나타나면 먼저 push 된 학생 delete
		if (s[i].second == min)
			continue;

		if (s[i].second < min) {
			min = s[i].second;
			idx = i;
		}
	}
	s.erase(s.begin() + idx);
}

void cal(int a) { //calculate

		//이미 해당 학생이 있으면 추천수만 증가
		for (int i = 0; i < s.size(); i++) {
			if (s[i].first == a) {
				s[i].second++;
				return;
			}
		}

		if (s.size() == n) { //새 학생 사진 게시해야하는데 틀이 가득차면
			del(); //사진 삭제하기
		}

		//학생 사진 새로 게시하기
		s.push_back(make_pair(a, 1));
		return;
}

int main() {
	cin >> n >> total;
	
	int a, temp = total;
	while (temp--) {
		cin >> a;
		cal(a);
	}
	
	sort(s.begin(), s.end());
	for (temp = 0; temp < s.size(); temp++) {
		cout << s[temp].first << ' ';
	}

}
