#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;
void solve(){
    string s, t;
    cin >> s >> t;
    ll cost = 0;
    vector<int> mask[26];
    forn(s_cur, s.length()){
        mask[s[s_cur] - 'a'].em(s_cur+1);
    }
    int prev_index = -1;
    forn(t_cur, t.length()){
        int index = -1;
        vector<int> loc_arr = mask[t[t_cur] - 'a'];
        if (loc_arr.size() == 0){
            cout << -1 << endl;
            return;
        }

        if(prev_index == -1){
            index = loc_arr[0];
            cost += index;
        }
        else{
            int passive_index = -1;
            auto search = upper_bound(loc_arr.begin(), loc_arr.end(), prev_index);
            if(search == loc_arr.end()){
                index = loc_arr[0];
                cost += (s.length() - prev_index + index);
            }
            else{
                index = *search;
                cost += (index - prev_index);
            }
        }
        prev_index = index;
    }
    cout << cost << endl;
}

int main(){ 
    solve();
    return 0;
}