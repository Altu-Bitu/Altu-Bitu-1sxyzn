#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	map<string, int> o;
	vector<string> x;
	int n, temp;
	cin >> n;
	temp = n;

	//정답 map으로 저장
	string s;
	while (temp--) {
		cin >> s;
		o[s] = n - temp;
		
	}

	//학생의 답 vector로 저장
	temp = n;
	while (temp--) {
		cin >> s;
		x.push_back(s);
	}
	
	//정답 구하기
	int answer = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			//o[alpa]=0, o[beta]=1
			//위와 같이 저장되어있으므로 비교해서 카운트
			if (o[x[i]] < o[x[j]]) answer++;
		}
	}

	cout << answer << '/' << n*(n-1)/2 << '\n';

}
