```c
//1.直接暴力搜索
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        vector<int> ret(n,-1);
        int i,j;
        for(i=0;i<n-1;i++)
            for(j=i+1;j<n;j++){
                if(A[j]>A[i]){
                    ret[i]=A[j];
                    break;
                }
            }
        return ret;
    }
};
//时间：O(N^2)

//2.栈
class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        vector<int> ret(n,-1);
        stack<int> stk;//用来存储下标，还没遇到更大元素的下标
        stk.push(0);
        for(int i=1;i<n;i++){
            while(!stk.empty() && A[i]>A[stk.top()]){
                ret[stk.top()]=A[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ret;
    }
};
```
以[11,13,10,5,12,21,3]为例，说明栈：<br>
初始：stk[0],ret全是-1；
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [0]<br>
ret:     []<br>
- 1. i=1<br>
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [     1]<br>
ret:    [13]<br>
- 2. i=2<br>
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [     1,  2]<br>
ret:    [13]<br>
- 3. i=3<br>
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [     1,  2, 3]<br>
ret:    [13]<br>
- 4. i=4<br>
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [     1,         4]<br>
ret:    [13 ,-1, 12, 12]<br>
- 5. i=5<br>
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [                    5]<br>
ret:    [13 ,21, 12, 12, 21]<br>
- 6. i=6<br>
数组：   [11, 13, 10, 5, 12, 21, 3]<br>
下标：   [0,   1,  2, 3,  4,  5, 6]<br>
栈：     [                    5, 6]<br>
ret:    [13 ,21, 12, 12, 21]<br>
