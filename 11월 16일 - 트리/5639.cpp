#include<iostream>
#include<map>
#include<string>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* new_node(int n) { //새 노드 생성
	Node* node = new Node;
	node->data = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Node* insert(Node* tree, int n) { //노드 삽입
	if (tree == NULL) return new_node(n);
	if (n < tree->data) // 단말 노드 만날 때 까지 재귀
		tree->left = insert(tree->left, n);
	else if (n > tree->data)// 단말 노드 만날 때 까지 재귀
		tree->right = insert(tree->right, n);
	return tree;
}

void postorder(Node* tree) { //후위 순회
	if (tree->left != NULL)
		postorder(tree->left);
	if (tree->right != NULL)
		postorder(tree->right);
	cout << tree->data << '\n';
}

int main() {
	Node* tree = NULL;
	string s;
	int n;
	while (true) {
		getline(cin, s);
		if (s == "") break; //마지막 입력이라면 반복문 탈출
		n = stoi(s); //입력이 있다면 문자열을 정수로 변환
		tree = insert(tree, n);
	}
	postorder(tree);
}
