```c
class Change {
public:
    int countChanges(vector<string> dic, int n, string s, string t) {
        // write code here
        vector<bool> used(n);//判断是否被遍历过
        queue<string> q,q2;
        q.push(s);//首先将起始点加入队列
        for (int i = 0; i < n; i++)
          if (dic[i] == s)
            used[i] = 1;
        int cnt = 1;
        while (!q.empty()||!q2.empty()) {
          while (!q.empty()) {
            string st = q.front();
            q.pop();
            for (int i = 0; i<n; i++) {
              if (used[i] == false && can(dic[i], st)) {
                if (dic[i] == t)//到达终点
                  return cnt ;
                used[i] = true;
                q2.push(dic[i]);//下一步要遍历的点加入新的队列中
              }
            }
          }
          cnt++;//步数加一
          
          while (!q2.empty()) {
            string st = q2.front();
            q2.pop();
            for (int i = 0; i<n; i++) {
              if (used[i] == false && can(dic[i], st)) {
                if (dic[i] == t)
                  return cnt ;
                used[i] = true;
                q.push(dic[i]);
              }
            }
          }
          cnt++;
        }
        return -1;
    }
    bool can(string s1,string s2){//判断s1,s2是否只是一个字符不同，如果是，相当于图中的两点可以连通
        if(s1.size()!=s2.size())
            return false;
        bool flag=1;
        for(int i=0;i<s1.size();i++)
            if(s1[i]!=s2[i]){
                if(flag)
                    flag=false;
                else return false;
            }
         return true;       
    }
};
```
该题可以表示成从一个起点到达终点的最少步数，当两字符串可变化表示两点之间可连通，<br>
图的BFS的改变，如果两点可达，从起点开始，不断向外层遍历，用队列存储相同步骤数的节点，直至到达终点或返回-1.<br>
