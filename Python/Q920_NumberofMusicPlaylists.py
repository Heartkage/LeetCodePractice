class Solution:
    def combination(self, c: int, r: int):
        ans = 1
        maxV = r if r > c-r else c-r
        minV = c-r if r > c-r else r
        index = 2
        for i in range(c, maxV, -1):
            ans *= i
            if index <= minV and (ans % index == 0):
                ans //= index
                index += 1
        return ans

    def numMusicPlaylists(self, n: int, goal: int, k: int) -> int:
        max = (10 ** 9) + 7
        def factorial(n):
            result = 1
            if n > 1:
                for i in range(2, n + 1):
                    result *= i
            return result
        
        def pow(x, n):
            return x ** n

        def part2(m):
            multi = 1
            for i in range(k):
                multi *= m-i
            multi *= pow(m-k, goal-k)
            return multi

        if(n == goal):
            return int(factorial(n) % max)
        else:
            ans = 0
            for i in range(n):
                ans += self.combination(n, n-i) * part2(n-i) * pow(-1, i)
            return int(ans % max)

temp = Solution()
ans = temp.numMusicPlaylists(95, 100, 0)
print(ans)
