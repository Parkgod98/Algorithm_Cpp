#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define UPPER 10000000


/*
가장 큰 약수를 찾아주면 됨.
배열은 begin ~ end까지. end-begin + 1의 사이즈를 가지는 배열을 만들어주면되고.
인덱스에는 의미를 부여하지말자. 헷갈리기만 할것.

도로 길이는 10억인데.
블록은 천만까지 나오니까.
가장 큰 약수가 천만 초과일 수는 없음.
천만 이하이면서 가장 큰 약수를 찾아줘야 함.

1. 원하는 사이즈의 vector<int> ans 배열을 만들어 주고 싶음.
2. end부터 begin까지 떨어지면서 나의 약수중에 천만 이하이면서 가장 큰 약수를 채워넣어 주면 될거 같음
그럼 이제 내가 해결해야 할건 하나.
나의 약수중에 천만 이하이면서 가장 큰 약수는 어떻게 찾을까?

가장 러프하게 생가해보면
그냥 O(N)으로 떨어지면서 찾으면됨.
그러면 근데 N억번 이상 연산을 해야겠네. 몇번? end - begin + 1번.
이건 안돼.
약수를 찾는 다른 방법이 있나?
있지.
for (int i = 1; i* i <= n; ++i)
이렇게해서 찾으면되고.
약수는 짝을 지어서 나오기 때문에
이떄 위쪽 짝이 1천만 이하이면 그냥 바로 적으면 됨.
*/

long long GetDiv(long long n){
    
    int ans = 1;
    for (long long i = 2; i * i <= n; ++i){
        if(n%i == 0){
            if(n/i <= UPPER)
                return n/i;
            
            ans = i;
        }
    }
    
    return ans;
}
vector<int> solution(long long begin, long long end) {
    vector<int> ans(end - begin +1, 0);
    
    for (int i = end; i >= begin; --i){
        ans[i-begin] = GetDiv(i);
    }
    if(begin == 1)
        ans[0] = 0;

    
    return ans;
}