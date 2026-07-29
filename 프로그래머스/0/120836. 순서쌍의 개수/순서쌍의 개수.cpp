using namespace std;

int solution(int n) {
    int ans = 0;
    
    for (int i = 1; i * i <= n; ++i){
        if(i*i == n)
            ++ans;
        else if (n%i == 0)
            ans +=2;
    }
    return ans;
}