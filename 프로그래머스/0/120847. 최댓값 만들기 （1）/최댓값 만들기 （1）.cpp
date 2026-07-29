#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int first, second;
    first = -1;
    second = -2;
    
    for (int &n : numbers){
        if(n > first){
            second = first;
            first = n;
        }
        else if(n <= first && n > second){
            second = n;
        }
    }
    return first * second;
}