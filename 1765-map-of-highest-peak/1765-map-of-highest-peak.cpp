class Solution {
    enum {
        UNVISITED = -1,
        LAND = 0,
        WATER = 1
    };
    int directions[4][2] = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1}
    };
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int ROW = isWater.size();
        int COL = isWater[0].size();
        vector<vector<int>> heights(ROW, vector<int>(COL, UNVISITED));

        queue<pair<int, int>> cells;

        // add all water cells
        for(int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (isWater[i][j] == WATER) {
                    heights[i][j] = 0;
                    cells.push({i, j});
                }
            }
        }

        // start BFS and increase height by 1 for neighboring cells
        while(!cells.empty()) {
            auto [r, c] = cells.front(); cells.pop();
            int height = heights[r][c];

            for(auto [i, j]: directions) {
                i += r;
                j += c;

                if (i < 0 || j < 0 || i >= ROW || j >= COL || heights[i][j] != UNVISITED) continue;

                heights[i][j] = height + 1;
                cells.push({i, j});
            }
        }

        return heights;
    }
};