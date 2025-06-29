#include<iostream>
#include<string>
#include<math.h> 
using namespace std;
int zhuanhua(string n, int sum) {
    //定义字符串n
    //定义转化为十进制的数字为sum
    //    cout<<"请输入二进制数字：";
 
    for (int i = 0; i < n.size(); i++)
    {
        //边界条件判断 递归思想(我想应该是递归思想吧，哈哈），也可写个else if判断条件为这个，如果不是输出非法输入再break掉也可以。
        if (n[i] > '1')
        {
            cout << "非法输入";
            return 0;//直接退出
        }
        //判断当前字符串n[i]是否为1，因为不是1就是0，为0的话，0的2次方还是等于0，不需要加法运算。
        if (n[i] == '1')
        {
            int j = pow(2, n.size() - i - 1);//这里考虑好二进制转化成十进制公示里面i和次方的关系
            sum += j;
        }
    }
    return sum;
 
}
int main() {
    int n;
    cin >> n;
    //按照题意应该建立结构体数组  关于string类型的 数组
    string* newarr = new string[n];//建立结构体string的数组 
    for (int i = 0; i < n; i++) {
        cin >> newarr[i];
 
    }
    //在进行没把为的怕暖
    for (int j = 0; j < n; j++) {
        string temp;
        for (int i = 0; i < newarr[j].size(); i += 8) {
            temp = newarr[j].substr(i, 8);//原来是题意的理解错误！  后面的一个数字不是编辑室位置 而死标表示后面多少个数字
            cout << zhuanhua(temp, 0);
            if (i + 8 < newarr[j].size()) {
                cout << ".";
            }
            
//难道【判断i+=8是无效的？
//事实证明了是没有用的
 
 
        }
        cout << endl;
    }
 
 
 
    return 0;
}