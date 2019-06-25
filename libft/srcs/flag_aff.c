/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 18:18:37 by auverneu          #+#    #+#             */
/*   Updated: 2019/06/24 21:26:15 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	print(t_file *prtf)
{
	if ((ft_strchr("cC", *prtf->form)) && *prtf->i == 0)
	{
		write(prtf->fd, "\0", 1);
		prtf->print += 1;
	}
	else
		ft_putstr_fd(prtf->i, prtf->fd);
}

void	display_o(t_file *prtf, int *i)
{
	if (prtf->flag[3] == 1 && prtf->flag[15] == 0)
		F_WIDTH--;
	if (F_ZERO == 2 && F_NBPREC >= 0)
		F_ZERO = 0;
	if (F_NBPREC < *i)
		F_NBPREC = *i;
	if (prtf->flag[15] == 1 && F_WIDTH > 0)
		F_WIDTH -= 1;
	if ((ft_strchr("oO", *prtf->form) != NULL) && F_HASH == 1)
	{
		if (F_ZERO == 1 && (ft_atoi(prtf->i) != 0))
			ft_putchar_prtf('0', prtf);
		F_WIDTH--;
	}
	if (ft_strchr("xXp", (int)(*prtf->form)) != NULL && F_HASH == 1)
	{
		if (F_ZERO == 1)
			flag_sharp(prtf);
		F_WIDTH -= 2;
	}
	if ((ft_strchr("diu", *prtf->form) != NULL) &&
		(F_ZERO == 1 || prtf->flag[2] == 1))
		if (prtf->flag[3] == 1 && prtf->flag[15] == 0)
			ft_putchar_prtf('+', prtf);
}

void	display_prec(t_file *prtf, int i, int j)
{
	if ((ft_strchr("cCsS", *prtf->form) != NULL) && F_NBPREC > i)
		F_NBPREC = i;
	if (F_HASH == 1)
	{
		if (prtf->flag[3] == 1 && prtf->flag[15] != 1)
			ft_putchar_fd('+', prtf->fd);
		if ((ft_strchr("oO", *prtf->form) != NULL) && (((F_NBPREC <= i &&
			F_ZERO == 0 && ft_atoi(prtf->i) != 0) || ((ft_atoi(prtf->i) == 0) &&
			F_PREC == 1 && F_NBPREC == 0))))
			ft_putchar_prtf('0', prtf);
		if (ft_strchr("xXp", (int)(*prtf->form)) != NULL && F_ZERO == 0)
			flag_sharp(prtf);
	}
	while (j < (F_NBPREC - i))
	{
		ft_putchar_prtf('0', prtf);
		j++;
	}
	print(prtf);
	prtf->print += i;
}

void	display_t(t_file *prtf, int i, int j)
{
	if (prtf->flag[4] == 1 && prtf->flag[15] == 0 &&
		(ft_strchr("diu", *prtf->form) != NULL))
	{
		ft_putchar_prtf(' ', prtf);
		F_WIDTH--;
	}
	if ((F_ZERO == 1 || prtf->flag[2] == 1) && prtf->flag[15] == 1)
		ft_putchar_prtf('-', prtf);
	if (prtf->flag[2] == 1)
		display_prec(prtf, i, 0);
	while (j < (F_WIDTH - i - (F_NBPREC - i)))
	{
		if (F_ZERO != 0 && prtf->flag[2] == 0)
			ft_putchar_prtf('0', prtf);
		else
			ft_putchar_prtf(' ', prtf);
		j++;
	}
	if ((ft_strchr("diu", *prtf->form) != NULL) && F_ZERO == 0)
		if (prtf->flag[3] == 1 && prtf->flag[15] == 0 && prtf->flag[2] == 0)
			ft_putchar_prtf('+', prtf);
	if (F_ZERO == 0 && prtf->flag[2] == 0 && prtf->flag[15] == 1)
		ft_putchar_prtf('-', prtf);
	if (prtf->flag[2] == 0)
		display_prec(prtf, i, 0);
}

void	flag_sharp(t_file *prtf)
{
	if ((ft_strchr("oO", *prtf->form) != NULL) && (ft_atoi(prtf->i) != 0))
		ft_putchar_prtf('0', prtf);
	else if (*prtf->form == 'x' || *prtf->form == 'p')
	{
		ft_putstr_fd("0x", prtf->fd);
		prtf->print += 2;
	}
	else if (*prtf->form == 'X')
	{
		ft_putstr_fd("0X", prtf->fd);
		prtf->print += 2;
	}
}
