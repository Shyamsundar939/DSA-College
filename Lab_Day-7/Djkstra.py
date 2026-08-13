import math

G={
    'A':{'B':2, 'C':6, 'D':4},
    'B':{'A':2, 'C':5},
    'C':{'B':5, 'A':6, 'D':7 ,'E':3},
    'D':{'A':4, 'C':7, 'E':8},
    'E':{'C':3, 'D':8},

}

def initialize(G, start):
    cost={}
    prev={}
    for vertex in G.keys():
        cost[vertex]=math.inf
        prev[vertex]=None
    cost[start]=0
    return cost,prev

def relax(u,v,G,cost,prev):
    if cost[v]> cost[u]+G[u][v]:
        cost[v]=cost[u]+G[u][v]
        prev[v]=u
    return cost,prev

def Dijkstra(G,start):
    cost,prev=initialize(G,start)
    PQ={}
    for vertex in G.keys():
        PQ[vertex]=cost[vertex]
    visited=set()
    while(PQ):
        current=min(PQ,key=PQ.get)
        del PQ[current]
        visited.add(current)
        for neighbour in G[current].keys():
            if neighbour not in visited:
                old_cost=cost[neighbour]
                cost,prev=relax(current ,neighbour,G,cost,prev)
                if old_cost>cost[neighbour]:
                    PQ[neighbour]=cost[neighbour]
        # print(f'Current= {current}')
        # print(cost)
        # print(prev)
    return cost,prev

def construct_Path(node,prev):
    path=[node]
    while(prev[node] != None):
        path.append(prev[node])
        node=prev[node]
    path.reverse()
    return '->'.join(path)

cost,prev=Dijkstra(G,"A")
for vertex in G.keys():
    print(f"Shortest path from {"A"} to {vertex} is {construct_Path(vertex,prev)} | Cost={cost[vertex]}")
