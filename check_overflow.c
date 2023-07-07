/*
 * Originally by Libby Shoop, updated by Susan Fox
 * Performs checks to see if overflow has occurred in unsigned
 * and signed ints
 */

#include <stdio.h>


void check_unsigned_add();                    // Runs tests on uadd_ok
int uadd_ok(unsigned int a, unsigned int b);  // Checks if a + b overflows
void check_signed_add();                      // Runs tests on sadd_ok
int sadd_ok(int x, int y);                    // Checks if x + y overflows

void check_unsigned_subtr();                  // Runs tests on ssub_ok
int usub_ok(unsigned int a, unsigned int b);  // Checks if a - b overflows
void check_signed_subtr();                    // Runs tests on usub_ok
int ssub_ok(int x, int y);                    // Checks if x - y overflows

/*
 *  main()  to test out the above functions and demonstrate overflow
 */
int main() {
    // Check our overflow test for unsigned addition
    check_unsigned_add();

    // Check our overflow test for signed addition
    check_signed_add();

    // Check out overflow test for unsigned subtraction
    //check_unsigned_subtr();

    // Check out overflow test for signed subtraction
    //check_signed_subtr();

    return 0;
}


/*
 * Runs tests on unsigned addition overflow checker
 */
void check_unsigned_add() {
    unsigned int u, v;  // the numbers we will add

   // TODO (Task 1): Read this code carefully, then add assert statements to
    // check for the correct result from uadd_ok (you can remove the printf
    // when you do)

    printf("\n\n----- Checking unsigned addition -----\n");

    // 1. two largish positive numbers
    u = 0x7FFFFFF0;
    v = 0xA000FFFF;  // enough to be slightly over when added to u

    printf("Case 1: Large positive numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (uadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 2. Large and small positive number
    u = 0xBFFFFFFF;
    v = 0x00000008;
    printf("Case 2: Large and small, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (uadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 3. Large and small, just enough to go over
    u = 0xFFFFFF55;
    v = 0x000000BB;

    printf("Case 3: v is just big enough: u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (uadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 4. two numbers that should not overflow
    u = 0x00000070;
    v = 0x00FF0000;
    printf("Case 4:  Good medium-small numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (uadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 5. two medium-big numbers that should not overflow
    u = 0x4FFF0000;
    v = 0x80400000;
    printf("Case 5:  Good medium-big numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (uadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }    
  }


/*
  * 
  * Determine if unsigned ints a + b can be added without overflow
  *
  * Return 1 if they can be added without overflow and 0 if not.
  * Overflow only occurs if the result is smaller than either a or b
  */
int uadd_ok(unsigned int a, unsigned int b) {
    unsigned int res = a + b;
    return (res >= a) && (res >= b);
}


/*
 * Runs tests on unsigned addition overflow checker
 */
 void check_signed_add() {
    int u, v;  // the numbers we will add

    // TODO (Task 2): Read this code carefully, then add assert statements to
    // check for the correct result from sadd_ok (you can remove the printf
    // when you do)

    printf("----- Checking signed addition -----\n");

    // 1. two high positive numbers
    u = 0x7FFFFFF0;
    v = 0x000000FF;  // enough to be slightly over when added to u

    printf("Case 1: High positive numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (sadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 2. two really large negative numbers
    u = 0xBFFFFFFF;
    v = 0xBFFFFFFE;
    printf("Case 2: Large negative numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (sadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 3. Negative numbers: v is just enough to go over
    u = 0xBFFFFFFF;
    v = 0xB0000001;
    printf("Case 3: v is just negative enough: u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (sadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 4. two positive numbers that should not overflow
    u = 0x00000070;
    v = 0x00FF0000;
    printf("Case 4:  Good positive numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (sadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }

    // 5. two negative numbers that should not overflow
    u = 0xFFFF0000;
    v = 0x80400000;
    printf("Case 5:  Good negative numbers, u = %x, v = %x, u + v = %x\n", u, v, u + v);
    if (sadd_ok(u,v)) {
      printf("  Addition was okay and did not overflow.\n");
    } else {
      printf("  Addition overflow!\n");
    }    
  }



/*
 * Takes in two signed integers, and checks whether their addition overflows,
 * which happens when (1) the two starting numbers have the same sign and (2)
 * the result has the opposite sign. A positive and a negative
 * signed integer added together can never overflow!
 */
int sadd_ok(int x, int y) {
    int sum = x + y;  // we will check to see if this number seems amiss

    // x, y, are 2 negative signed integers: result must be negative, or overflow!
    int neg_over = (x < 0  &&  y < 0)  &&  sum >= 0;

    // x, y, are 2 positive signed integers: result must be positive, or overflow!
    int pos_over = (x >= 0  && y >= 0)  &&  sum < 0;

    // If x and y have opposite sign, then no overflow can possibly happen

    // If neither possible overflow happened, then return 1, else 0
    return !neg_over  && !pos_over;
 }



/*
 * Make test calls to check if our overflow-checker works correctly
 */
void check_unsigned_subtr() {
    unsigned int u, v;  // // the numbers we will subtract

    printf("\n\n----- Checking unsigned subtraction -----\n");

    // TODO (Task 3): add at least 5 test calls here to check scenarios
    // where overflow occurs and where it doesn't: use assert!
}    
 

/*
  * 
  * Determine if unsigned a - b can be added without overflow
  *
  * Return 1 if they can be added without overflow and 0 if not.
  */
int usub_ok(unsigned int a, unsigned int b) {
    unsigned int res = a - b;

    // TODO (Task 3): Replace the returned expression below with one that
    // checks for unsigned subtraction overflow!
    return 0;
}


/*
 * Make test calls to check if our overflow-checker works correctly
 */
void check_signed_subtr() {
    int u, v;  // the number we will try in ssub_ok function

    printf("\n\n----- Checking signed subtraction -----\n");

    // TODO (Task 4): add at least 5 test calls here to check scenarios
    // where overflow occurs and where it doesn't: use assert!

}


/*
 * Determine if x - y can be subtracted without overflow.
 *
 * Return 1 if they can be subtracted without overflow and 0 if not.
 */
int ssub_ok(int x, int y) {
    // TODO (Task 4): Use test calls in the previous to identify when this
    // function returns the wrong answer, and then modify the returned value
    // below so that it works correctly!
    return sadd_ok(x, -y);
}



