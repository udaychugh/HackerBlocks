#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll merge(ll arr[], ll l, ll m, ll r)
{
    ll i, j, k;
    ll n1 = m - l + 1;
    ll n2 =  r - m;
    ll alpha=0ll;
    /* create temp arrays */
    ll L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    //int current_alpha=0;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            alpha+=(((L[i]%mod)*((r-j)-m))%mod);
            alpha%=mod;
            arr[k] = L[i];
            i++;

        }
        else
        { // cout<<"sda"<<endl;

          //inversion+=m-l+1-i;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
//  cout<<inversion<<" dfs"<<endl;
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {  // inversion++;
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return alpha%mod;
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
ll mergeSort(ll arr[], ll l, ll r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l+(r-l)/2;

        // Sort first and second halves
     ll a1=   mergeSort(arr, l, m)%mod;
      ll a2=  mergeSort(arr, m+1, r)%mod;

      ll a3=  merge(arr, l, m, r)%mod;
    // cout<<a1<<" "<<a2<<" "<<a3<<endl;
      return (((a1+a2)%mod+a3)%mod);
    }
    return 0ll;
}

/* UTILITY FUNCTIONS */
/* Function to print an array */


/* Driver program to test above functions */
int main()
{
  
  
      ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }




     cout<<  mergeSort(arr, 0,n-1)<<endl;

  

    return 0;
}