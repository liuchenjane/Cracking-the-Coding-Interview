class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        int cnt = 0, i, n = iniString.size();
			for (i = 0; i<n; i++)
				if (iniString[i] == ' ')
					cnt++;
			if (cnt == 0) return iniString;
			string s;
			for (i = 0; i < n; i++) {
				if (iniString[i] == ' ')
					s.append("%20");
				else
					s+=(iniString[i]);
			}
			//cout << s << endl;
			return s;
    }
};
