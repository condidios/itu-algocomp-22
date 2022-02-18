from collections import defaultdict

class Path:
    def __init__(self,fromV,toV):
        self.fromV = fromV
        self.toV = toV

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)
    def addEdge(self, u, v):
        self.graph[u].append(v)
    def removeEdge(self,u,v):
        self.graph[u].remove(v)
    def addVertex(self):
        self.V += 1
    def removeVertex(self,k):
        self.V -= 1
        self.graph.pop(n[0])
    def printAllPathsUtil(self, u, d, visited, path):
        visited[u] = True
        path.append(u)
        if u == d and len(path) > 3:
            p = Path(u,d)
            if p not in pathRecord:
                pathRecord.append(p)
        else:
            for i in self.graph[u]:
                if visited[i]== False:
                    self.printAllPathsUtil(i, d, visited, path)
        path.pop()
        visited[u]= False
    def printAllPaths(self, s, d):
        visited =[False]*(self.V)
        path = []
        self.printAllPathsUtil(s, d, visited, path)
n = input().split(" ")
n[0] = int(n[0])
n[1] = int(n[1])
setList = []
for i in range(n[1]):
    temp = input().split(" ")
    a = int(temp[0]) -1
    b = int(temp[1]) -1
    temp[0] = a
    temp[1] = b
    setList.append(temp)
    temp2 = []
    temp2.append(b)
    temp2.append(a)
    setList.append(temp2)
pathRecord = [];
g = Graph(n[0])
for i in setList:
    g.addEdge(i[0],i[1])
for i in range(n[0]):
    g.addVertex()
    for k in setList:
        if k[0] == i:
            g.addEdge(n[0], k[1])
        elif k[1] == i:
            g.addEdge(k[0],n[0])
    s = i ; d = n[0]
    g.printAllPaths(s, d)
    for k in setList:
        if k[0] == i:
            g.removeEdge(n[0], k[1])
        elif k[1] == i:
            g.removeEdge(k[0],n[0])
    g.removeVertex(n[0])
print (len(pathRecord))

