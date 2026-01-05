#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    ifstream inputFile("d2p1.txt");

    if (!inputFile)
    {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string s;

    unsigned long long ans = 0;
    string temp;
    while (getline(inputFile, line))
    {
        s = line;
        size_t pos = s.find('-');
        string start = s.substr(0,pos);
        string end = s.substr(pos + 1);
        
        long long st = stoll(start);
        // cout<<st<<endl;
        long long ed = stoll(end);
        // cout<<ed<<endl;
        
        for(st;st<=ed;st++){
            string ss = to_string(st);
            int len = ss.length();
            int half = len/2;
            if(len % 2 == 0){
                string t1 = ss.substr(0,half);
                string t2 = ss.substr(half);
                if(t1 == t2){
                    ans+=st;
                    // cout<<st<<endl;
                }
            }
        }
    }
    inputFile.close();
    cout << ans;
    return 0;
}
