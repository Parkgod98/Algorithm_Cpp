#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

vector<int> v;
int main() {
	int N;
	cin >> N;
	v = vector<int>(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int sum = 0;

	if (v.size() % 2 == 0) {
		for (int i = N-1; i >= 0; i -= 2) {
			int a = v[i];
			int b = v[i - 1];

			if (a < 0 && b < 0) {
				sum += (a*b);
			}
			else if (a < 0 && b == 0) {
				sum += a * b;
			}
			else if (a == 0 && b < 0)
				sum += (a*b);
			else if (a == 0 && b == 0) {
				continue;
			}
			else if (a == 0 && b > 0) {
				sum += b;
			}
			else if (a > 0 && b == 0) {
				sum += a;
			}
			else if (a > 0 && b > 0) {
				if (a == 1 || b == 1)
					sum += (a + b);
				else if (a != 1 && b != 1) {
					sum += (a*b);
				}
			}
			else
				sum += (a + b);
		}
	}
	else {
		vector<int> minus, zero, plus;
		for (int i = 0; i < N; ++i) {
			if (v[i] < 0)
				minus.push_back(v[i]);
			else if (v[i] == 0)
				zero.push_back(0);
			else
				plus.push_back(v[i]);
		}

		if (minus.size() % 2 == 0) { // 음수가 짝수개면 다 곱해서 더하는게 이득
			for (int i = 0; i < minus.size(); i += 2) {
				int a = minus[i];
				int b = minus[i + 1];
				sum += (a*b);
			}
		}
		else { // 음수가 홀수개면 한개는 어쩔수 없이. 그냥 더해야함. 0이없다면.
			if (zero.size() >= 1) { // 0이 하나라도 있다면. 맨 마지막 제일 큰 음수 하나는 0으로 곱해서 죽일수있음.
				zero.pop_back();
				minus.pop_back();

				for (int i = 0; i < minus.size(); i += 2) {
					int a = minus[i];
					int b = minus[i + 1];
					sum += (a*b);
				}
			}
			else { // 0이 하나도 없으면 어쩔수 없이 다 더해야함. 곱했을떄 제일커지는걸 더해서 합을 최대화 시킴.
				sum += minus[minus.size() - 1];
				minus.pop_back();
				for (int i = 0; i < minus.size(); i += 2) {
					int a = minus[i];
					int b = minus[i + 1];
					sum += (a*b);
				}
			}
		}

		/* 여기까지하면 모든 음수는 처리 완료. 이제 0아니면 싹다 양수임. */
		int i = plus.size() - 1;
		for (i; i >= 0; i -= 2) {
			if (i == 0) {
				sum +=plus[i];
			}
			else {
				int a = plus[i];
				int b = plus[i - 1];
				if (a == 1 || b == 1) {
					sum += (a + b);
				}
				else
					sum += (a*b);
			}
		}

	}

	cout << sum << "\n";


}
