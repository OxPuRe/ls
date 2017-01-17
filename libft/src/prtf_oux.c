/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtf_oux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 23:01:57 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/12 20:58:52 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	prtf_o(t_file *prtf)
{
	if (prtf->flag[8] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, ULONG)), 8);
	else if (prtf->flag[7] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, ULLONG)), 8);
	else if (prtf->flag[6] == 1)
		prtf->i = ft_ulltoa_base((USHRT)(va_arg(prtf->ap, UINT)), 8);
	else if (prtf->flag[5] == 1)
		prtf->i = ft_ulltoa_base((UCHAR)(va_arg(prtf->ap, UINT)), 8);
	else if (prtf->flag[9] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, uintmax_t)), 8);
	else if (prtf->flag[10] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, size_t)), 8);
	else
		prtf->i = ft_lltoa_base((va_arg(prtf->ap, UINT)), 8);
}

static void	prtf_u(t_file *prtf)
{
	if (prtf->flag[8] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, ULONG)), 10);
	else if (prtf->flag[7] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, ULLONG)), 10);
	else if (prtf->flag[6] == 1)
		prtf->i = ft_ulltoa_base((USHRT)(va_arg(prtf->ap, UINT)), 10);
	else if (prtf->flag[5] == 1)
		prtf->i = ft_ulltoa_base((UCHAR)(va_arg(prtf->ap, UINT)), 10);
	else if (prtf->flag[9] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, uintmax_t)), 10);
	else if (prtf->flag[10] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, size_t)), 10);
	else
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, UINT)), 10);
	prtf->flag[4] = 0;
}

static void	prtf_x(t_file *prtf)
{
	if (prtf->flag[8] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, ULONG)), 16);
	else if (prtf->flag[7] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, ULLONG)), 16);
	else if (prtf->flag[6] == 1)
		prtf->i = ft_ulltoa_base((USHRT)(va_arg(prtf->ap, UINT)), 16);
	else if (prtf->flag[5] == 1)
		prtf->i = ft_ulltoa_base((UCHAR)(va_arg(prtf->ap, UINT)), 16);
	else if (prtf->flag[9] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, uintmax_t)), 16);
	else if (prtf->flag[10] == 1)
		prtf->i = ft_ulltoa_base((va_arg(prtf->ap, size_t)), 16);
	else
		prtf->i = ft_lltoa_base((va_arg(prtf->ap, UINT)), 16);
	if (prtf->i[0] == '0')
		prtf->flag[0] = 0;
}

void		prtf_oux(t_file *prtf)
{
	if (*prtf->form == 'o' || *prtf->form == 'O')
		prtf_o(prtf);
	else if (*prtf->form == 'u' || *prtf->form == 'U')
		prtf_u(prtf);
	else if (*prtf->form == 'x' || *prtf->form == 'X')
		prtf_x(prtf);
	prtf->flag[3] = 0;
}
