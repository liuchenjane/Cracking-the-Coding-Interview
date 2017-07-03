//解1：
class Different {
public:
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
};
//解2：
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
//解3：
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
