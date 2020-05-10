/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 *
 * https://leetcode-cn.com/problems/simplify-path/description/

 */
class Solution {
   public:
    /*
    以/ 分割  取出每个 // 之间的部分：
    1、若是 .. 则丢弃上一个路径
    2、若是. 则跳过
    3、多个/// 只保留一个
   
    */
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        int size = path.size();
        while (i < size) {
            while (i < size && path[i] == '/') {
                i++;  // 字符串开始的 /
            }
            if (i == size) {
                break;
            }
            int start = i;
            while (i < size && path[i] != '/') {
                i++;
            }
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            cout << s << "     ";
            if (s == "..") {
                if (!v.empty()) {
                    v.pop_back();
                }
            } else if (s == ".") {
                continue;
            } else {
                v.push_back(s);
            }
            i++;
        }

        if (v.empty()) {
            return "/";
        }
        string result;
        for (auto i = 0; i < v.size(); i++) {
            result += '/' + v[i];
        }

        return result;
    }
};
