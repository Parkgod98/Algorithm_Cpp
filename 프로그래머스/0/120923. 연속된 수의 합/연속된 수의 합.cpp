#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> ans;
    
    double mid = total/(double)num;
    
    int s;
    if(num%2 == 0){
        s = mid - num/2 + 0.5;
    }
    else{
        s = mid - num/2;
    }
    for (int i = s; i < s + num; ++i){
        ans.push_back(i);
    }
    return ans;
}