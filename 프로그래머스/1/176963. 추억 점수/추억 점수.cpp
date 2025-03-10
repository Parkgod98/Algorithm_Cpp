#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


vector<int> solution( vector<string> name, vector<int> yearning, vector<vector<string>> photo ) {
    map<string, int> score_map;
    vector<int> ans;
    ans.reserve( photo.size() );
    for( int i = 0; i < name.size(); ++i ){
        score_map[name[i]] = yearning[i];
    }
    for( vector<string>& v : photo ){
        int sum = 0;
        for( string& s : v ){
            if( score_map.find( s ) != score_map.end() ){
                sum += score_map[s];
            }
        }
        ans.emplace_back( sum );
    }
    return ans;
}