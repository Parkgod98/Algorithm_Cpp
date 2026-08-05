#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> solution(vector<string> strArr) {
    int sz = strArr.size();
    
    for (int i = 0; i < sz; ++i){
        if(i%2 == 1){
            for (char &c : strArr[i]){
                c = toupper(c);
            }
        }
        else{
            for (char &c : strArr[i]){
                c = tolower(c);
            }
        }
    }
    return strArr;
}