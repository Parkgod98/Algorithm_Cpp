#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int mul = 1;
    int sum = 0;
    
    for(int &n : num_list){
        mul *= n;
        sum += n;
    }
    sum *= sum;
    
    return mul < sum ? 1 : 0;
}