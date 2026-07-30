#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int res = 0;
    for (int &nn : array){
        if(nn == n)
            res++;
    }
    return res;
}