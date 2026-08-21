#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    
    for (vector<int> &v : queries){
        int s = v[0];
        int e = v[1];
        
        int len = (e-s+1);
        for (int i = 0; i < len/2; ++i){
            char tmp = my_string[i + s];
            my_string[i+s] = my_string[s + len -i - 1];
            my_string[s + len -i - 1] = tmp;
        }
    }
    return my_string;
}