#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	string ss;
	while(getline(cin,ss)) {
		int s, l, n, e;
		s = l = n = e = 0;

		for (int i = 0; i < ss.size(); ++i) {
			if (islower(ss[i]))
				++s;
			else if (isupper(ss[i]))
				++l;
			else if (isdigit(ss[i]))
				++n;
			else if (ss[i] == ' ')
				++e;
		}
		cout << s << " " << l << " " << n << " " << e << "\n";
	}
}