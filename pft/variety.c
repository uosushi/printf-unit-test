#include <check.h>

int	ft_printf(const char *input, ...);

int		i = 42;
#define ARG_NULL    0, 0, 0, 0, 0, 0, 0, 0, 0
#define ARG_BASIC '2',"hello",&i,INT_MIN,INT_MAX,UINT_MAX,UINT_MAX,UINT_MAX
#define ARG_MINUS_WIDTH -15,'2',-15,"hello",-15,&i,-15,INT_MIN,-15,INT_MAX,-15,UINT_MAX,-15,UINT_MAX,-15,UINT_MAX,-15
#define FMT1 "|%c|%s|%p|%d|%i|%u|%x|%X|%%|\n"
#define FMT2 "|%#c|%#s|%#p|%#d|%#i|%#u|%#x|%#X|%#%|\n"
#define FMT3 "|%15c|%15s|%15p|%15d|%15i|%15u|%15x|%15X|%15%|\n"
#define FMT4 "|%*c|%*s|%*p|%*d|%*i|%*u|%*x|%*X|%*%|\n"
#define FMT5 "|%-15c|%-15s|%-15p|%-15d|%-15i|%-15u|%-15x|%-15X|%-15%|\n"
#define FMT6 "|%015c|%015s|%015p|%015d|%015i|%015u|%015x|%015X|%015%|\n"
#define FMT7 "|%-015c|%-015s|%-015p|%-015d|%-015i|%-015u|%-015x|%-015X|%-015%|\n"
#define FMT8 "|% c|% s|% p|% d|% i|% u|% x|% X|% %|\n"
#define FMT9 "|%+c|%+s|%+p|%+d|%+i|%+u|%+x|%+X|%+%|\n"
#define FMT_ZERO_PRECI "|%.0c|%.0s|%.0p|%.0d|%.0i|%.0u|%.0x|%.0X|%.0%|\n"
#define FMT_TWO_PRECI "|%.2c|%.2s|%.2p|%.2d|%.2i|%.2u|%.2x|%.2X|%.2%|\n"

// cspdiuxX%
// #0- +
// width preci

void	run(void)
{
	title("cspdiuxX%");
	printf("%s", FMT1);
	check(ft_printf(FMT1, ARG_NULL) == printf(FMT1, ARG_NULL));
	printf("%s", FMT1);
	check(ft_printf(FMT1, ARG_BASIC) == printf(FMT1, ARG_BASIC));
	case_title("#");
	check(ft_printf(FMT2, ARG_BASIC) == printf(FMT2, ARG_BASIC));
	case_title("15");
	check(ft_printf(FMT3, ARG_BASIC) == printf(FMT3, ARG_BASIC));
	case_title("*, -15");
	check(ft_printf(FMT4, ARG_MINUS_WIDTH) == printf(FMT4, ARG_MINUS_WIDTH));
	case_title("-15");
	check(ft_printf(FMT5, ARG_BASIC) == printf(FMT5, ARG_BASIC));
	case_title("015");
	check(ft_printf(FMT6, ARG_BASIC) == printf(FMT6, ARG_BASIC));
	case_title("-015");
	check(ft_printf(FMT7, ARG_BASIC) == printf(FMT7, ARG_BASIC));
	case_title("space");
	check(ft_printf(FMT8, ARG_BASIC) == printf(FMT8, ARG_BASIC));
	case_title("+");
	check(ft_printf(FMT9, ARG_BASIC) == printf(FMT9, ARG_BASIC));
	PRECI ;
	check(ft_printf(FMT_ZERO_PRECI, ARG_BASIC) == printf(FMT_ZERO_PRECI, ARG_BASIC));
	check(ft_printf(FMT_TWO_PRECI, ARG_BASIC) == printf(FMT_TWO_PRECI, ARG_BASIC));
	check(ft_printf(FMT_TWO_PRECI, ARG_NULL) == printf(FMT_TWO_PRECI, ARG_NULL));
	check(ft_printf(FMT_ZERO_PRECI, ARG_NULL) == printf(FMT_ZERO_PRECI, ARG_NULL));
}
