#include <string>
#include <vector>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    
    int first,second,third;
    first = second = third = -1;
    
    for (int i = 0; i < rank.size(); ++i){
        if(!attendance[i])
            continue;
        
        if(first == -1 || rank[i] < rank[first]){
            third = second;
            second = first;
            first = i;
        }
        else if(second == -1 || rank[i] < rank[second]){
            third = second;
            second = i;
        }
        else if(third == -1 || rank[i] < rank[third]){
            third = i;
        }
    }
    
    return first * 10000 + second *100 + third;
}