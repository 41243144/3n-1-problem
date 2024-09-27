#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution() {
        dp[1] = 1;
        mainLogic();
    }

private:
    unordered_map<int, int> dp;

    void mainLogic() {
        int a, b;
        // 讀取整個輸入並處理
        while (cin >> a >> b) {
            int start = min(a, b);
            int end = max(a, b);
            int maximum = 1;
            // 遍歷範圍內的每個數字
            for (int number = start; number <= end; ++number) {
                maximum = max(maximum, process(number));
            }
            // 輸出結果
            cout << a << " " << b << " " << maximum << endl;
        }
    }

    int process(int number) {
        if (dp.find(number) != dp.end()) {
            return dp[number];
        }
        if (number % 2 == 1) {
            dp[number] = process(number * 3 + 1) + 1;
        } else {
            dp[number] = process(number / 2) + 1;
        }
        return dp[number];
    }
};

int main() {
    Solution solution;
    return 0;
}
