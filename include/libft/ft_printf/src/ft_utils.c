/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:10:42 by mipham            #+#    #+#             */
/*   Updated: 2017/12/18 18:10:20 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

intmax_t	ft_get_signed_from_length(va_list *args, t_arg *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->length == hh)
		nbr = (char)nbr;
	else if (arg->length == h)
		nbr = (short int)nbr;
	else if (arg->length == l)
		nbr = (long int)nbr;
	else if (arg->length == ll)
		nbr = (long long int)nbr;
	else if (arg->length == j)
		nbr = (intmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

uintmax_t	ft_get_unsigned_from_length(va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = va_arg(*args, uintmax_t);
	if (arg->length == hh)
		nbr = (unsigned char)nbr;
	else if (arg->length == h)
		nbr = (unsigned short int)nbr;
	else if (arg->length == l)
		nbr = (unsigned long int)nbr;
	else if (arg->length == ll)
		nbr = (unsigned long long int)nbr;
	else if (arg->length == j)
		nbr = (uintmax_t)nbr;
	else if (arg->length == z)
		nbr = (size_t)nbr;
	else
		nbr = (unsigned int)nbr;
	return (nbr);
}

size_t	ft_calc_nbrstrlen(uintmax_t nbr, char *base,
		char *p, t_arg *arg)
{
	size_t	nbr_len;
	size_t	nbrstrlen;

	nbr_len = ft_nbrlen(nbr, base);
	if (nbr == 0 && arg->get_prec && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->get_prec)
		nbrstrlen = ft_max(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->force_prefix && p != NULL && nbr != 0)
		nbrstrlen += ft_strlen(p);
	return (nbrstrlen);
}

ssize_t	ft_nbrforceprefix(uintmax_t nbr,
		char *base, t_arg *arg, char *prefix)
{
	unsigned	nbr_len;
	size_t		nbr_cut;

	nbr_len = ft_calc_nbrstrlen(nbr, base, NULL, arg) +
		ft_strlen(prefix);
	nbr_cut = ft_strlen(prefix);
	if (arg->get_width && !arg->right_pad && !arg->pad_zero)
	{
		ft_width_pad(nbr_len, arg->width, ' ');
		nbr_cut += ft_max(arg->width - nbr_len, 0);
		arg->get_width = 0;
	}
	else if (arg->get_width)
		arg->width -= ft_strlen(prefix);
	ft_putstr(prefix);
	return (ft_handle_uint(nbr, arg, base, NULL) + nbr_cut);
}

ssize_t	ft_handle_unsigned(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_get_unsigned_from_length(args, arg);
	return (ft_handle_uint(nbr, arg, "0123456789", NULL));
}

unsigned int	ft_nbrlen(uintmax_t nbr, char *base)
{
	size_t			base_nbr;
	unsigned int	i;

	base_nbr = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base_nbr;
		i++;
	}
	return (i);
}

void	ft_width_pad(size_t nbrstrlen, int width, char padwith)
{
	while (nbrstrlen < (size_t)width)
	{
		ft_putchar(padwith);
		nbrstrlen++;
	}
}
