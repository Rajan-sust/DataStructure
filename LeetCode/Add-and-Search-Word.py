class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}
        

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        node = self.trie
        for ch in word:
            node = node.setdefault(ch, {})
        node['end'] = {}
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        
        def dfs(node, i = 0):
            if i == len(word):
                return 'end' in node
            elif word[i] == '.':
                return any(dfs(n, i+1) for n in node.values())
            
            else:
                return word[i] in node and dfs(node[word[i]], i+1)
                
        return dfs(self.trie)
        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
