class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> tmp = matrix;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[j][row-1-i] = tmp[i][j];
            }
        }
    }
};