/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 17:28:49 by auverneu          #+#    #+#             */
/*   Updated: 2018/05/18 17:32:15 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double		ft_pow(double x, int y)
{
    double	temp;

    if (y == 0)
       return 1;
    temp = ft_pow(x, (y / 2));       
    if ((y % 2) == 0)
        return (temp*temp);
    else
    {
        if(y > 0)
            return (x * temp * temp);
        else
            return ((temp * temp) / x);
    }
}
