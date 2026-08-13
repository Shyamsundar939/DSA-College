import timeit
import random
import copy
import sys
import math

def Binarysearch(A,l,r,key):
    arr=[]
    while(l<=r):
        m=math.floor((l+r)/2)
        if(A[m]==key):
            arr.append(m)
            break
        elif (A[m]<key):
            l=m+1
        else:
            r=m-1
    i=m-1
    j=m+1

    while i>=l and A[i]==key:
        arr.append(i)
        i=i-1
    while j<=r and A[j]==key:
        arr.append(j)
        j=j+1

    return arr

n=int(sys.argv[1])
key=int(sys.argv[2])
list1=[]
for i in range(n):
    list1.append(random.randint(1,100000))

list1.sort()
list2=copy.deepcopy(list1)

t1=timeit.default_timer()
Binarysearch(list1,0,n-1,key)
t2=timeit.default_timer()

print(f"The time taken by linear serach is {t2-t1} seconds")

    
        
