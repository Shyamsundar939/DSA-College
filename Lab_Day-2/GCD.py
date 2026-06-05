# 3.GCD using recursion

from timeit import default_timer

def GCD(a,b):
    if(b==0):
        return a
    else:
        return GCD(b,a%b)
    
n1=int(input("Enter a number:"))
n2=int(input("Enter another number:"))

start=default_timer()
result=GCD(n1,n2)
end=default_timer()
print(f"The GCD of {n1} and {n2} is {result}")
print(f"The time taken is {start-end} seconds")
