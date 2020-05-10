/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * Medium (51.29%)
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 示例:
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 *
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    回溯法
    */
    unordered_map<char, string> map = {
            {'2',"abc"}, 
            {'3',"def"}, 
            {'4',"ghi"}, 
            {'5',"jkl"}, 
            {'6',"mno"}, 
            {'7',"pqrs"}, 
            {'8',"tuv"}, 
            {'9',"wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;
        string cur_res;
        backtrace(digits, 0, cur_res, res);
        return res;
    }

    void backtrace(string& digits, int index, string& cur, vector<string>& res){
        if (cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }
        string s = map[digits[index]];
        // cout << s <<" " << index <<" --";

        for (auto i = 0; i < s.size(); i++) {
            cur+=s[i];
            index++;
            backtrace(digits, index, cur, res);
            cur.pop_back();
            index--;
        }
    }
};
// @lc code=end
