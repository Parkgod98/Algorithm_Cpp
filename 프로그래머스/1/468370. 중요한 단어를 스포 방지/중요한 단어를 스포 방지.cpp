#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    set<string> normalWords;
    set<string> spoilerWords;

    int start = 0;

    while (start < message.size()) {
        int end = message.find(' ', start);

        if (end == string::npos)
            end = message.size();

        int wordEnd = end - 1;
        bool isSpoiler = false;

        for (const auto& range : spoiler_ranges) {
            int spoStart = range[0];
            int spoEnd = range[1];

            // 두 구간이 겹친다
            if (!(wordEnd < spoStart || spoEnd < start)) {
                isSpoiler = true;
                break;
            }
        }

        string word = message.substr(start, end - start);

        if (isSpoiler)
            spoilerWords.insert(word);
        else
            normalWords.insert(word);

        start = end + 1;
    }

    int answer = 0;

    for (const string& word : spoilerWords) {
        if (normalWords.find(word) == normalWords.end())
            ++answer;
    }

    return answer;
}