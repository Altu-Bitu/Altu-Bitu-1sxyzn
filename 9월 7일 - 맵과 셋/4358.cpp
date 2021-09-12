#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
	map<string, int> tree;
	string temp;
	int count = 0;

	//계속 입력을 받다가 입력이 없으면 무한루프 탈출
	//공백도 입력받아야 하므로 cin말고 getline으로
	//getline은 엔터 전까지의 문자열을 입력받음
	while (true) {
		getline(cin, temp);
		if (temp == "") break;

		//새 나무라면 갯수 1개
		if (tree[temp] == NULL) {
			tree[temp] = 1;
		}

		//카운트 했던 나무라면 갯수 +1
		else
			tree[temp]++;
		
		//전체 나무 카운트(백분율 계산시 이용)
		count++;
	}

	//소수점 넷째자리까지 반올림하는 법
	cout << fixed;
	cout.precision(4);

	//형변환 안해주면 출력값 0 나옴, 형변환 해주기
	for (auto i : tree)
		cout << i.first << ' ' << (float) (i.second) / count * 100<<"\n";
}
