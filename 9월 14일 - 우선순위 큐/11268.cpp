#include<iostream>
#include<queue>

using namespace std;

int main() {
	//p에는 양수인 것들을 최소 힙으로 저장
	//m에는 음수인 것들의 절댓값을 최소 힙으로 저장
	priority_queue<int,vector<int>, greater<int>> p;
	priority_queue<int, vector<int>, greater<int>> m;

	int n;
	cin >> n;

	int q;
	int k;

	while (n--) {
		cin >> q;
		if (q != 0) { //0이 아니면 힙에 넣기
			if (q > 0) p.push(q);
			else {
				k = -q; //양수로 전환해서 힙에 저장
				m.push(k);
			}
		}
		else {
			if (m.empty() || p.empty()) { //둘 중 한 힙이 비어있을 때 
				if (m.empty() && p.empty()) { //둘 다 비어있으면 0 출력
					cout << 0 << '\n';
				}
				else if (m.empty()) { //음수 힙이 비어있으면 양수 힙에서 최솟값 출력
					cout << p.top() << '\n';
					p.pop();
				}
				else { //양수 힙이 비어있으면 음수 힙 최솟값을 음수로 출력
					cout << -m.top() << '\n';
					m.pop();
				}
			}
			else if (m.top() <= p.top()) { //최솟값 끼리 비교
				cout << -(m.top()) << '\n';
				m.pop();
			}
			else {
				cout << p.top() << '\n';
				p.pop();
			}
		}
	}

}
