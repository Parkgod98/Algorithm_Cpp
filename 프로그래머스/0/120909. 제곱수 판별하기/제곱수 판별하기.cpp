#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    
    int r = sqrt(n);
    return r*r == n ? 1 : 2;
}