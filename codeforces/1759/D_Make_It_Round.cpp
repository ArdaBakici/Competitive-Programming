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
    int n, m;
    cin >> n >> m;
    int f = 0;
    int t = 0;
    int ans = 1;
    int tmp = n;
    while(!(tmp%2)){
        tmp /= 2;
        t++;
    }
    tmp = n;
    while(!(tmp%5)){
        tmp /= 5;
        f++;
    }

    if(t > f){
        t = t-f;
        f = 0;
    }
    else{
        f = f - t;
        t = 0;
    }

    while(f > 0 && (ans*2) <= m){
        ans *= 2;
        f--;
    }

    while(t > 0 && (ans*5) <= m){
        ans *= 5;
        t--;
    }

    int index = 10;
    while(index > 1){
        if((ans*index) <= m){
            ans *= index;
        }
        else{
            index--;
        }
    }

    out(ans*n);
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
