#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int res = 0;
    
    int s1_sz = s1.size();
    int s2_sz = s2.size();
    
    for (int i = 0; i < s1_sz; ++i){
        for (int j = 0; j < s2_sz; ++j){
            if(s1[i] == s2[j])
                ++res;
        }
    }
    return res;
}