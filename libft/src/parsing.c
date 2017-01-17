/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 16:03:28 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/13 18:30:21 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	parse(t_file *prtf)
{
	flag(prtf);
	if (*prtf->form == 'S' || (*prtf->form == 's' && prtf->flag[8] == 1))
		prtf_s_up(prtf, 0);
	else if (*prtf->form == 's')
		prtf_s(prtf);
	else if (*prtf->form == 'p')
		prtf_p(prtf);
	else if (*prtf->form == 'd')
		prtf_di(prtf);
	else if (*prtf->form == 'D')
	{
		prtf->flag[8] = 1;
		prtf_di(prtf);
	}
	else if (*prtf->form == 'i')
		prtf_di(prtf);
	else if (*prtf->form == '%')
		prtf_percent(prtf);
	parse_sd(prtf);
}

void	parse_sd(t_file *prtf)
{
	char	*tmp;

	if (ft_strchr("oux", *prtf->form))
		prtf_oux(prtf);
	else if (*prtf->form == 'O')
	{
		prtf->flag[8] = 1;
		prtf_oux(prtf);
	}
	else if (*prtf->form == 'U')
	{
		prtf->flag[8] = 1;
		prtf_oux(prtf);
	}
	else if (*prtf->form == 'X')
	{
		prtf_oux(prtf);
		tmp = ft_strupper(prtf->i);
		ft_memdel((void *)&(prtf->i));
		prtf->i = tmp;
	}
	else if (*prtf->form == 'C' || (*prtf->form == 'c' && prtf->flag[8] == 1))
		prtf_c_up(prtf);
	else if (*prtf->form == 'c')
		prtf_c(prtf);
}
