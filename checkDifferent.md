## 1.用到O(1)存储结构 <br>
hash表存储每个字符出现的次数，如超过1，就有重复。
```c
 bool checkDifferent(string iniString) {
        // write code here
        int n=iniString.size();
        if(n>256) return false;
        if(n==0)
            return true;
        vector<int> hash(256);
        for(int i=0;i<n;i++){
            int x=iniString[i];
            hash[x]++;
            if(hash[x]>1)
                return false;
        }
        return true;
    }
```  
时间复杂度：O(n);空间复杂度： O(1) <br>

## 2. 每一个字符与其他都比较
```c
class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        int n=iniString.size();
        if(n>256) return false;
      
        for (int i=0; i<n; i++){
            for (int j=0;j<n;j++){
                if(i!=j && (iniString[i] == iniString[j]))
                    return false;
            }
        }
        return true;
    }
};
```
时间复杂度：O(n)，空间复杂度：O(1)

## 3. 排序

```c
class Different {
public:
    bool checkDifferent(string iniString) {
        // write code here
        int n=iniString.size();
        if(n>256) return false;
         
        sort(iniString.begin(),iniString.end());
        for (int i=0; i<n-1; i++){
            if(iniString[i] == iniString[i+1])
                return false;
        }
        return true;
    }
};
```
时间复杂度：O(nlogn), 排序算法可能会占用额外空间
