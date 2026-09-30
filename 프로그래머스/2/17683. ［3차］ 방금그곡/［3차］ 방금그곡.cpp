#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string Convert(string s){
    string ret = "";

    for(int i=0;i<s.size();++i){
        if(i+1 < s.size() && s[i+1]=='#'){
            ret += tolower(s[i]);
            ++i;
        }
        else{
            ret += s[i];
        }
    }

    return ret;
}

string solution(string m, vector<string> musicinfos) {
    string ans = "(None)";
    int mx_len = -1;

    m = Convert(m);

    for(string &s : musicinfos){
        int idx = s.find(',');

        string start = s.substr(0,idx);

        int prev = idx+1;
        idx = s.find(',',prev);
        string end = s.substr(prev,idx-prev);

        prev = idx+1;
        idx = s.find(',',prev);
        string name = s.substr(prev,idx-prev);

        string sequence = s.substr(idx+1);
        sequence = Convert(sequence);

        int sm = stoi(start.substr(0,2))*60 + stoi(start.substr(3,2));
        int em = stoi(end.substr(0,2))*60 + stoi(end.substr(3,2));

        int play_time = em-sm;

        string played = "";

        for(int i=0;i<play_time;++i)
            played += sequence[i%sequence.size()];

        if(played.find(m) != string::npos){
            if(play_time > mx_len){
                mx_len = play_time;
                ans = name;
            }
        }
    }

    return ans;
}