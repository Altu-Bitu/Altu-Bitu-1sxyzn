#include <iostream>
#include <vector>

using namespace std;

//남학생의 스위치 바꾸기
vector<int> changeSwitchBoy(int n, int number, vector<int> switches) { // 남학생 스위치 변경
    for (int i = number; i <= n; i += number) //배수에 있는 스위치 바꾸기
        switches[i] = !switches[i]; //스위치 상태 바꾸기

    return switches; //스위치 상태 리턴
}

//여학생의 스위치 바꾸기
vector<int> changeSwitchGirl(int n, int number, vector<int> switches) { // 여학생 스위치 변경
    switches[number] = !switches[number]; //스위치 상태 바꾸기
    for (int i = 1; i < number; i++) { //전체 여학생
        if ((number + i > n) || (switches[number - i] != switches[number + i])) //스위치 범위 넘어가거나 좌우 대칭이 아니면
            break; // 바꾸지말고 종료
        switches[number - i] = !switches[number - i]; // 좌우 대칭으로 상태 변경
        switches[number + i] = !switches[number + i]; // 좌우 대칭으로 상태 변경
    }

    return switches; // 상태 리턴
}

/**
 * 남학생 -> 해당 번호의 배수에 해당하는 스위치 상태 바꾸기
 * 여학생 -> 해당 번호를 중심으로 좌우 대칭이면서 가장 많은 스위치 포함하는 구간의 상태 모두 바꾸기
 *
 * 좌우 대칭 검사 시, 스위치 범위 주의 (주어진 스위치 범위 넘어가지 않도록)
 * 스위치 20개씩 출력하는 부분 주의
 */
int main() {
    int n, m; //스위치 개수,  학생 수
    int student, number; // 학생 성별, 학생이 받은 수

    //입력
    cin >> n; //스위치 개수 입력
    vector<int> switches(n + 1, 0); //스위치 벡터 초기화
    for (int i = 1; i <= n; i++) //스위치 개수만큼
        cin >> switches[i]; //스위치 상태 입력받기

    //입력 & 연산
    cin >> m; // 학생 수 입력
    while (m--) { //학생 수 만큼
        cin >> student >> number; //성별과 학생이 받은 수 입력
        if (student == 1) // 1이면 남자
            switches = changeSwitchBoy(n, number, switches); //남학생 상태 변경
        else //0이면 여자
            switches = changeSwitchGirl(n, number, switches);//여학생 상태 변경
    }

    //출력
    for (int i = 1; i <= n; i++) { //스위치 갯수 만큼
        cout << switches[i] << ' '; // 20개씩 한줄에 스위치 상태 출력
        if (i % 20 == 0) //만약 21번 스위치가 있으면
            cout << '\n'; //줄바꿔서 출력
    }
    return 0; //프로그램 종료
}
