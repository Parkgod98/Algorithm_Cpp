#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    
    int arr[26] = {0};
    
    int sz = choices.size();
    for (int i = 0; i < sz; ++i){
        int c = choices[i];
        
        if(c >= 5){
            c -=4;
            arr[survey[i][1]-'A'] += c;
        }
        else if(c <= 3){
            c = (-c + 4);
            arr[survey[i][0]-'A'] += c;
        }
    }
    
    string ans = "";
    if(arr['R'-'A'] >= arr['T'-'A'])
        ans += 'R';
    else
        ans += 'T';
    if(arr['C'-'A'] >= arr['F'-'A'])
        ans += 'C';
    else
        ans += 'F';
    if(arr['J'-'A'] >= arr['M'-'A'])
        ans += 'J';
    else
        ans += 'M';
    if(arr['A'-'A'] >= arr['N'-'A'])
        ans += 'A';
    else
        ans += 'N';
    return ans;
}