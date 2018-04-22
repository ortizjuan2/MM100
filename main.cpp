// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <ctime>



using namespace std;
#define MAX_NUM_COLORS 6
#define TIME_LIMIT 8.0


template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}

class SameColorPairs {
public:
    vector<vector<pair<int, int> > > columns;
    bool time_out;
    clock_t start_time;
    // constructor actions
    SameColorPairs(){
        columns.resize(MAX_NUM_COLORS);
        time_out = false;
        start_time = clock();
    };
    ~SameColorPairs(){};

    bool check_rectangle(pair<int, int> p1, pair<int, int> p2, vector<string> & board){

       int upper_row = min(p1.first, p2.first);
       int upper_column = min(p1.second, p2.second);
       int lower_row = max(p1.first, p2.first);
       int lower_column = max(p1.second, p2.second);


        for (int i = upper_row; i <= lower_row; i++){
            for (int j = upper_column; j <= lower_column; j++){
                if(board[i][j] != board[p1.first][p1.second]){
                    if(board[i][j] != 'x')
                        return false;
                }
            }

        }
        return true;
    }

    vector<string> removePairs(vector<string> board) {
        vector<string> ret;
        int H = board.size(), W = board[0].size();
        // load columns
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                int indx = board[i][j] - '0';
                columns[indx].push_back(make_pair(i, j));
            }
        }
//
//
//        cerr << "Columns Size: " << columns.size() << endl;
//        for (int i = 0; i< columns.size(); i++){
//            cerr << "column: " << i << endl;
//            for (int j = 0; j < columns[i].size(); j++){
//                cerr << columns[i][j].first << ", " << columns[i][j].second << endl;
//            }
//        }
        bool state_changed = false;
        double sizes = 0;
        while(!time_out){
            for(int i = 0; i < columns.size(); i++){
                state_changed = false;
                for(int j = 0; j < columns[i].size(); j++){
                    for(int k = 0; k < columns[i].size(); k++){
                        if(j != k){
                            bool result = check_rectangle(columns[i][j], columns[i][k], board);
                            if(result){
                                ret.push_back(to_string(columns[i][j].first) + " " + to_string(columns[i][j].second)
                                              + " " + to_string(columns[i][k].first) + " " + to_string(columns[i][k].second));
                                board[columns[i][j].first][columns[i][j].second] = 'x';
                                board[columns[i][k].first][columns[i][k].second] = 'x';

                                columns[i].erase(columns[i].begin()+j);
                                columns[i].erase(columns[i].begin()+k-1);
                                state_changed = true;

                            }


                        }
                        if (state_changed)
                            break;

                    }
                    if (state_changed)
                        break;


                }


            }

            double lapse_time = ( clock() - start_time ) /  CLOCKS_PER_SEC;
            if (lapse_time >= TIME_LIMIT){
                time_out = true;
            }


            sizes = 0;
            for(int n = 0; n < columns.size(); n++)
                sizes += columns[n].size();

            if(sizes == 0) break;


        }






        // find the first pair of horizontally adjacent tiles and remove them
//        for (int i = 0; i < H; ++i)
//            for (int j = 1; j < W; ++j)
//                if (board[i][j] == board[i][j-1]) {
//                    ret.push_back(to_string(i) + " " + to_string(j) + " " + to_string(i) + " " + to_string(j-1));
//                    ret.push_back("0 2 0 3");
//                    //            cout << ret[0] << endl;
//                    return ret;
//                }
//        //            ret.push_back("0 2 0 3");
//        for(int i = 0; i < ret.size(); i++){
//            cerr << ret[i] << endl;
//        }
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
    cerr << "Size of ret: " << ret.size() << endl;
    cout << ret.size() << endl;
    for (int i = 0; i < (int)ret.size(); ++i){
        cout << ret[i] << endl;
        cerr << ret[i] << endl;
    }
    cout.flush();

    return 0;

}
