#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    
    int i = 0;
    int j = people.size()-1;
    
    int ans = 0;
    while(i < j){
        int a = people[i];
        int b = people[j];
        
        if(a + b <= limit){
            ++ans;
            ++i;
            --j;
        }
        else{
            ++ans;
            --j;
        }
    }
    if(i==j)
        ++ans;
    
    return ans;
}