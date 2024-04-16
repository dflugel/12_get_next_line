/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:55:59 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/16 12:46:37 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

#endif
