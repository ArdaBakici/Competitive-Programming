#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<vi> subsets(n);
    vector<vi> matrix(n);

    forn(i, n){
        subsets[i].pb(i+1);
        string s;
        cin >> s;
        forn(x, n){
            int input;
            input = s[x] - '0';
            if(input){
                subsets[x].pb(i+1);
            }
        }
    }

    for(auto i: subsets){
        cout << i.size();
        for(auto x:i){
            cout << " " << x; 
        }
        cout << endl;
    }

    /*
    forn(i, n){
        subsets[i].pb(i+1);
        forn(x, n){
            int input;
            cin >> input;
            matrix[i].pb(input);
        }
    }
    */
}

int32_t main(){
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
