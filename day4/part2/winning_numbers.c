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
	return (winners);
}

int main(void)
{
	FILE	*file;
	char	line[200];
	int		cards[201];
	int		sum;
	int		index;

	file = fopen("input.txt", "r");
	if (!file)
		return (perror("Error on open\n"), 1);
	sum = 0;
	index = 0;
	while (index < 201)
	{
		cards[index] = 1;
		index++;
	}
	index = 0;
	while (fgets(line, sizeof(line), file))
	{
		sum = check_numbers(line);
		while (sum > 0)
		{
			cards[index + sum] += cards[index];
			sum--;
		}
		for (int x = 0; x < 101; x++)
		index++;
		// scanf("%c\n", &c);
	}
	sum = 0;
	index = 0;
	while (index < 201)
	{
		sum += cards[index];
		index++;
	}
	printf("%d\n", sum);
	return (0);
}