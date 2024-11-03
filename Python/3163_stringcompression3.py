class Solution:
    def compressedString(self, word: str) -> str:
        ans = ""
        p=0
        while p<len(word):
            c=0
            curr=word[p]
            while(p<len(word)  and word[p]==curr and c<9):
                c+=1
                p+=1
            ans=ans+str(c)+curr
            # ans.append(curr)
        return ans
        