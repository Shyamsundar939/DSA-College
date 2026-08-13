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

void Bubblesort(int Arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0; j<n-i-1;j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                swapp(&Arr[j],&Arr[j+1]);
            }
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
    Bubblesort(Arr,n);
    auto end=std::chrono::steady_clock::now();

    printarray(Arr,n);
    auto time_taken=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
    std::cout<<"Time taken for bubble_sort is:"<<time_taken.count()*1e-9<< "s" << std::endl;
    return 0;
}