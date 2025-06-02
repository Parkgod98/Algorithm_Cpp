#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N % 2 == 1)
		cout << "SK";
	else
		cout << "CY";
}