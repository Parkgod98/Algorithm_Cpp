#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int sz = citations.size();
    
    sort(citations.begin(),citations.end()); // NlogN
    int mx = citations[sz-1];
    vector<int> prefix_sum(mx+1,0); // N
    
    for (int &n : citations) // N
        prefix_sum[n]++;
    
    for (int i = mx; i >=0; --i){
        if(i!=mx)
            prefix_sum[i] = prefix_sum[i] + prefix_sum[i+1];
    }
    
    // for (int i = 0; i <= mx; ++i){
    //     cout << "i " << i << "이상인 논문 갯수 : " << prefix_sum[i] << "\n";
    // }
    int i = 0; // 제일 작은값
    int j = mx; // 제일 큰값
    int mid = (i+j)/2;
    
    while(i!=mid){
        if(prefix_sum[mid] == mid){ // mid이상의 인용수가 동일할떄
            i = mid;
            mid = (i+j)/2;
        }
        else if(prefix_sum[mid] < mid){ // mid이상 인용된 논문수가 mid보다 작아
            j = mid;
            mid = (i+j)/2;
        } 
        else{ // mid이상 인용된 논문 수가 mid보다 커! // 더키워보자. 계속 커질떄까지.
            i = mid;
            mid = (i+j)/2;
        }
    }
    
    return mid;
}