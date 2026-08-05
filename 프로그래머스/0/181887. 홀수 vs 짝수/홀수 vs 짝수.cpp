#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) { 
    int sum1,sum2;
    sum1 = sum2 = 0;
    int sz = num_list.size();
    for (int i = 0; i < sz; ++i){
        if(i%2 == 1)
            sum1 += num_list[i];
        else
            sum2 += num_list[i];
    }
    return sum1 > sum2 ? sum1 : sum2;
}