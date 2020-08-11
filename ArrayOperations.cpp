
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

/*
Equilibrium point

Q.Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs
in the array. Equilibrium position in an array is a position such that the sum of 
elements before it is equal to the sum of elements after it.

Input: A[] = {-7, 1, 5, 2, -4, 3, 0}
Output: 2
2 is an equilibrium element, because:
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]

#include<iostream>
using namespace std;

int EquilibriumPoint(int n)
{
 int i,j;
 int a[n];
 
 for(i=0;i<n;i++)
  cin>>a[i];
  
 for(i=0;i<n;i++)
 {
     
     int leftSum=0;
     for(j=0;j<i;j++)
     {
         leftSum=leftSum+a[j];
     }
     
     int rightSum=0;
     for(j=i+1;j<n;j++)
     {
         rightSum=rightSum+a[j];
     }
     
     if(rightSum == leftSum)
       return a[i];
 }
 
 return -1;
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int result = EquilibriumPoint(n);
        cout<<result<<"\n";
    }
    return 0;
}
*/

/*
Leaders in an array

Q.Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all 
the elements to its right side. Also, the rightmost element is always a leader. 

Example:
Input:
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
Output:
17 5 2
4 0
7 7 3

Explanation:
Testcase 3: All elements on the right of 7 (at index 0) are smaller than or equal to 7. 
Also, all the elements of right side of 7 (at index 3) are smaller than 7. And, the last 
element 3 is itself a leader since no elements are on its right.

#include<iostream>
using namespace std;
int LeaderArray(int n)
{
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];
    
    int flag=1;
    int temp[n];
    int k=0;
for(int i=0;i<n;i++)
{
    for(int j=i+1;j<n;j++)
    {
     if(a[i]<a[j])
     {
         flag=0;
         break;
     }else
     {
         flag=1;
     }
    }
    if(flag==1)
    {
        temp[k]=a[i];
        k++;
    }else{
        continue;
    }
}
 
 for(int i=0;i<k;i++)
  cout<<temp[i]<<" ";
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        LeaderArray(n);
        cout<<"\n";
    }
    return 0;
}
*/

/*

Minimum Platforms

Given arrival and departure times of all trains that reach a 
railway station. Your task is to find the minimum number of platforms 
required for the railway station so that no train waits.

Note: Consider that all the trains arrive on the same day and leave 
on the same day. Also, arrival and departure times will not be same for
a train, but we can have arrival time of one train equal to departure 
of the other. In such cases, we need different platforms, i.e at any 
given instance of time, same platform can not be used for both departure
of a train and arrival of another.

#include<iostream>
#include<algorithm>
using namespace std;

void MinimumPlatform(int n)
{
    int arrival[n], departure[n];
    
    for(int i=0;i<n;i++)
     cin>>arrival[i];
     
    for(int i=0;i<n;i++)
     cin>>departure[i];
     
     //sort
     sort(arrival,arrival+n);
     sort(departure,departure+n);
     
     
      int platformNeeded=0,result=0,i=0,j=0;
      
      while(i<n && j<n)
      {
          
          if(arrival[i]<=departure[j])
          {
            platformNeeded++;
            i++;
          }
          else if(arrival[i]>departure[j])
          {
              platformNeeded--;
              j++;
          }
          
          if(result<platformNeeded)
          {
              result=platformNeeded;
          }
      }
      cout<<platformNeeded;
}
int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        MinimumPlatform(n);
        cout<<"\n";
    }
    return 0;
}
*/

/*
Reverse the group ??????????
#include<iostream>
using namespace std;

void ReverseArrayInGroup(int n,int p)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    int temp[n];
    int k=0;
   
   for(int i=0;i<n;i++)
   {
       int left=i;
       
   }
    
    for(int i=0;i<k;i++)
     cout<<temp[i]<<" ";
}
int main()
{
    int t;
    cin>>t;
    int n,k;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        ReverseArrayInGroup(n,k);
    }
    return 0;
}
*/

/*

Kth smallest element

Given an array arr[] and a number K where K is smaller than size of array, 
the task is to find the Kth smallest element in the given array. It is given 
that all array elements are distinct.
#include<algorithm>
#include<iostream>
#include<limits.h>
using namespace std;

void KsmallestElement(int n, int k)
{
int a[n];
for(int i=0;i<n;i++)
 cin>>a[i];
 
sort(a,a+n);

cout<<a[k-1];
}

int main()
{
    int t;
    cin>>t;
    int n,k;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k; //n: no. of element in array, k=position of smallest elemnt
        KsmallestElement(n,k);
    }
    return 0;
}
*/

/*
k largest(or smallest) elements in an array 

//Write an efficient program for printing k largest elements in an array. Elements in array can be in any order.
//For example, if given array is [1, 23, 12, 9, 30, 2, 50] 
//and you are asked for the largest 3 elements i.e., k = 3 then your program should print 50, 30 and 23.


#include<algorithm>
#include<iostream>
#include<limits.h>
using namespace std;

void KLargestElements(int n, int k)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    sort(a,a+n);
    
    for(int i=n-1;i>k;i--)
     cout<<a[i]<<" ";
}

int main()
{
    int t;
    cin>>t;
    int n,k;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k; //n: no. of element in array, k=position of smallest elemnt
        KLargestElements(n,k);
    }
}
*/







/*
//Trapping Rain Water
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

#include<iostream>
#include<algorithm>
using namespace std;

 void RainWaterTrap(int n)
 {
     int a[n];
     for(int i=0;i<n;i++)
      cin>>a[i];
      
      //logic
      
      // To store the maximum water  
    // that can be stored
      int result=0;
      for(int i=1;i<n-1;i++)
      {
          // Find the maximum element on its left
          int left=a[i];
          for(int j=0;j<i;j++)
          {
           left=max(left,a[j]);    
          }
          
          // Find the maximum element on its right
          int right=a[i];
          for(int j=i+1;j<n;j++)
          {
              right=max(right,a[j]);
          }
          
          // Update the maximum water
          result=result+(min(left,right)-a[i]);
      }
      
      cout<<result<<"\n";
 }
 
int main()
{
int t;
cin>>t;
int n;
for(int i=1;i<=t;i++)
 {
     cin>>n;
     RainWaterTrap(n);
 }
    return 0;
}
*/

/*
#include<iostream>
using namespace std;
void chocolate(int n,int m)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    int result;
    //logic
    for(int i=0;i<n-m;i++)
    {
        for(int j=i;j<m;j++)
        {
            
        }
    }
}

int main()
{
    int t;
    cin>>t;
    int n,m;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        chocolate(n,m);
    }
    return 0;
}
*/

/*
Find a partition point in array
or
Element with left side smaller and right side greater
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7

#include<iostream>
#include<algorithm>
using namespace std;

int fun(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    
    
    for(int i=1;i<n-1;i++)
    {
        int flag=0;
       for(int j=0;j<i;j++)
       {
           if(a[i]<=a[j])
            {
                flag=1;
                break;
            }
            
       }
       
       for(int j=i+1;j<n;j++)
       {
           if(a[i]>=a[j])
            {
            flag=1;
            break;
           }
       }
       
       if(flag==0)
        return a[i];
    }
return -1;    
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int result=fun(n);
        cout<<result<<"\n";
    }
    return 0;
}
*/

/*
Convert array into Zig-Zag fashion
Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

#include<iostream>
#include<algorithm>
using namespace std;

void fun(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            if(a[i]>a[i+1])
             swap(a[i],a[i+1]);
        }
        else{
            if(a[i]<a[i+1])
            {
                swap(a[i],a[i+1]);
            }
        }
        
        flag=!flag;
    }
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        fun(n);
    }
    return 0;
}
*/

/*

Find the index of first 1 in a sorted array of 0’s and 1’s
Last Updated: 22-07-2019
Given a sorted array consisting 0’s and 1’s. The problem is to find the index of first ‘1’ in the sorted array. It could be possible that the array 
consists of only 0’s or only 1’s. If 1’s are not present in the array then print “-1”.

Examples :

Input : arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
Output : 6
The index of first 1 in the array is 6.

Input : arr[] = {0, 0, 0, 0}
Output : -1
1's are not present in the array.


#include<iostream>
using namespace std;

int fun(int n)
{
int a[n];
for(int i=0;i<n;i++)
 cin>>a[i];
 
for(int i=0;i<n;i++)
{
    if(a[i]==1)
     return i;
}
return -1;
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=n;i++)
    {
     cin>>n;
     int result=fun(n);
     cout<<result<<"\n";
    }
    return 0;
}
*/



/*
//Trapping Rain Water
//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

#include<iostream>
#include<algorithm>
using namespace std;

 void RainWaterTrap(int n)
 {
     int a[n];
     for(int i=0;i<n;i++)
      cin>>a[i];
      
      //logic
      
      // To store the maximum water  
    // that can be stored
      int result=0;
      for(int i=1;i<n-1;i++)
      {
          // Find the maximum element on its left
          int left=a[i];
          for(int j=0;j<i;j++)
          {
           left=max(left,a[j]);    
          }
          
          // Find the maximum element on its right
          int right=a[i];
          for(int j=i+1;j<n;j++)
          {
              right=max(right,a[j]);
          }
          
          // Update the maximum water
          result=result+(min(left,right)-a[i]);
      }
      
      cout<<result<<"\n";
 }
 
int main()
{
int t;
cin>>t;
int n;
for(int i=1;i<=t;i++)
 {
     cin>>n;
     RainWaterTrap(n);
 }
    return 0;
}
*/


/*
Find a partition point in array
or
Element with left side smaller and right side greater
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7

#include<iostream>
#include<algorithm>
using namespace std;

int fun(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    
    
    for(int i=1;i<n-1;i++)
    {
        int flag=0;
       for(int j=0;j<i;j++)
       {
           if(a[i]<=a[j])
            {
                flag=1;
                break;
            }
            
       }
       
       for(int j=i+1;j<n;j++)
       {
           if(a[i]>=a[j])
            {
            flag=1;
            break;
           }
       }
       
       if(flag==0)
        return a[i];
    }
return -1;    
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int result=fun(n);
        cout<<result<<"\n";
    }
    return 0;
}
*/

/*
Convert array into Zig-Zag fashion
Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

#include<iostream>
#include<algorithm>
using namespace std;

void fun(int n)
{
    int a[n];
    for(int i=0;i<n;i++)
     cin>>a[i];
    
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(flag)
        {
            if(a[i]>a[i+1])
             swap(a[i],a[i+1]);
        }
        else{
            if(a[i]<a[i+1])
            {
                swap(a[i],a[i+1]);
            }
        }
        
        flag=!flag;
    }
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        fun(n);
    }
    return 0;
}
*/

/*

Find the index of first 1 in a sorted array of 0’s and 1’s
Last Updated: 22-07-2019
Given a sorted array consisting 0’s and 1’s. The problem is to find the index of first ‘1’ in the sorted array. It could be possible that the array 
consists of only 0’s or only 1’s. If 1’s are not present in the array then print “-1”.

Examples :

Input : arr[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
Output : 6
The index of first 1 in the array is 6.

Input : arr[] = {0, 0, 0, 0}
Output : -1
1's are not present in the array.


#include<iostream>
using namespace std;

int fun(int n)
{
int a[n];
for(int i=0;i<n;i++)
 cin>>a[i];
 
for(int i=0;i<n;i++)
{
    if(a[i]==1)
     return i;
}
return -1;
}

int main()
{
    int t;
    cin>>t;
    int n;
    for(int i=1;i<=n;i++)
    {
     cin>>n;
     int result=fun(n);
     cout<<result<<"\n";
    }
    return 0;
}
*/


