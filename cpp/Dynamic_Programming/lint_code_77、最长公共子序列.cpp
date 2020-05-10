class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        if (A.size()==0 || B.size() ==0) {
            return 0;
        }
        
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        int result = INT_MIN;
        // 第1列
        for(auto i=0; i<A.size(); i++) {
            if (A[i] == B[0]) {
                dp[i][0] = 1;
                if (result == INT_MIN) {
                    result =1;
                }
            
            }
        }
        // 第1行
        for(auto j=0; j<B.size(); j++) {
            if (A[0] == B[j]) {
                dp[0][j] =1;
                if (result == INT_MIN) {
                    result =1;
                }
            }
        }
        for(auto i=1; i<A.size(); i++) {
            for(auto j =1; j<B.size(); j++) {
                if (A[i] ==B[j]) {
                    dp[i][j]= dp[i-1][j-1] +1;
                    result = max(dp[i][j], result);
                } else {
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                    result = max(dp[i][j], result);
                }
            }
        }
        return result;
    }

};