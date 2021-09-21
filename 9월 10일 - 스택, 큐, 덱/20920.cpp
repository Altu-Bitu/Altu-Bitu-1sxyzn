#include<iostream>
#include<map>
#include<algorithm> //sort
#include<vector>
#include<utility> //pair

using namespace std;

//문제에 주어진 정렬
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second != b.second)
		return a.second > b.second;
	else {
		if (a.first.length() != b.first.length())
			return a.first.length() > b.first.length();
		else
			return a.first < b.first;
	}
}

int main() {
	//더 빠른 입출력을 위해
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    //추가적으로 endl;보단 '\n';이 더 빠르다고 한다.

	map<string, int> dic;
	
	//입력받을 변수 = 정수 n,m && 문자열 word
	string word;
	int n, m, temp = 0;
	cin >> n >> m;

	//map에 단어 횟수와 단어를 담는다.
	while (temp < n) {
		cin >> word;
		if (word.length() >= m) {
			dic[word]++;
		}
		temp++;
	}

	//map은 정렬하기 힘들다
	//vector로 둘러싼 pair에 값을 그대로 복사한다
	vector<pair<string, int>> v;

	//dic 탐색
	for (auto iter : dic)
		v.push_back(make_pair(iter.first, iter.second));

	//정렬
	sort(v.begin(),v.end(),cmp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << '\n';
}
