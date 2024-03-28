/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:56:01 by dflugel           #+#    #+#             */
/*   Updated: 2024/03/28 22:48:18 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

char	*get_next_line(int fd)
{
	char			*result;
	static t_list	*temp;

	get_as_list(temp, fd);
	return (result);
}

/*t_list	get_as_list(t_list *lst, int fd)
{
	char	letter;
	t_list	*temp;

	read(fd, letter, 1);
	while (letter != "\n")
	{
		// funktioniert wsl so nicht,
		// ich muss die neue Node in einer eigenen Funktion hinzufügen.
		temp = ft_lstnew(letter);
		ft_lstadd_back(lst, temp);
		read(fd, letter, 1);
	}
}*/
