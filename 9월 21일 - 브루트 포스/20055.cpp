#include <iostream>
#include <vector>

using namespace std;

struct info { //내구도와 로봇 존재 여부
	int power; //내구도
	bool is_on; //존재 여부
};

vector<info> belt;  //컨테이너 벨트 정보(내구도, 로봇 여부)
int zero_power;     //내구도가 0인 벨트 칸의 개수

int minusPosition(int n, int pos) { //인덱스 감소
	if (--pos >= 0) //인덱스 감소. 인덱스 0보다 크면
		return pos; // 그 자리 리턴
	return n * 2 - 1; //인덱스 음수가 되면 끝 인덱스 리턴 (벨트가 도니까)
}

void second(int n, int start, int end) { //로봇 이동이 가능한지 확인하기
	int cur = end; //전체 자리마다 검사를 하기 위해 임시 변수를 생성
	while (cur != start) { //end - 1 부터 start 까지 검사
		cur = minusPosition(n, cur); //인덱스 감소 시키며 검사
		int next = (cur + 1) % (n * 2); //다음 위치
		if (belt[cur].is_on && !belt[next].is_on && belt[next].power) { //현재 위치에 로봇이 있고, 다음 위치에 로봇이 없으며 내구성 1이상인 경우 -> 로봇 옮김
			belt[cur].is_on = false; // 로봇 옮기므로 해당 자리 로봇 사라짐
			belt[next].power--; // 옮겼으므로 내구도 감소
			if (next != end) //내리는 위치 아닐 경우만
				belt[next].is_on = true; //로봇 옮기기
			if (belt[next].power == 0) //해당 자리 내구도가 0이면
				zero_power++; // 내구도 0인 자리의 갯수 +1 시키기
		}
	}
}

void third(int start) { //로봇 존재 여부 체크, 내구도 감소
	if (belt[start].power) { //올리는 위치의 내구도가 0이 아니라면 로봇 올림
		belt[start].is_on = true; // 로봇이 올라왔으니 존재 true
		belt[start].power--; //내구도 감소
		if (belt[start].power == 0) //감소시킨 내구도가 0이라면
			zero_power++; // 내구도 0인 칸의 갯수 up
	}
}

/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동 (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 벨트의 로봇을 옮기는 게 아니라, 올리는 위치와 내리는 위치의 인덱스 값을 바꿔서 접근
 * 필요한 컨테이너: 내구도와 로봇의 존재여부를 체크할 배열
 * 1번: 벨트의 방향이 오른쪽이므로, 벨트 한 칸 회전 시 올리는 위치와 내리는 위치의 인덱스 값은 하나 감소
 * 2번: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사 -> 로봇 옮기는 거 가능하면 존재여부 체크하고 내구도 감소
 * 3번: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 */

int main() {
	ios_base::sync_with_stdio(false); //입출력 향상
	cin.tie(NULL); //입출력 향상

	int n, k; //n은 칸, k는 내구도가 0인 칸이 k개 있으면 과정 종료

	cin >> n >> k; //입력
	belt.assign(n * 2, { 0, false }); //n*2만큼 0과 false로 할당
	for (int i = 0; i < n * 2; i++) //전체 반복문
		cin >> belt[i].power; //전체의 내구도 값 입력 받기

	//연산
	int start = 0;    //올리는 위치
	int end = n - 1;  //내리는 위치
	int step = 0;     //단계 수
	while (true) { // 내구도 0인 벨트가 k개 이상이면 무한 반복
		start = minusPosition(n, start); //벨트 이동. 인덱스 감소
		end = minusPosition(n, end); //벨트 이동. 인덱스 감소
		if (belt[end].is_on) //벨트 회전 후, 로봇이 내리는 위치에 있다면 내리기
			belt[end].is_on = false; //내렸으니 존재 여부 false로 바꾸기
		second(n, start, end); //로봇 이동이 가능한지 확인하기
		third(start); //로봇 존재 여부 체크, 내구도 감소
		step++; //한 단계 완료
		if (zero_power >= k) // 내구도 0인 벨트가 k개 이상이면
			break; //종료조건에 해당되므로 무한 루프 탈출
	}

	
	cout << step << '\n'; //출력

	return 0; //프로그램 종료
}
