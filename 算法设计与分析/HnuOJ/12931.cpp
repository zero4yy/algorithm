#include <stdio.h>
#define INT __int64
#define M 1000000009
int InvFact[100];//预处理n!的逆元

void ProductOfMatrix(int a[2][2],int b[2][2],int c[2][2]){
//矩阵乘法，a*b=c，但是矩阵大小是2*2的
    int i,j,k,d[2][2];
    INT t;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
               t=0LL;
               for(k=0;k<2;k++){
             t+=1LL*a[i][k]*b[k][j];
         }
               d[i][j]=t%M;
    }
}
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            c[i][j]=d[i][j];
}

int Power(int a,int b){     //二分计算a的b次方%M
INT t=1LL,T=a%M;
    while(b){
        if(b&1)t=t*T%M;
        T=T*T%M;
        b>>=1;
    }
    return t;
}    

void PowerOfMatrix(int k,int b[2][2]){
//二分法求递推矩阵的k次幂
        int a[2][2];
        a[0][0]=a[0][1]=a[1][0]=b[0][0]=b[1][1]=1;
        a[1][1]=b[0][1]=b[1][0]=0;
        while(k){
            if(k&1)ProductOfMatrix(a,b,b);
            k>>=1;
            ProductOfMatrix(a,a,a);
        }    
}

int ZZ0(int a,int b,int k){
//求初始值为a,b时的ZZ(0,k)
    int c[2][2];INT t;    
    if(k==1)return a;
    if(k==2)return b;
    PowerOfMatrix(k-2,c);
    t=(1LL*c[0][0]*b+1LL*c[0][1]*a)%M;
    return t;
} 

int Solve(int a,int b,int c,int d){
//函数计算初值为a,b时 ZZ(c,d)的值
    int t1=ZZ0(a,b,d+2*c);
    INT t2=0,t=1;
    int i;
    for(i=0;i<c;i++){
        t2=(t2+((ZZ0(a,b,(c-i)<<1)*t)%M)*InvFact[i])%M;
        t=t*(d+i)%M;
    }
    t1-=t2;
    if(t1<0)t1=t1+M;
    return t1;
}

int main()
{
    int i,t,a,b,c,d;
    InvFact[0]=InvFact[1]=1;
    //预处理出n!关于M的逆元，逆元的含义、求法要自己取找。目前只需要记住，一个数和它的逆元相乘结果取模后是1. 
    //InvFact[n]存储的元素就是n!的逆元 
    for(i=2;i<100;i++) InvFact[i]=(1LL*InvFact[i-1]*Power(i,M-2))%M;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",Solve(a,b,c,d));
    }
    return 0;
}