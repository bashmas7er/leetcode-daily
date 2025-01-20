class Solution {
    int directions[4][2] = {
        {0, 1}, //RIGHT
        {0, -1}, // LEFT
        {1, 0}, // DOWN
        {-1, 0} // UP
    };
    
    bool isValid(int row, int col, int numRows, int numCols) {
        return row >= 0 && row < numRows && col >= 0 && col < numCols;
    }
    
public:
    int minCost(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>> costs(ROW, vector<int>(COL, INT_MAX));

        deque<pair<int, int>> cells;
        cells.push_front({0,0});
        costs[0][0] = 0;

        while(!cells.empty()) {
            auto [row, col] = cells.front(); cells.pop_front();

            for (int d = 0; d < 4; d++) {
                auto [i, j] = directions[d];
                i = i + row;
                j = j + col;
                int cost = 0;

                if (grid[row][col] != (d+1)) cost++;

                if (!isValid(i, j, ROW, COL) || costs[row][col] + cost >= costs[i][j]) continue;

                costs[i][j] = costs[row][col] + cost;
                
                if (cost) cells.push_back({i, j});
                else cells.push_front({i, j});
            }
        }
        return costs[ROW - 1][COL - 1];
    }
};