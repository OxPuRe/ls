/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:04:01 by auverneu          #+#    #+#             */
/*   Updated: 2019/04/18 18:46:14 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_cmpstring(const void *a, const void *b)
{
	return (ft_strcmp(*((char * const *)a), *((char * const *)b)));
}

void    ft_ls_sort(t_structls *ls)
{
    if ((ls->flag & F_L))
        ft_qsort(ls->elem, ls->nbe, sizeof(char *), &ft_cmpstring);
}