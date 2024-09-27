def mergeAlternately(word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        st1=0
        st2=0
        string = ""
        while(st1 < len(word1) and st2 < len(word2)):
            string+=word1[st1]
            string+=word2[st2]
            st1+=1
            st2+=1
        
        while(st1 < len(word1)):
            string+=word1[st1]
            st1+=1
        while(st2 < len(word2)):
            string+=word2[st2]
            st2+=1
        return string
print(mergeAlternately("ab","pqrs"))

        