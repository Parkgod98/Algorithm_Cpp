#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    
    int mx = 9999999;
    int sz = array.size();
    int res = 9999999;
    for (int i = 0; i < sz; ++i){
        int value = abs(n-array[i]);
        if(mx > value){
            mx = value;
            res = array[i];
        }
        else if(mx == value && array[i] < res){
            res = array[i];
        }
    }
    return res;
}