#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < A.size(); ++i){
        while(j < B.size() && B[j] <= A[i]){
            ++j;
        }
        
        if(j == B.size())
            break;
        
        ++j;
        ++cnt;
    }
    return cnt;
}