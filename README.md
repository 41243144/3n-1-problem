# 題目敘述
## 英文版
Problems in Computer Science are often classified as belonging to a certain class of problems (e.g., NP, Unsolvable, Recursive). In this problem, you will be analyzing a property of an algorithm whose classification is not known for all possible inputs.

Consider the following algorithm:

input n
print n
if n = 1 then STOP
if n is odd then n ← 3n + 1
else n ← n / 2
GOTO 2
Given the input 22, the following sequence of numbers will be printed:

22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

It is conjectured that the algorithm above will terminate (when a 1 is printed) for any integral input value. Despite the simplicity of the algorithm, it is unknown whether this conjecture is true. It has been verified, however, for all integers n such that 0 < n < 1,000,000 (and, in fact, for many more numbers than this).

Given an input n, it is possible to determine the number of numbers printed before and including the 1 is printed. For a given n, this is called the cycle length of n. In the example above, the cycle length of 22 is 16.

For any two numbers i and j, you are to determine the maximum cycle length over all numbers between and including both i and j.

Input

The input will consist of a series of pairs of integers i and j, one pair of integers per line. All integers will be less than 10,000 and greater than 0.

You should process all pairs of integers and for each pair determine the maximum cycle length over all integers between and including i and j.

You can assume that no operation overflows a 32-bit integer.

Output

For each pair of input integers i and j, you should output i, j, and the maximum cycle length for integers between and including i and j. These three numbers should be separated by at least one space, with all three numbers on one line and with one line of output for each line of input. The integers i and j must appear in the output in the same order in which they appeared in the input and should be followed by the maximum cycle length (on the same line).

Sample Input
1 10
100 200
201 210
900 1000

Sample Output
1 10 20
100 200 125
201 210 89
900 1000 174

## 中譯
問題通常會根據不同類型（例如，NP、不可解、遞歸）來分類。在這個問題中，你將分析一個演算法，其對所有可能輸入的分類仍然未知。

請考慮以下演算法：

輸入 n
印出 n
1.如果 n = 1，則結束
2.如果 n 是奇數，則 n ← 3n + 1
3.否則 n ← n / 2
回到第 2 步
給定輸入 22，將會印出以下數列： 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

據推測，上述演算法對於任何整數輸入最終都會終止（當輸出 1 時）。儘管這個演算法看起來很簡單，但目前尚不確定這個猜想是否正確。不過，已經驗證了對於 0 < n < 1,000,000 的所有整數（實際上對於更多的數字也已驗證）。

給定一個輸入 n，可以計算在印出 1 之前（包含 1）的數字數量，這個數量被稱為 n 的「循環長度」。在上面的例子中，22 的循環長度是 16。

對於兩個數字 i 和 j，你需要計算 i 和 j 之間（包含 i 和 j）的所有數字中，最大的循環長度。

輸入格式
輸入將由一系列的整數對 i 和 j 組成，每行包含一對整數。所有整數都小於 10,000 且大於 0。

你需要處理每一對整數，並且對每對整數計算 i 和 j 之間（包含 i 和 j）的所有整數的最大循環長度。

你可以假設所有操作都不會超過 32 位整數的範圍。

輸出格式
對於每對輸入的整數 i 和 j，你應該輸出 i、j 以及 i 和 j 之間（包含 i 和 j）的整數中的最大循環長度。這三個數字應該用至少一個空格分隔，並且都在同一行。每組輸入的 i 和 j 必須按照它們在輸入中出現的順序輸出，並且後面跟著對應的最大循環長度（在同一行中）。

## 題目簡單敘述
- 給定兩格數字，你要將這兩個數字間(包含頭尾)所有數字照著3n + 1算法求出哪個數字需要花費最多次數才會變成1

## 解法1 暴力破解
簡單明瞭，對於範圍內每個數字都跑一輪3n + 1規則

## 解法2 動態規劃
利用動態規劃記錄已找過的數字，讓重複出現的數字不必再操作一次

1.如果nmuner在字典中，則返回number在陣列中的值
2.如果number不在陣列中且number為奇數，number ← number * 3 + 1，否則number / 2
3.重複步驟2直到nmuber = 1或找到number