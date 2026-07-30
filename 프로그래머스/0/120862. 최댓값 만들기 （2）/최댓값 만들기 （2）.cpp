#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    sort(numbers.begin(),numbers.end());
    int a = numbers[0] * numbers[1];
    
    int sz = numbers.size();
    int b = numbers[sz-1] * numbers[sz-2];
    
    return a > b ? a : b;
}