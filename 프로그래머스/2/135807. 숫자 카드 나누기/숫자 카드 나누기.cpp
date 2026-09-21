#include <string>
#include <vector>
#include <iostream>

using namespace std;

int GetGCD(int a, int b){
    
    while(a%b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcd = arrayA[0];
    int gcd2 = arrayB[0];
    for (int i = 0; i < arrayA.size(); ++i){
        gcd = GetGCD(arrayA[i],gcd);
        gcd2 = GetGCD(arrayB[i],gcd2);
    }
    
    bool a = true;
    bool b = true;
    for (int i = 0; i < arrayA.size(); ++i){
        if(arrayB[i]%gcd == 0){
            a = false;
        }
        if(arrayA[i]%gcd2 == 0){
            b = false;
        }
    }
    cout << gcd << " " << gcd2 << "\n";
    
    
    if(!a && !b)
        return 0;
    else if(a && !b)
        return gcd;
    else if(!a && b)
        return gcd2;
    return max(gcd,gcd2);

}