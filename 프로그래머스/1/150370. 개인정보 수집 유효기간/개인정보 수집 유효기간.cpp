#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int ty = stoi(today.substr(0,4));
    int tm = stoi(today.substr(5,2));
    int td = stoi(today.substr(8,2));
    
    int arr[26] = {0};
    
    for (string &s : terms){
        int idx = s.find(' ');
        arr[s[0] - 'A'] = stoi(s.substr(idx+1));
    }
    
    int cnt = 1;
    
    cout << ty << " " << tm << " " << td << "\n";
    for (string &s : privacies){
        int idx = s.find(' ');
        
        int y = stoi(s.substr(0,4));
        int m = stoi(s.substr(5,2));
        int d = stoi(s.substr(8,2));
        char tar = s[idx+1];
        
        m += arr[tar-'A'];
        // 5 6 7 8 9 10 11 12
        if(m%12 != 0){
            y += m/12;
            m%= 12;
        }
        else{
            y += (m/12 - 1);
            m = 12;
        }
        
        --d;
        if(d == 0){
            m--;
            d = 28;
            if(m == 0){
                y--;
                m = 12;
            }
        }
        
        cout << y << " " << m << " " << d << "\n";
        // ty < y, 
        if(ty > y)
            answer.push_back(cnt);
        else if(ty == y && (tm > m))
            answer.push_back(cnt);
        else if(ty == y && tm == m && (td > d))
            answer.push_back(cnt);
        
        ++cnt;
    }
    return answer;
}