#include <string>
#include <vector>

using namespace std;

int solution(vector<string> order) {
    
    int sum = 0;
    for(string &s : order){
        if(s.find("americano") != string::npos){
            sum += 4500;
        }
        else if(s.find("cafelatte") != string::npos){
            sum += 5000;
        }
        else{
            sum += 4500;            
        }
    }
    return sum;
}