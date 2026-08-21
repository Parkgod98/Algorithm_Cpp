#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer;
    
    vector<int> arr(52,0);
    
    for (char &c : my_string){
        if(isupper(c)){
            arr[c-'A']++;
        }
        else if(islower(c)){
            arr[c-'a'+26]++;
        }
    }
    return arr;
}