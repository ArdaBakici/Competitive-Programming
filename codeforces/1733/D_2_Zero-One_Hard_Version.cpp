#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back
#define iter(i) i.begin(),i.end()

using namespace std;

void solve(){
    string a, b;
    int n, x, y;

    cin >> n >> x >> y;
    cin >> a >> b;
    
    vector<int> diff;
    priority_queue<pair<int, pair<int, int>>> que;
    int prev_index = -1;
    forn(i, a.length()){
        if(a[i] != b[i]){
            diff.push_back(i);
            if(prev_index != -1){
                que.push({prev_index - i, {prev_index, i}});
            }
            prev_index = i;
        }
    }

    if(diff.size()%2){
        cout << -1 << endl;
        return;
    }

    bool flag_a = x < y; // use x when avaible
    bool flag_b = !flag_a && x < 2*y; // use y but when consecutive use y
    ll ans = 0;
    vector<bool> visited(n);
    fill(iter(visited), false);

    if(flag_a){
        bool flag_c = true;
        int removedx = 0;
        while(!que.empty() && flag_c){
            pair<int, pair<int, int>> elem = que.top();
            que.pop();
            int dist = -1 * elem.first;
            int prev_index = elem.second.first;
            int next_index = elem.second.second;
            if(visited[prev_index] || visited[next_index]){
                continue;        
            }
            visited[prev_index] = true;
            visited[next_index] = true;
            if(dist*x < y){
                ans += (ll)dist*x;
                removedx++;
            }
        }
        ans += (ll)(((diff.size()/2) - removedx) * y);
    }
    else{
        forn(index, diff.size()/2){
        int comp = diff[(diff.size()/2) + index];
        int i = diff[index];
        if((comp - i) == 1){
            if(flag_b){
                ans += (ll)x;
            }
            else{
                ans += (ll)2*y;
            }
        }
        else{
            ans += (ll)y;
        }
    }
    }
    
    cout << ans << endl;
}

int main(){
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