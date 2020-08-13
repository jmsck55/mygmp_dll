
#include "stdafx.h"

#include "mygmp.h"

int main() {
    void * a;
    void * b;
    char * str;
    // std::string st;
    int i;
    long exponent, prec;
    int roundingMethod = 0;
    //size_t targetLength = 100;

    // put code here.
#ifdef TEST_FOO
    foo();
#endif

    prec = f_get_default_prec();
    prec *= 10;
    f_set_default_prec(prec);
    prec = f_get_default_prec();
    printf("default_prec is: %li\n", prec);

    a = allocate_f();
    b = allocate_f();
    
    register_f(a);
    register_f(b);
    
    printf("Status: (0 for good) %d\n", 
        f_set_str(a, "1234.5678", 10, roundingMethod));

    f_set(b, a, roundingMethod);

    i = f_add(a, a, b, roundingMethod);
    printf("f_add returned: %i\n", i);
    i = f_sub(a, b, a, roundingMethod);
    printf("f_sub returned: %i\n", i);

    str = f_get_str(NULL,&exponent,10,0,a,roundingMethod);
    printf("Answer is: %s\n", str);
    printf("With exponent: %li\n", exponent);
    f_free_str(str);

    clear_f(a);
    clear_f(b);
    generic_free(a);
    generic_free(b);
    clear_f_cache();

	printf("Press enter to continue.\n");
	getc(stdin);

    // std::cout << "Hi world! (type a string then press Enter to exit)" << std::endl;
    // std::cin >> st;
    // std::cout << st << std::endl;
    return 0;
}
