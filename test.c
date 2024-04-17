/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:50:30 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/17 11:16:13 by dflugel          ###   ########.fr       */
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
	FILE	*file_ptr;
	char	*text;

	file_ptr = fopen("testtext.txt", "r+");
	text = get_next_line(3);
	printf("Test");
	printf("1: %s\n", text);
	free(text);
	text = get_next_line(3);
	printf("2: %s", text);
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
