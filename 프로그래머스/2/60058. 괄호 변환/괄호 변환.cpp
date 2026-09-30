#include <string>
#include <vector>

using namespace std;

string DFS(string &p){
    
    if(p == "")
        return "";
    
    int sum = 0;
    
    bool uflag = true;
    for (int i = 0; i < p.size(); ++i){
        if(p[i] == '('){
            ++sum;        
        }
        else if(p[i] == ')')
            --sum;
        
        if(sum < 0)
            uflag = false;
        
        if(sum == 0){
            
            string u = p.substr(0,i+1);
            string v = p.substr(i+1);
            
            if(uflag)
                return u + DFS(v);
            string n = "(";
            
            u = u.substr(1);
            u.pop_back();
            for (char &c : u){
                if(c == '(')
                    c = ')';
                else
                    c = '(';
            }
            return n + DFS(v) + ")" + u;
        }
    }
}

string solution(string p) {
    
    return DFS(p);
}