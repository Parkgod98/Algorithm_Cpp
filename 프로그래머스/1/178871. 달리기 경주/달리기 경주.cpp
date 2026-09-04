#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string,int> name_to_idx;
    map<int,string> idx_to_name;
    for (int i = 0; i < players.size(); ++i){
        name_to_idx[players[i]] = i+1;
        idx_to_name[i+1] = players[i];
    }
    
    for (int i = 0; i < callings.size(); ++i){
        int cur_rank = name_to_idx[callings[i]];
        int next_rank = cur_rank - 1;
        string scur = callings[i];
        string nx = idx_to_name[next_rank];
        
        name_to_idx[scur] = next_rank;
        name_to_idx[nx] = cur_rank;
        idx_to_name[cur_rank] = nx;
        idx_to_name[next_rank] = scur;
    }
    
    vector<string> ans(players.size());
    
    for (auto &it : name_to_idx){
        ans[it.second-1] = it.first;
    }
    return ans;
}