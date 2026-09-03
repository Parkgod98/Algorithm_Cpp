#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    vector<int> st;
    int answer = 0;

    for (int n : ingredient) {
        st.push_back(n);

        int sz = st.size();

        if (sz >= 4 &&
            st[sz - 4] == 1 &&
            st[sz - 3] == 2 &&
            st[sz - 2] == 3 &&
            st[sz - 1] == 1) {

            for (int i = 0; i < 4; ++i)
                st.pop_back();

            ++answer;
        }
    }

    return answer;
}