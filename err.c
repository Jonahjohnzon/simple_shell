#include "shell.h"

/**
 * _eratoi - err
 * @a: input
 * Return: int
 */
int _eratoi(char *a)
{
	int i = 0;
	unsigned long int r = 0;

	if (*a == '+')
	{
		a++;
	}
	for (i = 0;  a[i] != '\0'; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			r *= 10;
			r += (a[i] - '0');
			if (r > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
	}
	return (r);
}

/**
 * print_err - print err mgs
 * @inform: input
 * @str: input
 * Return: void
 */
void print_err(info_table *inform, char *str)
{
	_errputs(inform->fname);
	_errputs(": ");
	print_d(inform->line_count, STDERR_FILENO);
	_errputs(": ");
	_errputs(inform->argv[0]);
	_errputs(": ");
	_errputs(str);
}

/**
 * print_d - function
 * @input: input
 * @f: file
 * Return:int
 */
int print_d(int input, int f)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abst_, curr;

	if (f == STDERR_FILENO)
	{
		__putchar = _errputchar;
	}
	if (input < 0)
	{
		_abst_ = -input;

		__putchar('-');
		count++;
	}
	else
	{
		_abst_ = input;
	}
	curr = _abst_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abst_ / i)
		{
			__putchar('0' + curr / i);
			count++;
		}
		curr %= i;
	}
	__putchar('0' + curr);
	count++;

	return (count);
}

/**
 * convert_number - convert function
 * @num: input
 * @base: input
 * @flag: input
 * Return: char
 */
char *convert_number(long int num, int base, int flag)
{
	static char *arr;
	static char buff[50];
	char sig = 0;
	char *pt;
	unsigned long n = num;

	if (!(flag & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sig = '-';

	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buff[49];
	*pt = '\0';

	do	{
		*--pt = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sig)
	{
		*--pt = sig;
	}
	return (pt);
}

/**
 * remove_comment - remove comment
 * @buff: input
 * Return: void;
 */
void remove_comment(char *buff)
{
	int in;

	for (in = 0; buff[in] != '\0'; in++)
		if (buff[in] == '#' && (!in || buff[in - 1] == ' '))
		{
			buff[in] = '\0';
			break;
		}
}
