#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> v(2,0);
    
    int len = board[0]/2;
    int len2 = board[1]/2;
    cout << len << " " << len2 << "\n";
    
    for (string &s : keyinput){
        if(s == "left"){
            if(v[0] == -len)
                continue;
            v[0]--;
        }
        else if(s == "right"){
            if(v[0] == len)
                continue;
            v[0]++;
        }
        else if(s == "up"){
            if(v[1] == len2)
                continue;
            v[1]++;
        }
        else{
            if(v[1] == -len2)
                continue;
            v[1]--;
        }
    }
    

    return v;
}