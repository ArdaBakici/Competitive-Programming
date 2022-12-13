#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define INF 1000000000000000000
#define forn(i, n) for (int i = 0; i < n; i++)
#define fornn(i, n) for (int i = 1; i <= n; i++)
#define iter(i) i.begin(), i.end()
#define pb push_back
#define endl "\n"
#define vi vector<int>
#define p(x) array<int, x>
#define out(x) cout << (x) << endl

using namespace std;

vector<vi> dp;
vector<bool> switches;
vector<vector<bool>> visited;
vector<vector<p(2)>> adj;

int dfs(int v, int p)
{
    if (dp[v][p] != -1)
        return dp[v][p];

    visited[v][p] = true;
    if (switches[v])
        visited[v][!p] = true;
    int ans = INT_MAX;
    for (auto [nv, np] : adj[v])
    {
        if (visited[nv][np])
            continue;
        if (np == p)
        {
            ans = min(dfs(nv, np), ans);
        }
        else if (switches[v])
        {
            ans = min(dfs(nv, np), ans);
        }
    }
    if (ans != INT_MAX)
        ans++;
    dp[v][p] = ans;
    return dp[v][p];
}

int solve1(int vn, int vm, int vk, vector<p(3)> vinput, vi input2)
{
    int n, m, k;
    n = vn;
    m = vm;
    k = vk;
    adj = vector<vector<p(2)>>(n);
    switches = vector<bool>(n, false);
    dp = vector<vi>(n, vi(2, -1));
    visited = vector<vector<bool>>(n, vector<bool>(2, false));

    forn(i, m){
        int v1, v2, p;
        v1 = vinput[i][0];
        v2 = vinput[i][1];
        p = vinput[i][2];
        v1--; v2--;
        adj[v1].pb({v2, p});
        adj[v2].pb({v1, p});
    }

    forn(i, k){
        int input;
        input = input2[i];
        input--;
        switches[input] = true;
    }

    dp[n-1][0] = 0;
    dp[n-1][1] = 0;

    int res = dfs(0, 1);

    if(res >= INT_MAX){
        return -1;
    }

    return res;
}

int solve2(int vn, int vm, int vk, vector<p(3)> vinput, vi input2){
    typedef pair<int, int> edge;
    int n, m, k;
    vector<edge> G[1000];
    int dist[1000];
    n = vn;
    m = vm;
    k = vk;
    int u, v, a, s;
    for (int i = 1; i <= m; i++){
        u = vinput[i-1][0];
        v = vinput[i-1][1];
        a = vinput[i-1][2];
        if (a)
            G[u].push_back(edge(v, 1)), G[v].push_back(edge(u, 1));
        else
            G[n + u].push_back(edge(n + v, 1)), G[n + v].push_back(edge(n + u, 1));
    }

    for (int i = 1; i <= k; i++){
        s = input2[i-1];
        G[s].push_back(edge(n + s, 0)), G[n + s].push_back(edge(s, 0));
    }

    deque<int> deq;
    deq.push_back(1);
    for (int i = 1; i <= 2 * n; i++)
        dist[i] = 10e9;
    
    dist[1] = 0;

    while (deq.size()){
        int v = deq.front();
        deq.pop_front();
        for (int i = 0; i < (int)G[v].size(); i++){
            int u = G[v][i].first, c = G[v][i].second;
            if (dist[u] > dist[v] + c){
                dist[u] = dist[v] + c;
                if (c == 0)
                    deq.push_front(u);
                else
                    deq.push_back(u);
            }
        }
    }

    int ans = min(dist[n], dist[2 * n]);
    if (ans == (int)10e9)
        ans = -1;
    return ans;
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ans1 = 0, ans2 = 0, n1, m1, k1;

    // Write limits to below
    int limitn = 4;
    // int limitn = 4, limita = (1 << 2);

    vector<p(3)> input1;
    vi input2;
    srand(time(0));
    while (ans1 == ans2)
    {
        n1 = (rand() % limitn) + 2;
        m1 = (rand() % limitn) + 1;
        k1 = rand() % (n1 + 1);

        input1 = vector<p(3)>(m1);
        forn(i, m1){
            input1[i][0] = (rand() % n1) + 1;
            input1[i][1] = (rand() % n1) + 1;
            while(input1[i][1] == input1[i][0]) input1[i][1] = (rand() % n1) + 1;
            input1[i][2] = (rand() % 2);
        }
        input2 = vi(k1);

        forn(i, k1){
            input2[i] = (rand() % n1) + 1;
        }

        ans2 = solve2(n1, m1, k1, input1, input2);
        ans1 = solve1(n1, m1, k1, input1, input2);
    }
    cout << n1 << " " << m1 << " " << k1 << endl;
    forn(i, m1){
        cout << input1[i][0] << " " << input1[i][1] << " " << input1[i][2] << endl;
    }

    for(auto x: input2){
        cout << x << " ";
    }
    /*out("Wrong in case : ");
    cout << "N is : " << n1 << endl;
    cout << "Input is:" << endl;
    for (auto x : input1)
        cout << x << " ";*/
    cout << endl;
    cout << "Judge Output: " << ans2 << endl;
    cout << "User Output: " << ans1 << endl;
    return 0;
}
