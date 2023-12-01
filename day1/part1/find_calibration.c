/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_calibration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <lagonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:28:34 by lagonzal          #+#    #+#             */
/*   Updated: 2023/12/01 14:05:37 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	find_first_number(char *str)
{
	int	first;

	first = 0;
	while (str[first] && !isdigit(str[first]))
		first++;
	return ((int) str[first] - '0');
}

int	find_last_number(char *str)
{
	int	last;

	last = strlen(str);
	if (!last)
		return (0);
	while (last-- > 0 && !isdigit(str[last]) )
		;
	return ((int) str[last] - '0');
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
		sum += (find_first_number(line) * 10) + (find_last_number(line));
	printf("final value is %d\n", sum);
}