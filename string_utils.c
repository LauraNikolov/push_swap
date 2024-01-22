
#include "test.h"

long    ft_atol(const char *s)
{
    int	    i;
	int	    sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	/* while ((s[i] == ' ') || (s[i] >= 7 && s[i] <= 13))
	{
		i++;
	} */
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	return ((result) * (sign));

}