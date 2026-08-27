#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    
    int a,b;
    a = b = 0;
    
    for (char &c : s){
        if(tolower(c) == 'p')
            ++a;
        else if(tolower(c) == 'y')
            ++b;
    }
    
    return a == b ? true : false;
}