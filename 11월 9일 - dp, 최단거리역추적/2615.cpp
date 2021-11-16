#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19; // 19 * 19의 바둑판임

bool promising(int r, int c, int stone, vector<vector<int>> &board) { //범위와 돌의 종류가 유효한지 확인
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone; //바둑판 범위 안쪽이고 돌 종류가 유효하면 리턴1
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) { //오목 확인
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1}; // 가로 세로 우하향 대각, 우상향 대각
    int dc[4] = {1, 0, 1, 1};//가로 세로 우하향 대각, 우상향 대각
  
    bool is_six = promising(r - dr[d], c - dc[d], stone, board); //(r, c) 이전에 위치한 이어지는 돌이 있나?

    int cnt = 0;// 임시변수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; // 이어지면 바둑알 갯수 +1
        r += dr[d]; // 다음 알 확인
        c += dc[d]; //다음 알 확인
    }
    return cnt == 5 && !is_six; //오목이면 리턴 1
}

bool isEnd(int r, int c, vector<vector<int>> &board) { //오목 끝났는지 확인
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) // 오목이 완성되면
            return true; // 오목이 끝남
    }
    return false; //끝나지 않음
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));//바둑판

    //입력
    for (int i = 0; i < SIZE; i++) { //19만큼
        for (int j = 0; j < SIZE; j++) //19만큼
            cin >> board[i][j]; //바둑알 입력
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) { //19만큼
        for (int j = 0; j < SIZE; j++) { //19만큼
            if (!board[i][j]) //돌이 없음
                continue; // 다음 반복문 실행
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; // 가장 왼쪽 바둑알 위치 출력
                return 0; //종료
            }
        }
    }
    cout << 0;
}
