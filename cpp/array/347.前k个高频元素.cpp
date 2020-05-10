/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前K个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
 */

class Solution {
   public:
    // 方法1、1、先用hash_map 将数字计数，  2、将hasp_map 以pair形式转成vector，
    // 3、自定义vertor排序
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || k <= 0) {
            return result;
        }
        unordered_map<int, int> map;
    
        for (auto& num : nums) {
            map[num] ++;
        }
        vector<pair<int, int>> vec(map.begin(), map.end());
        sort(vec.begin(), vec.end(), comp);
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }

    static bool comp(const pair<int, int> pair1, const pair<int, int> pair2) {
        return pair1.second > pair2.second;
    }

    struct cmp {
        //建立一个小根堆
        bool operator()(pair<int, int>& a, pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    //方法2：1、先用hash_map 将数字计数，  2、堆排序（优先级队列）
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty() || k <= 0) {
            return result;
        }
        unordered_map<int, int> map;
        for (auto& num : nums) {
            if (map.find(num) != map.end()) {
                map[num]++;
            } else {
                map[num] = 1;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> queue;
        for (auto it = map.begin(); it != map.end(); it++) {
            if (queue.size() < k) {
                queue.push(make_pair(it->first, it->second));
            } else {
                if (it->second > queue.top().second) {
                    queue.pop();
                    queue.push(make_pair(it->first, it->second));
                }
            }
        }
        while (!queue.empty()) {
            result.push_back(queue.top().first);
            queue.pop();
        }
        return result;
    }
};
