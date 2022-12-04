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
    int n, x;
    cin >> n >> x;
    
    if(n%x){
        out(-1);
        return;
    }

    vi answer;
    forn(i, n){
        if(i==0){
            answer.pb(x);
        }
        else if(i==n-1){
            answer.pb(1);
        }
        else if(i == (x-1)){
            answer.pb(INT_MAX);
        }
        else{
            answer.pb(i+1);
        }
    }

    int mover = n;
    int change = x-1;

    if(x != n){
        forn(i, n-1){
            if(!(n % (i+1)) && !((i+1) % (change+1))){
                answer[change] = answer[i];
                answer[i] = n;
                change = i;
            }
        }
    }
    
    for(auto x:answer){
        cout << x << " ";
    }
    
    cout << endl;
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
