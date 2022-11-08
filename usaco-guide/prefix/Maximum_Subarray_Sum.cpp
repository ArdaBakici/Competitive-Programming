#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<ll> prefix(n);
    bool all_neg = true;
    forn(i, n){
        ll input;
        cin >> input;
        if(input > 0){
            all_neg = false;
        }
        if(i==0){
            prefix[0] = input;
        }
        else{
            prefix[i] = prefix[i-1] + input;
        }
    }

    if(all_neg){
        ll highest = -1*10e10;
        forn(i, n){
            if(i == 0){
                highest = max(highest, prefix[i]);
            }
            else{
                highest = max(highest, (prefix[i]-prefix[i-1]));
            }
        }
        cout << highest << endl;
        return;
    }

    ll tmp_lowest = 10e10;
    ll lowest=10e10;
    ll highest=-1*10e10;

    for(auto x:prefix){
        tmp_lowest = min(tmp_lowest, x);
        if(x > highest){
            lowest = tmp_lowest;
            highest = x;
        }
    }

    if(lowest<0){
        cout << highest-lowest << endl;
        return;    
    }
    cout << highest << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

/*
* When you get WA:
    - Check for integer overflows
    - Bugs
    - Arrays with uninitialized values
*/