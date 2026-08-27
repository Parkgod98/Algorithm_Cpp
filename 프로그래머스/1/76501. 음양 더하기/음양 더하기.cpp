#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    
    int sum = 0;
    int sz = (int)signs.size();
    
    for (int i = 0; i < sz; ++i){
        if(signs[i])
            sum += absolutes[i];
        else
            sum += (-absolutes[i]);
    }
    
    return sum;


}