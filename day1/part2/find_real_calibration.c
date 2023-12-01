/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_real_calibration.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:02:23 by lagonzal          #+#    #+#             */
/*   Updated: 2023/12/01 17:38:50 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

const static char *numbers[10] = {
	"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", NULL};

char	*find_last_digit(char *str)
{
	int	last;

	last = strlen(str);
	if (!last)
		return (0);
	while (last-- > 0 && !isdigit(str[last]) )
		;
	return (last >= 0 ? &str[last] : str);
}

char	*find_first_digit(char *str)
{
	int	first;

	first = 0;
	while (str[first] && !isdigit(str[first]))
		first++;
	return (&str[first]);
}

int	take_number(char *str)
{
	int	i;
	if (isdigit(str[0]))
		return ((int) str[0] - '0');
	i = 0;
	while (numbers[i] && strncmp(str, numbers[i], strlen(numbers[i])) != 0)
		i++;
	return (i + 1);
}

char	*strrstr(char *big, const char *small)
{
	int		i;
	char	*found;

	i = strlen(big) - 1;
	found = NULL;
	while (i >= 0 && !found)
	{
		if (strlen(&big[i]) >= strlen(small))
			found = strstr(&big[i], small);
		i--;
	}
	return (found);
}

int	find_numbers(char *str)
{
	char	*first_str;
	char	*last_str;
	char	*tmp_start;
	char	*tmp_end;
	
	last_str = find_last_digit(str);
	first_str = find_first_digit(str);
	for (int i = 0; numbers[i]; i++)
	{
		tmp_start = strstr(str, numbers[i]);
		tmp_end = strrstr(str, numbers[i]);
		if (tmp_start)
		{
			if (tmp_start > last_str)
				last_str = tmp_start;
			if (tmp_start < first_str)
				first_str = tmp_start;
		}
		if (tmp_end)
		{
			if (tmp_end > last_str)
				last_str = tmp_end;
			if (tmp_start < first_str)
				first_str = tmp_end;
		}
	}
	return (take_number(first_str) * 10 + take_number(last_str));
}

int	main(void)
{
	FILE	*file;
	char	line[100];
	int		sum;

	file = fopen("input.txt", "r");
	if (!file)
	{
		perror("Error while opening the file\n");
		return (1);
	}
	sum = 0;
	while (fgets(line, sizeof(line), file))
	{
		sum += (find_numbers(line));
	}
	printf("%d\n", sum);
}