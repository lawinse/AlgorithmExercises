class Solution {
public:
    string multiply(string a,string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len_a=a.length();
    int len_b=b.length();
    int max_len = max(len_a,len_b);
    int *c;
    c = new int [2*max_len+10];
    memset(c,0,sizeof(int)*(2*max_len+10));
    for (int i = 0; i < len_a;++i)
    for (int j = 0; j < len_b;++j)
    c[j+i]+=(a[i]-'0')*(b[j]-'0');
    for (int i = 0; i < len_a+len_b-1; ++i)
    {
    c[i+1]+=c[i]/10;
    c[i]=c[i]%10;
    }
    bool flg=1;
    string res="";
    for (int i = 2*max_len+8;i>=0;--i)
    {
    if (c[i]==0&&flg) continue;
    else res+=('0'+c[i]),flg=0;
    }
    delete [] c;
    if (res == "") res = "0";
    return res;
}

    
};