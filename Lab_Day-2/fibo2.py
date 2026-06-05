# 2. nth fibonacci term using  memoization

from timeit import default_timer

table={}

def fibo(n):
    if(n==1 or n==2):
        return 1
    else:
        if n not in table:
            table[n]=fibo(n-1)+fibo(n-2)
        return table[n]

n=int(input("Enter a number:"))
start=default_timer()
result=fibo(n)
end=default_timer()
print(f"The {n}th fibonacci term is {result}")
print(f"The time taken is {end-start} seconds")