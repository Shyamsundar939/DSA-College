# 4.TOH using recursion

def TOH(n,src,dst,temp):
    if(n==1):
        print(f"Move disc {n} from {src} to {dst}")
    else:
        TOH(n-1,src,temp,dst)
        print(f"Move disc {n} from {src} to {dst}")
        TOH(n-1,temp,dst,src)

n=int(input("Enter a number:"))
print(f"Total numbers of move for moves for {n} disc is {(2**n)-1}")
TOH(n,'A','B','C')
