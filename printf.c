#include <unistd.h>
#include <stdarg.h>

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		s = "(null)";
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long nbr, int base)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i += write (1, "-", 1);
	}
	if (nbr >= base)
		i += putnbr((nbr / base), base);
	i += write(1, &"0123456789abcdef"[nbr % base], 1);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		c;
	va_list	args;

	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			c += write(1, &s[i], 1);
		else
		{
			i++;
			if (s[i] == 's')
				c += ft_printstr(va_arg(args, char *));
			if (s[i] == 'd')
				c += ft_putnbr(va_arg(args, int), 10);
			if (s[i] == 'x')
				c += ft_putnbr(va_arg(args, unsigned int), 16);
		}
		i++;
	}
	va_end (args);
	return (c);
}
