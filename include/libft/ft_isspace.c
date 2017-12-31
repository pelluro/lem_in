//
// Created by pelluro on 28/12/17.
//
#include "libft.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\a')
		return (1);
	return (0);
}