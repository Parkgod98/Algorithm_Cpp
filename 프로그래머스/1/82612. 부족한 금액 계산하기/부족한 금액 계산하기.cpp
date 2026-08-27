#include <algorithm>
#include <cmath>

using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = (((long long)price + price *count)*count)/2;
    
    long long ans = max((long long)0,sum-money);

    return ans;
}