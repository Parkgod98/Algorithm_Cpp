#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int ans = 0;
    
    int r = wallet[0];
    int c = wallet[1];
    
    while(1){
        if((bill[0] <= r && bill[1] <= c) || (bill[0] <= c && bill[1] <= r))
            break;
        else{
            if(bill[0] < bill[1])
                bill[1] /= 2;
            else
                bill[0] /=2;
            ++ans;
        }
    }
    
    return ans;
}