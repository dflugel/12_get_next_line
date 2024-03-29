/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:50:30 by dflugel           #+#    #+#             */
/*   Updated: 2024/03/29 16:43:35 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int		ft_list_append(t_list **lst, char letter);
void	ft_print_list(t_list **lst);
void	ft_lstclear(t_list **lst);

int	main(void)
{
	//atexit(check_leaks);
	FILE			*file_ptr;
	char			*text;
	int				i;
	static t_list	*next_line;
	char			temp;

	text = malloc(11);
	file_ptr = fopen("testtext.txt", "r+");
	i = 0;
	temp = '\0';
	next_line = malloc(sizeof(t_list));
	if (!next_line)
		return (0);
	next_line->next = NULL;
	while (i < 10)
	{
		read(3, (text + i), 1);
		i++;
	}
	*(text + i) = '\0';
	printf("%s", text);
	i = 0;
	while (i < 10)
	{
		read(3, &temp, 1);
		ft_list_append(&next_line, temp);
		i++;
	}
	ft_print_list(&next_line);
	ft_lstclear(&next_line);
	free(next_line);
	free(text);
	fclose(file_ptr);
	return (0);
}

void	ft_print_list(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next != NULL)
	{
		printf("%c", temp->content);
		temp = temp->next;
	}
	printf("%c", temp->content);
}

int	ft_list_append(t_list **lst, char letter)
{
	t_list	*new;
	t_list	*temp;

	if (!lst || !letter)
		return (-1);
	new = malloc(sizeof(t_list));
	if (!new)
		return (-1);
	new->content = letter;
	if (lst == NULL)
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
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		if (lst == NULL)
		{
			return ;
		}
		free(current);
		current = next;
	}
	*lst = NULL;
}
