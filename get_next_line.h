/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dflugel <dflugel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:55:59 by dflugel           #+#    #+#             */
/*   Updated: 2024/03/20 18:56:20 by dflugel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

// Structs

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Prototypes

char	*get_next_line(int fd);

// utils

t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst);
