/*
http://lionrex.pixnet.net/blog/post/48777542
http://www.cplusplus.com/forum/windows/17153/
http://pydoing.blogspot.tw/2013/01/cpp-array-parameter.html
*/
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

void first_move_to_pivot(int arr[], int first, int len)
//第一個參數其實是傳址，第二第三個參數是傳值
{
    int temp[len], L=0, R=len-1;

    for(int i=1; i<len; i++)
    {
        if(arr[first+i]<arr[first])
            temp[L++]=arr[first+i];
        else
            temp[R--]=arr[first+i];
    }
    temp[L]=arr[first];

    for(int i=0; i<len; i++)
        arr[first+i]=temp[i];

    if(L>0)
        first_move_to_pivot(arr, first, L);
    if(len-L-1>0)
        first_move_to_pivot(arr, first+L+1, len-L-1);
}

int main()
{
    cout<<"生幾個二位數：";
    int n;
    cin>>n;
    int a[n];
    srand (time(NULL));
    for(int i=0; i<n; i++)
    {
        a[i]=rand()%90+10;
        cout<<a[i]<<" ";
    }

    first_move_to_pivot(a,0,n);

    cout<<endl<<"快速排序結果："<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
