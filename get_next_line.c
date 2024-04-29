/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:01 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/27 11:56:06 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd);
char	*ft_list_to_string(t_list **lst, int new_line_loc);
int		ft_list_append(t_list **lst, char *buf);
void	ft_lstclear(t_list **lst);

char	*get_next_line(int fd)
{
	static t_list	*line_list;
	char			*temp;
	char			*next_line;
	int				error;
	int				new_line_loc;

	line_list = NULL;
	temp = calloc(BUFFER_SIZE + 1, sizeof(char));
	/*error = read(fd, temp, BUFFER_SIZE);
	if (temp == 0 || error < 0)
		return (NULL);
	ft_list_append(&line_list, temp);
	new_line_loc = find_next_line(temp);*/
	error = 1;
	new_line_loc = BUFFER_SIZE;
	while (*(temp + new_line_loc) != '\n' && error != 0)
	{
		error = read(fd, temp, BUFFER_SIZE);
		printf("Buffer: %s\nNL: %i\nError: %i\nNL Char: %c\n", temp, new_line_loc, error, *(temp + new_line_loc));
		if (error == 0 && line_list == NULL)
			return (0);
		else if (error < 0)
			return (ft_lstclear(&line_list), free(line_list), NULL);
		ft_list_append(&line_list, temp);
		new_line_loc = find_next_line(temp);
	}
	printf("list:\n");
	ft_print_list(&line_list);
	next_line = ft_list_to_string(&line_list, new_line_loc);
	ft_list_polish(&line_list, new_line_loc);
	free(temp);
	return (next_line);
}

char	*ft_list_to_string(t_list **lst, int new_line_loc)
{
	t_list	*temp;
	int		len;
	int		i;
	char	*str;

	temp = *lst;
	len = 0;
	while (temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	temp = *lst;
	str = calloc(len * BUFFER_SIZE + new_line_loc + 1, sizeof(char));
	len = 0;
	while (temp->next != NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE)
			*(str + len++) = temp->content[i++];
		temp = temp->next;
	}
	i = 0;
	while (i <= new_line_loc)
		*(str + len++) = temp->content[i++];
	*(str + len) = '\0';
	return (str);
}

int	ft_list_append(t_list **lst, char *buf)
{
	t_list	*new;
	t_list	*temp;
	int		i;

	if (!lst || !buf)
		return (-1);
	new = malloc (sizeof (t_list));
	if (!new)
		return (-1);
	i = 0;
	printf("Test: %i\n", BUFFER_SIZE);
	while (i <= BUFFER_SIZE)
	{
		printf("Char: %c\nString: %s\nCounter: %i\n", new->content[i], new->content, i);
		new->content[i + 1] = *(buf + i);
		i++;
		printf("Char: %c\nString: %s\nCounter: %i\n", new->content[i], new->content, i);
	}
	new->next = NULL;
	if (NULL == *lst)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		if (temp)
			temp->next = new;
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
