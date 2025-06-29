#include "iostream"
#include "string"
#include "iomanip"
#include "fstream"
#include <bits/stdc++.h>
using namespace std;

/*
正则表达式可选字符集的排列顺序先为‘*’，‘？’，操作文件名序列中出现的所有字符按其频率递减的次序随后

大体思路：
正则表达式为s，当前考察文件为f

match(i, j)为s[1,i]与f[1,j]匹配情况
如果match(i-1, j-1) = 1, s[i] = '?'
    match(i-1, j-1) = 1, s[i] = f[j]
    match(i-1, k) = 1,   s[i] = '*'
match(i, j) = 1
否则 match(i, j) = 0
*/

const int MAXN = 250;  //文件数
const int MAXL = 8;  //文件名长度
const int MAXP = 62; //大写字母 + 小写字母 + 数字
int minlen;  //最优正则表达式长度
int maxmat;  //最优正则表达式所能匹配的操作文件数
int curmat;  //当前正则式所能匹配的操作文件数
string f[MAXN+1];  //操作文件
string k[MAXN+1];  //非操作文件
int n[2];  //n[0]为操作文件数，n[1]为非操作文件数
int p[MAXP];  //p[len-1] 存储 s[len]可选字符数
char s[MAXP];  //存储临时正则表达式
char minmat[MAXP];  //最优正则表达式
int match[MAXP][MAXN+1][MAXP];  //match[len][i][j]表示正则表达式的第len个字符与第i个文件的第j个字符的匹配情况

struct Cha
{
    char c;  //字符
    int f;   //字符出现的频率
};

Cha cha[MAXN][MAXP]; //cha[len][i]表示正则表达式长度为len时的字符排序情况

//对操作文件名中出现的字符按出现频率排序存储，以加快搜索进程
void save(char c, int len)
{
    int i, j;
    for(i=1; i<=p[len]; i++)
        if(cha[len][i].c == c)
        {
            cha[len][i].f++;
            cha[len][0] = cha[len][i]; 
            j = i;
            while(cha[len][j-1].f < cha[len][0].f)  //将频率小于当前字符频率的字母后移
            {
                cha[len][j] = cha[len][j-1];
                j--;
            }
            cha[len][j] = cha[len][0];  //将当前字母放到适当位置
            return;
        }
    //如果p[len] = 0，或者字符c第一次出现，则增加一个字符
    cha[len][++p[len]].c = c;
    cha[len][p[len]].f = 1;
}

//计算当前匹配情况
bool check(int len)
{
    int i, j, t, k = 0;
    curmat = 0;
    for(i=1; i<=n[0]; i++)  //操作文件数
    {
        for(j=0; j<MAXP; j++)
            match[len][i][j] = 0;
        if(len==1 && s[1]=='*')
            match[len][i][0] = 1;
        for(j=1; j<=f[i].length(); j++)  //操作文件的每个字符
        {
            switch(s[len])
            {
                case '*': 
                    for(t=0; t<=j; t++)
                        if(match[len-1][i][t]==1)
                        {
                            match[len][i][j] = 1; //正则表达式的第len个字符与第i个文件的第j个字符的匹配情况
                            break;
                        }
                        break;  //此处的break不能省略！
                case '?':
                    match[len][i][j] = match[len-1][i][j-1];
                    break;
                default:
                    if(s[len]==f[i][j-1])
                        match[len][i][j] = match[len-1][i][j-1];
                    break;
            }
        }
        for(j=f[i].length(); j>=1; j--)  
        {
            if(match[len][i][j] == 1)
            {
                k++;
                if(j == f[i].length()) //说明第i个文件与正则表达式匹配
                    curmat++; 
                break;
            }
        }
    }
    if(k<maxmat || k==maxmat && len>=minlen)
        return false;
    p[len] = 0;
    for(i=1; i<=n[0]; i++) //对与正则表达式匹配的文件中的字符重新排序，以便正则式下次扩展
        for(j=1; j<f[i].length(); j++)
            if(match[len][i][j]==1)
                save(f[i][j], len);
    return true;
}

//判断是否匹配非操作文件
bool ok(int len)
{
    int i, j, l, t;
    for(l=1; l<=len; l++)
    {
        for(i=n[0]+1; i<=n[0]+n[1]; i++)
        {
            for(j=0; j<MAXP; j++)
                match[l][i][j] = 0;
            if(s[1]=='*' && l==1)
                match[l][i][0] = 1;
            for(j=1; j<=f[i].length(); j++)
            {
                switch(s[l])
                {
                    case '*':
                        for(t=0; t<=j; t++)
                            if(match[l-1][i][t]==1)
                            {
                                match[l][i][j] = 1;
                                break;
                            }
                            break;  
                    case '?':
                        match[l][i][j] = match[l-1][i][j-1];
                        break;
                    default:
                        if(s[l]==f[i][j-1])
                            match[l][i][j] = match[l-1][i][j-1];
                        break;
                }
            }
        }
    }
    for(i=n[0]+1; i<=n[0]+n[1]; i++)  //如果正则表达式与非操作文件匹配
        if(match[len][i][f[i].length()]==1)
        return false;
    return true;
}

//求最优匹配的回溯法
//len 为当前正则表达式长度
//正则表达式可选字符集的排列顺序先为‘*’，‘？’，操作文件名序列中出现的所有字符按其频率递减的次序随后
void search(int len)
{
    if((curmat > maxmat || (curmat==maxmat && len<minlen)) && ok(len))
    { 
        maxmat = curmat;
        minlen = len;
        for(int i = 0; i <= minlen; i++)
            minmat[i] = s[i]; 
    }
    len++; 
    if(len == 1 || s[len-1] != '*')
    {
        s[len] = '?';
        if(check(len))
            search(len); 
        s[len] = '*';
        if(check(len))
            search(len);
    }
    for(int i=1; i<=p[len-1]; i++)
    {
        s[len] = cha[len-1][i].c;
        if(check(len))
            search(len); 
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream out("output.txt");
    n[0] = 0;
    n[1] = 0;
    p[0] = 0;
    string str;
    char ch;
    while( fin >> str >> ch)
    {
        if(ch == '+')
        {
            f[++n[0]] = str;
            out << f[n[0]] << " " << ch << endl;
            save(f[n[0]][0], 0);
        }
        else
        {
            k[++n[1]] = str;
            out << k[n[1]] << " " << ch << endl;
        }
    }
    for(int i=1; i<=n[1]; i++)
        f[n[0]+i] = k[i];
    memset(match, 0, sizeof(match));
    for(int i=1; i<=n[0]+n[1]; i++)
        match[0][i][0] = 1; 
    maxmat = 0;
    minlen = 255;

    search(0);
    // 匹配最多文件数：
    out << maxmat << endl;
    // 正则表达式
    
    for(int i=0; i<=minlen; i++)
        if ((int)minmat[i]!=0) out << minmat[i];
    out << endl;
    fin.close();
    return 0;
}