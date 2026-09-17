#include <string>
#include <vector>
#include <map>

using namespace std;
map<string,int> mp;
char arr[5] = {'A','E','I','O','U'};

int solution(string word) {
    int cnt = 0;
    
    string s = "";
    for (int i = 0; i < 5; ++i){
        s.push_back(arr[i]);
        ++cnt;
        mp[s] = cnt;
        for (int j = 0; j < 5; ++j){
            s.push_back(arr[j]);
            ++cnt;
            mp[s] = cnt;
            for (int k = 0; k < 5; ++k){
                s.push_back(arr[k]);
                ++cnt;
                mp[s] = cnt;
                for (int y = 0; y < 5; ++y){
                    s.push_back(arr[y]);
                    ++cnt;
                    mp[s] = cnt;
                    for (int x = 0; x < 5; ++x){
                        s.push_back(arr[x]);
                        ++cnt;
                        mp[s] = cnt;
                        s.pop_back();
                    }
                    s.pop_back();
                }
                s.pop_back();
            }
            s.pop_back();
        }
        s.pop_back();
    }
    return mp[word];
}