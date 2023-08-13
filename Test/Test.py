
class Map:
    
    def isWalkable(self, map, table, y, x) -> bool:
        if y < 0 or x < 0:
            return False
        elif y >= len(map) or x >= len(map[y]):
            return False
        elif(table[y][x] == True):
            return False
        elif(map[y][x] == 1):
            return False
        else:
            return True
        
    
    def BreadthFirstSeach(self, map, endY, endX):
        xDir = [1,0,-1,0,1,1,-1,-1]
        yDir = [0,-1,0,1,1,-1,1,-1]
        table = [[False for i in range(n)] for j in range(m)]
        bfs = []
        bfs.append((0, 0, 0))

        while(len(bfs) > 0):
            point = bfs.pop(0)
            if point[0] == endY and point[1] == endX:
                return point[2]

            for i in range(len(xDir)):
                nextY = point[0] + yDir[i]
                nextX = point[1] + xDir[i]
                if self.isWalkable(map, table, nextY, nextX):
                    bfs.append((nextY, nextX, point[2] + 1))
        return 0
    
    def routes(self, map, endY, endX) -> int:
        # xDir = [1,0,-1,0]
        # yDir = [0,-1,0,1]
        # dir = ['r', 'u', 'l', 'd']
        xDir = [1,0,-1,0,1,1,-1,-1]
        yDir = [0,-1,0,1,1,-1,1,-1]
        dir = ['r', 'u', 'l', 'd','rd', 'ru', 'ld', 'lu']
        m = len(map)
        n = len(map[0])
        table = [[False for i in range(n)] for j in range(m)]
        table[0][0] = True
        def X_depthFirstSearch(map, y, x) -> int:
            if y == endY and x == endX:
                return 1
            #self.printMap(table)
            ans = 0
            for i in range(len(xDir)):
                nextX = x + xDir[i]
                nextY = y + yDir[i]
                if(self.isWalkable(map, table, nextY, nextX)):
                    table[nextY][nextX] = True
                    ans += X_depthFirstSearch(map, nextY, nextX)
                    table[nextY][nextX] = False
            return ans

        res = []
        subRes = []
        pathMap = [['-' for i in range(n)] for j in range(m)]
        def depthFirstSearch(map, y, x, subRes, pathMap):
            # self.printMap(pathMap)
            if x == endX and y == endY:
                res.append(subRes[:])
                print(subRes[:])
                self.printMap(pathMap)
            else:
                for i in range(len(xDir)):
                    nextX = x + xDir[i]
                    nextY = y + yDir[i]
                    
                    if self.isWalkable(map, table, nextY, nextX):
                        table[nextY][nextX] = True
                        pathMap[nextY][nextX] = dir[i]
                        subRes.append(dir[i])
                        depthFirstSearch(map, nextY, nextX, subRes, pathMap)
                        table[nextY][nextX] = False
                        pathMap[nextY][nextX] = '-'
                        subRes.pop(-1)

        depthFirstSearch(map, 0, 0, subRes, pathMap)
        print(len(set(tuple(l) for l in res)))
        return res, X_depthFirstSearch(map, 0, 0)
    def printMap(self, map):
        for i in range(len(map)):
            for j in range(len(map[i])):
                print(f'{map[i][j]:^3}', end=" ")
            print("")
        print("")


m = 3
n = 4
endY = 0
endX = 3

map = [[0 for i in range(n)] for j in range(m)]
map[0][1] = 1
map[0][2] = 1
map[1][2] = 1

ans = Map()
ans.printMap(map)
print(ans.BreadthFirstSeach(map, endY, endX))