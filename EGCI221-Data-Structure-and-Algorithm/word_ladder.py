from collections import deque
from typing import List

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        wordList = set(wordList)
        queue = deque([(beginWord, 1)])

        while queue:
            current_word, length = queue.popleft()

            if current_word == endWord:
                return length

            for i in range(len(current_word)):
                for char in 'abcdefghijklmnopqrstuvwxyz':
                    new_word = current_word[:i] + char + current_word[i+1:]
                    
                    if new_word in wordList:
                        wordList.remove(new_word)
                        queue.append((new_word, length + 1))

        return 0

# Example usage:
solution = Solution()
beginWord = "hit"
endWord = "cog"
wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
print(solution.ladderLength(beginWord, endWord, wordList))  # Output should be 5
