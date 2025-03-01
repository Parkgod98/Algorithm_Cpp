#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    bool IsTrue = 0;
    do{
        IsTrue = false;
        answer++;
        for (int i = 0; i < arr.size(); ++i){
            if (arr[i]%2 ==0 && arr[i] >=50){
                arr[i]/=2;
                IsTrue = true;
            }
            else if (arr[i] < 50 && arr[i]%2 == 1){
                arr[i] = arr[i]*2 + 1;
                IsTrue = true;
            }
        }
    }while(IsTrue);
    return --answer;
}