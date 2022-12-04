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
    int n;
    cin >> n;
    int limit = 1000000000;
    int ma = limit;
    int mi = 1;
    
    int l = 1;
    int r = limit;
    int al = 1;
    int ar = limit-n;

    bool flag = false;
    bool higher = false;
    bool lower = false;
    int min_sum, max_sum, goal;
    while(l <= r && r >= l){
        higher = false;
        lower = false;
        ma = l + (r-l)/2;
        al = 1;
        ar = ma-n;
        while(al <= ar && ar >= al){
            mi = al + (ar-al)/2;
            goal = (ma-mi)*(ma-mi);
            min_sum = ((((2*mi)+n-2)*(n-1))/2) + ma;
            max_sum = ((((2*ma)-n+2)*(n-1))/2) + mi;
            if(goal > max_sum){
                al = mi+1;
                lower = true;
            }
            else if(goal < min_sum){
                ar = mi-1;
                higher = true;
            }
            else{
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
        if(lower){
            r = ma-1;
        }
        else if(higher){
            l = ma+1;
        }
    }
    
    int addition = goal - min_sum;
    forn(i, n){
        if(i==0){
            cout << mi << " ";
        }
        else if(i == (n-1)){
            cout << ma << endl;
        }
        else{
            if(addition){
                int lim = ma-mi-(2*i);
                int addit = min(lim, addition);
                cout << mi+i+addit << " ";
                addition -= addit;
            }
            else{
                cout << mi+i << " ";
            }
        }
    }

    //cout << mi << " " << ma << " " << min_sum << " " << max_sum << " " << goal << endl;
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
