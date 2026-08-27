#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int arr1[26] = {0};
    int arr2[26] = {0};
    for (char &c : s){
        if(islower(c))
            arr1[c-'a']++;
        else
            arr2[c-'A']++;
    }
    
    string ans = "";
    for (int i = 25; i >=0; --i){
        
        while(arr1[i]-- > 0)
            ans += (i+'a');
    }
    for (int i = 25; i >=0; --i){
        while(arr2[i]-- >0)
            ans += (i+'A');
    }
    return ans;
}