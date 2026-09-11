#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> A, vector<int> B)
{

    int cnt1[1001] = { 0 };
    int cnt2[1001] = { 0 };

    int sz = A.size();
    for (int i = 0; i < sz; ++i) {
        cnt1[A[i]]++;
        cnt2[B[i]]++;
    }

    int i = 0;
    int j = 1000;
    
    int ans = 0;
    while (i < 1001 && j >= 0) {
        while (cnt1[i] == 0)
            ++i;
        while (cnt2[j] == 0)
            --j;

        while (i >=0 && j >= 0 && cnt1[i] > 0 && cnt2[j] > 0) {
            ans += (i * j);
            cnt1[i]--;
            cnt2[j]--;
        }
    }
    
    return ans;
}