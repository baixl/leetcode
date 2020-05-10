/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 *
 * https://leetcode-cn.com/problems/k-closest-points-to-origin/description/
 *
 * Medium (55.70%)
 *
 * 我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。
 * （这里，平面上两点之间的距离是欧几里德距离。）
 * 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。
 *
 * 示例 1：
 * 输入：points = [[1,3],[-2,2]], K = 1
 * 输出：[[-2,2]]
 * 解释：
 * (1, 3) 和原点之间的距离为 sqrt(10)，
 * (-2, 2) 和原点之间的距离为 sqrt(8)，
 * 由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
 * 我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
 *
 * 示例 2：
 *
 * 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
 * 输出：[[3,3],[-2,4]]
 * （答案 [[-2,4],[3,3]] 也会被接受。）
 *
 * 提示：
 *
 * 1 <= K <= points.length <= 10000
 * -10000 < points[i][0] < 10000
 * -10000 < points[i][1] < 10000
 *
 *
 */

// @lc code=start
class Solution {
   public:
    /*************************************************
    方法1： 直接排序求解 
    pass，时间和空间都较差
    
    Your runtime beats 7.39 % of cpp submissions
    Your memory usage beats 6.26 % of cpp submissions (191.8 MB)    
    时间 O(NlogN)
    *************************************************/
    vector<vector<int>> kClosest1(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        sort(points.begin(), points.end(), compare);
        for (auto i = 0; i < k; i++) {
            res.push_back(points[i]);
        }

        return res;
    }
    static bool compare(vector<int> a, vector<int> b) {
        int disa = a[0] * a[0] + a[1] * a[1];
        int disb = b[0] * b[0] + b[1] * b[1];
        return disa < disb;
    }

    /*************************************************
    方法2：快排分区
    这个题目本质还是个topk问题
    可以利用快排的partition方法, 将离远点距越小的点移动到数组的前面，

    假设和依次排序后，pivot将数组分成两部分
    1、left: points[0:i] 元素值都 < pivot，长度为left_len
    2、right： point[i+1:size] 元素值都 > pivot，长度为right_len

    相似题目：215数组中第k个最大元素
    *************************************************/
    vector<vector<int>> kClosest2(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        while (left < right) {
            int index = partition(points, left, right);
            if (index == k - 1) {
                break;
            } else if (index < k - 1) {
                left = index + 1;
            } else {
                right = index - 1;
            }
        }
        vector<vector<int>> res;
        for (auto i = 0; i < k; i++) {
            res.push_back(points[i]);
        }

        return res;
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = get_dis(points[left]); // 分界点的值
        vector<int> left_vec = points[left];
        int pivot_indx = left;

        while (left < right) {
            // 找到第1个< pivot节点
            while (left < right && get_dis(points[right]) >= pivot) {
                right--;
            }
            // 找到1个比pivot大的点
            while (left < right && get_dis(points[left]) <= pivot) {
                left++;
            }
            swap(points, left, right);
        }
        swap(points, left, pivot_indx);
        return left;
    }

    int get_dis(vector<int>& point) { return point[0] * point[0] + point[1] * point[1]; }

    void swap(vector<vector<int>>& points, int i, int j) {
        int temp = points[i][0];
        points[i][0] = points[j][0];
        points[j][0] = temp;

        temp = points[i][1];
        points[i][1] = points[j][1];
        points[j][1] = temp;
    }

    /*************************************************
     * topk 问题，那么可以使用堆排序，这里使用priority_queue
     *
    *************************************************/
    // 自定义比较函数
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            int disa = a[0] * a[0] + a[1] * a[1];
            int disb = b[0] * b[0] + b[1] * b[1];
            return disa < disb;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> q; // 默认是大顶堆
        int i = 0;
        for (i = 0; i < k; i++) {
            q.push(points[i]);
        }
        for (auto i = k; i < points.size(); i++) {
            q.push(points[i]);
            q.pop();
        }

        vector<vector<int>> res;
        while (!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
// @lc code=end
