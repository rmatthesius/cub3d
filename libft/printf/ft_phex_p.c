/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:48:06 by jkarras           #+#    #+#             */
/*   Updated: 2024/04/30 14:52:29 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_phex_p(unsigned int n, size_t *counter, const char *s)
{
	if (n >= 16)
		ft_phex_p(n / 16, counter, s);
	ft_putchar_p(s[n % 16], counter);
}
