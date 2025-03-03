#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> str_list) {
     vector<string> answer;
     int l_idx = find(str_list.begin(), str_list.end(), "l") - str_list.begin();
     int r_idx = find(str_list.begin(), str_list.end(), "r") - str_list.begin();
     if (l_idx == string::npos && r_idx == string::npos)
          return answer;
     if (l_idx < r_idx) {
          return vector<string>(str_list.begin(), str_list.begin() + l_idx);
     }
     else if (l_idx > r_idx) {
          return vector<string>(str_list.begin() + r_idx + 1, str_list.end());
     }
     return answer;
}