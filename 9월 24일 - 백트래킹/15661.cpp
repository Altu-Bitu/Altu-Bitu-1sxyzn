#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 20; //20이라는 수 대신 SIZE변수 사용
const int INF = 10e8; //10e8 대신 INF 변수 사용

int n;//축구 인원 입력받기위한 변수
int answer = INF; //최솟값을 answer에 담을 예정. 우선 큰 값을 담아둠
int power[SIZE][SIZE];//능력치 관계를 입력 받아 저장할 배열
bool is_start[SIZE]; //스타트 팀원 체크
int start[SIZE], link[SIZE]; //스타트와 링크 팀에 속하는 사람

//각 팀의 능력치를 계산하는 함수
int calcPower(int arr[], int size) {//능력치 계산함수 
	int result = 0; //result변수 선언

	//모든 Sij의 합
	for (int i = 0; i < size; i++) {//Sij의 합을 구하기 위한
		for (int j = i + 1; j < size; j++)//이중 for문
			result += power[arr[i]][arr[j]] + power[arr[j]][arr[i]]; //Sij+Sji합을 해서 result에 저장
	}
	return result; //능력치 합 반환
}

void backtracking(int cnt, int st) { //백트래킹 함수
	if (cnt == n) //n이면 팀 더 이상 꾸릴 수 x (기저조건)
		return; //함수 종료
	if (cnt > 0) { //최소 1명이 팀에 있어야 함
		int idx = 0;//idx변수 초기화
		for (int i = 0; i < n; i++) { //스타트팀 전체 탐색 위한 반복문
			if (!is_start[i]) //스타트 팀이 아니라면->링크팀
				link[idx++] = i; //링크팀 추가
		}
		int diff_value = abs(calcPower(link, idx) - calcPower(start, cnt)); //두 팀의 능력치 차이
		answer = min(answer, diff_value); //차이의 최솟값 저장
	}
	for (int i = st; i < n; i++) { //스타트 팀원 체크를 위한 for문
		is_start[i] = true; //링크 팀에 속하는 사람 추리기 위해 스타트 팀원 체크
		start[cnt] = i; //스타트 팀에 배치
		backtracking(cnt + 1, i + 1); //다음값 확인하기
		if (i == 0) //1번 사람이 링크 팀이 됨 -> 어차피 스타트 팀이었던 경우와 값 같음 (왜 그런지 디버깅 해보자!)
			return; //함수 종료
		is_start[i] = false; //팀원 체크 후 false로 변경
	}
}

/**
 * [백트래킹 풀이] (84ms)
 * 오름차순 수열을 만드는 것을 활용하여 팀 조합
 * 오름차순 수열을 만들어가는 과정에서 길이가 1이상이 되면 팀배정 완료된 것 (최소 1명 이상이 팀원이므로)
 * 스타트 팀을 꾸려가는 것을 기준으로 풀이, 나머지는 링크 팀에 수동배정
 * ex. n = 4
 * 1 -> 1번 사람이 스타트 팀
 * 1 2 -> 1, 2번 사람이 스타트 팀
 * (생략)
 * 2 3 4 -> 2, 3, 4번 사람이 스타트 팀
 *
 * 팀 배정을 모두 끝낸 후, 능력치 차이 계산
 */

int main() {
	//입력
	cin >> n;//축구를 하기위해 모인 사람
	for (int i = 0; i < n; i++) {//nXn 능력치를 입력해야하기 때문에
		for (int j = 0; j < n; j++) {//이중 반복문 이용
			cin >> power[i][j]; //사람 사이의 능력치 관계
		}
	}

	//연산
	backtracking(0, 0); //백트래킹 함수 호출

	//출력
	cout << answer << '\n';//최솟값 출력

	return 0;//프로그램 종료
}
