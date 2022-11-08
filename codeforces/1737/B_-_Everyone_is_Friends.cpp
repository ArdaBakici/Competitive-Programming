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
    int n, m;
    cin >> n >> m;
    ll noi = (n*(n+1))/2;
    
    bool seen[n][n];

    forn(i, n){
        forn(x, n){
            seen[i][x] = false;
        }
    }

    forn(i, m){
        int k;
        int fp;
        cin >> k;
        vector<int> tmp;
        forn(x, k){
            int input;
            cin >> input;
            tmp.pb(input);
        }

        sort(iter(tmp));

        forn(ina, tmp.size()){
            for(int inb = ina; inb < tmp.size(); inb++){
                if(!seen[tmp[ina]-1][tmp[inb]-1]){
                    noi--;
                    seen[tmp[ina]-1][tmp[inb]-1] = true;
                }
            }
        }
    }

    if(noi == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
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