/*
 * [412] Fizz Buzz
 写一个程序，输出从 1 到 n 数字的字符串表示。
1. 如果 n 是3的倍数，输出“Fizz”；
2. 如果 n 是5的倍数，输出“Buzz”；
3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
示例：
n = 15,
返回:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 */
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (auto i = 1; i <= n; i++) {
            int result1 = i % 3;
            int result2 = i % 5;
            string s;
            if (result1 == 0 && result2 == 0 ) {
                s = "FizzBuzz";
            } else if (result1 == 0) {
                s = "Fizz";
            } else if (result2 == 0) {
                s = "Buzz";
            } else {
                s = to_string(i);
            }

            result.push_back(s);
        }
        return result;
    }
};

