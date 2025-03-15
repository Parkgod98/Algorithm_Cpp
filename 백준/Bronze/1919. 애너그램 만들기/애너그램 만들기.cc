#include <bits/stdc++.h>
using namespace std;

int main(void) {
     ios_base::sync_with_stdio(0);
     cin.tie(0);

     string s1, s2;
     cin >> s1 >> s2;
     vector<int> freq(26, 0);
     vector<int> freq2(26, 0);

     int cnt = 0;
     for(int i = 0; i < s1.size(); ++i)
          ++freq[s1[i] - 'a'];
     for(int i = 0; i < s2.size(); ++i) 
          ++freq2[s2[i] - 'a'];
     for(int i = 0; i < freq.size(); ++i)
          cnt += abs(freq[i]-freq2[i]);
     cout << cnt;

}