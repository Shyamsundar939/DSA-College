#include <iostream>
using namespace std;

void Insertionsort(int Arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        int j= i-1;
        int temp=Arr[i];
        while(j>=0 and temp < Arr[j])
        {
            Arr[j+1]=Arr[j];
            j=j-1;
        }
        Arr[j+1]=temp;
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
    Insertionsort(arr,n);
    printarray(arr,n);

    return 0;
}