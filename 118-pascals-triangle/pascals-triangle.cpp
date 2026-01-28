class Solution {
public:
    int ncr(int n, int r) {
        int res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int row = 1; row <= numRows; row++) {
            vector<int> temp;
            for (int col = 1; col <= row; col++) {
                int v = ncr(row - 1, col - 1);
                temp.push_back(v);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};