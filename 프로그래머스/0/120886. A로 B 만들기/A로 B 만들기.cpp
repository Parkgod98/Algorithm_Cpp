#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    int arr[26] ={0};
    int arr2[26] ={0};
    
    for (char &c : before){
        arr[c-'a']++;
    }
    for (char &c : after){
        arr2[c-'a']++;
    }
    for (int i = 0; i < 26; ++i){
        if(arr[i] != arr2[i])
            return 0;
    }
    return 1;
}