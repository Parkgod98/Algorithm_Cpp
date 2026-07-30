#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int a = 0;
    int b = 0;
    for (int &n : num_list){
        if(n%2 == 0){
            a = a*10 + n;
        }
        else
            b = b*10 + n;
    }
    
    return a + b;
}