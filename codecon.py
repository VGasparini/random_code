class Graph: 
  
    def __init__(self,graph): 
        self.graph = graph
        self.original = [i[:] for i in graph] 
        self.ROW = len(graph) 
        self.COL = len(graph[0]) 
  
    def BFS(self,s, t, root): 
        visited =[False]*(self.ROW) 

        queue=[] 
        queue.append(s) 
        visited[s] = True
  
        while queue: 

            u = queue.pop(0) 
            for ind, val in enumerate(self.graph[u]): 
                if visited[ind] == False and val > 0 : 
                    queue.append(ind) 
                    visited[ind] = True
                    root[ind] = u 
  
        return True if visited[t] else False
  
    def minCut(self, source, sink): 
        parent = [-1]*(self.ROW) 

        max_flow = 0
  
        while self.BFS(source, sink, parent) : 
  
            path_flow = float("Inf") 
            s = sink 
            while(s !=  source): 
                path_flow = min (path_flow, self.graph[parent[s]][s]) 
                s = parent[s] 
  
            max_flow +=  path_flow 
  
            v = sink 
            while(v !=  source): 
                u = parent[v] 
                self.graph[u][v] -= path_flow 
                self.graph[v][u] += path_flow 
                v = parent[v] 
  
        ans = 0
        for i in range(self.ROW): 
            for j in range(self.COL): 
                if self.graph[i][j] == 0 and self.original[i][j] > 0: 
                    ans+=self.original[i][j]
        return ans

computers,B = map(int,input().split())
graph = []

for i in range(computers):
    D,M = map(int,input().split())
    vertexes = []
    for j in range(M):
        v,d = map(int,input().split())
        vertexes.append([v,d])
    graph.append(vertexes)

matrix = [[0 for i in graph] for j in range(len(graph))]
for idx,vertexes in enumerate(graph):
    for vertex in vertexes:
        u,d = vertex
        matrix[idx][u] = d
        matrix[u][idx] = d
  
g = Graph(matrix) 
ans = g.minCut(0, B)
print(ans) 