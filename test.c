/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:50:30 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/03 17:07:01 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void	ft_print_list(t_list **lst);
void	ft_lstclear(t_list **lst);

int	main(void)
{
	FILE			*file_ptr;
	char			*text;
	char			*text2;
	int				i;

	text = malloc(11);
	file_ptr = fopen("testtext.txt", "r+");
	i = 0;
	while (i < 10)
	{
		read(3, (text + i), 1);
		i++;
	}
	*(text + i) = '\0';
	printf("%s", text);
	text2 = get_next_line(3);
	printf("%s", text2);	
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
