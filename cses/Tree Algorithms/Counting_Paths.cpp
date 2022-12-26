#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> v[1000000];
int sum[1000000];
int depth[1000000];
int up[1000000][31];

int lift(int a,int value){
    for(int i = 0;i <= 30;i++){
        if(value & (1 << i)){
            a = up[a][i];
        }
    }
    return a;
}

        
void dfs0(int a,int p,int d){
    depth[a] = d;
    for(int i =1;i <= 30;i++){
        up[a][i] = up[up[a][i-1]][i-1]; //binary lifting
    }
    for(auto z:v[a]){
        if(z == p)continue;
        // go through all nodes except ancestor
        up[z][0] = a; // lift 0 is ancestor
        dfs0(z,a,d+1); // call with more depth
    }
}

int lca(int a,int b){
    if(depth[a] < depth[b])swap(a,b); // make sure a is deeper in the tree
    a = lift(a,depth[a] - depth[b]); // is ancestor check
    if(a == b) return a;
    for(int i = 30;i >= 0;i--){ // if no than go through
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

void dfs1(int a,int p){
    for(auto z:v[a]){
        if(z == p)continue;
        dfs1(z,a);
        sum[a] += sum[z];
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i =0;i < n-1;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // call dfs on root with ancestor of root
    dfs0(1,1,0);
    // got binary lifting and depths
    while(m--){
        int p,q;
        cin >> p >> q;
        // take quaries
        sum[p] += 1;
        sum[q] += 1;
        int l = lca(p,q); // find lca
        sum[l] += -1; // lca negative -1
        sum[up[l][0]] += -1; // parent of lca is also -1
    }
    dfs1(1,1);
    for(int i =1;i <= n;i++){
        cout << sum[i] << " ";
    }
    cout << endl;
}
signed main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}