#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <algorithm>
using namespace std;
 
//物品抽象为类，包括价值、重量、性价比
class good
{
public:
    int id;
    int value;
    int weight;
    double vpw;
};
bool cmp(good a,good b)
{
    return a.vpw>=b.vpw;
}
//主算法：使用贪心算法求解0-1背包问题
double greedy_solve(int n,int limit,good* &Goods,int* ans)
{
    double max_value = 0;
    //计算物品性价比并降序排列
    for(int i = 0;i<n;i++)
        Goods[i].vpw = 1.0*Goods[i].value/Goods[i].weight;
    sort(Goods,Goods+n,cmp);
    //从性价比高的开始装，直到装满
    for(int i=0;i<n;i++)
    {
        if(limit==0) break;        //背包无空闲
        int id = Goods[i].id;
        //装的下该物品，全装
        if(limit>=Goods[i].weight)
        {
            ans[id] = 1; //全装
            max_value += Goods[i].value;
            limit -= Goods[i].weight;
        }
        else
        {
            ans[id] = 2; //装部分
            max_value += Goods[i].vpw*limit;
            limit = 0;
        }
    }
    return max_value;
}

int main()
{
    for(int cnt = 0;cnt<3;cnt++)
    {
        //生成规模为n的随机数，并存到txt文件中
        cout << "Input data scale n: " ;
        int n; cin >> n;
        cout << "Limit weights: " ;
        int limit;cin >> limit;
        ofstream fin;
        if(cnt==0)
            fin.open("./algorLab/lab1.4/input1.txt");
        else if(cnt==1)
            fin.open("./algorLab/lab1.4/input2.txt");
        else 
            fin.open("./algorLab/lab1.4/input3.txt");
        fin << n << " " << limit << endl;
        srand((unsigned)time(NULL));
        for(int i =0;i<n;i++)
        {
            fin<<rand()%10+1 <<' ';  //weights
            fin<<rand()%10+1 ;       //values
            fin << endl;
        }
        fin.close();

        //读出文件数据，存入数组
        ifstream fout;
        if(cnt==0)
            fout.open("./algorLab/lab1.4/input1.txt");
        else if(cnt==1)
            fout.open("./algorLab/lab1.4/input2.txt");
        else 
            fout.open("./algorLab/lab1.4/input3.txt");
        fout >> n; fout>>limit;
        good* Goods = new good[n];
        for(int i=0;i<n;i++)
        {
            Goods[i].id = i;
            fout >> Goods[i].weight;
            fout >> Goods[i].value;
        }
        int* ans = new int[n];    //记录物品是否被选
        for(int i =0;i<n;i++) ans[i] = 0;
        LARGE_INTEGER nFreq,nBegin,nEnd; //计算时间所用变量
        double time;
        QueryPerformanceFrequency(&nFreq);	
        QueryPerformanceCounter(&nBegin);
        double Maxvalue = greedy_solve(n,limit,Goods,ans);
        QueryPerformanceCounter(&nEnd);
        time=(double)(nEnd.QuadPart-nBegin.QuadPart)/(double)nFreq.QuadPart;
        cout << "Max Value: " << Maxvalue << endl;
        // cout << "Choose goods: ";
        // for(int i=0;i<n;i++)
        // {
        //     if(ans[i]==1)
        //         cout << "\tall of " << i+2;
        //     else if(ans[i]==2)
        //         cout << "\tpart of " << i+2;
        // }
        // cout << endl;
        cout << "Use time: " << time << "s\n";
        delete Goods,ans;
    }
    return 0;
}
