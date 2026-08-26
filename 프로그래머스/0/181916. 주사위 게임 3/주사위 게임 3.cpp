#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    int visited[7] = {0};
    visited[a]++;
    visited[b]++;
    visited[c]++;
    visited[d]++;
    
    int three = -1;
    int two1 = -1;
    int two2 = -1;
    int x,y,z,w;
    x = y = z = w = -1;
    for (int i = 1; i <= 6; ++i){
        if(visited[i] == 4){
            return 1111*i;
        }
        else if(visited[i] == 3){
            three = i;
        }
        else if(visited[i] == 2){
            if(two1 == -1)
                two1 = i;
            else
                two2 = i;
        }
        else if(visited[i] == 1){
            if(x == -1)
                x = i;
            else if(y == -1)
                y = i;
            else if(z == -1)
                z = i;
            else
                w = i;
        }
    }
    
    if(three != -1){
        cout << three << " " << a << "\n";
        return (10*three + x) * (10*three + x);
    }
    else if(two1 != -1 && two2 != -1)
        return (two1 + two2) * (two1- two2 > 0 ? two1 - two2 : -(two1-two2));
    else if(two1 !=-1 && x!=-1 && y!=-1)
        return x*y;
    return x;
}