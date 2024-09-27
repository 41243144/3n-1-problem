import sys
class Solution():
    # 初始化類別，在類別被宣告時會執行
    def __init__(self) -> None:
        self.main()
    # 主要程式碼
    def main(self):
        input = sys.stdin.read # 修改input，一次讀取整個檔案
        data = list(map(int, input().split())) # 將讀取到的資料轉換成整數後放入data 串列
        data_length = len(data) # 資料總長度
        counter = 0 # 計數器

        while counter < data_length:
            # 因題目給定的是範圍，需自行找出比較小的數字當開始端，較大的數字為結束端
            start = min(data[counter], data[counter + 1])
            end = max(data[counter], data[counter + 1])
            # 初始化最大值
            maxmium = 1

            for number in range(start, end + 1):
                count = 1 # 計數number經歷循環次數
                while number != 1:
                    if number % 2 == 1:
                        number = number * 3 + 1
                    else:
                        number //= 2
                    count += 1
                # 更新最大值
                maxmium = max(maxmium, count)
            
            print(f"{data[counter]} {data[counter + 1]} {maxmium}")
            counter += 2

if __name__ == "__main__":
    run = Solution()