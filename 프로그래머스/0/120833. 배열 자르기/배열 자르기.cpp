#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, int num1, int num2) {
    int sz = num2 - num1 + 1;
    vector<int> ans(sz);
    
    for (int i = num1; i <= num2; ++i)
        ans[i-num1] = numbers[i];
    return ans;
}