#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    vector<pair<ll,ll>> c_arr;
    ll health = 0;
    forn(i, n){
        ll input;
        cin >> input;
        if(i == (k-1)){
            health = input;
        }
        arr.pb(input);
    }

    ll prev = 0;

    vector<pair<ll,ll>> c_tmp;
    ll req = 0;
    for(int x = k-2; x >= 0; x--){
        ll cur = prev + arr[x];
        if(prev > 0 && cur < prev){
            c_tmp.pb({prev, req});
            req = 0;
            cur = arr[x];
            prev = cur;
            if(x == 0){
                c_tmp.pb({cur, req});
            }
            continue;
        }
        if(arr[x] < 0){
            req = cur;
        }
        if(x == 0){
            c_tmp.pb({cur, req});
        }
        prev = cur;
    }

    for(int x = c_tmp.size()-1; x>=0;x--){
        c_arr.pb(c_tmp[x]);
    }

    int p_index = c_arr.size();

    c_arr.pb({0, 0});

    prev = 0;
    req = 0;
    for(int x = k; x < n; x++){
        ll cur = prev + arr[x];
        if(prev > 0 && cur < prev){
            c_arr.pb({prev, req});
            req = 0;
            cur = arr[x];
            if(x == (n-1)){
                c_arr.pb({cur, req});
            }
            continue;
        }
        if(arr[x] < 0){
            req = cur;
        }
        if(x == (n-1)){
            c_arr.pb({cur, req});
        }
        prev = cur;
    }

    /*for(auto x:c_arr){
        cout << x.first << " " << x.second << " || ";
    }*/


    bool flag = true;
    int l_index = p_index - 1;
    int r_index = p_index + 1;
    while(flag){
        if(health >= -1*c_arr[l_index].second && l_index > 0){
            health += c_arr[l_index].first;
            l_index--;
        }
        else if(health >= -1*c_arr[r_index].second && r_index < c_arr.size()-1){
            health += c_arr[r_index].first;
            r_index++;
        }
        else{
            flag = false;
        }

        
    }

    if(c_arr[c_arr.size()-1].first >= 0){
        if(health >= -1*c_arr[c_arr.size()-1].second){
            cout << "YES" << endl;
            return;
        }
    }
    else if(health >= -1*c_arr[c_arr.size()-1].first){
        if(health >= -1*c_arr[c_arr.size()-1].second){
            cout << "YES" << endl;
            return;
        }
    }

    if(c_arr[0].first >= 0){
        if(health >= -1*c_arr[0].second){
            cout << "YES" << endl;
            return;
        }
    }else if(health >= -1*c_arr[0].first){
        if(health >= -1*c_arr[0].second){
        cout << "YES" << endl;
        return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    int tt;
    cin >> tt;
    forn(i, tt) solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/