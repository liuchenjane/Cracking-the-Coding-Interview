class Zipper {
public:
    string zipString(string iniString) {
        // write code here
        string s;
        int i,n=iniString.size();
        int cnt=0;
        for(i=0;i<n;i++){
            if(i==0 || iniString[i]!=iniString[i-1]){
                if(cnt>0)
                    s+=to_string(cnt);
                s+=iniString[i];
                cnt=1;
            } else
                cnt++;
        }
        s+= to_string(cnt);
        return s.size()<iniString.size()?s:iniString;
    }
};
