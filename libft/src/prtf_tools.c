/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 18:22:09 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 09:01:36 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_file	*create(char *format)
{
	t_file	*new;

	new = (t_file *)ft_memalloc(sizeof(t_file));
	if (new)
	{
		reset_flag(new);
		new->form = format;
		new->print = 0;
		new->i = NULL;
	}
	return (new);
}

void	reset_flag(t_file *prtf)
{
	int		j;

	j = 0;
	while (j < 16)
	{
		prtf->flag[j] = 0;
		j++;
	}
}

void	ft_free_s(t_file *prtf)
{
	if (prtf)
		ft_memdel((void **)&(prtf));
}
