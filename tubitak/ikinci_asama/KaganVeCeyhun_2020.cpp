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
    int n, q;
    cin >> n >> q;
    string arr;
    cin >> arr;
    vector<pair<int, int>> nums(q+1);
    nums[0].first = 0;
    nums[0].second = 0;
    for(auto x:arr){
        if(x == '1'){
            nums[0].first++;
        }
        else{
            nums[0].second++;
        }
    }

    vector<set<int>> delta(q+1, set<int>());
    
    forn(i, q){
        int day, x, value;
        cin >> day >> x >> value;

        
        set<int> vals = delta[day];
        int n1 = nums[day].first;
        int n0 = nums[day].second;

        auto it = delta[day].lower_bound(x);
        //arda karatay
        if(it == delta[day].end()){
            if(value!=(arr[x-1]-'0')){
                if(value == 1){
                    n0--; n1++;
                }
                else{
                    n0++; n1--;
                }
                vals.insert(x);
            }
        }
        else{
            if(value != !arr[x-1]){
                if(value == 1){
                    n0--; n1++;
                }
                else{
                    n0++; n1--;
                }
                vals.erase(x);
            }
        }

        delta[i+1] = vals;
        nums[i+1] = {n1, n0};
        if(n0 == n1){
            out("EVET");
        }
        else{
            out("HAYIR");
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
