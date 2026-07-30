#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    sort(array.begin(),array.end());
    
    int sz = array.size();
    return array[sz/2];
}