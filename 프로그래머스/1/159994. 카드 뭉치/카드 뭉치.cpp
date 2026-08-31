#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int cur1 = 0;
    int cur2 = 0;

    for (string& word : goal) {
        if (cur1 < cards1.size() && cards1[cur1] == word) {
            ++cur1;
        }
        else if (cur2 < cards2.size() && cards2[cur2] == word) {
            ++cur2;
        }
        else {
            return "No";
        }
    }

    return "Yes";
}