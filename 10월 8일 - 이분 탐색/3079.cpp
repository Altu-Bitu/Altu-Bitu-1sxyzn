#include <iostream>
#include <vector>

using namespace std;
typedef long long ll; //long long 타입을 ll로 별칭

vector<ll> immigration; // 입국검사하는데 걸리는 시간 저장

//심사를 받는데 걸리는 시간이 tot_time일 때, 심사를 받을 수 있는 사람의 수
ll cntPeople(ll tot_time) { //tot_time 내에 심사 받을 수 있는 사람 수 체크
    ll cnt = 0; //사람 수 받을 변수
    for (int i = 0; i < immigration.size(); i++) //심사대 수 만큼 
        cnt += (tot_time / immigration[i]); // 전체시간에서 심사대마다 걸리는 시간 나누고 저장
    return cnt; //입국 심사 받을 수있는 사람 수 리턴
}

ll lowerSearch(ll left, ll right, int target) { //총 심사 시간의 최솟값 체크하는 함수
    ll ans = 0; //심사 시간 최솟값 담을 변수
    while (left <= right) { //left가 right를 넘어가지 않았을 때
        //심사를 받는데 걸리는 시간이 mid일 때, 몇 명의 친구들이 심사를 받을 수 있는가?
        ll mid = (left + right) / 2; //중간 값 저장
        ll entrance = cntPeople(mid); //mid 시간 내에 몇 명이 심사를 받을 수 있는지 저장

        if (entrance >= target) { //심사 받을 수 있는 사람이 전체 사람보다 많으면
            ans = mid; //mid 값 저장
            right = mid - 1; //right 값 안쪽으로 이동
        } else if (entrance < target) //심사 가능한 사람이 더 적으면
            left = mid + 1; //left 값 오른쪽으로 이동
    }
    return ans; //총 심사하는데 걸리는 최솟값 리턴
}

/**
 * 상근이와 친구들이 심사를 받는데 걸리는 시간의 최솟값
 * -> 시간이 t만큼 주어질 때, m명 이상의 친구들이 입국 심사를 받을 수 있는가?
 *
 * left : 모든 심사대의 심사 시간이 k이고, 심사대가 친구들의 수만큼 주어진다면 걸리는 시간은 k
 * right : 심사가 가장 오래 걸리는 심사대 k에서 모든 친구들이 한명씩 입국심사를 받는다면, 걸리는 시간은 k*m
 *
 * !주의! right k*m의 최댓값은 심사 시간의 최댓값 10^9와 m의 최댓값 10^9를 곱한 10^18이다.
 * 그러므로 long long 범위를 써야 함.
 */
int main() {
    int n, m; // n= 입국심사대 수 , m= 입국심사 받을 사람들의 수
    ll max_time = 0, min_time = 1e9; //최대 시간과 최소 시간

    //입력
    cin >> n >> m; // 입국심사대 수와 사람의 수 입력
    immigration.assign(n, 0); //입국 심사하는데에 걸리는 시간 저장할 벡터
    for (int i = 0; i < n; i++) { //심사대 수 만큼
        cin >> immigration[i]; // 각 심사대에서 얼마나 걸리는지 입력받기
        max_time = max(max_time, immigration[i]); //입력받은 시간과 기존의 최댓값중에 큰 값 저장
        min_time = min(min_time, immigration[i]); //입력받은 시간과 기존의 최솟값중에 작은 값 저장
    }

    //연산 & 출력
    cout << lowerSearch(min_time, max_time * m, m); //심사를 마치는데에 걸리는 시간의 최솟값 출력
}
