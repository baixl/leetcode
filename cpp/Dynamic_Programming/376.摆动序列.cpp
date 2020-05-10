/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 *
 * https://leetcode-cn.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (41.18%)
 * Likes:    128
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 26K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * 如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
 * 
 * 例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和
 * [1,7,4,5,5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
 * 
 * 给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
 * 
 * 示例 1:
 * 
 * 输入: [1,7,4,9,2,5]
 * 输出: 6 
 * 解释: 整个序列均为摆动序列。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,17,5,10,13,15,10,5,16,8]
 * 输出: 7
 * 解释: 这个序列包含几个长度为 7 摆动序列，其中一个可为[1,17,10,13,10,16,8]。
 * 
 * 示例 3:
 * 
 * 输入: [1,2,3,4,5,6,7,8,9]
 * 输出: 2
 * 
 * 进阶:
 * 你能否用 O(n) 时间复杂度完成此题?
 * 
 */

// @lc code=start
class Solution {
public:
    /*
     方法1: 动态规划：双数组
    使用数组 up、down，分别记录到当前位置的摆动序列是上升还是下降，
    依次遍历之前的元素：若 
        若nums[i] > nums[j]： 则此时是上升的序列，则up[i] = max(up[i] ,down[j] + 1)
        若nums[i] < nums[j]： 则此时是下降的序列，则down[i] = max(down[i] , up[j] + 1)
    时间：O(N^2)
    空间 O(N)
    */
    int wiggleMaxLength1(vector<int>& nums) {
        int size =nums.size();
        if (size <2)  return size;
        if (size == 2) return  nums[0]!= nums[1]? 2:1;
        vector<int> up(size, 0); // 记录当前位置为摆动序列的上升位置
        vector<int> down(size, 0); // 记录当前位置为摆动序列的下降位置
        
        for(auto i = 1; i< size; i++) {
            for (auto j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    up[i] = max(up[i], down[j] +1);
                } else if (nums[i] < nums[j]) {
                    down[i] = max(down[i], up[j] +1);
                }
            }
        }
        return 1+ max(down[size-1], up[size-1]);
    }
     /*
     方法2: 动态规划：线性空间
    对数组中任何一个位置有三种状态：
    1.上升的位置： num[i] > nums[i-1]
    2.下降的位置： num[i] < nums[i-1]
    3.相同的位置： num[i] == nums[i-1]
    更新的过程如下：
        如果 nums[i]>nums[i−1] ，意味着这里在摆动上升，前一个数字肯定处于下降的位置。所以 up[i] = down[i-1] + 1 ， down[i] 与 down[i-1] 保持相同。
        如果 nums[i]<nums[i−1] ，意味着这里在摆动下降，前一个数字肯定处于上升的位置。所以down[i] = up[i-1] + 1，p[i] 与 up[i-1]保持不变。
        如果 nums[i] == nums[i-1]  ，意味着这个元素不会改变任何东西因为它没有摆动。所以 down[i]与 up[i] 与 down[i-1]和 up[i-1] 都分别保持不变。
    */
    int wiggleMaxLength2(vector<int>& nums) {
        int size =nums.size();
        if (size <2)  return size;
        if (size == 2) return  nums[0]!= nums[1]? 2:1;
        vector<int> up(size, 0); // 记录当前位置为摆动序列的上升位置
        vector<int> down(size, 0); // 记录当前位置为摆动序列的下降位置
        up[0] = 1;
        down[0] = 1;
        
        for(auto i = 1; i< size; i++) {
            if (nums[i] > nums[i-1]) {
                up[i] =down[i-1] +1;
                down[i] = down[i-1];
            } else if (nums[i] < nums[i-1]) {
                 down[i] = up[i-1] +1;
                 up[i] = up[i-1];
            } else {
                up[i] = up[i-1];
                down[i] = down[i-1];
            }
            
        }
        return max(down[size-1], up[size-1]);
    }
     /*
    方法3: 动态规划 在方法2基础上进行空间优化
    可以看到up down两个数组只用了最后一个位置， 可以用两个变量代替
    */
    int wiggleMaxLength3(vector<int>& nums) {
        int size =nums.size();
        if (size <2)  return size;
        if (size == 2) return  nums[0]!= nums[1]? 2:1;
        int up =1, down =1;
        
        for(auto i = 1; i< size; i++) {
            if (nums[i] > nums[i-1]) {
                up = down+1;
            } else if (nums[i] < nums[i-1]) {
                 down = up+1;

            } else {
               
            }
            
        }
        return max(down, up);
    }

     /*
    方法4: 贪心算法
    https://leetcode-cn.com/problems/wiggle-subsequence/solution/bai-dong-xu-lie-by-leetcode/
    */
    int wiggleMaxLength(vector<int>& nums) {
        int size =nums.size();
        if (size <2)  return size;
        if (size == 2) return  nums[0]!= nums[1]? 2:1;
        int prevdiff = nums[1] - nums[0];
        int count =  prevdiff != 0?2:1;
        for(auto i =2; i< size; i++) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
                count++;
                prevdiff = diff;
            }
        }
        return count;
    }
};
// @lc code=end

