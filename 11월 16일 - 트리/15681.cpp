#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt; //서브트리의 갯수 저장

int treeDp(int cur, vector<vector<int>> &graph) { //연산
    if (subtree_cnt[cur] != -1) //이미 탐색했던 상태
        return subtree_cnt[cur]; // 탐색결과 리턴

    subtree_cnt[cur] = 0;//서브트리에 속한 정점의 수를 세고, 저장
    int node = 1; //정점 갯수
    for (int i = 0; i < graph[cur].size(); i++) //그래프 전체 확안
        node += treeDp(graph[cur][i], graph); //서브트리 정점수 재귀로 계산
    return subtree_cnt[cur] = node; //서브트리 정점 수 저장
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 계산
 */
int main() {
    ios::sync_with_stdio(false); //입출력 향상
    cin.tie(NULL); //입출력 향상

    int n, r, q, u, v, input; //차례대로 정점의 수, 루트의 번호, 쿼리의 수, 간선의 정보 변수 2개, 루트가 될 노드

    cin >> n >> r >> q; //입력
    vector<vector<int>> graph(n + 1, vector<int>(0)); //트리
    subtree_cnt.assign(n + 1, -1); //서브 트리 카운트

    while (--n) { //무방향 그래프
        cin >> u >> v; //간선 정보 저장
        graph[u].push_back(v); //간선
        graph[v].push_back(u); //간선
    }

    treeDp(r, graph);//연산

    while (q--) {    //출력
        cin >> input; // 루트가 될 노드들 입력
        cout << subtree_cnt[input] << '\n'; //서브트리 개수 출력
    }
}
