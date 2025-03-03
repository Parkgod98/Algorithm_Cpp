#include <cmath>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr)
{
    vector<vector<int>> answer;

    int size=max(arr.size(), arr[0].size());
    vector<vector<int>> temp(size, vector<int>(size, 0));
    for(int i=0; i<arr.size(); i++)
        for(int j=0; j<arr[i].size(); j++)
            temp[i][j]=arr[i][j];
    answer=temp;

    return answer;
}