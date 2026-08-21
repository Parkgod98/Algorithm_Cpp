#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    int mode = -1;
    if(n >= m)
        mode = 0;
    else if(n <= m)
        mode = 1;
    else if(n > m)
        mode = 2;
    else
        mode = 3;
    
    if(ineq == ">" && (mode == 0 || mode == 2)){
        if(eq == "!" && (n == m))
            return 0;
        return 1;
    }
    else if(ineq == "<" && (mode == 1 || mode == 3)){
        if(eq == "!" && (n == m))
            return 0;
        return 1;
    }
    if(n == m && eq == "=")
        return 1;
    return 0;
}