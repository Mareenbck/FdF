/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:16:53 by mbascuna          #+#    #+#             */
/*   Updated: 2022/02/05 17:55:14 by marinebas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s || !fd)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	long long	result;
	int	neg;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * neg);
}

void ft_error(char *msg)
{
	perror(msg);
  //ft_putstr_fd(msg, 2);
  exit(EXIT_FAILURE);
}

int	ft_check_overflow(char *av)
{
	long long nb;
	nb = ft_atoi(av);
	if (nb >= INT_MAX && nb <= INT_MIN && ft_strlen(av) < 12)
		return (1);
	ft_error("error");
	return (0);
}

int main(int ac, char **av)
{
	ft_check_overflow(av[1]);
	return (0);
}
