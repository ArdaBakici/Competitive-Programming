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

struct dsu{
    int n;
    vi links, size;
    int largest = 1;
    int components;

    dsu(int s){
        n = s;
        links = vi(n);
        size = vi(n, 1);
        forn(i, n){
            links[i] = i;
        }
        components = n;
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(size[b] > size[a]) swap(a, b);

        links[b] = a;
        size[a] += size[b];
        largest = max(size[a], largest);
        components--;
    }

    int find(int a){
        int b = a;
        while(b != links[b]) b = links[b];
        links[a] = b;
        return b;
    }

    bool same(int a, int b){
        return find(a) == find(b);
    }
};

void solve(){
    int n, m;
    cin >> n >> m;

    dsu d = dsu(n);

    forn(i, m){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        d.unite(v1, v2);
        cout << d.components << " " << d.largest << endl;
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
