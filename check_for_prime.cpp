#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout<<"Enter the number:";
  cin>>n;
  
  int flag=0;
  
  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
      flag=1;
      break;
    }
  }
  
  if(flag)
    cout<<n<<" is not a prime number";
  else
    cout<<n<<" is a prime number";
  
  return 0;
  
}
