
/*
Subarray with given sum
#include<iostream>
using namespace std;

int findSumContiginous(int n,int sum)
{
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    int curr_sum;
    for(int i=0;i<n;i++)
    {
        curr_sum = a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(curr_sum==sum)
            {
                cout<<i<<" "<<j-1;
                return 1;
            }
            
            if(curr_sum>sum || j==n)
             break;
            curr_sum=curr_sum+a[j];
        }
    }
    
    return 0;
}
int main()
{
    int t,n,s;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>s;
        findSumContiginous(n,s);
    }
    return 0;
}
*/

/*
Kadane’s Algorithm
#include<iostream>
#include<limits.h>
using namespace std;

void maxSubArray(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
     
    int max_so_far=INT_MIN;
    int max_ending_here=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here=max_ending_here+a[i];
        if(max_so_far<max_ending_here)
        {
         max_so_far=max_ending_here;   
        }
        if(max_ending_here<0)
         max_ending_here=0;
    }
    cout<<max_so_far;
}

int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        maxSubArray(n);
    }
    return 0;
}*/

/*
Missing number in array
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int sum1,sum2=0,n;
    int a[10];
    cin>>n;
    sum1=((n+1)*(n+2))/2;
    cout<<sum1<<"\n";
    
    for(int i=0;i<n;i++)
     cin>>a[i];
     
    for(int i=0;i<n;i++)
     sum2+=a[i];
    
    cout<<sum2<<"\n";     
    cout<<"output: "<<abs(sum2-sum1);
    return 0;
}
*/

/*
//merging 2 arrays
#include<iostream>
using namespace std;

int mergeArray(int n)
{
    int a[n],b[n];
for(int i=0;i<n;i++)
 cin>>a[i];
for(int i=0;i<n;i++)
 cin>>b[i];
 
//logic
int c[n];
int k=0;
for(int i=0;i<n;i++)
{
    c[k]=a[i];
    k++;
}

for(int i=0;i<n;i++)
{
    c[k]=b[i];
    k++;
}

//output
for(int i=0;i<k;i++)
 cout<<c[i]<<"\t";
 
 return 0;
}

int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        mergeArray(n);
    }
    return 0;
}
*/

/*
//Merge two sorted arrays
#include<iostream>
using namespace std;

int mergeArray(int n1,int n2)
{
    int a[n1],b[n2];
for(int i=0;i<n1;i++)
 cin>>a[i];
for(int i=0;i<n2;i++)
 cin>>b[i];
 
 int k=0;
 int c[1000];
 int i=0,j=0;
 while(i<n1 && j<n2)
 {
     if(a[i]<b[j])
      {
        c[k]=a[i];
        k++;
        i++;
      }else
      {
          c[k]=b[j];
          k++;
          j++;
      }
 }
 while(i<n1)
  {
      c[k]=a[i];
      i++;
      k++;
  }
  while(j<n2)
  {
      c[k]=b[j];
      j++;
      k++;
  }
  
 //print sorted array
 for(int i=0;i<k;i++)
  cout<<c[i]<<" ";
}


int main()
{
    int t,n1,n2;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n1>>n2;
        mergeArray(n1,n2);
    }
    return 0;
}
*/
