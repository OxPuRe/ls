/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 15:12:58 by auverneu          #+#    #+#             */
/*   Updated: 2016/09/02 09:23:59 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_printf(const char *format, ...)
{
	t_file	*prtf;
	int		i;

	prtf = create((char *)format);
	va_start(prtf->ap, format);
	while (*prtf->form)
	{
		if (*prtf->form == '%' && prtf->form[1])
		{
			prtf->form++;
			parse(prtf);
			if (ft_strchr("sSpdDioOuUxXcC%", *prtf->form) != NULL)
				prtf->i ? ft_print(prtf) : NULL;
			else
				ft_putchar_prtf(*prtf->form, prtf);
		}
		else if (*prtf->form != '%')
			ft_putchar_prtf(*prtf->form, prtf);
		reset_flag(prtf);
		prtf->form++;
	}
	va_end(prtf->ap);
	i = prtf->print;
	ft_free_s(prtf);
	return (i);
}
