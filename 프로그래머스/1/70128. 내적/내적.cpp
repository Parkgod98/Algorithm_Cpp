#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    
    int sum = 0;
    int sz = a.size();
    for (int i = 0; i < sz; ++i)
        sum += a[i]*b[i];
    
    return sum;
}