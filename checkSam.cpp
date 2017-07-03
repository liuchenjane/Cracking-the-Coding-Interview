//解1：hash
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
       vector<int> h1(256),h2(256);
        int i,na=stringA.size(),nb=stringB.size();
        for(i=0;i<na;i++)
            h1[stringA[i]]++;
        for(i=0;i<nb;i++)
            h2[stringB[i]]++;
        for(i=0;i<256;i++)
            if(h1[i]!=h2[i])
                return false;
        return true;
    }
};
//解2：排序
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        // write code here
        int i,na=stringA.size(),nb=stringB.size();
        if (na!=nb) return false;
        sort(stringA.begin(),stringA.end());
        sort(stringB.begin(),stringB.end());
        return stringA==stringB;
    }
};
