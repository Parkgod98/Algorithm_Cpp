#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int idx = string::npos;
    int locate = 0;
    char c[3] = {'+','-','*'};
    
    for (int i = 0; i < 3; ++i){
        if(binomial.find(c[i]) != string::npos){
            locate = binomial.find(c[i]);
            idx = i;
            break;
        }
    }

    int num1 = stoi(binomial.substr(0,locate));
    int num2 = stoi(binomial.substr(locate+2));
    
    if(idx == 0)
        return num1 + num2;
    else if(idx == 1)
        return num1 - num2;
    return num1*num2;
}