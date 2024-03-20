/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:50:30 by dflugel           #+#    #+#             */
/*   Updated: 2024/03/20 18:34:49 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	FILE	*file_ptr;
	char	*text;
	char	*text2;
	int		i;

	text = malloc(10);
	text2 = malloc(10);
	file_ptr = fopen("testtext.txt", "r+");
	i = 0;
	while (i < 10)
	{
		read(3, (text + i), 1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		read(3, (text2 + i), 1);
		i++;
	}
	printf("%s\n%s\n", text, text2);
	fclose(file_ptr);
	return (0);
}
