#include <string>
#include <vector>
#include <algorithm>

using namespace std;


long long Calc(long long a, long long b, char op){
    if(op == '+'){
        return a + b;
    }
    else if(op == '-'){
        return a-b;
    }
    else{
        return a*b;
    }
}

long long solution(string expression) {
    vector<long long> v;
    vector<char> op_list;
    
    vector<char> op = {'+','*','-'};
    sort(op.begin(),op.end());
    
    int sum = 0;
    for(char &c : expression){
        if(isdigit(c)){
            sum = sum*10 + (c - '0');
        }
        else{
            v.push_back(sum);
            sum = 0;
            op_list.push_back(c);
        }
    }
    v.push_back(sum);
    
    
    long long mx = 0;
    do{
        
        vector<long long> num_list = v;
        vector<char> o_list = op_list;
        
        for(char tar : op){
            int i = 0;
            
            while(i < o_list.size()){
                if(o_list[i] == tar){
                    long long res = Calc(num_list[i],num_list[i+1],o_list[i]);
                    
                    num_list[i] = res;
                    num_list.erase(num_list.begin()+i+1);
                    o_list.erase(o_list.begin()+i);
                }
                else{
                    ++i;
                }
            }
        }
        mx = max(mx,llabs(num_list[0]));
        
    }while(next_permutation(op.begin(),op.end()));
    
    return mx;
}