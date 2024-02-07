#include<iostream>
using namespace std;
int fn(int n){
if(n==1)
return 1;
int t=2*fn(n-1)+1;
return t;
}
void steps(int n,int first,int second, int third){
if(n==0)
return;
steps(n-1,first,third,second);
cout<<first<<" "<<third<<endl;
steps(n-1,second,first,third);
}
int main(){
int N;
cin>>N;
cout<<fn(N)<<endl;
steps(N,1,2,3);
}