// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}





class SameColorPairs {
public:
    vector<string> removePairs(vector<string> board) {
        vector<string> ret;
        int H = board.size(), W = board[0].size();
        // find the first pair of horizontally adjacent tiles and remove them
        for (int i = 0; i < H; ++i)
            for (int j = 1; j < W; ++j)
                if (board[i][j] == board[i][j-1]) {
                    ret.push_back(to_string(i) + " " + to_string(j) + " " + to_string(i) + " " + to_string(j-1));
                    ret.push_back("0 2 0 3");
                    //            cout << ret[0] << endl;
                    return ret;
                }
        //            ret.push_back("0 2 0 3");
        for(int i = 0; i < ret.size(); i++){
            cerr << ret[i] << endl;
        }
        return ret;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}


int main() {
    SameColorPairs scp;
    int H;
    cin >> H;
    cerr << H << endl;
    vector<string> board(H);
    getVector(board);
    for (int i = 0; i < board.size(); i++){
        cerr << board[i] << " ";
    }
    cerr << endl;
    vector<string> ret = scp.removePairs(board);
    cerr << ret.size() << endl;
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i){
        cout << ret[i] << endl;
        cerr << ret[i] << " ";
    }
    cerr << endl;
    cout.flush();

    return 0;

}
