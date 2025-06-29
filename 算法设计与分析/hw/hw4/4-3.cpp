// 电路板排列问题
#include<bits/stdc++.h>
using namespace std;
class Board
{
    friend int Arrangement(int **, int, int, int*);
    private:
        void Backtrack(int i, int cd);
        int n,      //电路板数
            m,      //连接块数
            *x,     //当前解
            *bestx, //当前最优解
            bestd,  //当前最优密度
            *total, //total[j]为连接块j的电路板数
            *now,   //now[j]为当前解中所含连接块j的电路板数
            **B;    //连接块数组
};
void Board::Backtrack(int i, int cd)        //回溯搜索排列树,cd表示已经确定的x[1:i]个插槽中相邻两个插槽被跨越数最大的(就是密度)
{
    static int k = 1;
    if(i == n)  //由于算法仅完成那些比当前最优解更好的排列,故cd肯定优于bestd,直接更新
    {
        cout<<"当前已经确定下来最后一个插槽,我们选择"<<x[n]<<endl;
        cout<<"第"<<k++<<"个方案为: ";
        for(int j=1; j<=n; j++)
        {
            bestx[j] = x[j];
            cout<<x[j]<<" ";
        }
        bestd = cd;
        cout<<"获得的密度为: "<<bestd<<endl<<"到达最后一层,回溯一层到达第"<<n-1<<"层"<<endl;
    }
    else
    {
        for(int j=i; j<=n; j++)     //选择x[j]为下一块电路板
        {
            int ld = 0;     //新的排列部分密度
            for(int k=1; k<=m; k++)     //遍历连接块1~m,并且计算得到跨越插槽i和i+1的导线数ld
            {
                now[k] += B[x[j]][k];
                if(now[k]>0 && total[k]!=now[k])  //判断是否发生了跨越(左边有,右边也有)
                    ld++;
            }
            cout<<"当前位于第"<<i<<"层,我们选择电路板"<<x[j]<<", 通过计算得到跨越相邻插槽"<<i<<"和"<<i+1<<"的导线数为:"<<ld<<", 目前得到的最大数值为:"<<cd<<endl;
            cout<<"当前构造出的now[]数组为(now[j]表示当前解所含连接块j的电路板数): ";
            for(int j=1; j<=m; j++) cout<<now[j]<<" ";
            cout<<endl; 
            if(cd > ld)     //更新ld,cd为原来的最大密度,ld为当前的最大密度,哪个大取哪个  为什么要这么做?因为每一层我们只可以算出跨越插槽i和i+1的导线数,所以我们必须要和之前的最大值进行比较,取较大者(这是密度的定义)
            {    
                ld = cd;
                cout<<"ld<cd, ld已经被更新为"<<cd<<endl;
            }
            if(ld < bestd)  //满足剪枝函数,搜索子树
            {
                swap(x[i], x[j]);
                cout<<"满足剪枝函数,递归深入一层,将到达第"<<i+1<<"层"<<endl;
                Backtrack(i+1, ld);
                cout<<"当前第"<<i+1<<"层,递归回退一层,将到达第"<<i<<"层"<<endl;
                swap(x[i], x[j]);
                for(int k=1; k<=m; k++)     //恢复状态
                    now[k] -= B[x[j]][k];
                cout<<"第"<<i<<"层撤销选择电路板"<<x[j]<<",恢复now[]数组为(now[j]表示当前解所含连接块j的电路板数): ";
                for(int j=1; j<=m; j++) cout<<now[j]<<" ";
                cout<<endl; 
                
            }
            else cout<<"目前获得的密度已经大于最优值,故直接剪枝."<<endl;
            if(j==n) cout<<"当前层所有情况遍历完,回溯"<<endl;
        }
    }
}
int Arrangement(int **B, int n, int m, int *bestx)
{
    Board X;
    //初始化X
    X.x = new int[n+1];
    X.total = new int[m+1];
    X.now = new int[m+1];
    X.B = B;
    X.n = n;
    X.m = m;
    X.bestx = bestx;
    X.bestd = m+1;
    //初始化total和now
    for(int i=1; i<=m; i++)
    {
        X.total[i] = 0;
        X.now[i] = 0;
    }
    //初始化x为单位排列并计算total
    for(int i=1; i<=n; i++)
    {
        X.x[i] = i;
        for(int j=1; j<=m; j++)
            X.total[j] += B[i][j];
    }
    cout<<"total数组为: ";
    for(int i=1; i<=m; i++) cout<<X.total[i]<<" ";
    cout<<endl;
    X.Backtrack(1, 0);
    delete[] X.x;
    delete[] X.total;
    delete[] X.now;
    return X.bestd;
}
int main()
{
    cout<<"请输入电路板个数和连接块个数:";
    int n, m;
    while(cin>>n>>m && n && m)
    {
        cout<<"输入连接块矩阵"<<endl;
        int **B = new int*[n+1];
        for(int i=0; i<=n; i++) B[i] = new int[m+1];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>B[i][j];
        int *bestx = new int[n+1];
        for(int i=1; i<=n; i++) bestx[i] = 0;
        int ans = Arrangement(B, n, m, bestx);
        cout<<"得到的最小密度为:"<<ans<<endl;
        for(int i=0; i<=n; i++) delete[] B[i];
        delete[] B;
        delete[] bestx;
        cout<<"请输入电路板个数和连接块个数";
    }
    system("pause");
    return 0;
}

//使用的B数组
//0 0 1 0 0
//0 1 0 0 0
//0 1 1 1 0
//1 0 0 0 0
//1 0 0 0 0
//1 0 0 1 0
//0 0 0 0 1
//0 0 0 0 1
