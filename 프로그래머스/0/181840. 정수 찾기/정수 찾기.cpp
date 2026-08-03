#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list, int n) {
    for (int &k : num_list){
        if(k == n)
            return 1;
    }
    return 0;
}