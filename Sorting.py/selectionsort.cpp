#include <iostream>
using namespace std;

void Selectionsort(int Arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        int least=Arr[i];
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(Arr[j]< least)
            {
                least=Arr[j];
                pos=j;
            }
        }
        if(i != pos)
        {
            swap(Arr[i],Arr[pos]);
        }
    }
}

void printarray(int Arr[],int n){
    for(int i=0;i<n;i++){
        cout << Arr[i] << " ";
    }
}

int main(){
    int n=10;
    int arr[]={4,1,5,2,3,7,6,9,8,10};
    Selectionsort(arr,n);
    printarray(arr,n);

    return 0;
}