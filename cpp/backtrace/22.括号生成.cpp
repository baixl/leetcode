/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <vector>
class Solution {
public:
	// 回溯法
	// 回溯法实现：（DFS）沿着某个方向一直前进，
	//当前方向不通时，则回退上一步，换一个方向前进
	//回溯法的关键：找到递归的出口； 
	//本题的解法：只要在回溯的过程中满足左括号的数量一直大于等于右括号数量即可
	vector<string> generateParenthesis(int n) {
		int left =0, right =0;
		vector<string> res;
		string box="()";

		backtrace("", n, res, left, right);
		return res;
	}
	void backtrace(string temp,int n, vector<string>& res, int left, int right){
		if (temp.size() == 2* n) {
			res.push_back(temp);
			return;
		}
		if (left <n) {
			temp.push_back('(');
			left ++;
			backtrace(temp, n, res, left, right);
			left--;
			temp.pop_back();
		}

		if (right <n && right < left) {
			temp.push_back(')');
			right++;
			backtrace(temp, n, res, left, right);
			right--;
			temp.pop_back();
		}
	}
};

