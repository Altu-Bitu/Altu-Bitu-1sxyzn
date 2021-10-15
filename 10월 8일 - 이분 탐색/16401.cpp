#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(vector<int> &snacks, int len) { //몇 명에게 나눠줄 수 있는지 체크
    int cnt = 0; //몇 명에게 나누어주는지
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break; //for문 종료
        cnt += (snacks[i] / len); // 나눠줄 수 있는 아이들의 수 누적으로 합하기
    }

    return cnt; //아이들의 수 리턴
}

int upperSearch(vector<int> &snacks, int left, int right, int target) { //조카 1명에게 줄 수 있는 과자의 최대 길이 구하는 함수
    int ans = 0; //정답 담을 변수
    while (left <= right) { //최솟값 <= 최댓값 이면
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(snacks, mid); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1; //이분탐색, left 이동
            ans = mid; // 중간값이 최대길이가 될 수 있으므로 mid 저장
        } else { //아이들의 수가 target보다 작으면
            right = mid - 1; //right 이동
        }
    }

    return ans; //1인당 최대 과자 길이 리턴
}

/**
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0; //조카의 수 m, 과자의 수 n, 최솟값 left, 최댓값 right

    //입력
    cin >> m >> n; //조카와 과자의 수 입력받기
    vector<int> snacks(n, 0); //과자 수 만큼 벡터 생성
    for (int i = 0; i < n; i++) //과자 수 만큼
        cin >> snacks[i]; //과자 길이 입력받기

    //연산
    sort(snacks.begin(), snacks.end()); // 과자 길이 정렬
    right = snacks[n - 1]; //최댓값은 제일 긴 과자 길이로 설정

    //연산 & 출력
    cout << upperSearch(snacks, left, right, m); // 1명에게 줄 수 있는 과자의 최대 길이 출력

    return 0; //프로그램 종료
}
