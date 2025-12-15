#include <iostream>
using namespace std;

int main() {
	int n,
    stu, //학생수
    app, //사과개수
    r_sum=0; //나머지의 합
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stu >> app;
		r_sum += app % stu;
	}
	cout << r_sum;

	return 0;
}