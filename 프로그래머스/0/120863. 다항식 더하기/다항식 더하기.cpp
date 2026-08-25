#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string polynomial) {
    int sum = 0;
    int c = 0;
    
    int sz = polynomial.size();
    
    int num = 0;
    for (int i = 0; i < sz; ++i){
        if(isdigit(polynomial[i])){
            num = num*10 + (polynomial[i] - '0');
        }
        else if(polynomial[i] == 'x'){
            sum += num;
            if(num == 0)
                sum += 1;
            num = 0;
        }
        else if(polynomial[i] == '+'){
            c += num;
            num = 0;
        }
        else
            continue;
    }
    
    if(num !=0)
        c += num;
    
    string ans = "";
    if(sum!=0){
        if(sum == 1)
            ans += "x";
        else
            ans += to_string(sum) +"x";
    }
    if(c != 0){
        if(sum!=0)
            ans += " + ";
        ans += to_string(c);
    }
    
    return ans;
}