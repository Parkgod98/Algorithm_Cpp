#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lcd(int a, int b){
    while(a%b != 0){
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return b;
}

int solution(int n) {
    return n/lcd(n,6);
}