#include<iostream>
#include<set>
#include<map>

using namespace std;

int main() {
	int n, m;
	map<string, int> name;
	string temp;
	cin >> n >> m;

	while (n--) {
		cin >> temp;
		name[temp] = 1;
	}

	//듣지도(n) 보지도(m) 못한 사람의 명단을 set에 저장
	set<string> output;
	
	while (m--) {
		cin >> temp;
		if (name[temp] == 1)
			output.insert(temp);
	}

	cout << output.size() << '\n';

	for (auto i : output)
		cout << i << '\n';
}
