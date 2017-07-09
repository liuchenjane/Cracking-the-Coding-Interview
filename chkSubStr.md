```c
class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        // write code here
        Trie *root=new Trie();
        vector<bool> ret(n);
        int i, n1 = s.size();
        for (i = 0; i<n1; i++) {
          root->insert(s.substr(i));//将所有子串都插入Trie树
        }
        for(int i=0;i<n;i++)
            ret[i]=root->search(p[i]);//判断是否是子串
        return ret;
    }
    //下面是建Trie
    struct TrieNode{
        TrieNode* childs[26];//每个节点最多有26个孩子
        TrieNode(){
            memset(childs,0,sizeof(childs));
        }
    };
    class Trie{
        public:
        TrieNode* root;
        Trie(){
            root=new TrieNode();
        }
        void insert(string s){
            if(s=="")return;
            TrieNode* p=root;
            for(int i=0;i<s.size();i++){
                char c=s[i];
                if(p->childs[c-'a']==nullptr)
                    p->childs[c-'a']=new TrieNode();
                p=p->childs[c-'a'];
            }
        }   
        bool search(string s){
            TrieNode* p=root;
            for(int i=0;i<s.size();i++){
                if(p->childs[s[i]-'a']==nullptr)
                    return false;
                p=p->childs[s[i]-'a'];
            }
            return true;
        }
    };
};
```
以abc为例,其后缀树如下：<br>
```c
           root
         /   |   \
        a    b    c
       /    /
      b    c
     /
    c       
```
对["a","b","c","d"]中，判断是否是s=“abc”的子串，只要判断能否在以s建立的Trie中遍历到它们即可。
