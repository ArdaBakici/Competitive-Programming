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
    int prev_index = -1;
    forn(t_cur, t.length()){
        int index = -1;
        for(int s_cur = (prev_index == -1) ? 0 : prev_index; s_cur < s.length(); s_cur++){
            if(t[t_cur] == s[s_cur]){
                index = s_cur+1;
                break;
            }
        }
        if(index == -1){
            for(int s_cur = 0; s_cur < prev_index; s_cur++){
                if(t[t_cur] == s[s_cur]){
                    index = s_cur+1;
                    break;
                }
            }
            if (index == -1){
                cout << -1 << endl;
                return;
            }
        }
        if(prev_index == -1){
            cost += (ll)index;
        }
        else if(index > prev_index){
            cost += (ll)(index - prev_index);
        }
        else{
            cost += (ll)(s.length() - prev_index + index);
        }
        prev_index = index;
    }
    cout << cost << endl;
}

int main(){ 
    solve();
    return 0;
}