/*
给出两个字符串，找到最长公共子串，并返回其长度。
样例
样例 1:
	输入:  "ABCD" and "CBCE"
	输出:  2
	解释:
	最长公共子串是 "BC"
样例 2:
	输入: "ABCD" and "EACB"
	输出:  1
	解释: 
	最长公共子串是 'A' 或 'C' 或 'B'
挑战
O(n x m) time and memory.
注意事项
子串的字符应该连续的出现在原字符串中，这与子序列有所不同。

如果 str1 的长度为 N，str2 的长度为 M，生成大小为 N*M 的 数组 dp , dp[i][j]表示 str1[0…N] 与 str2[0…M] 的
最长公共子串的长度。
dp[i][j]计算方式（状态转移方程）：
dp第1列dp[0...n-1][0]：对于某个位置(i, 0) 如果str1[i] == str2[0], 则dp[i][0] = 1, 否则 dp[i][0]=0
dp第1行dp[0][0…m-1]：对于某个位置(0, j) 如果str1[0] == str2[j], 则dp[0][j] = 1, 否则 dp[0][j]=0
其他位置：
若 str1[I] == str2[j] , dp[i][j] = dp[i-1][j-1] + 1
若 str1[I] ！= str2[j]， dp[i][j] =0
str1=“abc",str2=“caba"的 dp 矩阵如下:
    a　  b　　c
c　　0　　0　　1
a　　1　　0　　0
b　　0　　2　　0
a　　1　　0　　0
最终结果为 dp数组中的最大值
 */
class Solution {
public:

    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        if (A.size()==0 || B.size() ==0) {
            return 0;
        }
        
        vector<vector<int>> dp(A.size(), vector<int>(B.size(), 0));
        
        int result = INT_MIN;
        // 第1列
        for(auto i=0; i<A.size(); i++) {
            if (A[i] == B[0]) {
                dp[i][0] = 1;
                result = max(dp[i][0], result);
            }
        }
        // 第1行
        for(auto j=0; j<B.size(); j++) {
            if (A[0] == B[j]) {
                dp[0][j] =1;
                result = max(dp[0][j], result);
            }
        }
        
        for(auto i=1; i<A.size(); i++) {
            for(auto j =1; j<B.size(); j++) {
                if (A[i] ==B[j]) {
                    dp[i][j]= dp[i-1][j-1] +1;
                    result = max(dp[i][j], result);
                } 
            }
        }
        
        return result;
        
    }
};