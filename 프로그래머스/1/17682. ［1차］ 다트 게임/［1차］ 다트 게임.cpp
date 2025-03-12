#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define CANT -9999999


int solution(string dartResult) {
     vector<int> score(3);

     int idx = 0;
     char prev = ' ';
     for(int i = 0; i < dartResult.size(); ++i) {
          if(isdigit(dartResult[i])) {
               int n = 0;
               while(isdigit(dartResult[i])) {
                    n = (dartResult[i] - '0')  + n*10;
                    i++;
               }
               i--;
               score[idx] = n;
          }
          else if(isalpha(dartResult[i])) {
               switch(dartResult[i]) {
               case 'S':
                    break;
               case 'D':
                    score[idx] = score[idx] * score[idx];
                    break;
               case 'T':
                    score[idx] = score[idx] * score[idx] * score[idx];
                    break;
               }
               idx++;
          }
          else {
               if(dartResult[i] == '*') {
                    if(idx == 1) // 첫 트라이에 나옴
                    {
                         score[idx - 1] *= 2;
                    }
                    else {
                         score[idx - 2] *= 2;
                         score[idx - 1] *= 2;
                    }

               }
               else if(dartResult[i] == '#') {
                    score[idx - 1] *= -1;
               }
               prev = dartResult[i];
          }
     }
     int ans = 0;
     for(int i = 0; i < score.size(); ++i) {
          ans += score[i];
     }
     return ans;
}