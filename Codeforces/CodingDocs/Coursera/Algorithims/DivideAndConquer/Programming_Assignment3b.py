pivot1 = 1
pivotlast = 2
pivotmid = 3

comparisons = 0

def swap(ar, i, j):
    t = ar[i]
    ar[i] = ar[j]
    ar[j] = t

    
def is_median(ar, i, j, k):

    return (ar[i] < ar[j] and ar[i] > ar[k]) or\
           (ar[i] > ar[j] and ar[i] < ar[k])


def _quickSort(ar, l, r, pivot):
    
    global comparisons
    
    if l >= r:
        return

    p = 0
    if pivot == pivot1:
        p = ar[l]
    elif pivot == pivotlast:
        p = ar[r]
        swap(ar, l, r)
    elif pivot == pivotmid:
        m = l + ((r-l) >> 1)
        if is_median(ar, l, m, r):
            p = ar[l]
        elif is_median(ar, m, l, r):
            p = ar[m]
            swap(ar, l, m)
        else:
            p = ar[r]
            swap(ar, l, r)
            
    comparisons += (r-l)

    i = l+1
    for j in range(l+1, r+1):
        if ar[j] < p:
            swap(ar, i, j)
            i += 1
    swap(ar, l, i-1)
    
    _quickSort(ar, l, i-2, pivot)
    _quickSort(ar, i, r, pivot)
    


def quickSort(ar, pivot):

    _quickSort(ar, 0, len(ar)-1, pivot)



def main():
    
    global comparisons
  

    input_array = [1,3,5,2,4,6]
    quickSort(input_array, pivot1)
    print(input_array)

    f = open('QuickSort.txt', 'r')
    lst = []
    

    for line in f.readlines():
        lst.append(int(line))
        
    
    input_array = lst[:] 
    comparisons = 0
    quickSort(input_array, pivot1)
    print(comparisons)
    

    input_array = lst[:] #
    comparisons = 0
    quickSort(input_array, pivotlast)
    print(comparisons)

    input_array = lst[:] 
    comparisons = 0
    quickSort(input_array, pivotmid)
    print(comparisons)
    
    
if __name__ == '__main__':
    main()