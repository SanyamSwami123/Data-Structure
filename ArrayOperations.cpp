
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

/*
//Q.Rearrange Array Alternately
//Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively 
//i.e first element should be max value, second should be min value, third should be second max, 
//fourth should be second min and so on...

1 <=T<= 100
1 <=N<= 107
1 <=arr[i]<= 107

Example:
Input:
2
6
1 2 3 4 5 6
11 
10 20 30 40 50 60 70 80 90 100 110

Output:
6 1 5 2 4 3
110 10 100 20 90 30 80 40 70 50 60

Explanation:
Testcase 1: Max element = 6, min = 1, second max = 5, second min = 2, and so on... Modified array is : 6 1 5 2 4 3.

#include<iostream>
using namespace std;

void Rearange(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    int temp[n];
    int small=0,large=n-1;
    
    int flag=true;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
         temp[i]=a[large];
         large--;
        }else{
            temp[i]=a[small];
            small++;
        }
        flag=!flag;
    }
    
    //display
    for(int i=0;i<n;i++)
     cout<<temp[i];
}


int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        Rearange(n);
    }
    return 0;
}
*/


/*
Count Inversions in an array

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If array is already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j

Example:

Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).

#include<iostream>
using namespace std;

#include <bits/stdc++.h> 
using namespace std; 
  
int getInvCount(int n) 
{ 
    for(int i=0;i<n;i++)
     cin>>arr[i];
    int inv_count = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (arr[i] > arr[j]) 
                inv_count++; 
  
    return inv_count; 
} 

int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int 
        getInvCount(n);
    }
    return 0;
}
*/

/*

SORTINGS

#include<iostream>
using namespace std;

//selection sort:
//this is the sorting technique which choose the smallest element and place it in the correct place.
void sort(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    int temp;
    for(int i=0;i<n-1;i++)
    {
        int small=a[i];
        int p=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<small)
            {
                small=a[j];
                p=j;
            }
        }
        temp=a[p];
        a[p]=a[i];
        a[i]=temp;
    }
    
    //print 
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}

// Bubble sort:
//it's the sorting technique which check the adjecent elements.
void sort(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
     
     
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    //print 
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}

int main()
{
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        sort(n);
    }
    return 0;
}
*/
