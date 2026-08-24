#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(char &c : str){
        if(c >= 'a' && c <= 'z'){
            c -= ('a' - 'A');
        }
        else if(c >= 'A' && c <= 'Z'){
            c += ('a' - 'A');
        }
    }
    
    cout << str << "\n";
    return 0;
}