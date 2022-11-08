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
    string s;
    cin >> s;
    ll res = 0;
    vector<int> prefix(n);
    forn(i, n){
        if(i==0){
            prefix[i] = (int)s[i] - (int)'0';
        }
        else{
            prefix[i] = prefix[i-1] + (int)s[i] - (int)'0';
        }
    }
    forn(i, n){
        for(int x=i; x<n; x++){
            ll pre, suf;
            if(i == 0){
                pre = 0;
            }
            else{
                pre = prefix[i-1];
            }          
            
            suf = prefix[x];
            

            if((x-i+1) == (suf-pre)){
                res++;
            }
        }
    }

    cout << res << endl;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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