#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double sum = 0;
    for (int &n : arr)
        sum += n;
    sum /= (int)arr.size();
    return sum;
}