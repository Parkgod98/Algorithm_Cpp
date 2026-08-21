#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr) {
    int garo = arr[0].size();
    int sero = arr.size();
    
    if(garo < sero){
        for (vector<int> &v : arr){
            while(v.size() < sero)
                v.push_back(0);
        }
    }
    else if(garo > sero){
        for (int i = 0; i < garo-sero; ++i)
            arr.push_back(vector<int>(garo,0));
    }
    return arr;
}