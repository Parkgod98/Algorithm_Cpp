#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    
    int ans = 0;
    for (int &n : num_list){
        while(n != 1){
            if(n%2 == 0)
                n/=2;
            else
                n = (n-1)/2;
            ++ans;
        }
    }
    return ans;
}