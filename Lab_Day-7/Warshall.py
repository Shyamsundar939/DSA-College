import copy
w=[
    
    [0,1,0,0],
    [0,0,1,0],
    [0,0,0,1],
    [0,0,0,0]
    
]

def warshall(w):
    n=len(w)
    W=copy.deepcopy(w)
    for k in range(0,n):
        for i in range(0,n):
            for j in range(0,n):
                w[i][j]=w[i][j] or w[i][k] and w[k][j]
    return w

print(w)

#project 1
#kruskals and primps mst algorithm implement garne{5 marks}