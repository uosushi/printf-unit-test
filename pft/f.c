#include <check.h>

int	ft_printf(const char *input, ...);

#define NAN1 (0.0 / 0.0)
#define NAN2 -(0.0 / 0.0)
#define INF (1 / 0.0)
#define MINUS_INF (-1 / 0.0)

static void	normal(double n)
{
	int	ex_len;
	int	ft_len;

	printf("EX [");
	ex_len = printf("%f", n);
	printf("]\n");
	write(1, "FT [", 4);
	ft_len = ft_printf("%f", n);
	write(1, "]\n", 2);
	check(ex_len == ft_len);
}

static void	width(int width, double n)
{
	int	ex_len;
	int	ft_len;

	printf("EX [");
	ex_len = printf("%*f", width, n);
	printf("]\n");
	write(1, "FT [", 4);
	ft_len = ft_printf("%*f", width, n);
	write(1, "]\n", 2);
	check(ex_len == ft_len);
}

static void	preci(int preci, double n)
{
	int	ex_len;
	int	ft_len;

	printf("EX [");
	ex_len = printf("%.*f", preci, n);
	printf("]\n");
	write(1, "FT [", 4);
	ft_len = ft_printf("%.*f", preci, n);
	write(1, "]\n", 2);
	check(ex_len == ft_len);
}

void	run(void)
{
	u_int64_t	n;
	double		irn;

	BASIC ;
	normal(4.2);
	normal(DBL_MAX);
	normal(NAN1);
	normal(NAN2);
	normal(INF);
	normal(MINUS_INF);
	WIDTH ;
	width(20, 0.0);
	width(-20, 0.0);
	width(INT_MAX, 0.0);
	PRECI ;
	n = (1ull << 52) - 1;
	irn = *(double *)(&n);
	preci(-1, 4.2);
	preci(10, 4.2);
	preci(10, -4.2);
	preci(2000, irn);
}
