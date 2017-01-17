/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:03:35 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/12 21:04:44 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	flag(t_file *prtf)
{
	while ((ft_strchr("sSpdDioOuUxXcC%", (int)(*prtf->form))) == NULL &&
			(ft_strchr("#0-+ .123456789hljz*", *prtf->form) != NULL))
	{
		if (*prtf->form == '0' && prtf->flag[12] == 0)
			prtf->flag[1] = 1;
		else if (*prtf->form == ' ' && prtf->flag[3] == 0)
			prtf->flag[4] = 1;
		else if (*prtf->form == '+')
		{
			prtf->flag[3] = 1;
			prtf->flag[4] = 0;
		}
		else if (*prtf->form == 'h' && *(prtf->form + 1) == 'h')
		{
			prtf->flag[5] = 1;
			prtf->form++;
		}
		else if (*prtf->form == 'l' && *(prtf->form + 1) == 'l')
		{
			prtf->flag[7] = 1;
			prtf->form++;
		}
		flag_sd(prtf);
	}
}

void	flag_sd(t_file *prtf)
{
	if (*prtf->form == 'h' && *prtf->form + 1 != 'h' && prtf->flag[5] == 0)
		prtf->flag[6] = 1;
	else if (*prtf->form == 'l' && *prtf->form + 1 != 'l' && prtf->flag[7] == 0)
		prtf->flag[8] = 1;
	else if (*prtf->form == '#')
		prtf->flag[0] = 1;
	else if (*prtf->form == '-')
		prtf->flag[2] = 1;
	else if (*prtf->form == 'j')
		prtf->flag[9] = 1;
	else if (*prtf->form == 'z')
		prtf->flag[10] = 1;
	else if (ft_strchr("0123456789", *prtf->form))
	{
		prtf->flag[14] = ft_atoi((char *)prtf->form);
		if (*prtf->form == '0' && prtf->flag[12] == 0)
			prtf->flag[13] = 1;
		while (ft_strchr("0123456789", *prtf->form))
			prtf->form++;
		prtf->form--;
	}
	flag_prec(prtf);
	prtf->form++;
}

void	flag_prec(t_file *prtf)
{
	if (*prtf->form == '.')
	{
		prtf->flag[12] = 1;
		prtf->form++;
		if (*prtf->form == '*')
		{
			prtf->flag[11] = va_arg(prtf->ap, int);
			prtf->form++;
		}
		else
		{
			while (*prtf->form == '0')
				prtf->form++;
			prtf->flag[11] = ft_atoi((char *)prtf->form);
			while (ft_strchr("0123456789", *prtf->form))
				prtf->form++;
		}
		prtf->form--;
		prtf->flag[13] = 0;
		prtf->flag[1] = 2;
	}
	else if (*prtf->form == '*')
		flag_star(prtf);
}

void	flag_star(t_file *prtf)
{
	prtf->flag[14] = va_arg(prtf->ap, int);
	if (prtf->flag[14] < 0)
	{
		prtf->flag[14] = -(prtf->flag[14]);
		prtf->flag[2] = 1;
	}
}
