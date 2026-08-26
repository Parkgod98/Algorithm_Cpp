#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> ans;
    

    int visited[10] = {0};
    for (char &c : my_string){
        if(isdigit(c))
            visited[c-'0']++;
    }
    
    for (int i = 0; i < 10; ++i){
        while(visited[i] != 0){
            ans.push_back(i);
            visited[i]--;
        }
    }
    return ans;
}