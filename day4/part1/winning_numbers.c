/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winning_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:33:23 by lagonzal          #+#    #+#             */
/*   Updated: 2023/12/04 18:33:23 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <fcntl.h>
#include <string.h>
#include "libft/libft.h"

int	power(int base, int power)
{
	int	result;

	result = 1;
	while (power > 0)
	{
		result *= base;
		power--;
	}
	return (result);
}

int	check_numbers(char *line)
{
	char	*win;
	char	*nums;
	char	**win_nums;
	char	**my_nums;
	int		n, m, winners;

	win = strchr(line, ':') + 1;
	nums = strchr(line, '|') + 1;
	*(nums - 1) = '\0';
	win_nums = ft_split(win, ' ');
	my_nums = ft_split(nums, ' ');
	n = 0;
	winners = 0;
	win_nums = ft_multitrim(win_nums, "\n");
	my_nums = ft_multitrim(my_nums, "\n");
	while (win_nums[n])
	{
		m = 0;
		while (my_nums[m])
		{
			if (atoi(win_nums[n]) == atoi(my_nums[m]))
				winners++;
			m++;
		}
		n++;
	}
	ft_double_free(win_nums);
	ft_double_free(my_nums);
	if (winners == 0)
		return (0);
	return (power(2, winners - 1));
}

int main(void)
{
	FILE	*file;
	char	line[200];
	int		sum;

	file = fopen("input.txt", "r");
	if (!file)
		return (perror("Error on open\n"), 1);
	sum = 0;
	while (fgets(line, sizeof(line), file))
	{
		sum += check_numbers(line);
	}
	printf("result %d\n", sum);
	return (0);
}