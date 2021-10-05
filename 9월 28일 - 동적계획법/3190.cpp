#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci; //pair ci 생성

ci dir[4] = {{0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0}}; //하

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) { //보드 크기, 보드, 회전 정보 전달
    //뱀 초기화
    deque<ci> snake; //snake 생성
    snake.push_front(ci(0, 0)); //뱀 초기 위치
    board[0][0] = 1; // 뱀 시작 길이 = 1

    int t = 0, head = 0; //시간, 뱀의 머리 방향
    while (true) { // 종료 조건 만나기 전까지 무한 반복
        t++; //시간 증가
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first; // 뱀의 머리 위치는,
        int nc = snake.front().second + dir[head].second; // 몸을 늘려 머리를 다음칸으로 위치시켜 조정

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) //늘린 머리가 보드에 충돌, 또는 늘린 머리가 있는 위치에 자기 몸 있음
            break; //게임 종료, 무한 반복문 탈출

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0; //몸 길이를 줄이기
            snake.pop_back(); //위치한 칸을 비우기
        }

        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc)); //위치를 다음칸으로
        board[nr][nc] = 1; // 몸 길이를 늘린다

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4; // L을 만나면 머리방향 head를 왼쪽회전
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4; //D을 만나면 머리방향 head 오른쪽회전
    }
    return t; //무한 반복문 종료 후 시간을 리턴
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */
int main() {
    int n, k, row, col, l, x; //n은 보드의 크기, k는 사과의 갯수, row col은 행과 열- 사과의 위치
    //x는 게임 시작 시간 이후 x초가 지남을 의미, l은 방향 변화 횟수
    char c; // x초가 지난 후 입력받은 c방향으로 이동

    //입력
    cin >> n >> k; //보드 크기 >> 사과 갯수 입력
    vector<vector<int>> board(n, vector<int>(n)); //이차원 벡터 선언
    for (int i = 0; i < k; i++) { // 사과 위치 k번 입력받기위한 반복문
        cin >> row >> col; // 사과 위치
        board[row - 1][col - 1] = 2; //사과 표시
    }
    cin >> l; // 방향 변화 횟수 입력
    map<int, char> cmd; //방향 변화 정보를 map에 저장
    for (int i = 0; i < l; i++) { //회전 정보
        cin >> x >> c; // 게임 시작 후 x초 후 c위치로 회전
        cmd[x] = c; //회전 정보 저장
    }

    //연산 & 출력
    cout << playGame(n, board, cmd);//함수 실행, 
}
