#include <iostream>
#include <vector>

using namespace std;

//단절점, 단절선 파악 함수
string isTrue(int t, int k, vector<vector<int>> &tree) { //단절점/선 파악하기
    if (t == 2) // 단절선인지에 대한 질문
        return "yes"; //정답으로 출력
    if (tree[k].size() >= 2) // 단절점인지에 질문시, 트리에 정점이 2개 이상이면
        return "yes"; //단절점임. 정답을 출력
    return "no"; //점 1개면 단절점아님. no 출력
}

/**
 * 부모 노드를 알 수 없기에 트리를 양방향 그래프로 저장
 * 단절점: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 연결된 간선이 2개 이상이면 단절점
 * 단절선: 트리는 모든 정점이 연결되어 있고, 싸이클이 존재하지 않기 때문에 모든 간선이 단절선
 */

int main() {
    ios_base::sync_with_stdio(false); //입출력향상
    cin.tie(NULL); //입출력향상
    int n, a, b, q, t, k; //정점 갯수, 간선 정보 a b, 질의 갯수 q
    //t=1이면 단절점인지? t=2이면 단절선인지?
    //k번째 정점/간선이 단절점/선 인지?

    cin >> n; //입력
    vector<vector<int>> tree(n + 1, vector<int>(0)); //트리
    for (int i = 0; i < n - 1; i++) { //정점 갯수만큼
        cin >> a >> b; //간선 입력
        tree[a].push_back(b); //양방향 저장
        tree[b].push_back(a); //양방향 저장
    }
    cin >> q; //질의 갯수 입력
    while (q--) { //질문 갯수 만큼
        cin >> t >> k; //입력
        cout << isTrue(t, k, tree) << '\n'; //정답 출력
    }
    return 0; //프로그램 종료
}
