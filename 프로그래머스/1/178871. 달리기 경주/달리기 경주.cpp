#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string,int> name_to_idx;
    for (int i = 0; i < players.size(); ++i){
        name_to_idx[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); ++i){
        int cur_rank = name_to_idx[callings[i]];
        string prev = players[cur_rank-1];
        
        swap(players[cur_rank],players[cur_rank-1]);
        
        name_to_idx[callings[i]]--;
        name_to_idx[prev]++;

    }

    return players;
}