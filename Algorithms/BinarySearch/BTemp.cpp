//FOR ANY BINARY SEARCH
//CHECK THE LAST TWO ENDPOINTS, YOU SHOULD ALWAYS BREAK OUT OF THE LOOP
//TRY LO = 6 and HI = 7, and PUT THEM THROUGH BOTH CASES WHERE P(mid) == true and P(mid) == false
binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo)/2 // rounds down, +lo for neg
      if p(mid) == true:
         hi = mid //include hi in your search; you're looking for 1st true
      else:
         lo = mid+1 //don't include lo in your search; you're looking for 1st true
          
   if p(lo) == false:
      complain                // p(x) is false for all x in S!
      
   return lo         // lo is the least x for which p(x) is true

binary_search(lo, hi, p):
   while lo < hi:
      mid = lo + (hi-lo+1)/2 // rounds up
      if p(mid) == true:
         hi = mid-1 //don't include hi in your search; you're looking for last false
      else:
         lo = mid //include lo in your search; you're looking for last false
          
   if p(lo) == true:
      complain                // p(x) is true for all x in S!
      
   return lo         // lo is the greatest x for which p(x) is false

//Just remember to always test your code on a two-element set 
//where the predicate is false for the first element and true for the second.
//beware of inf loop!

//over all real numbers, just find something closest to what you need
//100 iterations / compare bounds
binary_search(lo, hi, p):
   while we choose not to terminate: //compare relative distances or do set iterations
      mid = lo + (hi-lo)/2
      if p(mid) == true:
         hi = mid
      else:
         lo = mid
          
   return lo // lo is close to the border between no and yes