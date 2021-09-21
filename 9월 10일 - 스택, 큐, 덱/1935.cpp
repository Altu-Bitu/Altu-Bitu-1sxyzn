#include<iostream>
#include<stack>

using namespace std;

int main() {
	// 1,2,3.... 숫자를 스택에 저장
	stack<double> s;

	//n은 갯수를, temp는 카운트용 변수
	int n, temp = 0;
	cin >> n;

	// ABC*+DE/- 후위표기식 저장
	string str;
	cin >> str;

	// alpa[인덱스]=알파벳, 저장
	int alpa[26];

	while (temp < n) {
		//라벨링은 A, B, C순으로 됨
		//첫 번째 들어온 숫자 n은 A의 값
		//즉 첫 번째 입력은 alpa[0] 이면서 A를 가리키게됨
		cin >> alpa[temp];
		temp++;
	}

	//스택에서 pop할 변수, pop1이 더 위에 있던 것
	double pop1, pop2;

	for (int i = 0; i < str.length(); i++) {
		//알파벳이 들어옴
		//alpa[?]=해당 알파벳 을 찾고 싶은 것임
		//alpa[0]는 A, alpa[1]=B이므로
		//원하는 알파벳 - 'A' = 인덱스
		if (str[i] >= 'A' && str[i] <= 'Z')
			s.push(alpa[str[i]-'A']);

		//기타 문자이면
		else {
			pop1 = s.top();
			s.pop();
			pop2 = s.top();
			s.pop();

			switch (str[i]) {

			//pop1 연산 pop2 하면 안됨
			// (45/)의 경우, 4/5인데
			// 이때 pop1=5, pop2=4, 즉 pop2/pop1이 됨
			case '+':
				s.push(pop2 + pop1);
				break;
			case '-':
				s.push(pop2 - pop1);
				break;
			case '*':
				s.push(pop2 * pop1);
				break;
			case '/':
				s.push(pop2 / pop1);
				break;
			}
		}
	}

	double result = s.top();
	//소숫점 둘째자리까지
	cout << fixed;
	cout.precision(2);
	cout << result << '\n';
}
