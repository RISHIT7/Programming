#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    string b;
	    cin>>b;
	    for(int i=0;i<b.length();i++){
	        if(b[i]=='p' && b[i+1]=='a' && b[i+2]=='r' && b[i+3]=='t' && b[i+4]=='y'){
	            b[i+2] ='w';
	            b[i+3] ='r';
	            b[i+4] ='i';
	        }
	    }
	    cout<<b<<endl;
	}
	return 0;
}