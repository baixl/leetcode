/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * Hard (24.93%)
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 说明:
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 
 * 示例 1:
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 输入:
 * s = "aa"
 * p = "a*"
 * 输出: true
 * 解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 示例 3:
 * 输入:
 * s = "ab"
 * p = ".*"
 * 输出: true
 * 解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 示例 4:
 * 输入:
 * s = "aab"
 * p = "c*a*b"
 * 输出: true
 * 解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 示例 5:
 * 输入:
 * s = "mississippi"
 * p = "mis*is*p*."
 * 输出: false
 * 
 */

// @lc code=start

/*
解题思路：
1、当pattern中无*时， 比较简单，只需要看当前的字符是否匹配即可
2、当pattern中有*时， 就变得比较复杂：

动态规划：
定义：dp[i][j]比表示s前i个字符能否被p的前j个字符匹配
转移方程：即dp[i][j] 如何由 dp[i-1][j-1]变换而来
这时需要考虑s[i] 和p[j]的情况：

1、考虑最简单的情况： s[i] == p[j] ==> dp[i][j] = dp[i-1][j-1]
2、p[j] == '.'; : dp[i][j] = dp[i-1][j-1]

3、当p[j] == "*"时， 情况就比较复杂了:
*可以配零个或多个前面的字符， 而能否匹配需要看前一个位置j-1 是否和s[i]匹配。
    3.1、p[j-1] != s[i]:
        即j-1位置和i不匹配，此时让* 匹配0个前面的字符:dp[i][j] = dp[i][j-2]
    3.2、p[j-1] == s[i] 或者 p[j-1] == '.': 
        可以让*代表0个字符 或多个字符， （如果p[j-1]为'.'就可以替换为s[i]的字符）
        1）* 取0个字符：
            例子：s:aab,p:aabb*,虽然j-1和i相等，但是dp[i][j-2]已经匹配了，直接删去j-1和j-2即可（你来之前我们就已经是总冠军了）

            dp[i][j] = dp[i][j-2]
        2）* 取1个字符：
            例子：s:aab,p:aab*
            dp[i][j] = dp[i][j-1] (取1个字符，相当于去掉p[j]的*)
        3） * 取多个字符
            例子：s：aabb,p：aab*,要判断的是s:aab和aab* 是否可以匹配，如果可以匹配的话，那么s后面再加上一个b也没关系，因为*可以变成多个b。

            dp[i][j] = dp[i-1][j] (取多个字符)

最后来个归纳：
如果 p.charAt(j) == s.charAt(i) : dp[i][j] = dp[i-1][j-1]；
如果 p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1]；
如果 p.charAt(j) == '*'：
如果 p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2] //in this case, a* only counts as empty
如果 p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.'：
dp[i][j] = dp[i-1][j] //in this case, a* counts as multiple a
or dp[i][j] = dp[i][j-1] // in this case, a* counts as single a
or dp[i][j] = dp[i][j-2] // in this case, a* counts as empty
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        // if(s.empty() && (p.empty() || p[0] =='.' || p[0]== '*') return true;
        if (p.empty()) return s.empty();
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<bool>> dp(s_size+1, vector<bool>(p_size+1, false));
       
        dp[0][0] = true;
        if (s_size!=0 && (p[0] == s[0] || p[0] == '.')) dp[1][1] =  true;
        if (p[0] == '*') dp[0][1]=true;

        //初始化情况：
        for(auto i = 1; i< p_size; i++) {
            if (p[i] == '*' && dp[0][i-1] == true) {
                dp[0][i+1] = true; 
            }  
        }

        for (auto i = 0; i < s_size; i++) {
            for (auto j = 1; j < p_size; j++) {
                if (p[j] == '.' || p[j] == s[i]) {
                    dp[i+1][j+1] = dp[i][j];
                } else if (p[j] == '*') {
                    if (p[j-1] != s[i] && p[j-1] != '.') {
                        dp[i+1][j+1] = dp[i+1][j-1];
                    } else {
                        dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j-1]||dp[i + 1][j];
                    }
                    
                }
            }
        }

        return dp[s_size][p_size];
    }
};
// @lc code=end

