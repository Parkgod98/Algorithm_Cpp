#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int t = bandage[0];
    int heal = bandage[1];
    int bonus_heal = bandage[2];
    
    int hp = health;
    
    int prev = 0;
    for (vector<int> &at : attacks){
        int time = at[0];
        int damage = at[1];
        cout << time << " " << hp << "\n";
        
        hp = min(health,hp+(time-prev-1)*heal + (time-prev-1 >= t ? bonus_heal*((time-prev-1)/t) : 0));
        cout << time << " " << hp << "\n";
        
        prev = time;
        hp -= damage;
        if(hp <= 0)
            return -1;
        cout << time << " " << hp << "\n";
        
    }
    
    if(hp <= 0)
        return -1;
    return hp;
}