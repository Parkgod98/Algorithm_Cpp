#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string dartResult) {
    int sz = dartResult.size();
    vector<int> score;
    
    int num = 0;
    for (int i = 0; i < sz; ++i){
        char c = dartResult[i];
        if(isdigit(c)){
            num = num*10 + (c-'0');
        }
        else if(c == 'S' || c == 'D' || c == 'T'){
            if(c == 'D')
                num *= num;
            else if(c == 'T')
                num *= (num*num);
            
            score.push_back(num);
            num = 0;
        }
        else if(c == '#'){
            score[score.size()-1] *= -1;
        }
        else if(c == '*'){
            score[score.size()-1] *=2;
            if(score.size() >= 2)
                score[score.size()-2]*=2;
        }
    }
    
    int sum = 0;
    for (int &n : score)
        sum += n;
    return sum;
}