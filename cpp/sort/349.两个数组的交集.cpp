/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.71%)
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 示例 1:
 * 
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 
 * 说明:
 * 
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * 
 */

// @lc code=start
class Solution {
   public:
    //方法1 排序 + 两指针
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 > size2) {
            return intersection(nums2, nums1);
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int i = 0, j = 0;
        unordered_set<int> set;
        //这里用set接，避免出现重复的元素
        while (i < size1 && j < size2) {
            if (nums1[i] == nums2[j]) {
                set.insert(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }
        vector<int> result;
        for (unordered_set<int>::iterator it = set.begin();
             it != set.end(); it++) {
            result.push_back(*it);
        }
        return result;
    }

    //方法2 hash
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        if (size1 > size2) {
            return intersection(nums2, nums1);
        }

        unordered_map<int, int> map;
        for (int i = 0; i < size1; i++) {
            if (map.find(nums1[i]) == map.end()) {
                map.insert({nums1[i], 0});
            }
        }

        for (int i = 0; i < size2; i++) {
            if (map.find(nums2[i]) != map.end()) {
                map[nums2[i]] = 1;
            }
        }
        vector<int> result;
        unordered_map<int, int>::iterator it = map.begin();
        for (; it != map.end(); it++) {
            if (it->second != 0) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};
// @lc code=end

