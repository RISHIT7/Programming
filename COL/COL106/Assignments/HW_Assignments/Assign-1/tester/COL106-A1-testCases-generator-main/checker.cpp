#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int test_cases = 1;  // change this here

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    system("mkdir output_generated");
    for(int i=1;i<=test_cases;i++){
        cout<<"generating output "<<i<<endl;
        string s="main <testcases/test-"+to_string(i)+".txt> myoutput-test-"+to_string(i)+".txt";
        system(&s[0]);
    }
    for(int i=1;i<=test_cases;i++){
        cout<<"checking test "<<i<<endl;
        string s="fc /n /w myoutput-test-"+to_string(i)+".txt testcases/result-test-"+to_string(i)+".txt";
        system(&s[0]);
    }
    return 0;
}