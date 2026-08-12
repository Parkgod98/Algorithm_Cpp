#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    int arr[102] = {0};
    for (int &i : indices)
        arr[i] = 1;
    
    for (int i = 0; i < my_string.size(); ++i){
        if(arr[i] == 0)
            answer += my_string[i];
    }
    return answer;
}