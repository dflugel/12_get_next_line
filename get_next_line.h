/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:55:59 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/03 16:57:41 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// Structs

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

// Prototypes

char	*get_next_line(int fd);
int		ft_list_append(t_list **lst, char letter);
char	*ft_list_to_string(t_list **lst);

// utils
