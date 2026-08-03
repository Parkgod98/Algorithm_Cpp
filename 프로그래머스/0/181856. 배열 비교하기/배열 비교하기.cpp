#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    if(arr1.size() != arr2.size())
        return arr1.size() > arr2.size() ? 1 : -1;
    else{
        int sum1,sum2;
        sum1 = sum2 = 0;
        
        int sz = arr1.size();
        for (int i = 0; i < sz; ++i){
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
        
        if(sum1 > sum2)
            return 1;
        else if(sum1 < sum2)
            return -1;
        return 0;
    }
}