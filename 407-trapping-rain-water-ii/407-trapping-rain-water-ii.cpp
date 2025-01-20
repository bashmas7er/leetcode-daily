class Cell {
public:
    int height;
    int x;
    int y;

    Cell(int height, int x, int y): height(height), x(x), y(y) {}

    // for min Heap
    bool operator<(const Cell& other) const {
        return height >= other.height;
    }
};

bool isValidCell(int row, int col, int numOfRows, int numOfCols) {
    return row >= 0 && col >= 0 && row < numOfRows && col < numOfCols;
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int ROW = heightMap.size();
        int COL = heightMap[0].size();

        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

        priority_queue<Cell> boundary;

        for (int r = 0; r < ROW; r++) {
            boundary.push(Cell(heightMap[r][0], r, 0));
            boundary.push(Cell(heightMap[r][COL - 1], r, COL -1));

            visited[r][0] = true;
            visited[r][COL - 1] = true;
        }

        for (int c = 1; c < COL - 1; c++) {
            boundary.push(Cell(heightMap[0][c], 0, c));
            boundary.push(Cell(heightMap[ROW - 1][c], ROW - 1, c));

            visited[0][c] = true;
            visited[ROW - 1][c] = true;
        }

        int directions[4][2] = {
            {0,-1},
            {0, 1},
            {-1, 0},
            {1, 0}
        };

        int water = 0;
        while(!boundary.empty()) {
            Cell curr = boundary.top(); boundary.pop();
            int minHeight = curr.height;
            int row = curr.x;
            int col = curr.y;

            for (auto [i, j]: directions) {
                i = i + row;
                j = j + col;

                if (!isValidCell(i, j, ROW, COL) || visited[i][j]) continue;

                int nbrHeight = heightMap[i][j];

                if (nbrHeight < minHeight) {
                    water += minHeight - nbrHeight;
                }

                boundary.push(Cell( max(nbrHeight, minHeight), i, j));
                visited[i][j] = true;
            }

        }

        return water;
    }
};