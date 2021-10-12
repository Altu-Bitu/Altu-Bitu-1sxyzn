#include <iostream>

using namespace std;

int ans = 0; //몇번째 방문인지 결과 출력용 변수
bool found = false; // 찾았는지 확인여부 체크하는 변수

void divide(int r, int c, int row, int col, int size) { //분할 정복!
    //Conquer : 찾던 위치에 도달함
    if (row == r && col == c) { //찾던 위치
        found = true; //찾음
        return; //함수 종료
    }
    if (found) //찾았다면
        return; //함수 종료

    //Combine : (r, c)보다 먼저 탐색하는 원소의 개수 세기
    if (r < row || r >= row + size || c < col || c >= col + size) { //이 사분면 안에 (r, c)가 없을 때
        ans += size * size; //(r, c) 앞에 (size * size)개의 원소가 있음
        return; //함수 종료
    }

    //Divide : 4개의 사분면으로 나누기
    int next_size = size / 2; //4등분 내기
    for (int i = 0; i <= next_size; i += next_size) { //등분낸 만큼
        for (int j = 0; j <= next_size; j += next_size) //등분낸 만큼
            divide(r, c, row + i, col + j, next_size); // 분할 정복
    }
}

/**
 * 1. 종이 4등분 하기
 * 2. z의 형태에 맞춰 1->2->3->4 사분면 순서로 탐색
 * 3. 만약 sub-사분면이 (r, c)의 범위를 넘어서면, 이 사분면은 (r, c)보다 먼저 탐색하는 사분면 (왜그런지 생각해보기)
 *    sub-사분면의 크기는 (sub-size * sub-size)이므로 (r, c) 앞에 그만큼의 원소가 있음
 */
int main() { //메인 함수
    int n, r, c; // 입력받을 변수들

    //입력
    cin >> n >> r >> c; //2^n*2^n, r행, c열

    //연산
    divide(r, c, 0, 0, 1 << n); //분할 정복 시작

    //출력
    cout << ans; //몇번째 방문인지 출력
}
