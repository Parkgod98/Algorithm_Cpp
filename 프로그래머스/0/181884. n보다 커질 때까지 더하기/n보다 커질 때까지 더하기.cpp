#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int n) {
    int sz = numbers.size();
    int sum = 0;
    for (int i = 0; i < sz; ++i){
        sum += numbers[i];
        if(sum > n){
            return sum;
        }
    }
    return sum;
}