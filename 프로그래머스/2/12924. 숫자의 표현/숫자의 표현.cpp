#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    int i = 1;
    int j = 1;
    int sum = 0;

    int cnt = 0;

    while (1) {
        if (sum == n) {
            ++cnt;
            sum -= i;
            ++i;
        }
        else if (sum < n) {
            sum += j;
            ++j;
        }
        else {
            sum -= i;
            ++i;
        }

        if (j > n + 1)
            break;
    }
    return cnt;
}