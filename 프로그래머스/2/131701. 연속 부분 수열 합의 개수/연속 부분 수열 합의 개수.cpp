#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    
    set<int> st;
    int sz = elements.size();
    
    for (int k = 1; k < sz; ++k){
        int sum = 0;
        int s = 0;
        int e = k;
        for (int i = s; i < e; ++i)
            sum += elements[i];
        
        while(s < sz){
            st.insert(sum);
            sum -= elements[s];
            s++;
            sum += elements[e];
            e++;
            e%=sz;
        }
    }
    int sum = 0;
    for (int i = 0; i <sz; ++i){
        sum += elements[i];
    }
    st.insert(sum);
    
    return (int)st.size();
}