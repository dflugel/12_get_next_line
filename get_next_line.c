/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:01 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/03 17:05:06 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
int		ft_list_append(t_list **lst, char letter);
char	*ft_list_to_string(t_list **lst);
void	ft_lstclear(t_list **lst);

char	*get_next_line(int fd)
{
	int				i;
	static t_list	*line_list;
	char			temp;
	char			*next_line;

	i = 0;
	temp = '\0';
	line_list = malloc(sizeof(t_list));
	if (!line_list)
		return (0);
	line_list->next = NULL;
	while (i < 10)
	{
		read(fd, &temp, 1);
		ft_list_append(&line_list, temp);
		i++;
	}
	next_line = ft_list_to_string(&line_list);
	ft_lstclear(&line_list);
	free(line_list);
	return (next_line);
}

char	*ft_list_to_string(t_list **lst)
{
	t_list	*temp;
	int		len;
	char	*str;

	temp = *lst;
	len = 0;
	while (temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	temp = *lst;
	str = malloc(len + 1);
	len = 0;
	while (temp->next != NULL)
	{
		*(str + len++) = temp->content;
		temp = temp->next;
	}
	*(str + len++) = '\0';
	return(str);
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
		*lst = new;
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
