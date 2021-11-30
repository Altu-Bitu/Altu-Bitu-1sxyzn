#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 401; //최댓값 20*20 =400에서 +1
typedef pair<int, int> ci; //좌표

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) { //다음 물고기의 거리, 위치 연산
    int dr[4] = {-1, 1, 0, 0}; //상하좌우
    int dc[4] = {0, 0, -1, 1};
  
    int min_dist = INF; //최소 거리 저장하는 변수
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> visited(n, vector<int>(n, 0)); //상어의 방문 여부
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    visited[shark.first][shark.second] = 1; //현재 위치
    q.push(shark); //현재 위치 저장
  
    while (!q.empty()) { // 큐가 빌 때 까지 반복
        int row = q.front().first; //현재의 행
        int col = q.front().second; //현재의 열
        int dist = visited[row][col]; //거리 저장
        q.pop(); //큐에서 꺼내기

        if (dist >= min_dist) //최단거리 이상은 탐색할 필요 없음
            continue; //최단거리 이상이면 아래 코드 무시
        for (int i = 0; i < 4; i++) { //위치 만큼
            int nr = row + dr[i]; //행 이동
            int nc = col + dc[i]; //열 이동
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || board[nr][nc] > shark_size) //표를 넘거나, 방문 했거나, 상어보다 크면
                continue; //아래 코드 무시

            visited[nr][nc] = visited[row][col] + 1; //이동할 수 있으면  이동거리 저장
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //먹을 수 있는 물고기 위치 저장
                min_dist = visited[nr][nc]; //최단 거리 갱신
                continue; //
            }
            q.push({nr, nc}); // 큐게 물고기 위치 
        }
    }

    if (list.empty()) //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //최단 거리와 -1 리턴

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬
        if (p1.first != p2.first) //물고기 위치 다르면
            return p1.first < p2.first; //가까운 물고기로
        return p1.second < p2.second; //왼쪽 물고기로
    });
    return {min_dist - 1, list[0]}; //다음 물고기의 거리, 위치 리턴
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) { //연산
    int ans = 0, size = 2, cnt = 0; //정답, 상어 크기
    while (true) { //물고기 있을 때 까지 무한 반복
        pair<int, ci> result = nextPos(n, size, shark, board); //물고기 탐색
        if (result.first == INF) //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //반복문 종료
        ans += result.first; //물고기가 있으면 정답 갱신
        cnt++; //물고기 수 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0; // 물고기 수 초기화 
            size++; //크기 증가
        }

        ci pos = result.second; //상어 이동
        board[shark.first][shark.second] = 0; //상어 이동
        shark = pos; //상어 위치 갱신
    }
    return ans; //혼자 먹을 수 있는 물고기 갯수 리턴
}

/**
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */
int main() {
    int n; //공간의 크기
    pair<int, int> shark_pos; //상어 위치

    cin >> n;    //입력
    vector<vector<int>> board(n, vector<int>(n)); //표 생성
    for (int i = 0; i < n; i++) { //공간 크기 만큼
        for (int j = 0; j < n; j++) { //공간 크기 만큼
            cin >> board[i][j]; //공간의 상태 받기
            if (board[i][j] == 9) //상어의 초기 위치
                shark_pos = make_pair(i, j); //아기 상어의 위치
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board); //아기 홀로 물고기 잡아먹는 시간 출력
}
