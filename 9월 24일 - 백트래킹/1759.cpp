#include <iostream>
#include <algorithm>

using namespace std;

int l, c; //l:암호 길이, c: 주어지는 문자 개수
bool is_vowel[26]; //모음 체크
char alpha[20]; //알파벳 저장

void backtracking(int cnt, int start, int vowel_cnt, string password) { //cnt는 암호 길이, start는 시작 위치, vowel_cnt는 모음 개수, password는 암호 일부
	if (cnt == l) { //암호의 길이만큼 수를 만들면 (기저조건)
		if (vowel_cnt >= 1 && (cnt - vowel_cnt) >= 2) //조건(모음 최소 1개, 자음 최소 2개)에 맞다면 출력
			cout << password << '\n'; //완성된 암호 출력
		return; //함수 종료
	}
	for (int i = start; i < c; i++) { // 암호의 길이를 더 길게 해야한다면 경우의 수 찾기
		if (is_vowel[alpha[i] - 'a']) //모음이라면
			backtracking(cnt + 1, i + 1, vowel_cnt + 1, password + alpha[i]); //모음수 카운트하고 백트래킹 함수 호출
		else //자음이라면
			backtracking(cnt + 1, i + 1, vowel_cnt, password + alpha[i]); //모음 개수 카운트하지 않고 백트래킹 함수 호출
	}
}

/**
 * [백트래킹 풀이] (0ms)
 * 매개변수로 시작위치를 보내줘서 오름차순 암호만 검사하도록 가지치기 진행 (N과 M(2)와 동일)
 * 매개변수로 암호 속에 포함된 모음 개수 카운트해서 조건 만족하지 않으면 가지치기 진행
 * 매개변수로 password 보내주면서 암호 만들어나감
 */

int main() {
	//입력
	cin >> l >> c; //l은 암호의 길이, c는 주어지는 문자의 개수
	for (int i = 0; i < c; i++) { //문자의 개수만큼 문자 입력 받기
		cin >> alpha[i]; //사용자로부터 문자 입력
	}

	//모음 저장
	is_vowel['a' - 'a'] = is_vowel['e' - 'a'] = is_vowel['i' - 'a'] = is_vowel['o' - 'a'] = is_vowel['u' - 'a'] = true;//a e i o u 는 true로 저장

	//연산
	sort(alpha, alpha + c); //암호를 미리 오름차순으로 정렬

	//연산 + 출력
	//차례로 암호 길이, 시작 위치, 모음 개수, 암호에 대한 매개변수
	backtracking(0, 0, 0, "");//백트래킹 함수 호출

	return 0; //프로그램 종료
}
