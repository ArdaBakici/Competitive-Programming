#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int h, w;
    cin >> h >> w;


    vi ssize(w, 0);
    vi shsize(h, 0);
    vi tsize(w, 0);
    vi thsize(h, 0);

    forn(i, h){
        string input;
        cin >> input;
        forn(x, w){
            if(input[x] == '#'){
                ssize[x]++;
                shsize[i]++;
            }
        }
    }

    forn(i, h){
        string input;
        cin >> input;
        forn(x, w){
            if(input[x] == '#'){
                tsize[x]++;
                thsize[i]++;
            }
        }
    }

    forn(i, h){
        if(thsize[i] != shsize[i]){
            out("No");
            return;
        }
    }

    sort(iter(tsize));
    sort(iter(ssize));

    forn(i, w){
        if(tsize[i] != ssize[i]){
            out("No");
            return;
        }
    }

    out("Yes");
}

int32_t main(){
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
