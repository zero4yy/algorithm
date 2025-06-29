#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// 生成随机整数数组并写入文件
void generateRandomArrayToFile(const char* filename, int size, int lowerBound, int upperBound) {
    ofstream outFile(filename);
    for (int i = 0; i < size; i++) {
        int randomValue = ((rand() % 32768) + (rand() % 32768) * 32768) % (upperBound - lowerBound + 1);
        outFile << randomValue << " ";
    }
    outFile.close();
}

int main() {
    srand((unsigned int)(time(NULL))); // 使用当前时间作为随机种子

    const int SIZE = 1000000; // 数组大小
    const int LOWER_BOUND = 1; // 随机数下界
    const int UPPER_BOUND = 2147483600; // 随机数上界

    generateRandomArrayToFile("testData/large_input2.txt", SIZE, LOWER_BOUND, UPPER_BOUND); // 生成随机数组并写入文件

    return 0;
}
