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
