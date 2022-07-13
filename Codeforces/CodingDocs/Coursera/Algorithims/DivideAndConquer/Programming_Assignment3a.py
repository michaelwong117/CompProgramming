firstcomparison = 0
lastcomparison = 0
mediancomparison = 0

def partition1(array, leftend, rightend):
    pivot = array[leftend]
    i = leftend + 1
    for j in range(leftend + 1, rightend):
        if array[j] < pivot:
            temp = array[j]
            array[j] = array[i]
            array[i] = temp
            i += 1

    leftendval = array[leftend]
    array[leftend] = array[i-1]
    array[i-1] = leftendval
    return i - 1 

def quick_sort1(array, leftindex, rightindex):
    global firstcomparison
    if leftindex < rightindex:
        
        newpivotindex = partition1(array, leftindex, rightindex)
        
        firstcomparison += (rightindex - leftindex-1)
        
        quick_sort1(array, leftindex, newpivotindex) 
        
        quick_sort1(array, newpivotindex + 1, rightindex)

    return array, firstcomparison
# def partition2(array, leftend, rightend):
#     pivot = array[rightend - 1]
#     #print pivot
#     i = rightend - 1
#     #print i
#     for j in reversed(range(leftend, rightend)):
#         #print 'i, j =', i, j
#         if array[j] > pivot:
#             temp = array[j]
#             array[j] = array[i]
#             array[i] = temp
#             i -= 1
#     rightendval = array[rightend - 1]
#     array[rightend-1] = array[i-1]
#     array[i-1] = rightendval
#     return i-1
# def quick_sort2(array, leftindex, rightindex):
#     global lastcomparison
#     if leftindex < rightindex:
        
#         newpivotindex = partition2(array, leftindex, rightindex)
        
#         lastcomparison += (rightindex - leftindex-1)
        
#         quick_sort2(array, leftindex, newpivotindex) 
        
#         quick_sort2(array, newpivotindex + 1, rightindex)











data = []
def run(file_in):

    f = open(file_in, "r")
    for i in xrange(10000):

        str_in = int(f.readline().strip())

        data.append(str_in)
    # quick_sort1(data, 0, 10000)
    #print partition2(data, 0, 10000)
    print quick_sort2(data, 0, 10000)
    #print data












def main():
    run("Quicksort.txt")


if __name__ == "__main__":
    main()