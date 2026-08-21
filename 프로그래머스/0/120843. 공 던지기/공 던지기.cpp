#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    k = ((k-1)*2)%numbers.size();
    return numbers[k];
}