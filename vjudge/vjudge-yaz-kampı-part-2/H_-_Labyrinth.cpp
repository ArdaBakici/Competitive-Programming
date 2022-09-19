#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

void solve(){
    int h, w;
    pair<int, int> start_loc;
    pair<int, int> end_loc;
    cin >> h >> w;
    vector<vector<pair<int, int>>> visited;
    visited.resize(h);
    queue<pair<int, int>> bfs_q;
    forn(i, h){
        forn(x, w){
            visited[i].push_back({-5, -5});
        }
    }
    vector<vector<int>> l;
    l.resize(h);
    forn(i, h){
        l[i].resize(w);
        string line;
        cin >> line;
        forn(x, w){
            if(line[x] == '#') l[i][x] = 0;
            else if(line[x] == '.') l[i][x] = 1;
            else if(line[x] == 'A') l[i][x] = -1, start_loc.first=i, start_loc.second=x;
            else if(line[x] == 'B') l[i][x] = -2, end_loc.first=i, end_loc.second=x;
        }
    }

    visited[start_loc.first][start_loc.second] = {-1, -1};
    bfs_q.push(start_loc);
    pair<int, int> loc;
    bool flag = true;
    while(!bfs_q.empty() && flag){ //bfs
        pair<int, int> start = bfs_q.front();
        bfs_q.pop();
        forn(i, 4){
            switch (i)
            {
            case 0: // left
                loc = {start.first, start.second-1};
                break;
            case 1: // right
                loc = {start.first, start.second+1};
                break;
            case 2: // top
                loc = {start.first-1, start.second};
                break;
            case 3: // bottom
                loc = {start.first+1, start.second};
                break;
            }
            if(loc.first >= 0 && loc.second >= 0 && loc.first < h && loc.second < w && l[loc.first][loc.second] != 0 && visited[loc.first][loc.second].first == -5 && visited[loc.first][loc.second].second == -5){
                visited[loc.first][loc.second] = start;
                bfs_q.push(loc);
                if(l[loc.first][loc.second] == -2){
                    cout << "YES" << endl;
                    flag = false;
                    break;
                }
            }
        }
    }

    vector<char> ans;

    if(!flag){
        loc = end_loc;
        int index = 0;
        for(index = 0; visited[loc.first][loc.second].first != -1 && visited[loc.first][loc.second].second != -1; index++){
            pair<int, int> prev = visited[loc.first][loc.second];
            int delta_h = loc.first - prev.first;
            int delta_w = loc.second - prev.second;
            if (delta_h == 1){
                ans.push_back('D');
            }
            else if (delta_h == -1){
                ans.push_back('U');
            }

            if (delta_w == 1){
                ans.push_back('R');
            }
            else if(delta_w == -1){
                ans.push_back('L');
            }

            loc = prev;
        }

        cout << index << endl;

        for(int i = ans.size()-1; i >= 0; i--){
            cout << ans[i];
        }
        cout << endl;
    }
    else cout << "NO" << endl; 
}

int main(){
    solve();
    return 0;
}