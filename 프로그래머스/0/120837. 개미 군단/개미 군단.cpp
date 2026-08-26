#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int res = 0;
    res += hp/5;
    hp %= 5;
    res += hp/3;
    hp %= 3;
    res += hp;
    return res;
}