#include <iostream>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <time.h>
using namespace std;
 
//主算法：使用动态规划法求解0-1背包问题
int Solve(int n,int limit,int* values,int* weights,bool* ans)
{
    int dp[n][limit+1]; //选到第n个物品，剩余limit个空weight，的最大value
    //初始化dp数组
    for(int i=0;i<n;i++)
        for(int j=0;j<limit+1;j++)
            dp[i][j]=0;       
    //装第一个物品
    for(int i=0;i<limit+1;i++)
    {
        if(weights[0]<=i)
            dp[0][i] = values[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<limit+1;j++)
        {
            if(j-weights[i]<0)  //装不下第i个
                dp[i][j]=dp[i-1][j];
            else                //装得下
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-weights[i]]+values[i]);
        }
    }
    //回溯记录是否选上物品
    int w=limit;
    for(int i=n-1;i>0 && w>0;i--){
        if(dp[i][w]!=dp[i-1][w]){
            ans[i]=1;
            w-=weights[i];
        }  
    }
    return dp[n-1][limit];
}

int main()
{
    for(int cnt = 0;cnt<3;cnt++)
    {
        //生成规模为n的随机数，并存到txt文件中
        cout << "Input data scale n: " ;
        int n; cin >> n;
        cout << " Limit weights: " ;
        int limit;cin >> limit;
        ofstream fin;
        if(cnt==0)
            fin.open("./algorLab/lab1.3/input1.txt");
        else if(cnt==1)
            fin.open("./algorLab/lab1.3/input2.txt");
        else 
            fin.open("./algorLab/lab1.3/input3.txt");
        fin << n << " " << limit << endl;
        srand((unsigned)time(NULL));
        for(int i =0;i<n;i++)
        {
            fin<<rand()%10+1 <<' ';  //weights
            fin<<rand()%10+1 ; //values
            fin << endl;
        }
        fin.close();

        //读出文件数据，存入数组
        ifstream fout;
        if(cnt==0)
            fout.open("./algorLab/lab1.3/input1.txt");
        else if(cnt==1)
            fout.open("./algorLab/lab1.3/input2.txt");
        else 
            fout.open("./algorLab/lab1.3/input3.txt");
        fout >> n; fout>>limit;
        int* weights = new int[n];
        int* values = new int[n];
        for(int i=0;i<n;i++)
        {
            fout >> weights[i];
            fout >> values[i];
        }
        bool ans[n]={0};    //记录物品是否被选
        LARGE_INTEGER nFreq,nBegin,nEnd; //计算时间所用变量
        double time;
        QueryPerformanceFrequency(&nFreq);	
        QueryPerformanceCounter(&nBegin);
        int Maxvalue = Solve(n,limit,values,weights,ans);
        QueryPerformanceCounter(&nEnd);
        time=(double)(nEnd.QuadPart-nBegin.QuadPart)/(double)nFreq.QuadPart;
        cout << "Max Value: " << Maxvalue << endl;
        cout << "Choose goods: ";
        for(int i=0;i<n;i++)
        {
            if(ans[i]) cout << i+2 << " ";
        }
        cout << endl;
        cout << "Use time: " << time << "s\n";
        delete weights,values;
    }
    return 0;
}
