# 1.Factorial using recursion

from timeit import default_timer

def fact(n):
    if(n==0 or n==1):
        return 1
    else:
        return n*fact(n-1)
    
n=int(input("Enter a number:"))
start=default_timer()
result=fact(n)
end=default_timer()
print(f"The result is {result}")
print(f"The time taken is {end-start} seconds")