//分治法实现合并排序
#include <bits/stdc++.h>
typedef long long ll;
const int N = 8;
using namespace std;
void merge(vector<ll>& arr, ll left, ll mid, ll right) {
    ll n1 = mid - left + 1; //左数组大小
    ll n2 = right - mid;    //右数组大小

    vector<ll> L(n1), R(n2); //创建左右临时数组
    // 拷贝数据到 L[] 和 R[]
    for(int i = 0; i < n1; ++i)L[i] = arr[left + i];
    for(int j = 0; j < n2; ++j)R[j] = arr[mid + 1 + j];

    //合并数组
    ll i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    //拷贝剩余元素
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}
void mergeSort(vector<ll>& arr, ll left, ll right) {
    if(left < right) {
        ll mid = left + (right - left) / 2; //防止溢出
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main() {
    ifstream ifs("testData/small_input2.txt");
    ofstream ofs("output2.txt");
    vector <ll> arr;
    ll number;
    while (ifs >> number) { // 逐行读取整数  
        arr.push_back(number); // 将读取的数字推入向量  
    }  
    // 开始计时
    auto start = chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    // 结束计时
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration = end - start;
    ofs << "time: " << duration.count() << " ms" << endl;
    for(auto y : arr) {
        ofs << y << ' ' ;
    }
    ifs.close();
    ofs.close();
    return 0;
}