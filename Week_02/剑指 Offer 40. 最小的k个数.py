class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        def partition(nums, left, right):
            pivot = nums[right]
            i = left
            for j in range(left, right):
                if nums[j] < pivot:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[right] = nums[right], nums[i]
            return i

        if k == 0:
            return []
        right = len(arr) - 1
        left = 0
        while left < right:
            curr_indice = partition(arr, left, right)
            if curr_indice == k - 1:
                return arr[:curr_indice + 1]
            elif curr_indice > k - 1:
                right = curr_indice - 1
            else:
                left = curr_indice + 1
        return arr[:left + 1]
