//https://gist.github.com/ericandrewlewis/720c374c29bbafadedc9
//https://stackoverflow.com/questions/8208021/how-to-increment-a-pointer-address-and-pointers-value
//https://www.tutorialspoint.com/cprogramming/c_pointer_arithmetic.htm

//&x gives you the memory address of x
//*pt++ increment pointer by its sizeof contents, also if pt is a pointer to array 
//moves to next element in array


int  var[] = {10, 100, 200};
int  i, *ptr;

/* let us have array address in pointer */
ptr = var;

for ( i = 0; i < MAX; i++) {

  printf("Address of var[%d] = %x\n", i, ptr );
  printf("Value of var[%d] = %d\n", i, *ptr );

  /* move to the next location */
  ptr++;
}

void setValueToFive(int x)
{
    std::cout << &x << "\n";
    x = 5;
}

int x = 3;
setValueToFive( x );
std::cout << "The value of x is " << x << ", setValueToFive() did not modify x.\n";
// Outputs: The value of x is 3, setValueToFive() did not modify x

void setPointerValueToFive(int *x)
{
    *x = 5;
}

int x = 3;
setPointerValueToFive( &x );
std::cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
// Outputs: The value of x is 5, setPointerValueToFive() modified x

void setValueToFiveWithReference(int& x)
{
    x = 5;
}

int x = 3;
setValueToFiveWithReference( x );
std::cout << "The value of x is " << x << ", setPointerValueToFive() modified x.\n";
// Outputs: The value of x is 5, setPointerValueToFive() modified x