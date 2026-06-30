#include <iostream>
using namespace std;

void Bubblesort(int Arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0; j<n-i-1;j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                swap(Arr[j],Arr[j+1]);
            }
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
    Bubblesort(arr,n);
    printarray(arr,n);

    return 0;
}