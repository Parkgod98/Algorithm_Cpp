/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

struct Node {
	int val;
	Node* next;
};

Node head, tail;

void init() {
	head.next = nullptr;
	tail.next = nullptr;
}

Node* make_new_node(int val) {
	Node* new_node = new Node();
	new_node->val = val;
	new_node->next = nullptr;

	return new_node;
}

void insert_first(int n) {
	Node* node = make_new_node(n);

	node->next = head.next;
	head.next = node;
	if (tail.next == nullptr) {
		tail.next = node;
	}
}

void insert_interval(int x, int n) {
	Node* node = make_new_node(n);
	Node* tmp = &head;
	for (int i = 0; i < x; ++i)
		tmp = tmp->next;
	node->next = tmp->next;
	tmp->next = node;
	if (node->next == nullptr) {
		tail.next = node;
	}
}

void insert_final(int n) {
	Node* node = make_new_node(n);

	if (tail.next != nullptr) { // 이미 삽인한 노드가 있을 경우에는 마지막 노드도 연결
		tail.next->next = node;
	}
	if (head.next == nullptr)
		head.next = node;
	tail.next = node;
}

void print_10_node() {
	Node* tmp = head.next;

	for (int i = 0; i < 10; ++i) {
		cout << tmp->val << " ";
		tmp = tmp->next;
		if (tmp == nullptr)
			break;
	}
}
void print_all_node() {
	Node* tmp = head.next;

	while (tmp != nullptr) {
		cout << tmp->val << " ";
		tmp = tmp->next;
	}
	cout << "\n";
}

int main(int argc, char** argv)
{
	for (int tc = 1; tc <= 10; ++tc) {
		int N;
		cin >> N;
		for (int i = 0; i < N; ++i) {
			int n;
			cin >> n;
			insert_final(n);
		}
		
		int command_num;
		cin >> command_num;
		for (int i = 0; i < command_num; ++i) {
			char c;
			cin >> c;
			int x, y;

			if (c == 'I') {
				cin >> x >> y;
				for (int j = 0; j < y; ++j) {
					int n;
					cin >> n;
					insert_interval(x,n);
					x++;
				}
			}
			else if (c == 'D') {
				cin >> x >> y;
				Node* tmp = &head;
				for (int i = 0; i < x; ++i)
					tmp = tmp->next;
				for (int j = 0; j < y; ++j) {
					Node* dnode = tmp->next;
					tmp->next = dnode->next;
					delete dnode;
				}
			}
			else {
				cin >> y;
				for (int j = 0; j < y; ++j) {
					int n;
					cin >> n;
					insert_final(n);
				}
			}
		}
		cout << "#" << tc << " ";
		print_10_node();
		cout << "\n";
	}
}