/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagonzal <larraingonzalez@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:04:27 by larra             #+#    #+#             */
/*   Updated: 2023/12/04 18:05:26 by lagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_resize(char **old, char *new_line)
{
	char	**new;
	int		m;
	int		n;

	n = 1;
	while (old && old[n])
		n++;
	new = malloc((n + 1) * sizeof(char *));
	if (!new)
		return (NULL);
	m = -1;
	while (old != NULL && old[m] != NULL)
		new[m] = old[m];
	new[n - 1] = new_line;
	new[n] = NULL;
	if (old)
		free(old);
	return (new);
}
