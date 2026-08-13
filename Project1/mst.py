import os

def find_root(parent, node):

    while parent[node] != node:
        node = parent[node]

    return node


def get_weight(edge):
    return edge[2]


def kruskal(edges, nodes):

    parent = {}

    for node in nodes:
        parent[node] = node

    edges_sorted = sorted(edges, key=get_weight)

    mst_edges = []
    total_weight = 0

    for u, v, w in edges_sorted:

        root_u = find_root(parent, u)
        root_v = find_root(parent, v)

        if root_u != root_v:

            parent[root_u] = root_v

            mst_edges.append((u, v, w))

            total_weight = total_weight + w

            if len(mst_edges) == len(nodes) - 1:
                break

    return mst_edges, total_weight


def prim(edges, nodes, start):

    visited = [start]

    mst_edges = []
    total_weight = 0

    while len(visited) < len(nodes):

        best_u = None
        best_v = None
        best_w = None

        for u, v, w in edges:

            if u in visited and v not in visited:

                if best_w is None or w < best_w:
                    best_u = u
                    best_v = v
                    best_w = w

            elif v in visited and u not in visited:

                if best_w is None or w < best_w:
                    best_u = v
                    best_v = u
                    best_w = w

        if best_u is None:
            print("Graph is disconnected. MST cannot be formed.")
            break

        visited.append(best_v)

        mst_edges.append((best_u, best_v, best_w))

        total_weight = total_weight + best_w

    return mst_edges, total_weight


def read_graph(path):

    edges = []
    nodes = set()

    folder = os.path.dirname(os.path.abspath(__file__))
    
    path = os.path.join(folder, path)

    try:

        file = open(path, "r")

        for line in file:

            if line.strip() != "":

                u, v, w = line.split()

                edges.append((u, v, int(w)))

                nodes.add(u)
                nodes.add(v)

        file.close()

    except FileNotFoundError:

        print("Error: graph.txt file not found.")
        print("Looking for file at:")
        print(path)

        return [], set()

    return edges, nodes


def main():

    edges, nodes = read_graph("graph.txt")

    if len(nodes) == 0:

        print("No graph data found.")
        return

    start = sorted(nodes)[0]

    print("Select MST algorithm")
    print("1. Kruskal's algorithm")
    print("2. Prim's algorithm")

    choice = input("Enter your choice (1 or 2): ")

    if choice == '1':

        mst_edges, total_weight = kruskal(edges, nodes)

        print("\nKruskal's Algorithm")

        for u, v, w in mst_edges:

            print(f"{u} -- {v}  (weight {w})")

        if len(mst_edges) == len(nodes) - 1:

            print("Total Weight:", total_weight)

        else:

            print("MST cannot be formed because graph is disconnected.")


    elif choice == '2':

        mst_edges, total_weight = prim(edges, nodes, start)

        print("\nPrim's Algorithm")

        for u, v, w in mst_edges:

            print(f"{u} -- {v}  (weight {w})")

        if len(mst_edges) == len(nodes) - 1:

            print("Total Weight:", total_weight)

        else:

            print("MST cannot be formed because graph is disconnected.")


    else:

        print("Enter a valid choice")


if __name__ == "__main__":
    main()