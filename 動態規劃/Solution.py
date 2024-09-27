import sys

class Solution():
    def __init__(self) -> None:
        # 利用dict儲存已經出現過的狀態，初始化1為1步
        self.dp = {1 : 1}
        self.main()
    
    def main(self) -> None:
        #資料讀取
        input = sys.stdin.read
        data = list(map(int, input().split()))
        data_length = len(data)
        counter = 0
        while counter < data_length:
            start = min(data[counter], data[counter + 1])
            end = max(data[counter], data[counter + 1])
            maxmium = 1
            for number in range(start, end + 1):
                self.process(number)
                maxmium = max(maxmium, self.dp[number])

            print(f"{data[counter]} {data[counter + 1]} {maxmium}")

            counter += 2
    
    # 計算number cycle length
    def process(self, number : int) -> int:
        if number in self.dp:
            return self.dp[number]
        if number % 2 == 1:
            self.dp[number] = self.process(number * 3 + 1) + 1
        else:
            self.dp[number] = self.process(number // 2) + 1
        return self.dp[number]
    
if __name__ == "__main__":
    run = Solution()

