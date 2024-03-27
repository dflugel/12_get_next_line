/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:50:30 by dflugel           #+#    #+#             */
/*   Updated: 2024/03/27 16:22:10 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void	check_leaks(void)
{
	system("leaks so_long");
}

int	main(void)
{
	atexit(check_leaks);
	FILE			*file_ptr;
	char			*text;
	char			*text2;
	int				i;
	//static t_list	*temp;

	text = malloc(10);
	//text2 = malloc(10);
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

int	ft_list_append(t_list **lst, char *letter)
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !letter)
		return (-1);
	new = malloc(sizeof(t_list));
	if (!new)
		return (-1);
	new->content = letter;
	temp = *lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	if (temp != 0)
	{
		temp->next = new;
	}
	return (1);
}
