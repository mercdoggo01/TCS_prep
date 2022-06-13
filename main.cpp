// Topic: Array
// Question link: https://www.geeksforgeeks.org/non-repeating-element/


// Logic: two ways of doing it:
// 1.) run two loops to find the first non repeating element
// 2.) use hashing


// use bits/stdc++.h instead of others to avoid trouble
#include <bits/stdc++.h>
using namespace std;


// method 1:

int first_nonrep(int a[],int n)
{
    // default answer to -1 if all elements are repeated
    int ans=-1;
    for(int i=0 ; i<n ; i++)
    {
        int j;
        for(j=0 ; j<n ; j++)
        {
            if(a[i]==a[j] && i!=j)
            {
                break;
            }
        }
        if(j==n)
        {
            return a[i];
        }
    }
    return ans;
}

// method 2
int first_nonrep2(int a[],int n)
{
    int ans = -1;
    // to store the frequency of each element
    unordered_map<int,int> mp;
    for(int i=0 ; i<n ; i++)
    {
        mp[a[i]]++;
    }
    // traversing original array again and checking if element occurred
    // only once throughout the array
     for(int i=0 ; i<n ; i++)
    {
        if(mp[a[i]]==1)
        {
            ans = a[i];
            break;
        }
    }
    return ans;
}

int main()
{
    // array and length can be modified by you
    // as you wish for testing


    // all 3 cases
    //1.) without and without repeat
    int a[] = {1,2,3,4,2,5,1,5,6,9,0,0,1,1};
    int n = 14;

    // 2.) no repeat
    int b[] = {1,2,3,4,5,6};
    int n1= 6;

    // 3.) everything repeated
    int c[] = {1,2,2,1,3,3,4,4,5,6,5,6};
    int n2 = 12;

    int res = first_nonrep(c,n2);
    cout<< res<< endl;

    int res2 = first_nonrep2(b,n1);
    cout<< res2 <<"\n";


    return 0;
}
