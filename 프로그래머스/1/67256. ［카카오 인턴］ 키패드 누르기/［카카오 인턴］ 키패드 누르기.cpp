#include <string>
#include <vector>

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

using namespace std;

string solution(vector<int> numbers, string hand) {
    string ans = "";
    
    int ly = 3;
    int lx = 0;
    int ry = 3;
    int rx = 2;
    
    for (int &n : numbers){
        if(n == 1 || n == 4 || n == 7){
            ans += "L";
            if(n == 1)
                ly = 0;
            else if(n == 4)
                ly = 1;
            else if(n == 7)
                ly = 2;
            lx = 0;
        }
        else if(n == 3 || n == 6 || n == 9){
            ans += "R";
            if(n == 3)
                ry = 0;
            else if(n == 6)
                ry = 1;
            else if(n == 9)
                ry = 2;
            rx = 2;
        }
        else{
            if(n == 2){
                int ldis = abs(ly - 0) + abs(lx - 1);
                int rdis = abs(ry - 0) + abs(rx - 1);
                
                if(ldis < rdis){
                    ly = 0;
                    lx = 1;
                    ans += "L";
                }
                else if(ldis > rdis){
                    ry = 0;
                    rx = 1;
                    ans += "R";
                }
                else{
                    if(hand == "left"){
                        ly = 0;
                        lx = 1;
                        ans += "L";
                    }
                    else{
                        ry = 0;
                        rx = 1;
                        ans += "R";
                        
                    }
                }
            }
            else if(n == 5){
                int ldis = abs(ly - 1) + abs(lx - 1);
                int rdis = abs(ry - 1) + abs(rx - 1);
                if(ldis < rdis){
                    ly = 1;
                    lx = 1;
                    ans += "L";
                    
                }
                else if(ldis > rdis){
                    ry = 1;
                    rx = 1;
                    ans += "R";
                    
                }
                else{
                    if(hand == "left"){
                        ly = 1;
                        lx = 1;
                        ans += "L";
                        
                    }
                    else{
                        ry = 1;
                        rx = 1;
                        ans += "R";
                        
                    }
                }
            }
            else if(n == 8){
                int ldis = abs(ly - 2) + abs(lx - 1);
                int rdis = abs(ry - 2) + abs(rx - 1);
                if(ldis < rdis){
                    ly = 2;
                    lx = 1;
                    ans += "L";
                    
                }
                else if(ldis > rdis){
                    ry = 2;
                    rx = 1;
                    ans += "R";
                    
                }
                else{
                    if(hand == "left"){
                        ly = 2;
                        lx = 1;
                        ans += "L";
                        
                    }
                    else{
                        ry = 2;
                        rx = 1;
                        ans += "R";
                        
                    }
                }
            }
            else{
                int ldis = abs(ly - 3) + abs(lx - 1);
                int rdis = abs(ry - 3) + abs(rx - 1);
                if(ldis < rdis){
                    ly = 3;
                    lx = 1;
                    ans += "L";
                    
                }
                else if(ldis > rdis){
                    ry = 3;
                    rx = 1;
                    ans += "R";
                    
                }
                else{
                    if(hand == "left"){
                        ly = 3;
                        lx = 1;
                        ans += "L";
                        
                    }
                    else{
                        ry = 3;
                        rx = 1;
                        ans += "R";
                        
                    }
                }
            }
        }
    }
    return ans;
}