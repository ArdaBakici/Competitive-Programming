#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define forn(i, n) for(int i = 0; i < n; i++)
#define em emplace_back

using namespace std;

bool find(vector<vector<int>> l, pair<int, int> start, vector<vector<bool>> visited, vector<int> prev){
    pair<int, int> loc;
    //cout << "Start is " << start.first << ", " << start.second << endl;
    forn(i, 4){
        vector<int> copy_prev = prev;
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
        //cout << "Here " << loc.first << ", " << loc.second << endl;
        if(loc.first >= 0 && loc.second >= 0 && l[loc.first][loc.second] != 0 && !visited[loc.first][loc.second]){
            //cout << "But here ? " << loc.first << ", " << loc.second << endl;
            // avaiable
            copy_prev.push_back(i);
            if(l[loc.first][loc.second] == -2){
                cout << "YES" << endl;
                cout << copy_prev.size() << endl;
                for(auto el:copy_prev){
                    switch (el)
                    {
                    case 0:
                        cout << "L";
                        break;
                    case 1:
                        cout << "R";
                        break;
                    case 2:
                        cout << "U";
                        break;
                    case 3:
                        cout << "D";
                        break;
                    }
                }
                cout << endl;
                return true;
            }
            visited[loc.first][loc.second] = true;
            if(find(l, {loc.first, loc.second}, visited, copy_prev)) return true;
        }
    }
    return false;
}

void solve(){
    int h, w;
    pair<int, int> start_loc;
    pair<int, int> end_loc;
    cin >> h >> w;
    vector<vector<bool>> visited;
    visited.resize(h);
    vector<int> prev;
    forn(i, h){
        forn(x, w){
            visited[i].push_back(false);
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
    visited[start_loc.first][start_loc.second] = true;
    if (!find(l, start_loc, visited, prev)) cout << "NO" << endl;
}

int main(){
    solve();
    return 0;
}