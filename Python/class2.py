# STANDARD DEVIATION OF ARRAY
if __name__ == "__main__":
    # implemnt this only then this file is explicility called
    # like if we call this file from another file, this part will not get exectued

def mean(arr):
    sum = 0
    for i in arr :
        sum += i
    return sum / len(arr)



def SD(arr):
    avg = mean(arr)
    sum = 0;
    for i in arr :
        sum += (i - avg)**2
    var = sum / len(arr)
    
    print(var**0.5)
    
SD([2,2,2])




    