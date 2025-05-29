#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	long long sum = 0;
	for (int i = 0; i < 3; ++i) {
		string s;
		cin >> s;
		long long n;
		if (i < 2) {
			if (s == "black") {
				n = 0;
			}
			else if (s == "brown") {
				n = 1;
			}
			else if (s == "red") {
				n = 2;
			}
			else if (s == "orange") {
				n = 3;
			}
			else if (s == "yellow") {
				n = 4;
			}
			else if (s == "green") {
				n = 5;
			}
			else if (s == "blue") {
				n = 6;
			}
			else if (s == "violet") {
				n = 7;
			}
			else if (s == "grey") {
				n = 8;
			}
			else if (s == "white") {
				n = 9;
			}
			sum = sum * 10 + n;
		}
		else {
			if (s == "black") {
				n = 1;
			}
			else if (s == "brown") {
				n = 10;
			}
			else if (s == "red") {
				n = 100;
			}
			else if (s == "orange") {
				n = 1000;
			}
			else if (s == "yellow") {
				n = 10000;
			}
			else if (s == "green") {
				n = 100000;
			}
			else if (s == "blue") {
				n = 1000000;
			}
			else if (s == "violet") {
				n = 10000000;
			}
			else if (s == "grey") {
				n = 100000000;
			}
			else if (s == "white") {
				n = 1000000000;
			}
			sum *= n;
		}
	}
	cout << sum;
}