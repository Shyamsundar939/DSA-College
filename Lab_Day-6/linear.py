import timeit
import random
import copy
import sys
import math

def Linearsearch(A,n,key):
    flag=0
    for i in range(n):
        if(key==A[i]):
            flag=1
            print(f"Element found at index {i}")
    if(flag==0):
        print("Search Unsuccessful!")

n=int(sys.argv[1])
key=(sys.argv[2])
list1=[]
for i in range(n):
    list1.append(random.randint(1,100000))

list2=copy.deepcopy(list1)

t1=timeit.default_timer()
Linearsearch(list1,n,key)
t2=timeit.default_timer()

print(f"The time taken by linear serach is {t2-t1} seconds")

    
        
