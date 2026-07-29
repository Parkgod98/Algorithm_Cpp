#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int res = 0;
    
    for (int &c : array){
        if(c > height)
            ++res;
    }
    return res;
}