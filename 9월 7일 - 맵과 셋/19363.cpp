#include<iostream>
#include<cmath> //floor이용, 버림

using namespace std;

struct person {
	int w0; //다이어트 전 체중
	int l0; //다이어트 전 일일 에너지 섭취량 및 일일 기초 대사량
	int t; //기초 대사량 변화 역치
	int d; //다이어트 기간
	int l; //다이어트 기간 일일 에너지 섭취량
	int a; //다이어트 기간 일일 활동 대사량
};

int main() {
	person de;//데시
	cin >> de.w0 >> de.l0 >> de.t;
	cin >> de.d >> de.l >> de.a;

	//일일 기초 대사량의 변화를 고려하지 않았을 때의
	//다이어트 후 예상 체중(no_change_w)과 일일 기초 대사량을 출력
	int no_change_w = de.w0 + (de.l - de.l0 - de.a) * de.d;

	//데시 사망
	if (no_change_w <= 0)
		cout << "Danger Diet" << '\n';

	else
		cout << no_change_w << ' ' << de.l0 << '\n';

	//-----------------------------------------------
	
	//일일 기초 대사량의 변화를 고려했을 때의
	//다이어트 후 예상 체중과 일일 기초 대사량을 출력
	int change_w = de.w0; //체중
	int change_b = de.l0; //기초 대사량
	int day = de.d;

	while (day--) {
		//체중 변화
		change_w = change_w + (de.l - change_b - de.a);

		if (abs(de.l - change_b - de.a) > de.t) {
			//-5/2 = -2 ....
			//-3이 나와야지 정답
			//floor이용해서 버림
			change_b += floor((float)(de.l - change_b - de.a) / 2);
		}
	}

	//데시 사망
	if (change_b <= 0 || change_w <= 0)
		cout << "Danger Diet" << '\n';

	else {
		cout << change_w << ' ' << change_b << ' ';

		//요요 조건
		if ((de.l0 - change_b - 0) > 0)
			cout << "YOYO" << '\n';
		else
			cout << "NO" << '\n';
		}
	}
