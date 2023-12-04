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

void	check_set(char *set, int *min_cubes)
{
	int		n;
	int		m;
	char	**piece;
	int		num;
	int		red, green, blue;

	m = 0;
	red = 0;
	green = 0;
	blue = 0;
	piece = ft_split(set, ',');
	while (piece[m])
	{
		n = 0;
		while (piece[m][n] && !isdigit(piece[m][n]))
			n++;
		num = atoi(&piece[m][n]);
		while (piece[m][n] && !isalpha(piece[m][n]))
			n++;
		printf("to compare\"%s\"\n", &piece[m][n]);
		if (strncmp(&piece[m][n], "red", 3) == 0 && num > red)
			red = num;
		else if (strncmp(&piece[m][n], "blue", 4) == 0 && num > green)
			green = num;
		else if (strncmp(&piece[m][n], "green", 5) == 0 && num > blue)
			blue = num;
		m++;
	}
	ft_double_free(piece);
	if (red > min_cubes[0])
		min_cubes[0] = red;
	if (green > min_cubes[1])
		min_cubes[1] = green;
	if (blue > min_cubes[2])
		min_cubes[2] = blue;
	printf("set result red: %d, green %d, blue %d\n", red, green, blue);
}

int	check_line(char *line)
{
	char		**set;
	char		*first_set;
	int			n;
	int			*min_cubes;
	int			result;

	first_set = strchr(line, ':') + 2;
	set = ft_split(first_set, ';');
	n = 0;
	min_cubes = malloc(3 * sizeof(int));
	min_cubes[0] = 0;
	min_cubes[1] = 0;
	min_cubes[2] = 0;
	while (set[n])
	{
		printf("set: %s\n", set[n]);
		check_set(set[n], min_cubes);
		printf("min_red %d, min_green %d, min_blue %d\n", min_cubes[0], min_cubes[1], min_cubes[2]);
		n++;
	}
	result = min_cubes[0] * min_cubes[1] * min_cubes[2];
	free(min_cubes);
	ft_double_free(set);
	return (result);
}

int main(void)
{
	FILE	*file;
	char	line[200];
	int		sum;

	file = fopen("input.txt", "r");
	if (!file)
		return (perror("Error opening the file\n"), 1);
	sum = 0;
	while (fgets(line, sizeof(line), file))
	{
		sum += check_line(line);
	}
	fclose(file);
	printf("%d\n", sum);
}