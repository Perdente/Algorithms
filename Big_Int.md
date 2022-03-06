### Condition for _a_ string to be $lexicographically$ $smaller$ than _b_ string
- If both strings are same size then $i$ th character from string $a$ is less than $i$ th character from string $b$.
- If the $size$ is not same, then we scan for $min(a.size(), b.size())$ and check if $i$ th character from string $a$ is less than $i$ th character from string $b$.
- If both strings are same till $min(a.size(), b.size())$ then minimum sized string is the _smaller_ one.

```c++
string a, b; cin >> a >> b;
int n = a.size(), m = b.size();
for (int i = 0; i < min(n, m); ++i) {
    if (a[i] < b[i]) {
        cout << a << '\n'; return;
    } else if (a[i] > b[i]) {
        cout << b << '\n'; return;
    }
}
if (n == m) {
    cout << "Both are same, bitch :)" << '\n'; return;
}
cout << (n < m ? a : b) << '\n';
```


### Print Lexicographically Bigger String
```c++
auto lexicographically_larger=[&](string str1,string str2)->string{
    int n=str1.size(),m=str2.size();
    if(n>m) return str1;
    if(n<m) return str2;
    for(int i=0;i<n;++i){
        if(str1[i]>str2[i]) return str1;
        else if(str1[i]<str2[i]) return str2;
    }return "Both are same";
};

```

### Check if it's _strictly_ Lexicographically Bigger String or not?
```c++
auto bigger=[&](string a, string b){
    if (a.length() > b.length()) return true;
    if (a.length() < b.length()) return false;
    for(int i=0;i<a.length();++i)
    {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return false;
};

```

### Check if it's Lexicographically Bigger or equal String or not?
```c++
auto bigger2=[&](string a, string b){
    if (a.length() > b.length()) return true;
    if (a.length() < b.length()) return false;
    for(int i=0;i<a.length();++i)
    {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return true;
};

```

### Addition of two big integer or strings
```c++
auto add=[&](string str1, string str2)->string{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;
    int carry = 0;
    for (int i=n1-1; i>=0; i--)
    {
        int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry) str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    while(str.size() > 1 && str[0] == '0') str.erase(0, 1);
    return str;
};

```

### Subtraction of two big integer or strings
```c++
auto sub=[&](string str1, string str2)->string{
    if (bigger(str2, str1)) swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++) 
    {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++) 
    {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
 
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    while (str.size() > 1 && str[0] == '0') str.erase(0, 1);
    return str;
};

```

### Multiplication of two big integer or strings
```c++
auto mul=[&](string A, string B)->string{
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    string C;
    C.resize(A.length() + B.length(),'0');
    for(int i=0;i<A.length();++i)
    {
        int c = 0;
        for(int j=0;j<B.length();++j)
        {
            c += ((A[i] - '0') * (B[j] - '0') + C[i + j] - '0');
            C[i + j] = (char)(c%10 + '0');
            c/=10;
        }
        if (c > 0) C[i + B.length()] += c;
    }
    reverse(C.begin(),C.end());
    while (C.size() > 1 && C[0] == '0') C.erase(0, 1);
    return C;
};


```

### Division of a big integer or string with an integer
```c++
auto div=[&](string number, int divisor)->string{
    string ans = "";
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) 
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
    while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
    if (ans.length() == 0) return "0";
    return ans;
};

```
### Find the quotient of two big integer or strings
```c++
// call every function except lex larger string
auto dv=[&](string a, string b)->string{ // 'a' ke 'b' diye vhag kore vhagfol store korbe
    if (bigger(b, a)) return "0";
    if (a == "0") return "0";
    string l = "0";
    string r = a;
    string mid, mid2;
    while (bigger2(r, l))
    {
        mid = add(r, l);
        if ((mid[mid.length() - 1] - '0') % 2 == 1) mid[mid.length() - 1]--;
        mid = div(mid, 2);
        if (mid == "0") break;
        mid2 = mul(mid, b);
        if (bigger(mid2, a)) r = sub(mid, "1");
        else l = add(mid, "1");
    }
    return r;
};

```

### Find the reminder of two big integer or strings
```c++
// call every function except lex larger string
auto md=[&](string a, string b)->string{//vhagses store korbe
    if (bigger(b, a)) return a;
    if (a == "0") return "0";
    if (b == "1") return "0";
    string l = "0";
    string r = a;
    string mid, mid2;
    while (bigger2(r, l))
    {
        if (mid == "0") break;
        mid = add(r, l);
        if ((mid[mid.length() - 1] - '0') % 2 == 1) mid[mid.length() - 1]--;
        mid = div(mid, 2);
        mid2 = mul(mid, b);
        if (bigger(mid2, a)) r = sub(mid, "1");
        else l = add(mid, "1");
    }
    mid = mul(r, b);
    mid = sub(a, mid);
    while (mid.size() > 1 && mid[0] == '0') mid.erase(0, 1);
    if (mid == b) return "0";
    return mid;
};

```

### GCD of two big integer or strings
```c++
// call md function
function<string(string,string)>strgcd=[&](string a, string b)->string{
    if (a == "0")return b;
    return strgcd(md(b, a), a);
};

```
### GCD of two big integer or strings
```c++
// call dv,mul and strgcd functions
auto strlcm=[&](string a,string b)->string{
    return dv(mul(a,b),strgcd(a,b));
};

```


