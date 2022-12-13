#include <iostream>
#define _CRT_SECURE_NO_DEPRECATE
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

vi a;
vi visited;
vi cycles;
int cur_branch = 0;
int cur_cycle = 0;
vi branch_origin;
vi sizes;
vi cycle_sizes;

p(2) dfs(int v){
    if(visited[v]){
        if(visited[v] == 1){
            // new discovered
            cur_cycle++;
            cycles[v] = cur_cycle;
            return {v, 0};   
        }
        else if(visited[v] == 2){
            // already discovered this is a branch
            if(cycles[v] > -1){
                // new branch
                cur_branch--;
                return {-1*(v+1), cur_branch};
            }
            else{
                return {branch_origin[v], cycles[v]};
            }
        }
    }

    visited[v] = 1;

    p(2) ans = dfs(a[v]);

    visited[v] = 2;

    sizes[v] = sizes[a[v]]+1;

    if(ans[0] == v){
        // back at node
        cur_branch--;
        cycles[v] = cycles[a[v]];
        cycle_sizes[cycles[v]] = sizes[v];
        return {-1*(v+1), cur_branch};
    }
    else if(ans[0] < 0){
        // branch
        if(cycles[a[v]] > -1){
            sizes[v] = 1;
        }
        branch_origin[-1*cur_branch] = (-1*ans[0])-1;
        cycles[v] = cur_branch;
        return ans;
    }
    else{
        cycles[v] = cycles[a[v]];
        return ans;
    }
}

void solve(){
    int log_max = 20;
    int n, q;
    cin >> n >> q;
    visited = vi(n, 0);
    cycles = vi(n, 0);
    branch_origin = vi(n+1, 0);
    sizes = vi(n, 0);
    cycle_sizes = vi(n+1, 0);
    vector<vi> jump(n, vi(log_max, 0));

    forn(i, n){
        int input;
        cin >> input;
        input--;
        a.pb(input);
    }

    forn(i, n){
        for(int x = 0; x < log_max; x++){
            if(x == 0){
                jump[i][x] = a[i];
                continue;
            }
            jump[i][x] = jump[jump[i][x/2]][x/2];
        }
    }

    forn(i, n){
        if(visited[i]) continue;
        dfs(i);
    }

    forn(i, q){
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;
        // case 1 both v1 and v2 in cycle
        if(cycles[v1] > -1 && cycles[v2] > -1){
            // then both should be in the same cycle
            if(cycles[v1] == cycles[v2]){
                // difference is
                int diff = sizes[v1] - sizes[v2];
                if(diff < 0){
                    diff += cycle_sizes[cycles[v1]];
                }
                out(diff);
                continue;
            }
        }
        // case 2 v1 in branch v2 in cycle
        if(cycles[v1] < 0 && cycles[v2] > -1){
            // then v1 origin should be cycle of v2
            if(cycles[branch_origin[-1*cycles[v1]]] == cycles[v2]){
                // then output is v1 distance to cycle and origin diff v2
                int diff = sizes[branch_origin[-1*cycles[v1]]] - sizes[v2];
                if(diff < 0){
                    diff += cycle_sizes[cycles[v2]];
                }
                out(diff+sizes[v1]);
                continue;
            }
        }
        // case 3 both v1 and v2 in branch
        if(cycles[v1] < 0 && cycles[v2] < 0){
            // then both should be in same branch and v1 should be farther from v2
            if(cycles[v1] == cycles[v2] && sizes[v1] >= sizes[v2]){
                // check if we can reach v1 from v2
                int current = v1;
                int m_j = sizes[v1]-sizes[v2];
                
                for(int f = 0; (1 << f) <= m_j; f++){
                    if(m_j & (1 << f)) current = jump[current][f];
                    //cout << current << " " << sizes[current] << endl;
                }

                //out("test");
                if(current == v2){
                    out(sizes[v1] - sizes[v2]);
                    continue;
                }
            }
        }
        out(-1);
    }
}

int32_t main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
