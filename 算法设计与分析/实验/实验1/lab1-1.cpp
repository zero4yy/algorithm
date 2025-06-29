//分治法查找最大最小值
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
pair<ll, ll> dcMaxMin(const vector<ll>& arr, ll low, ll high) { //const传递常数引用，避免拷贝开销
    if(low == high) return {arr[low], arr[high]};
    
    if(low + 1 == high) {
        if(arr[low] > arr[high])
            return {arr[low], arr[high]};
        else 
            return {arr[high], arr[low]};
    }

    ll mid = (low + high) / 2;

    //递归查找左右子数组的最大最小值
    auto leftMaxMin = dcMaxMin(arr, low, mid);
    auto rightMaxMin = dcMaxMin(arr, mid + 1, high);

    return {max(leftMaxMin.first, rightMaxMin.first), min(leftMaxMin.second, rightMaxMin.second)};
}
int main() {
    ifstream ifs("testData/small_input1.txt");
    ofstream ofs("output1.txt");
    vector <ll> arr;
    ll number;  
    while (ifs >> number) { // 逐行读取整数  
        arr.push_back(number); // 将读取的数字推入向量  
    }  
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    auto[MaxValue, MinValue] = dcMaxMin(arr, 0, arr.size() - 1);
    // 结束计时
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    ofs << "time: " << duration.count() << " ms" << endl;
    ofs << "Max:" << MaxValue << ' ' << "Min:" << MinValue;
    ifs.close();
    ofs.close();
    return 0;
}