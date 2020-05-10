/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：

拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：

输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：

输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 异常条件
        if (s.empty() || wordDict.empty()) return false;

        vector<bool> dp(s.size(), false);  // 动态规划数组

        for (auto i = 0; i < s.size(); i++) {
            for (auto j = 0; j < wordDict.size(); j++) {  // 遍历每个单词
                int size = wordDict[j].size();
                if (i < size - 1) continue;

                if (s.substr(i - size + 1, size) == wordDict[j]  //  substr 返回[pos, size]的子串，其中size为子串大小
                    && (i + 1 - size == 0 || dp[i - size] == true)) {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size() - 1];
    }
};