#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string a, string b) {
	string answer = "";
	int a_len = a.length();
	int b_len = b.length();
	int carry = 0;
	if (a_len == b_len) {
		
		for (int i = a_len - 1; i >= 0; --i) {
			int n = (a[i] - '0') + (b[i] - '0') + carry;
			carry = 0;
			if (n > 9)
				carry += 1;
			answer = to_string(n % 10) + answer;
		}
	}
	else if (a_len > b_len) {
		int diff = a_len - b_len;
		for (int i = b_len - 1; i >= 0; --i) {
			int n = (a[i+diff] - '0') + (b[i] - '0') + carry;
			carry = 0;
			if (n > 9)
				carry += 1;
			answer = to_string(n % 10) + answer;
		}
		for (int i = diff-1; i >= 0; --i) {
			int n = (a[i] - '0') + carry;
			carry = 0;
			if (n > 9)
				carry += 1;
			answer = to_string(n % 10) + answer;
		}
		
	}
	else {
		int diff = b_len - a_len;
		for (int i = a_len - 1; i >= 0; --i) {
			int n = (a[i] - '0') + (b[i + diff] - '0') + carry;
			carry = 0;
			if (n > 9)
				carry += 1;
			answer = to_string(n % 10) + answer;
		}
		for (int i = diff - 1; i >= 0; --i) {
			int n = (b[i] - '0') + carry;
			carry = 0;
			if (n > 9)
				carry += 1;
			answer = to_string(n % 10) + answer;
		}
	}
	if(carry !=0)
		answer = to_string(carry) + answer;
	return answer;
}