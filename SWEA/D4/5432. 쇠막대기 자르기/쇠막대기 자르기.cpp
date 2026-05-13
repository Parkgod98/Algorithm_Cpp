#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <string>
 
using namespace std;
 
int t;
string cmd;
 
int main(void){
 
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>t;
 
    for(int tc=1;tc<=t;tc++){
 
        cin>>cmd;
        int ans=0;
        int num_of_stick=0;
        int n=cmd.size();
         
        for(int i=1;i<n;i++){
            if(cmd[i]=='('){
                if(cmd[i-1]=='(') num_of_stick++;
            }
            else{
                if(cmd[i-1]=='('){
                    ans+=num_of_stick;
                }
                else{
                    ans+=1;
                    num_of_stick--;
                }
            }
        }
 
        cout<<'#'<<tc<<' '<<ans<<'\n';
    }
 
    return 0;
}