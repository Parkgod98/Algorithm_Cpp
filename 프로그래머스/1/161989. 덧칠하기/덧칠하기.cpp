#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    
    int ans = 0;
    int start = 1;
    
    int sz = section.size();
    for (int i = 0; i < sz; ++i){
        if(section[i] < start)
            continue;
        start = section[i]+m;
        ++ans;
    }
    return ans;
}