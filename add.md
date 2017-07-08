```c
//递归：
class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        if(B==0) return A;
        int sum =A^B;
        int carry=(A&B)<<1;
        return addAB(sum,carry);
    }
};
//迭代：
class UnusualAdd {
public:
    int addAB(int A, int B) {
        // write code here
        int sum=A;
        while(B){
            int t=sum;
            sum^=B;
            B=(t&B)<<1;
        }
        return sum;
    }
};
```
不准用算术运算，考虑通过位操作代替。<br>
整数用二进制表示，考虑二进制时的加法运算。<br>
- 1.不考虑进位，当两位不同时，为1，否则为0，这是异或的操作；
- 2.在加上进位，只有当两位同时为1时，才会进位，即考虑与操作，又因为进位是向前进一位，乘以2即左移。
- 3.两者相加，又是原来函数的递归调用。
