/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:56:16 by clbouche          #+#    #+#             */
/*   Updated: 2021/08/16 13:13:46 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *error)
{
	printf("Error : %s\n", error);
	exit(-1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			rslt = rslt * 10 + (str[i] - '0');
			i++;
		}
		else
			ft_error(ERR_NUM);
	}
	return (rslt * sign);
}
