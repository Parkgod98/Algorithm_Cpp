#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> ans;
    
    
    
    
    for (vector<int> &v : balls){
        double x = v[0];
        double y = v[1];
        
        double upper_x = x;
        double upper_y = n + (n-y);
        
        // cout << upper_x << " " << upper_y << "\n";
        
        double lower_x = x;
        double lower_y = -y;
        // cout << lower_x << " " << lower_y << "\n";
        
        
        double right_x = m + (m-x);
        double right_y = y;
        // cout << right_x << " " << right_y << "\n";
        
        double left_x = -x;
        double left_y = y;
        // cout << left_x << " " << left_y << "\n";
        
        double dist1 = ((startX-upper_x)*(startX-upper_x) +(startY-upper_y)*(startY-upper_y));
        double dist2 = ((startX-lower_x)*(startX-lower_x) +(startY-lower_y)*(startY-lower_y));
        double dist3 = ((startX-right_x)*(startX-right_x) +(startY-right_y)*(startY-right_y));
        double dist4 = ((startX-left_x)*(startX-left_x) +(startY-left_y)*(startY-left_y));
    
        
        if(y == startY && x < startX){
            dist4 = 9999999999;
        }
        else if(y == startY && x > startX){
            dist3 = 9999999999;
        }
        if(x == startX && y > startY){
            dist1 = 9999999999;
        }
        else if(x == startX && y < startY){
            dist2 = 9999999999;
        }
        
        // cout << dist1 << " " << dist2 << " " << dist3 << " " << dist4 << "\n";
        
        ans.push_back(min({dist1,dist2,dist3,dist4}));
        
    }
    return ans;
}