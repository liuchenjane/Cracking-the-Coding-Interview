```c
//1.直接法
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        vector<int> ret(n,-1);
        int i,j;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++)
                if(A[j]>A[i]){
                    if(ret[i]==-1)
                    ret[i]=A[j];
                    else ret[i]=min(ret[i],A[j]);
                }
        return ret;
    }
};
//2.栈
class NextElement {
public:
    vector findNext(vector A, int n) {
        // write code here
        vector ret(n,-1);
        stack stk,tmp;
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=A[i]){
                tmp.push(stk.top());
                stk.pop();
            }
            ret[i]=stk.empty()?-1:stk.top();
            stk.push(A[i]);
            while(!tmp.empty()){
                stk.push(tmp.top());
                tmp.pop();
            }
        }
        return ret;
    }
};
```
关于栈的解释：
从后往前遍历，当遍历到第i个数时，stk中存储着从i+1到n-1的所有数值的从低到高排列，栈顶元素最小。当要找到比第i个数大的最小数时，从栈顶遍历，遇到第一个大于A[i]的数即可。当遇到比A[i]小的数，就放入栈tmp中存储。找到目的数之后，把当前的A[i]加入栈stk中，再把tmp中所有比A[i]小的数加入stk，此时的stk依然保持着从栈顶到栈底不断增大的顺序。

<br>以[11,13,10,5,12,21,3]，7为例：<br>
初始时：stk=[];tmp=[];<br>

*   i=6:
    ret[6]=[-1];<br>
    stk=[3];<br>
    tmp=[];<br>
*   i=5:
    stk.top()=3 tmp=[3],stk=[];<br>
    ret[5]=-1;stk=[3,21];tmp=[];<br>
*   i=4:
    stk.top()=3 tmp=[3],stk=[21];<br>
    stk.top()=21>12 =>
    ret[4]=21;stk=[3,12,21];tmp=[];<br>
*   i=3:
    stk.top()=3 tmp=[3],stk=[12,21]<br>
    stk.top()=12>5 =>
    ret[3]=12,stk=[3,5,12,21],tmp=[]<br>
*   i=2:
    stk.top()=3tmp=[3],stk=[5,12,21]<br>
    stk.top()=5tmp=[5,3],stk=[12,21]<br>
    stk.top()=12>10 =>
    ret[2]=12;stk=[3,5,10,12,21];tmp=[];<br>
*   i=1:
    stk.top()=3tmp=[3],stk=[5,10,12,21]<br>
    stk.top()=5tmp=[5,3],stk=[10,12,21]<br>
    stk.top()=10tmp=[10,5,3],stk=[12,21]<br>
    stk.top()=12tmp=[12,10,5,3],stk=[21]<br>
    stk.top()=21>13 =>
    ret[1]=21;stk=[3,5,10,12,13,21];tmp=[];<br>
*   i=0:
    stk.top()=3tmp=[3],stk=[5,10,12,13,21];<br>
    stk.top()=5tmp=[5,3],stk=[10,12,13,21];<br>
    stk.top()=10tmp=[10,5,3],stk=[12,13,21];<br>
    stk.top()=12>11 =>
    ret[0]=12,stk=[3,5,10,11,12,13,21]<br>
