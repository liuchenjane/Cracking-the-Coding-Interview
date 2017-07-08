```c
class Count2 {
public:
    int countNumberOf2s(int n) {
        // write code here
        int max=bits(n);
        int sum=0;
        for(int i=1;i<=max;i++)
            sum+=countAt_ith(n,i);
        return sum;
    }
    int bits(int n){//计算总位数
        int ret=0;
        while(n){
            ret++;
            n/=10;
        }
        return ret;
    }
   int countAt_ith(int n,int i){//在第i位有多少个2
        int dived=pow(10,i-1);
        int ret=n/dived;
        int sum=0;
        if((ret%10)>2)//情况3
            sum=(ret/10+1)*dived;
        else if((ret%10)==2)//情况2
            sum=(ret/10)*dived+n%dived+1;
        else sum=(ret/10)*dived;//情况1
        return sum;
   }
};
```
2的个数总和是在各个位上的2的总个数。<br>
对于整数n,其在第i位（从低位往高位数）上的2的个数求法如下：<br>
根据第i位的数值可以分为3中情况，分别是小于2，等于2和大于2<br>
以6x123为例，i=4,x依次取小于2、等于2、大于2的三种情况；<br>
- 1. 第i位小于2
假设x=1,可知0\~n中，第i位取2的数值范围在：02000\~02999、12000\~12999、...、52000~52999；共有6*1000个；<br>
这里6是第i+1位的数值大小。<br>
- 2. 第i位等于2
假设x=2,可知0\~n中，第i位取2的数值范围在:02000\~02999、12000\~12999、...、52000\~52999、62000\~62123；共有6*1000+123+1个；<br>
这里6是第i+1位的数值大小,123是n%1000。<br>
- 3. 第i位大于2
假设x=4,可知0\~n中，第i位取2的数值范围在:02000\~02999、12000\~12999、...、52000\~52999、62000\~62999；共有7*1000个；
