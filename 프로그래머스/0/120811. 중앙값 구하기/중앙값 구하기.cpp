#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    
    int visited[2002] = {0};
    
    for (int &n : array){
        visited[n+1000]++;
    }
    int tar = array.size()/2;
    
    for (int i = 0; i < 2002; ++i){
        tar -= visited[i];
        
        if(tar < 0)
            return i-1000;
    }
}