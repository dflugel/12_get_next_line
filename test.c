/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:50:30 by dflugel           #+#    #+#             */
/*   Updated: 2024/03/28 23:33:26 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_list_append(t_list **lst, char letter);
void	ft_print_list(t_list **lst);

void	check_leaks(void)
{
	system("leaks so_long");
}

int	main(void)
{
	atexit(check_leaks);
	FILE			*file_ptr;
	char			*text;
	int				i;
	static t_list	*next_line = NULL;
	char			temp;

	text = malloc(10);
	file_ptr = fopen("testtext.txt", "r+");
	i = 0;
	temp = '\0';
	while (i < 10)
	{
		read(3, (text + i), 1);
		i++;
	}
	i = 0;
	while (i < 10)
	{
		ft_list_append(next_line, temp);
		i++;
	}
	printf("%s\n", text);
	ft_print_list(next_line);
	fclose(file_ptr);
	return (0);
}

void	ft_print_list(t_list **lst)
{
	write(1, "pb\n", 3);
	t_list	*temp;

	temp = *lst;
	while (temp->next != NULL)
	{
		printf("%c", temp->content);
		temp = temp->next;
	}
	printf("\n");
	write(1, "pe\n", 3);
}

int	ft_list_append(t_list **lst, char letter)
{
	write(1, "ab\n", 3);
	t_list	*new;
	t_list	*temp;

	if (!lst || !letter)
		return (-1);
	new = malloc(sizeof(t_list));
	write(1, "ae\n", 3);
	if (!new)
		return (-1);
	new->content = letter;
	if (*lst == NULL)
		{
			*lst = new;
		}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		if (temp)
		{
			temp->next = new;
			new->next = NULL;
		}
	}
	write(1, "ae\n", 3);
	return (1);
}
