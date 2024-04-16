
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        grid = [[0 for i in range(n)] for j in range(m)]
        if obstacleGrid[0][0] == 0:
            grid[0][0] = 1
        for y in range(1, m):
            if obstacleGrid[y][0] == 0:
                grid[y][0] = grid[y-1][0]
        for x in range(1, n):
            if obstacleGrid[0][x] == 0:
                grid[0][x] = grid[0][x-1]
        
        for y in range(1, m):
            for x in range(1, n):
                if obstacleGrid[y][x] == 0:
                    print(obstacleGrid[y][x])
                    grid[y][x] = grid[y][x-1] + grid[y-1][x]
                
                #print(y, x, grid[y][x], obstacleGrid[y][x])
        return grid[m-1][n-1]