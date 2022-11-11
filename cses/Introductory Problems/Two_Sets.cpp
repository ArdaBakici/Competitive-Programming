#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define out(x) cout<<x<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bool> a(n, false);
    int num = 0;
    int sum = (n*(n+1))/2;
    if(sum%2){
        out("NO");
        return;
    }

    sum /= 2;

    out("YES");

    for(int i=n; i > 0; i--){
        if(sum > i){
            sum -= i;
            a[i-1] = true;
            num++;
        }
        else{
            a[sum-1] = true;
            num++;
            break;
        }
    }

    out(num);

    forn(x, n){
        if(a[x]){
            cout << x+1 << " ";
        }
    }

    cout << endl;

    out(n-num);

    forn(x, n){
        if(!a[x]){
            cout << x+1 << " ";
        }
    }
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