/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnessrou <tnessrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 19:47:29 by tnessrou          #+#    #+#             */
/*   Updated: 2021/08/02 19:47:31 by tnessrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_handlers.h"

static	int	is_overflow(const long long *num, const int *sign)
{
	if (*sign && (*num > 2147483648))
		return (1);
	if (!*sign && (*num > 2147483647))
		return (1);
	return (0);
}

int	ft_atoi(const char *str, int *flag)
{
	long long	result;
	int			sign;

	result = 0;
	*flag = check_invalid_input(str);
	if (*flag)
		return (-1);
	sign = 0;
	if (*str == '-')
		sign = 1;
	while (*(str + sign))
	{
		result *= 10;
		result += *(str + sign) - 48;
		*flag = is_overflow(&result, &sign);
		if (*flag)
			return (-1);
		str++;
	}
	if (sign)
		return (-result);
	return (result);
}
