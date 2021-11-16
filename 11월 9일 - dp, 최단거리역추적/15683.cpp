#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65; //세로 가로 정답변수
vector<vector<int>> board; //사무실

//cctv 범위 표시
void ray(int row, int col, int dir) { //cctv 범위 표시
    int dr[4] = {-1, 0, 1, 0}; // 상 우 하 좌 
    int dc[4] = {0, 1, 0, -1}; // 상 우 하 좌

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시
            board[row][col] = 7;
        row += dr[dir]; //가로로 뻗어나가기
        col += dc[dir]; //세로로 뻗어나가기
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) { //방향지정
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir); //모두 통과
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4); //2보다 크거나 같고 3이면 안됨
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4); //cur이 2보다 크거나 같아야함
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4); //cur이 5
}

//사각지대 계산
int blindSpot() { //사각지대 계산
    int cnt = 0; //임시변수
    for (int i = 0; i < n; i++) { //세로크기 만큼
        for (int j = 0; j < m; j++) { //가로크기 만큼
            if (!board[i][j]) //사각지대 있으면
                cnt++; //+1 하기
        }
    }
    return cnt; //사각지대 수 리턴
}

void backtracking(int idx) { //백트래킹 연산
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return; // 모든 위치 확인시 함수 종료
    }

    int row = idx / m; // 가로크기로 나눈걸 행으로
    int col = idx % m; //가로크기 나누고 나머지를 열로
    int cur = board[row][col]; //보드 저장
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳
        return backtracking(idx + 1); //다음 백트래킹

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치
        install(cur, row, col, i); //cctv 방향 지정
        backtracking(idx + 1); // 다음 백트래킹
        board = save; // 보드 상태 저장

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0)) //2번 cctv, 5번 cctv가 조건에 맞으면
            break; //반복 종료
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m; //세로 가로 입력
    board.assign(n, vector<int>(m)); //사무실
    for (int i = 0; i < n; i++) { //세로만큼
        for (int j = 0; j < m; j++) //가로만큼
            cin >> board[i][j]; //사무실 각 칸의 정보 입력
    }

    //연산
    backtracking(0); //백트래킹

    //출력
    cout << ans; //사각지대의 최소 크기
}
