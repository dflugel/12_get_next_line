/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:55:59 by dflugel           #+#    #+#             */
/*   Updated: 2024/04/27 11:34:08 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

// Structs

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

// Prototypes
char	*get_next_line(int fd);
char	*ft_list_to_string(t_list **lst, int new_line_loc);
int		ft_list_append(t_list **lst, char *buf);
void	ft_lstclear(t_list **lst);

// utils

int		find_next_line(char *buf);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_list_polish(t_list **lst, int new_line_loc);

void	ft_print_list(t_list **lst);

#endif
