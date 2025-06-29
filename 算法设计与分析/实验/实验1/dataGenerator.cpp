#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// ��������������鲢д���ļ�
void generateRandomArrayToFile(const char* filename, int size, int lowerBound, int upperBound) {
    ofstream outFile(filename);
    for (int i = 0; i < size; i++) {
        int randomValue = ((rand() % 32768) + (rand() % 32768) * 32768) % (upperBound - lowerBound + 1);
        outFile << randomValue << " ";
    }
    outFile.close();
}

int main() {
    srand((unsigned int)(time(NULL))); // ʹ�õ�ǰʱ����Ϊ�������

    const int SIZE = 1000000; // �����С
    const int LOWER_BOUND = 1; // ������½�
    const int UPPER_BOUND = 2147483600; // ������Ͻ�

    generateRandomArrayToFile("input.txt", SIZE, LOWER_BOUND, UPPER_BOUND); // ����������鲢д���ļ�

    return 0;
}

