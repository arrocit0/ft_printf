#include "ft_printf.h"
#include <limits.h>

int   main(void)
{

//  unsigned int a = -1;
//    char    *s = "ojito";
//   	printf("\t1 -> %d", printf("%d%dd%d\n", 1, 2, -3));
//    printf("\t2 -> %d", ft_printf("%d%dd%d\n", 1, 2, -3));


//    printf("\t1 -> %d", printf("%d %d %ld %ld %lu %d %d\n\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
//    printf("\t2 -> %d", ft_printf("%d %d %d %d %d %d %d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));

	printf("\t1 -> %d", printf("%u\n", INT_MIN));
	printf("\t2 -> %d\n", ft_printf("%u\n", INT_MIN));
}

