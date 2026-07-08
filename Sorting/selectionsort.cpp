#include<iostream>
#include<cstdlib>
#include<chrono>
#define MAX 500000

void swapp(int *p ,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}

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
            swapp(&Arr[i],&Arr[pos]);
        }
    }
}

void printarray(int Arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<Arr[i]<<" ";
    }
    std::cout<<std::endl;
}

int main(){
    int i,n,Arr[MAX];
    std::cout<<"Enter n:";
    std::cin>>n;

    for(i=0;i<n;i++){
        Arr[i]=rand()%100000;
    }

    printarray(Arr,n);

    auto start= std::chrono::steady_clock::now();
    Selectionsort(Arr,n);
    auto end=std::chrono::steady_clock::now();

    printarray(Arr,n);
    auto time_taken=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout<<"Time taken for selection_sort is:"<<time_taken.count()*1e-9<< "s" << std::endl;
    return 0;
}