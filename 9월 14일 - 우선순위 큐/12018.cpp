#include<iostream>
#include<queue>

using namespace std;

int main() {
	priority_queue<int,vector<int>,greater<int>> q; // 내가 사용해야할 마일리지 담기
	
	int n, m;
	cin >> n >> m;

	while (n--) {
		priority_queue<int, vector<int>, greater<int>> temp; //한 과목당 다른 사람이 신청한 마일리지 담기 ex) 36 25 1 36 36
		
		//p는 수강신청한 사람, l은 수강가능인원
		int p, l;
		cin >> p >> l;
		int p_temp = p;

		//다른사람이 이 과목에 할당한 마일리지를 최소힙에 담기
		while (p_temp--) {
			int i;
			cin >> i;
			temp.push(i);
		}

		//자리가 여유롭다면 마일리지 1만 할당
		if (l > p)
			q.push(1);

		//정원이 다 찼다면, 제일 적게 할당한 사람 만큼만 할당하면 된다
		else if (l == p)
			q.push(temp.top());

		//5명 가능인데 7명이 신청할 경우,
		//오버한 만큼(2명)을 카운트하고, 그만큼 pop해준다
		//7명 중 2명 커트했고, 제일 적게 마일리지 넣은 사람만큼(5번째 사람)
		//내가 마일리지를 넣으면 수강신청 성공!
		else {
			int over = p - l;
			while ((over)--) {
				temp.pop();
			}
			q.push(temp.top());
		}
	}
	
	int total = 0;
	int my_m = 0;
	while (!q.empty()) {
		my_m += q.top();
		q.pop();
		if(my_m <= m) total++;
	}
	cout << total << '\n';
}
