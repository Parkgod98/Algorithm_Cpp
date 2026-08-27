#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    
    int tar = n -1;
    for (int i = 2; i * i <= tar; ++i){
        if(tar%i == 0)
            return i;
    }
}