#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {//위상정렬
    vector<int> result; //정렬 후 저장할 벡터
    queue<int> q; // 큐 이용

    for (int i = 1; i <= n; i++) { // 가수 수 만큼 정렬
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); //큐에 push
    }

    while (!q.empty()) { //큐가 빌 때까지
        int node = q.front(); // 큐 첫번째 원소 저장하고
        q.pop(); // 큐에서 꺼내기

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) { // 해당 정점의 크기만큼
            int next_node = graph[node][i]; // 다음 노드 저장
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); // 큐에 push
        }
    }
    return result; //정렬된 벡터 리턴
}

/**
 * 기본적인 위상 정렬 문제
 * 현재 가수와 바로 전 가수 사이의 선후관계를 정의
 * 순서를 정하는 것이 불가능한 경우(위상정렬을 할 수 없는 경우)는 모든 정점을 탐색하지 못한 경우
 */

int main() {
    int n, m, cnt, prev, cur; // 가수의 수, 보조 피디 수, 담당 가수 수, 가수의 순서

    //입력
    cin >> n >> m; // 가수의 수, 보조 피디 수
    vector<int> indegree(n + 1, 0); //진입 차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 리스트 그래프
    while (m--) { //보조 피티 수 만큼
        cin >> cnt; //담당 가수의 수
        cin >> prev; //처음 가수 입력
        while (--cnt) { //선후관계 정의
            cin >> cur; // 순서 입력
            indegree[cur]++; // 진입 차수 ++
            graph[prev].push_back(cur); //그래프에 push
            prev = cur; // 이전 순서 변경
        }
    }

    vector<int> result = topologicalSort(n, indegree, graph);  //연산

    //출력
    if (result.size() != n) { //순서를 정하는 것이 불가한 경우
        cout << "0\n"; // 0 출력
        return 0; // 종료
    }
    for (int i = 0; i < result.size(); i++) //출연 순서 출력
        cout << result[i] << '\n'; //출력
}
