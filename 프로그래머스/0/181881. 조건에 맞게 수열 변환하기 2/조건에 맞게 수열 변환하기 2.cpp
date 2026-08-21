#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int x = 0;    
    bool diff = false;
    int sz = arr.size();
    
    while(1){
        for (int i = 0; i < sz; ++i){
            if(arr[i] >=50 && arr[i]%2 == 0){
                arr[i] /=2;
                diff = true;
            }
            else if(arr[i] < 50 && arr[i]%2 == 1){
                arr[i] = arr[i]*2 + 1;
                diff = true;
            }
        }
        ++x;
        if(!diff){
            return x-1;
        }
        diff = false;
    }
}