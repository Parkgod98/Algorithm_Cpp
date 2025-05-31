#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {

	double cnt = 0;
	double sum = 0;
	for (int i = 0; i < 20; ++i) {
		string s;
		double n;
		string grade;
		cin >> s >> n >> grade;

		if (grade == "P") {
			continue;
		}
		else {
			double k;
			if (grade == "A+") {
				k = 4.5;
			}
			else if (grade == "A0") {
				k = 4.0;
			}
			else if (grade == "B+") {
				k = 3.5;
			}
			else if (grade == "B0") {
				k = 3.0;
			}
			else if (grade == "C+") {
				k = 2.5;
			}
			else if (grade == "C0") {
				k = 2.0;
			}
			else if (grade == "D+") {
				k = 1.5;
			}
			else if (grade == "D0") {
				k = 1.0;
			}
			else if (grade == "F") {
				k = 0;
			}
			sum += (n*k);
			cnt += n;
		}
	}

	cout.precision(6);
	cout << fixed;

	cout << sum / cnt << "\n";
}