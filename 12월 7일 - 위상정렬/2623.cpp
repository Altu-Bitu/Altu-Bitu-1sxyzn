#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) { //위상정렬
    vector<int> result; // 정답
    queue<int> q; //정렬시 이용

    for (int i = 1; i <= n; i++) { // 가수의 수 만큼
        if (!indegree[i]) //진입차수가 0 이라면
            q.push(i); //큐에 넣기
    }

    while (!q.empty()) { //큐가 빌 때까지 반복
        int node = q.front(); // 맨 처음 원소 저장
        q.pop(); //큐에서 빼기

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) { // 노드 크기만큼
            int next_node = graph[node][i]; //다음 노드 저장
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //다음 노드 큐에 저장
        }
    }
    return result; //위상 정렬한 결과 리턴
}

/**
 * 기본적인 위상 정렬 문제
 * 현재 가수와 바로 전 가수 사이의 선후관계를 정의
 * 순서를 정하는 것이 불가능한 경우(위상정렬을 할 수 없는 경우)는 모든 정점을 탐색하지 못한 경우
 */

int main() {
    int n, m, cnt, prev, cur; // 가수의 수, 보조 pd의 수, 담당 가수의 수, 처음 가수, 가수 순서
    //입력
    cin >> n >> m; //가수의 수, 보조 pd의 수 입력
    vector<int> indegree(n + 1, 0); // 진입 차수
    vector<vector<int>> graph(n + 1, vector<int>(0)); // 인접 그래프
    while (m--) { //보조 pd의 수
        cin >> cnt; //담당 가수의 수
        cin >> prev; //처음 가수 입력
        while (--cnt) { //선후관계 정의
            cin >> cur; // 가수 순서 입력
            indegree[cur]++; //진입 차수 ++
            graph[prev].push_back(cur); //인접 그래프에 넣기
            prev = cur; 
        }
    }

    vector<int> result = topologicalSort(n, indegree, graph); //연산

    //출력
    if (result.size() != n) { //순서를 정하는 것이 불가한 경우
        cout << "0\n"; // 0 출력
        return 0; // 프로그램 종료
    }
    for (int i = 0; i < result.size(); i++) // 순서대로 출력
        cout << result[i] << '\n'; // 남일이가 정한 가수 순서대로 출력
}
