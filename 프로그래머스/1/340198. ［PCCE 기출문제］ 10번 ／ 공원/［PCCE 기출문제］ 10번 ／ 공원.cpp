#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    sort(mats.begin(),mats.end());
    
    
    for (int i = mats.size()-1; i >= 0; --i){
        int w = mats[i];
        
        
        for (int r = 0; r +w<= park.size(); ++r){
            for (int c = 0;c +w <= park[0].size(); ++c){
                
                
                bool f = true;
                for (int rr = r; rr < r+w; ++rr){
                    for (int cc=c; cc < c + w; ++cc){
                        if(park[rr][cc] != "-1"){
                            f = false;
                            break;
                        }
                    }
                    if(!f)
                        break;
                }
                if(f)
                    return w;
            }
        }
    }
    
    return -1;
    
}