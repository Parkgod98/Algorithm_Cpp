#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    
    if(k%2 == 1){
        for (int &n : arr)
            n*=k;
    }
    else{
        for (int &n : arr)
            n += k;
    }
    return arr;
}