#include <bits/stdc++.h>
 
using namespace std;
//random number generation
long long gRand(long long min=0,long long max=100){
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static long long RMin = 0;
    static long long RMax = 1000000000000000000ll;
    static std::uniform_int_distribution<long long> Distribution(RMin, RMax);
    return min +(Distribution(gen))%(max-min+1);
}
bool prob(int x){
    if(gRand(1234,123400)%100<x) return true;
    return false;
}
int statdist(const vector<int> &percentages){
    int res=gRand(123456,12345600)%100;
    long long sum=0;
    int q=0;
    for(auto i:percentages){
        sum+=i;
        q++;
        if(res<sum){
            return q;
        }
    }
    return q;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int numCommands=1000;
    int setNumMax=20;
    int probabilityToIncreaseSetNumber=10;
    int sid,value,sid1,sid2;
    int maxValue=50;
    int numfiles;
    cout<<"Number of commands: ";
    cout.flush();
    cin>>numCommands;
    cout<<endl;
    cout<<"maxNumberOfSets: ";
    cout.flush();
    cin>>setNumMax;
    cout<<endl;
    cout<<"Probability to add a new set on each command(out of 100) (int): ";
    cout.flush();
    cin>>probabilityToIncreaseSetNumber;
    cout<<endl;
    cout<<"Magnitude of max +ve or -ve value as an insert to set: ";
    cout.flush();
    cin>>maxValue;
    cout<<endl;
    cout<<"Number of files to generate: ";
    cout.flush();
    cin>>numfiles;
    cout<<endl;
    vector<int> distbution={ 20,       20,       10,      10,    10,   5,   10,    10,      5};
                        // insert   delete   bel-to   unio     inter   sz  diff  sdiff   print
    for(int k=1;k<=numfiles;k++){
        int csetNum=0;
        cout<<"creating test-"<<k<<".txt"<<endl;
        ofstream fout("test-"+to_string(k)+".txt");
        fout<<"1 0 1"<<endl;
        for(int i=0;i<numCommands;i++){
            switch(statdist(distbution)){
                case 1:
                    sid=-1;
                    if(prob(probabilityToIncreaseSetNumber)){
                        if(csetNum<setNumMax){
                            csetNum++;
                            sid=csetNum;
                        }
                    }
                    sid=(sid==-1?gRand(0,csetNum):sid);
                    value=gRand(-maxValue,maxValue);

                    fout<<"9 "<<sid<<endl;
                    fout<<"1 "<<sid<<" "<<value<<endl;
                    fout<<"9 "<<sid<<endl;
                    break;
                case 2:
                    sid=gRand(0,csetNum+3);
                    value=gRand(-maxValue,maxValue);

                    fout<<"9 "<<sid<<endl;
                    fout<<"2 "<<sid<<" "<<value<<endl;
                    fout<<"9 "<<sid<<endl;
                    break;
                case 3:
                    sid=gRand(0,csetNum+3);
                    value=gRand(-maxValue,maxValue);

                    fout<<"9 "<<sid<<endl;
                    fout<<"3 "<<sid<<" "<<value<<endl;
                    break;
                case 4:
                    sid=-1;
                    if(prob(probabilityToIncreaseSetNumber)){
                        if(csetNum<setNumMax){
                            csetNum++;
                            sid=csetNum;
                        }
                    }
                    sid=(sid==-1?gRand(0,csetNum):sid);
                    value=gRand(0,csetNum);

                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    fout<<"4 "<<sid<<" "<<value<<endl;
                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    break;
                case 5:
                    sid=-1;
                    if(prob(probabilityToIncreaseSetNumber)){
                        if(csetNum<setNumMax){
                            csetNum++;
                            sid=csetNum;
                        }
                    }
                    sid=(sid==-1?gRand(0,csetNum):sid);
                    value=gRand(0,csetNum);

                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    fout<<"5 "<<sid<<" "<<value<<endl;
                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    break;
                case 6:
                    sid=-1;
                    if(prob(probabilityToIncreaseSetNumber)){
                        if(csetNum<setNumMax){
                            csetNum++;
                            sid=csetNum;
                        }
                    }
                    sid=(sid==-1?gRand(0,csetNum):sid);

                    fout<<"9 "<<sid<<endl;
                    fout<<"6 "<<sid<<endl;
                    break;
                case 7:
                    sid=-1;
                    if(prob(probabilityToIncreaseSetNumber)){
                        if(csetNum<setNumMax){
                            csetNum++;
                            sid=csetNum;
                        }
                    }
                    sid=(sid==-1?gRand(0,csetNum):sid);
                    value=gRand(0,csetNum);

                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    fout<<"7 "<<sid<<" "<<value<<endl;
                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    break;
                case 8:
                    sid=-1;
                    if(prob(probabilityToIncreaseSetNumber)){
                        if(csetNum<setNumMax){
                            csetNum++;
                            sid=csetNum;
                        }
                    }
                    sid=(sid==-1?gRand(0,csetNum):sid);
                    value=gRand(0,csetNum);

                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    fout<<"8 "<<sid<<" "<<value<<endl;
                    fout<<"9 "<<sid<<endl;
                    fout<<"9 "<<value<<endl;
                    break;
                case 9:
                    fout<<"9 "<<gRand(0,setNumMax)<<endl;
            }

            
        }
        fout.close();
    }
    cout<<"Done creating test file"<<endl;
    cout<<"Generating answer files"<<endl;
    for(int i=1;i<=numfiles;i++){
        cout<<"creating result-test-"<<i<<".txt"<<endl;
        string s="python3 ./solver.py < ./test-"+to_string(i)+".txt >./result-test-"+to_string(i)+".txt";
        system(&s[0]);
    }
    return 0;
}
