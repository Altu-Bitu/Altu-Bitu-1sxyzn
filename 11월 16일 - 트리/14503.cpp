#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) { //청소 칸 연산 후 갯수 리턴
    int dr[4] = {-1, 0, 1, 0};    //상, 우, 하, 좌
    int dc[4] = {0, 1, 0, -1};    //상, 우, 하, 좌

    int step = 0, ans = 0; //단계와 정답 담을 임시 변수
    while (true) { //한바퀴 돌 때 까지 무한반복
        if (board[r][c] == 0) { //0이면
            board[r][c] = 2; //청소 했다고 인식
            ans++; //카운트
        }

        if (step == 4) { //한바퀴 다 돌았을 때
            if (board[r - dr[d]][c - dc[d]] == 1) //벽 만나면
                return ans; //현재 정답 리턴
            r -= dr[d];//후진
            c -= dc[d];//후진
            step = 0;//다시 차례대로 탐색
        } else { //아직 한바퀴 다 돌지 않았으면
            d = (d + 3) % 4; // 회전
            if (board[r + dr[d]][c + dc[d]]) { //청소할 공간이 있으면
                step++; // 전진하고
                continue; //1번부터 진행
            }
            r += dr[d]; //한바퀴 다 안돌았는데
            c += dc[d]; /// 청소할 공간이 없다면 방향 회전 후
            step = 0; //2번으로 돌아감
        }
    }
}

/**
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d; //세로, 가로, 좌표 r c, 방향 d

    cin >> n >> m >> r >> c >> d;    //입력
    vector<vector<int>> board(n, vector<int>(m, 0)); // 장소
    for (int i = 0; i < n; i++) { //가로만큼
        for (int j = 0; j < m; j++) {//세로만큼
            cin >> board[i][j]; // 장소 상태 입력
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board); //청소칸 연산 후 출력
    return 0; //프로그램 종료
}
