# 1.factorial using tail recursion

from timeit import default_timer

def tailFact(n,a):
    if n==0 or n==1:
        return a
    else:
        return tailFact(n-1,a*n)

n=int(input("Enter a number:"))
start=default_timer()
result=tailFact(n,1)
end=default_timer()
print(f"The result is {result}")
print(f"The time taken is {end-start} seconds")