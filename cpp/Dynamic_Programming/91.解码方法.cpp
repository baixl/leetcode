/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * Medium (22.98%)
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
     /*
    有点像爬楼梯
    使用动态规划数组dp[i]表示到当前位置时，节能有的编码总数
    由于A-Z的字母，映射成数字后，最多有两位，所以dp[i] 只和的dp[i-1] 和dp[i-2]有关
    若s[i] == '0' 
        且s[i-1]!= '1' && s[i-1] !='2' return 0;
        否则 dp[i] = dp[i-2] // 当前两位只能是10或者20
    若s[i-1] == '1'  dp[i] = dp[i-1] + dp[i-2]
    若s[i-1] == '2' 
        s[i] == '1' 到 '6' , dp[i]= dp[i-1] + dp[i-2]
        否则，dp[i] = dp [i-1]
        
        
    */
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0')  return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0]=1, dp[1] = 1;
        for (auto i = 2; i <= s.size(); i++) {
            if (s[i-1] != '0') {  // s[i-1]为当前位置，若当前位置不为0， 则说明当前位置可以单独成为一个编码
                dp[i] += dp[i-1];
            }
            
            if (s[i-2] == '1'|| (s[i-2] == '2' && s[i-1]<='6')) {
                dp[i] += dp[i-2];
            }
        }
        return dp[dp.size()-1];
    }
};
// @lc code=end

