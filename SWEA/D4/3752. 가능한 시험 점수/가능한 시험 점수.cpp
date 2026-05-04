#include <iostream>
#include <bitset>
 
using namespace std;
 
bitset<10001> possible;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T;
    cin >> T;
 
    for (int t = 1; t <= T; t++)
    {
        int N;
        cin >> N;
 
        possible.reset();
        possible[0] = 1;
 
        for (int i = 1; i <= N; i++)
        {
            int score;
            cin >> score;
 
            possible = possible | (possible << score);
        }
 
        cout << '#' << t << ' ' << possible.count() << '\n';
    }
 
    return 0;
}