#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string letter) {
    string answer = "";
    map<string, string> morse = {
    {".-", "a"},
    {"-...", "b"},
    {"-.-.", "c"},
    {"-..", "d"},
    {".", "e"},
    {"..-.", "f"},
    {"--.", "g"},
    {"....", "h"},
    {"..", "i"},
    {".---", "j"},
    {"-.-", "k"},
    {".-..", "l"},
    {"--", "m"},
    {"-.", "n"},
    {"---", "o"},
    {".--.", "p"},
    {"--.-", "q"},
    {".-.", "r"},
    {"...", "s"},
    {"-", "t"},
    {"..-", "u"},
    {"...-", "v"},
    {".--", "w"},
    {"-..-", "x"},
    {"-.--", "y"},
    {"--..", "z"}
    };
    
    string word = "";
    for(char &c : letter){
        if(c == ' '){
            answer += morse[word];
            word.clear();
            continue;
        }
        word +=c;
    }
    answer += morse[word];

    return answer;
}