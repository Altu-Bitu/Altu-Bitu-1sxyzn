#include<iostream>
#include<vector>

using namespace std;

int main() {
	//n개의 입력을 받자
	int n;
	cin >> n;

	//총 그룹단어의 갯수를 담을 total 변수
	int total = n;
	vector<string> group;
	while (n != 0) {
		string str;
		cin >> str;
		group.push_back(str);
		n--;
	}

	//n개의 스트링이 있다고 하자
	//그 중 한 스트링의 특정 알파벳이
	//연속하지 않으면서 뒤에 재등장한다면
	//그룹 단어가 아니므로 전체 단어수 -1을 한다
	//아닌 것을 -1하다보면 총 그룹단어의 갯수만 남음

	int i, j, k;
	char temp;

	//첫 번째  스트링부터 보고자 함
	for (i = 0; i < group.size(); i++) {
		//i번째 스트링의 첫 번째 알파벳부터 보고자 함
		//마지막 문자열은 비교할 필요 X, 앞과 겹쳤으면 앞에서 걸렸을 터, 따라서 group[i].length()-1
		for (j = 0; j < group[i].length()-1; j++) {
			temp = group[i][j];
			k = j;
			//특정 알파벳과 다른 알파벳이 나올 때 까지 비교
			do {
				k++;
			} while (temp == group[i][k]);

			//기존의 total값 저장.
			//그룹이 아니게되면 total--이 되는데
			//그룹이 아닌게 밝혀진 후의 쓸데없는 비교를 줄이고자 함.
			int temp_total = total;

			//현재 k번째 알파벳과 특정 지은 알파벳이 다름
			while (k < group[i].length()-1) {
				//이후 특정지은 알파벳이 재등장하면
				//그룹단어가 아니니 -1하고 반복문 빠져나오기
				k++;

				if (temp == group[i][k]) {
					total--;
					break;
				}
			}
			//만약 앞에서 그룹단어가 아니라고 판명나면
			//이 스트링은 더 이상 볼 필요 없음, break
			
			//한 알파벳에 대해 그룹단어이면
			//그 다음 단어도 계속 체킹해야하므로 반복문 계속
			if(total != temp_total)
				break;
		}
	}
	cout << total << endl;
}
