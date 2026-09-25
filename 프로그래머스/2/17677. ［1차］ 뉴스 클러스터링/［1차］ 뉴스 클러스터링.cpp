#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solution(string str1, string str2) {
    
    
    
    int sz1 = str1.size();
    map<string,int> mp1;
    for (int i = 0; i < sz1-1; ++i){
        if(isalpha(str1[i]) && isalpha(str1[i+1])){
            str1[i] = tolower(str1[i]);
            str1[i+1] = tolower(str1[i+1]);
            mp1[str1.substr(i,2)]++;
        }
    }
    
    int sz2 = str2.size();
    map<string,int> mp2;
    for (int i = 0; i < sz2-1; ++i){
        if(isalpha(str2[i]) && isalpha(str2[i+1])){
            str2[i] = tolower(str2[i]);
            str2[i+1] = tolower(str2[i+1]);
            mp2[str2.substr(i,2)]++;
        }
    }
    
    int common = 0;
    int plus = 0;
    for (auto &it : mp1){
        if(mp2.find(it.first) != mp2.end()){
            if(mp2[it.first] < mp1[it.first]){
                plus += mp1[it.first];
                common += mp2[it.first];
            }
            else{
                plus += mp2[it.first];
                common += mp1[it.first];
            }
        }
        else{
            plus += mp1[it.first];
        }
    }
    
    for (auto &it : mp2){
        if(mp1.find(it.first) == mp1.end()){
            plus += mp2[it.first];
        }
    }
    
    int ans = 0;
    if(mp1.size() == 0 && mp2.size() == 0)
        ans = 1 * 65536;
    else
        ans = ((double)common/plus) * 65536;
    return ans;
}