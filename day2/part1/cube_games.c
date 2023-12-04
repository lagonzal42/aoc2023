/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_games.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:07:24 by lagonzal          #+#    #+#             */
/*   Updated: 2023/12/03 22:07:24 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft/libft.h"

static const int	max_red = 12;
static const int	max_green = 13;
static const int	max_blue = 14;

int	check_set(char *set)
{
	int		n;
	int		m;
	char	**piece;
	int		num;
	int		red = 0;
	int		blue = 0;
	int		green = 0;

	m = 0;
	piece = ft_split(set, ',');
	while (piece[m])
	{
		n = 0;
		while (piece[m][n] && !isdigit(piece[m][n]))
			n++;
		num = atoi(&piece[m][n]);
		while (piece[m][n] && !isalpha(piece[m][n]))
			n++;
		if (strcmp(&piece[m][n], "red") == 0)
			red += num;
		else if (strcmp(&piece[m][n], "blue") == 0)
			blue += num;
		else if (strcmp(&piece[m][n], "green") == 0)
			green += num;
		m++;
	}
	ft_double_free(piece);
	return (red > max_red || blue > max_blue || green > max_green);
}

int	check_line(char *line)
{
	char		**set;
	char		*first_set;
	int			n;

	first_set = strchr(line, ':') + 2;
	set = ft_split(first_set, ';');
	n = 0;
	while (set[n])
	{
		if (check_set(set[n]))
			return (ft_double_free(set), 1);
		n++;
	}
	ft_double_free(set);
	return (0);
}

int main(void)
{
	FILE	*file;
	char	line[200];
	int		sum;
	int		index;

	file = fopen("input.txt", "r");
	if (!file)
		return (perror("Error opening the file\n"), 1);
	sum = 0;
	index = 1;
	while (fgets(line, sizeof(line), file))
	{
		if (!check_line(line))
			sum += index;
		index++;
	}
	printf("%d\n", sum);
}