/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 * Medium (56.76%)
 * 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
 * 请注意，它是排序后的第k小元素，而不是第k个元素。
 * 示例:
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 返回 13。
 * 说明:
 * 你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n^2 。
 */

// @lc code=start
class Solution {
   public:
    /*
    方法1： 堆排序
    Your runtime beats 10.79 % of cpp submissions
    Your memory usage beats 14.64 % of cpp submissions (13.4 MB)
    */
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[0].size(); j++) {
                vec.push_back(matrix[i][j]);
            }
        }
        make_heap(vec.begin(), vec.end());  //默认大顶堆
        int result = vec.front();
        int size = vec.size();
        for (auto i = 0; i < size - k + 1; i++) {
            result = vec.front();
            pop_heap(vec.begin(), vec.end());
            vec.pop_back();
        }
        return result;
    }
    /*
    Your runtime beats 40.84 % of cpp submissions
    Your memory usage beats 14.39 % of cpp submissions (13.4 MB)
    */
    int kthSmallest2(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[0].size(); j++) {
                vec.push_back(matrix[i][j]);
            }
        }
        make_heap(vec.begin(), vec.end(), greater<int>());  // 小顶堆

        int result = vec.front();
        for (auto i = 0; i < k; i++) {
            result = vec.front();
            pop_heap(vec.begin(), vec.end(), greater<int>());
            vec.pop_back();
        }
        return result;
    }
    /*
    Your runtime beats 49.37 % of cpp submissions
    Your memory usage beats 5.12 % of cpp submissions (14.4 MB)
    */
    int kthSmallest3(vector<vector<int>>& matrix, int k) {
        vector<int> vec;
        for (auto i = 0; i < matrix.size(); i++) {
            for (auto j = 0; j < matrix[0].size(); j++) {
                vec.push_back(matrix[i][j]);
            }
        }
        // 创建小顶堆
        priority_queue<int> q;
        int i = 0;
        for (i = 0; i < k; i++) {
            q.push(vec[i]);
        }
        for (i = k; i < vec.size(); i++) {
            q.push(vec[i]);
            q.pop();
        }

        return q.top();
    }
    // 二分查找 TODO:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    }
};
// @lc code=end
