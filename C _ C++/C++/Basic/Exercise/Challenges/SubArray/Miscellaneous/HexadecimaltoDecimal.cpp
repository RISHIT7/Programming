#include <bits/stdc++.h>
using namespace std;

int hexadecimalToDecimal(string n){
    int ans = 0;
    int x = 1;

    int s= n.size();
    for (int i = s-1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x*(n[i]-'0');
        }
        else if(n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x*(n[i]-'A' +10);
        }
        x *= 16;
    }
    return ans;
}

string DecimalTohexadecimal(int n){
    int x= 1;
    string ans = "";
    while (x<=n){
        x *= 16;
        x /= 16;
    }
    while (x>0){
        int lastDigit = n/x;
        n -= lastDigit*x;
        x /= 16;

        if (lastDigit <= 9){
            ans = ans + to_string(lastDigit);
        }
        else{
            char c = 'A' + lastDigit - 10;
            ans.push_back(c);
        }
        
    }
    return ans;
}


int main()
{
    string i;
    // cin>>i;
    int j;
    cin>>j;
    cout<<DecimalTohexadecimal(j)<<endl;
    return 0;
}