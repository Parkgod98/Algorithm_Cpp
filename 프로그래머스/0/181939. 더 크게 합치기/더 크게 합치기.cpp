#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    vector<int> a_list;
    vector<int> b_list;
    
    while(a != 0){
        a_list.push_back(a%10);
        a/=10;
    }
    while(b != 0){
        b_list.push_back(b%10);
        b /=10;
    }
    
    int n1,n2;
    n1 = n2 = 0;
    
    for (int i = a_list.size()-1; i >= 0; --i){
        n1 = n1*10 + a_list[i];
    }
    for (int i = b_list.size()-1; i >=0; --i){
        n1 = n1*10 + b_list[i];
    }
    for (int i = b_list.size()-1; i >= 0; --i){
        n2 = n2*10 + b_list[i];
    }
    for (int i = a_list.size()-1; i >=0; --i){
        n2 = n2*10 + a_list[i];
    }
    
    return n1 >= n2 ? n1 : n2;
}