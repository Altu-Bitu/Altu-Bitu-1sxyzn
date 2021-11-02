#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //bfs시 큐에 담을 pair

int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1}; //상, 하, 좌, 우, 좌상향 대각선, 우상향 대각선, 좌하향 대각선, 우하향 대각선
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1}; //상, 하, 좌, 우, 좌상향 대각선, 우상향 대각선, 좌하향 대각선, 우하향 대각선

vector<vector<int>> board; //지도, 보드
int h, w; //높이와 너비

//dfs 탐색
void dfs(int cr, int cc) { //dfs로 탐색
    board[cr][cc] = 0; //방문 체크

    for (int i = 0; i < 8; i++) { //가능한 방향의 정점(자식노드) 모두 탐색
        int nr = cr + dr[i]; //새로 탐색할 row값
        int nc = cc + dc[i]; //새로 탐색할 col값
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc]) //탐색하려는 정점이 범위 내에 있고, 땅이라면
            dfs(nr, nc); //바로 탐색(깊게 탐색) 재귀로..
    }
}

//bfs 탐색
void bfs(int row, int col) { //bfs 탐색
    queue<ci> q; //큐 생성

    q.push(ci(row, col)); //pair에 좌표를 담아 큐에 저장
    board[row][col] = 0; //처음 위치 방문 체크

    while (!q.empty()) { //큐가 빌 때까지 무한 반복
        int cr = q.front().first; //현재 정점의 행 정보
        int cc = q.front().second; //현재 정점의 열 정보
        q.pop(); //탐색 했으므로 맨 앞의 정점 pop

        for (int i = 0; i < 8; i++) { //가능한 방향의 정점(자식노드) 모두 탐색
            int nr = cr + dr[i]; //새로 탐색할 row값
            int nc = cc + dc[i]; //새로 탐색할 col값
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc]) { //탐색하려는 정점이 범위 내에 있고, 땅이라면
                board[nr][nc] = 0; // 방문 체크
                q.push(ci(nr, nc)); //pair에 좌표를 담아 큐에 저장
            }
        }
    }
}

/**
 * 섬의 개수를 구하는 문제 -> 섬의 개수만큼 탐색을 하면 된다
 * 모든 정점을 검사해야 하므로 dfs, bfs 풀이 모두 가능
 * 입력으로 들어오는 보드를 방문 탐색 배열로 함께 사용 (방문하면 1(땅)을 0(바다)으로 바꾸기)
 */

int main() {
    while (true) { // 마지막 줄에 0이 두개 주어지면 종료
        cin >> w >> h;  // 지도의 너비와 높이 받기
        if (w == 0) //너비가 0이면
            break; //지도 생성 불가, 반복문 종료

        //보드 입력
        board.assign(h, vector<int>(w, 0)); //보드 생성
        for (int i = 0; i < h; i++) //높이만큼 반복
            for (int j = 0; j < w; j++) //너비만큼 반복
                cin >> board[i][j]; //보드를 땅과 바다로 채우기

        //연산 & 출력
        int ans = 0; //섬의 갯수 입력받을 변수
        for (int i = 0; i < h; i++) { //높이만큼 반복
            for (int j = 0; j < w; j++) { //너비만큼 반복
                if (board[i][j]) { //땅을 찾았다면 바로 탐색 시작
                    ans++; //섬의 갯수 추가
                    bfs(i, j); //bfs로 탐색
                    //dfs(i, j); // dfs로 탐색해도 된다
                }
            }
        }
        cout << ans << '\n'; //섬의 갯수 출력
    }
    return 0; // 
}
