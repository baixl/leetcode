class Solution {
   public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> res;
        if (A.empty()) return res;
        for (auto i = 0; i < A.size(); i++) {
            vector<int> cur_vec;
            for (auto j = A[i].size() - 1; j >= 0; j--) {
                cur_vec.push_back(abs(A[i][j]-1));
            }
            res.push_back(cur_vec);
        }
        return res;
    }
};