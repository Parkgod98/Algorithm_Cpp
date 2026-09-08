#include <vector>

using namespace std;

int GetGCD(int a, int b) {
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
}

int solution(vector<vector<int>> signals) {
    int lcm = 1;

    for (const vector<int>& signal : signals) {
        int cycle = signal[0] + signal[1] + signal[2];

        int gcd = GetGCD(lcm, cycle);
        lcm = lcm / gcd * cycle;
    }

    for (int time = 1; time <= lcm; ++time) {
        bool allYellow = true;

        for (const vector<int>& signal : signals) {
            int G = signal[0];
            int Y = signal[1];
            int cycle = signal[0] + signal[1] + signal[2];

            int cur = (time - 1) % cycle;

            if (!(G <= cur && cur < G + Y)) {
                allYellow = false;
                break;
            }
        }

        if (allYellow)
            return time;
    }

    return -1;
}