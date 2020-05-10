/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (58.37%)
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 根据每日 气温
 * 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。
 * 如果之后都不会升高，请在该位置用 0来代替。
 *
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
 * 你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 */
class Solution {
   public:
	// 相似题目：496 下一个更大元素
	// 单调栈： 栈顶元素最大：
	//后入栈的元素都比先入栈的元素小， 若当前元素比栈top大，则先pop，直到 当前元素比top小， 再入栈。
	// 当前的栈顶元素，就是当前元素的下一个最大值
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> result(T.size(), 0);
		if (T.empty()) {
			return result;
		}
		stack<int> s;
		for (auto i = 0; i < T.size(); i++) {
			while (!s.empty() && T[i] > T[s.top()]) {
				result[s.top()] = i - s.top();
				s.pop();
			}
			s.push(i);
		}
		return result;
	}
};
