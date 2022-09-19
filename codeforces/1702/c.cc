/**

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

**/

#include <iostream>
#include <vector>

#define forn(i, n) for(int i = 0; i<n; i++)
#define em emplace_back

using namespace std;

int main()
{
    int case_num;
    cin >> case_num;
    forn(i, case_num){
        int num_of_stations;
        int num_of_quaries;
        cin >> num_of_stations;
        cin >> num_of_quaries;
        vector<int> stations;
        vector<pair<int, int>> quaries;
        vector<int> res_array;

        forn(y, num_of_stations){
            int input = 0;
            cin >> input;
            stations.em(input);
        }

        forn(z, num_of_quaries){
            int a, b;
            cin >> a;
            cin >> b;
            pair<int, int> quary(a, b);
            quaries.em(quary);
            res_array.em(0);
        }

        /*for(vector<pair<int, int>>::iterator it = quaries.begin(); it != quaries.end(); it++){
            bool flag = false;
            int last_index;
            for(last_index = 0; last_index < stations.size(); last_index++){
                pair<int, int> t_pair = *it;
                //cout << "T pair " << t_pair.first << "iter " << stations[last_index] << endl;
                flag = (t_pair.first == stations[last_index]);
                if (flag) break;
            }
            if(!flag){
               cout << "NO" << endl;
               continue;
            }
            else{
                for(;last_index < stations.size(); last_index++){
                    pair<int, int> t_pair = *it;
                    //cout << "T pair " << t_pair.first << "iter " << stations[last_index] << endl;
                    flag = (t_pair.second == stations[last_index]);
                    if (flag) break;
                }
                if(flag) cout << "YES" << endl; else cout << "NO" << endl;
            }
        }*/

        for(vector<int>::iterator it = stations.begin(); it != stations.end(); it++){
            forn(q, quaries.size()){
                if (res_array[q] == 0){
                    res_array[q] = (quaries[q].first == *it) ? 1:0;
                }
                else if (res_array[q] == 1){
                    res_array[q] = (quaries[q].second == *it) ? 2:1;
                }
            }
        }

        for(vector<int>::iterator it = res_array.begin(); it != res_array.end(); it++){
            if (*it == 2){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}