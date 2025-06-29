# 一.基础算法

## 双指针

模板：

```c++
for(i = 0, j = 0; i < n; i ++ )
{
	while(j < i && check(i, j))
        j++;
  		//每道题目的具体逻辑
}
```



核心思想是将 $O(n^2)$ 的朴素算法优化到 $O(n)$​

利用了<font color=red>**单调性**</font>

# 二.数据结构

## 单链表

![image-20250218152909278](D:\Program Files\Typora\Typora-image\image-20250218152909278.png)

结构体实现方式：

struct Node

{
	int val;

​	Node *next;

};//面试可， 笔试不可

（动态链表的方式）

new Node()；//非常慢

**<font color=red>改进</font>**

## Tire树

高效的存储和查找字符串集合的数据结构

## 并查集

```htaccess
1.两个集合合并
2.询问两个元素是否在一个集合中
```

近乎 $O(1)$ 的时间复杂度支持以上两个操作

基本原理：每个集合用一颗树来表示。树根的编号就是整个集合的编号。每个节点存储它的父节点，p[x] 表示x的父节点



问题1：如何判断树根：if(p[x] == x)

问题2：如何求x的集合编号：while(p[x] != x) x = p[x];

问题3：如何合并两个集合：p[x]是x的集合编号，p[y]是y的集合编号，p[x] = y

![image-20250227155510167](D:\Program Files\Typora\Typora-image\image-20250227155510167.png)



优化：路径压缩

<img src="D:\Program Files\Typora\Typora-image\image-20250227155531525.png" alt="image-20250227155531525" style="zoom: 25%;" /><img src="D:\Program Files\Typora\Typora-image\image-20250227155607387.png" alt="image-20250227155607387" style="zoom: 50%;" />

## 哈希表

![image-20250227104515475](D:\Program Files\Typora\Typora-image\image-20250227104515475.png)

拉链法：

![image-20250227105121279](D:\Program Files\Typora\Typora-image\image-20250227105121279.png)

N一般取：大于上限的第一个质数

开放寻址法：

![image-20250227140137272](D:\Program Files\Typora\Typora-image\image-20250227140137272.png)

N一般开2~3倍
