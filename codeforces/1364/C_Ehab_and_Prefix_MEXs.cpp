#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for(int i = 0; i < n; i++)
#define fornn(i, n) for(int i = 1; i <= n; i++)
#define iter(i) i.begin(),i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout<<(x)<<endl

using namespace std;

void solve(){
    int n;
    cin >> n;
    vi a;
    vi values;

    forn(i, n){
        int input;
        cin >> input;
        a.pb(input);
    }

    values.pb(a[0]);
    forn(i, n){
        if(values.back() != a[i]){
            values.pb(a[i]);
        }
        
        if(a[i] > i+1){
            out(-1);
            return;
        }
    }

    int pt = 0;
    int index = 0;
    int in = 0;
    bool flag = false;

    while(index < n){
        if(index > 0 && a[index] != a[index-1]){
            cout << a[index-1] << " ";
            index++;
            continue;
        }

        while(in < values.size() && values[in] <= pt){
            if(pt == values[in]){
                flag = true;
                break;
            }
            else in++;
        }

        if(flag){
            flag = false;
            pt++;
            continue;
        }

        cout << pt << " ";
        pt++;
        index++;
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
