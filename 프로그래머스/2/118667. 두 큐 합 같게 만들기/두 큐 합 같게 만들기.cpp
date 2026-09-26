#include <string>
#include <vector>
#include <queue>
using namespace std;


/*


14  16
3 2 7 2  // 4 6 5 1

11            19
2 7 2 // 4 6 5 1 3 
*/

int solution(vector<int> queue1, vector<int> queue2) {
    int ans = 0;
    long long sum1,sum2;
    sum1 = sum2 = 0;
    
    queue<int> q1;
    for (int &n : queue1){
        q1.push(n);
        sum1 += n;
    }
    
    queue<int> q2;
    for (int &n : queue2){
        q2.push(n);
        sum2 += n;
    }
    
    
    int limit = q1.size() + q2.size();
    while(sum1 != sum2){
        if(sum1 < sum2){
            sum2 -= q2.front();
            sum1 += q2.front();
            
            q1.push(q2.front());
            q2.pop();
        }
        else if(sum1 > sum2){
            sum1 -= q1.front();
            sum2 += q1.front();
            
            q2.push(q1.front());
            q1.pop();
        }
        
        ++ans;
        
        if(ans >= 2*limit)
            return -1;
    }
    
    
    return ans;
}