#include <string>
#include <vector>

using namespace std;

int GetLCD(int a,int b){
    while(a%b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

vector<int> solution(vector<int> arr) {
    
    int sz = arr.size();
    
    int mx = 1;
    while(1){
        if(sz <= mx)
            break;
        mx *=2;
    }
    for (int i = 0; i < mx-sz; ++i)
        arr.push_back(0);
    return arr;
}