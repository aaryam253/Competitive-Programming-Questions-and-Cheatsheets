class Solution:
    # TC: O(N), SC: O(1)
    def sumEvenAfterQueries(
        self, nums: List[int], queries: List[List[int]]
    ) -> List[int]:
        answer = [0] * len(nums)
        for i in range(len(queries)):
            orig = nums[queries[i][1]]
            nums[queries[i][1]] = nums[queries[i][1]] + queries[i][0]
            if i == 0:
                answer[i] = sum(num for num in nums if not num % 2)
            else:
                answer[i] = answer[i - 1] - (orig if not orig % 2 else 0)
                answer[i] += nums[queries[i][1]] if not nums[queries[i][1]] % 2 else 0
        return answer
