#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 初始化類別時呼叫主函數
    Solution() {
        mainFunc();
    }

    // 主要程式碼
    void mainFunc() {
        int start, end;

        while (cin >> start >> end) {
            int originalStart = start;
            int originalEnd = end;
            
            // 找出範圍內較小的數作為開始，較大的數作為結束
            if (start > end) swap(start, end);
            
            int maxCycleLength = 1;

            for (int number = start; number <= end; ++number) {
                int cycleLength = 1;
                int tempNumber = number;

                // 計算該數字的循環次數
                while (tempNumber != 1) {
                    if (tempNumber % 2 == 1) {
                        tempNumber = tempNumber * 3 + 1;
                    } else {
                        tempNumber /= 2;
                    }
                    cycleLength++;
                }
                // 更新最大循環長度
                maxCycleLength = max(maxCycleLength, cycleLength);
            }

            // 輸出結果
            cout << originalStart << " " << originalEnd << " " << maxCycleLength << endl;
        }
    }
};

int main() {
    // 建立物件來執行程式
    Solution solution;
    return 0;
}
