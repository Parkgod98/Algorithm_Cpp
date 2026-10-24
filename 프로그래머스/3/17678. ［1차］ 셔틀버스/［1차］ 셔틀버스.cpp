#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (string &s : timetable) {
        int time = stoi(s.substr(0, 2)) * 60
                 + stoi(s.substr(3, 2));
        pq.push(time);
    }

    int late_time = 0;

    for (int i = 0; i < n; ++i) {
        int bus_time = 540 + i * t;
        int cnt = 0;
        int last = -1;

        while (!pq.empty() && pq.top() <= bus_time && cnt < m) {
            last = pq.top();
            pq.pop();
            ++cnt;
        }

        // 마지막 버스에서만 결정
        if (i == n - 1) {
            if (cnt < m)
                late_time = bus_time;
            else
                late_time = last - 1;
        }
    }

    string h = to_string(late_time / 60);
    string mi = to_string(late_time % 60);

    if (h.size() == 1) h = "0" + h;
    if (mi.size() == 1) mi = "0" + mi;

    return h + ":" + mi;
}