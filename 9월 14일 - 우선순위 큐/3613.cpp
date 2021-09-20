#include<iostream>

using namespace std;

string ctoj(string name) {
	string j;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == '_') {
			j += name[i + 1] - 32;
			i++;
		}
		else
			j += name[i];
	}
	return j;
}

string jtoc(string name) {
	string c;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] >= 'A' && name[i] <= 'Z') {
			c += '_';
			c += name[i] + 32;
		}
		else
			c += name[i];
	}
	return c;
}

int main() {
	string name;
	string type="default";

	cin >> name;
	for (int i = 0; i < name.length(); i++) {
		if (name[i] == '_') {
			// type이 java일 때 '_'가 등장하면 에러 (대문자, 언더바 섞였다는 뜻)
			//맨 처음에 _로 시작하면 에러, 시작은 소문자여야함.
			//맨 마지막에 _로 끝나도 에러, ex. c_는java로 변환불가
			//_가 두 번 연속 나와도 에러, 인덱스가 -1이면 문제가 생기므로 i!=0이라는 조건을 줌
			if (type == "java" || i==0 || i==name.length()-1 || i != 0 && name[i - 1] == '_') {
				type = "error";
				break;
			}
			type = "c++";
		}

		if (name[i] >= 'A' && name[i] <= 'Z') {
			if (type == "c++" || i == 0) {
				type = "error";
				break;
			}
			type = "java";
		}
	}

	if (type == "c++")
		cout << ctoj(name) << '\n';
	else if (type == "java")
		cout << jtoc(name) << '\n';
	else if (type == "default")
		cout << name << '\n';
	else
		cout << "Error!" << '\n';

}
