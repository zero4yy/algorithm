#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;
 
char str1[1005],str2[1005];
int revstr1[1005],revstr2[1005];
int res[1005];
 
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        /*重置部分*/
        memset(res,0,sizeof(res));//重置res,revstr1,revstr2避免上一组数据对下一组数据产生影响  
        memset(revstr1,0,sizeof(revstr1));
        memset(revstr2,0,sizeof(revstr2));
        
        /*读入与转化部分*/  
        scanf("%s%s",str1,str2);//通过两个char数组接受两个字符串类型的数字
        for(int i=0; i<=strlen(str1)-1; i++)//通过两个int数组接受两个转化为整型数值的数字方便进行加法运算
            revstr1[i]=str1[i]-'0';
        for(int i=0; i<=strlen(str2)-1; i++)
            revstr2[i]=str2[i]-'0';
        /*PS:我们当然也可以通过直接对字符进行加减运算获得结果，但相对来说整型加减运算更加方便*/  
 
        /*加法与进位部分*/  
        int length=max(strlen(str1),strlen(str2));//length表示当前结果的最大长度  
        for(int i=0; i<length; i++)
        {
            res[i]+=revstr1[i]+revstr2[i];
            if(res[i]>9)
            {
                res[i+1]+=res[i]/10;
                res[i]%=10;
                if(i+1>=length)         //如果进位时最大位提高了，我们就要更新结果长度  
                    length++;
            }
        }
        
        /*去除前导0部分*/  
        int p=0;                //从第0位开始寻找，如果时0就继续找，知道找到第一个不是0的数  
        while(!res[p])
            p++;
 
        /*输出部分*/  
        for(int i=p; i<length; i++)//这时我们上面计算得到的p（第一个不是0的数的下标），length（结果的长度）就用上了  
            printf("%d",res[i]);
        printf("\n");
    }
    return 0;
}