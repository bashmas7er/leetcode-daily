class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int ROW = mat.size();
        int COL = mat[0].size();

        vector<int> rowIndices(arr.size());
        vector<int> colIndices(arr.size());

        for(int i = 0; i < ROW; i++){
            for (int j = 0; j < COL; j++) {
                int idx = mat[i][j] - 1; 
                rowIndices[idx] = i;
                colIndices[idx] = j;
            }
        }

        vector<int> rowCount(ROW, 0);
        vector<int> colCount(COL, 0);

        for(int i = 0; i < arr.size(); i++) {
            int rowIdx = rowIndices[arr[i] - 1];
            int colIdx = colIndices[arr[i] - 1];

            rowCount[rowIdx]++;
            colCount[colIdx]++;

            if (rowCount[rowIdx] == COL || colCount[colIdx] == ROW) return i;
        }

        return arr.size();
    }
};