#Transformations
===============

##根据analysis，代码可以优化如下：
1.定义MAXN 
2.定义一个structure:board,里面包含 int n 和 char a[MAXN][MAXN]
3.函数返回值为board 这样可以多次调用实现180度和270度的旋转
4.为了减少程序执行量，应该用if(#1) else {if (#2) else{....}}的方法 
