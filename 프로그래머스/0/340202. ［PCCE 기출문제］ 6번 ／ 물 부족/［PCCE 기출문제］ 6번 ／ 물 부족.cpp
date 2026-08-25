#include <string>
#include <vector>

using namespace std;

int solution(int storage, int usage, vector<int> change) {
    int total_usage = 0;
    for(int i=0; i<change.size(); i++){
        usage = usage * (1 + (double)change[i] / 100.0);
        total_usage += usage;
        if(total_usage > storage){
            return i;
        }
    }
    return -1;
}