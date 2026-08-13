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
    Insertionsort(Arr,n);
    auto end=std::chrono::steady_clock::now();
    
    printarray(Arr,n);
    auto time_taken=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout<<"Time taken for insertion_sort is:"<<time_taken.count()*1e-9<< "s" << std::endl;
    return 0;
}