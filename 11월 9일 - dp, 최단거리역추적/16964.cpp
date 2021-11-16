#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> visited, sequence, result; //방문, 순서, 결과 저장할 벡터

bool cmp(const int& i1, const int& i2) {//비교 함수
    return sequence[i1] < sequence[i2]; //오름차순으로 비교
}


void dfs(int cur, vector<vector<int>>& graph) { //재귀함수로 dfs 수행
    visited[cur] = true; //방문함으로 상태 변경
    result.push_back(cur); //cur 저장
    for (int i = 0; i < graph[cur].size(); i++) { //전체 그래프 돌면서
        if (!visited[graph[cur][i]]) //방문하지않았다면
            dfs(graph[cur][i], graph);//재귀로 dfs 수행
    }
}


bool isDfs(vector<int>& route) { //입력받은 순서와 dfs 결과 비교
    for (int i = 0; i < route.size(); i++) { //전체 반복문 돌기
        if (route[i] != result[i]) //입력받은 순서랑 dfs결과가 다르면
            return false; //f 리턴
    }
    return true; //결과가 같으면 t 리턴
}

/**
 *  예제 입력 3  -> 예제 입력 3
 *  1 | 2 3        1 | 3 2
 *  2 | 1 4        2 | 1 4
 *  3 | 1          3 | 1
 *  4 | 2          4 | 2
 *
 *  route : 1 3 2 4
 *
 *  알 수 있는 것
 *  1. 1번 정점은 3, 2, 4번 정점보다 먼저 탐색된다.
 *  2. 3번 정점은 2, 4번 정점보다 먼저 탐색된다.
 *  3. 2번 정점은 4번 정점보다 먼저 탐색된다.
 *  -> 정점 i, j의 위치를 x, y라고 할 때, x < y면 정점 i는 정점 j보다 먼저 탐색해야 함
 *  -> 위치 관계를 기준으로 정렬
 *
 *  정렬 후 dfs 탐색을 한 결과가 입력된 경로와 같다면 올바른 방문 순서
 */
int main() {
    int n, a, b; //정점의 수, 간선 정보 받을 변수

    //입력
    cin >> n; //정점의 수 입력
    vector<vector<int>> graph(n + 1, vector<int>(0)); //그래프 저장
    vector<int> route(n, 0); //경로 저장
    visited.assign(n + 1, 0); // 방문 저장
    sequence.assign(n + 1, 0); // 순서 저장

    for (int i = 1; i < n; i++) { //무방향 그래프
        cin >> a >> b; //간선 정보 입력
        graph[a].push_back(b); //경로 저장
        graph[b].push_back(a); //경로 저장
    }
    for (int i = 0; i < n; i++) { //각 정점의 순서 인덱스를 sequence 배열에 저장
        cin >> route[i]; //dfs방문 순서 입력
        sequence[route[i]] = i; //순서 저장해둠
    }

    //연산
    for (int i = 1; i <= n; i++) //sequence 기준 오름차순 정렬
        sort(graph[i].begin(), graph[i].end(), cmp); //오름차순
    dfs(1, graph); //dfs연산

    //출력
    cout << isDfs(route);// 옳은 순서인지 아닌지 출력
}
