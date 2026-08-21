#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    
    int mx = max(sides[0],sides[1]);
    if(sides[0] > sides[1]){
        int tmp = sides[0];
        sides[0] = sides[1];
        sides[1] = tmp;
    }
    
    int cnt = 0;
    for (int i = 1; i <= mx; ++i){
        if(sides[0] + i > mx)
            ++cnt;
    }
    cnt += max((sides[0] + sides[1]) - (mx +1),0);
    
    return cnt;
}