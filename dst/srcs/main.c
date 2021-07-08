
#include "pushswap.h"

int	main(int argc, char **argv)
{
	if (argc != 1 && argv)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	write(1, "push_swap\n", 9);
	return (0);
}
