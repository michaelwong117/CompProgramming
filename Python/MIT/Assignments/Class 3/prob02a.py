def run_me():
   a = 'Soup and salad'
   b = 'Pasta with meat sauce'
   c = 'Chef\'s special'
   display_menu(a,b,c)

   choice = int( input("What number would you like to order? ") )
   if choice==1:
       print("One "+a+" coming right up!")
   elif choice==2:
       print("One "+b+" coming right up!")
   elif choice==3:
       print("One "+c+" coming right up!")
   else:
       print("Sorry, but that is not a valid choice!")
       return


def display_menu(a, b, c):

   '''(string, string, string)
   Print out the menu.
   For example, a = 'Soup and salad', b = 'Pasta with meat sauce'.
   It will print out
   1. Soup and salad
   2. Pasta with meat sauce

   '''
   print ('1. '+a)

   print ('2. '+b)

   print ('3. '+c)
   return





