class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        int cntFresh = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0}); // 1. Fix: q.push aur double braces {{}}
                }
                else if(grid[i][j] == 1) {
                    cntFresh++;
                }
            }
        }
        
        int delrow[4] = {-1, 0, +1, 0};
        int delcol[4] = {0, +1, 0, -1};
        int tm = 0;
        
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm, t); 
            q.pop();
            
            for(int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                    grid[nrow][ncol] = 2; // 2. Fix: Single '=' for assignment
                    q.push({{nrow, ncol}, t + 1}); // 3. Fix: q.push aur double braces {{}}
                    cntFresh--; // 4. Fix: Fresh count kam karna zaroori tha!
                }
            }
        }
        
        if(cntFresh != 0) {
            return -1;
        }
        return tm;
    }
};