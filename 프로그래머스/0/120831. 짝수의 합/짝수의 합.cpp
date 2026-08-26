using namespace std;

int solution(int n) {
    if(n!=2)
        return ((n/2) * (2 + n))/2;
    return 2;
}