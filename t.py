computers,B = map(int,input().split())
original_graph,extra_edges = [],[]

for i in range(computers):
    D,M = map(int,input().split())
    extra_edges.append(D)
    vertexes = []
    for j in range(M):
        v,d = map(int,input().split())
        vertexes.append([v,d])
    original_graph.append(vertexes)

final_graph = original_graph[:]

for idx,vertex in enumerate(original_graph[1:]):
    tmp_vertex = []
    new_idx = computers + idx
    final_graph[idx+1] = [[new_idx,extra_edges[idx+1]]]
    final_graph.append(vertex)
        

print(original_graph)
for i,j in enumerate(final_graph):
    print(i,j)

matrix = [[0 for i in final_graph] for j in range(len(final_graph))]
for idx,vertexes in enumerate(final_graph):
    for vertex in vertexes:
        u,d = vertex
        matrix[idx][u] = d
pprint(matrix)