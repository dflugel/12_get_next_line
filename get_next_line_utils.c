/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:06 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/27 11:43:27 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find_next_line(char *buf);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_list_polish(t_list **lst, int new_line_loc);

int	find_next_line(char *buf)
{
	int	i;

	i = 0;
	while (*(buf + i) != '\n' && *(buf + i) != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	int		n;
	char	*place;

	if (nmemb * size > 2147483647)
		return (NULL);
	i = 0;
	n = nmemb * size;
	place = (void *)malloc(n);
	if (!place)
		return (0);
	while (i < (n))
	{
		*(place + i) = '\0';
		i++;
	}
	return ((void *)place);
}

int	ft_list_polish(t_list **lst, int new_line_loc)
{
	t_list	*temp;
	char	*buf;
	int		i;
	t_list	*new;

	buf = calloc((BUFFER_SIZE - new_line_loc + 1), sizeof(char));
	i = 0;
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	while (new_line_loc <= BUFFER_SIZE)
		*(buf + i++) = temp->content[new_line_loc++];
	new = malloc (sizeof (t_list));
	if (!new)
		return (-1);
	new->next = NULL;
	i = 0;
	while (*(buf + i) != '\0')
	{
		new->content[i] = *(buf + i);
		i++;
	}
	new->content[i] = '\0';
	free(buf);
	ft_lstclear(lst);
	*lst = new;
	return (1);
}
