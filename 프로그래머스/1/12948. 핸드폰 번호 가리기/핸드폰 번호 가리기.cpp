#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    int sz = phone_number.size();
    
    for (int i = 0; i < sz-4; ++i)
        phone_number[i] = '*';
    return phone_number;
}