#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    
    for (int i = 1; i*i <= total; ++i){
        if(total%i == 0){
            int garo = i;
            int sero = total/i;
            
            int g = garo*2 + sero*2 - 4;
            int y = total - g;
            
            if(brown == g && yellow == y){
                vector<int> ans(2);
                ans[0] = sero;
                ans[1] = garo;
                return ans;
            }
        }
    }
    return answer;
}