/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 23:18:33 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/02 10:37:46 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t idx1;
	size_t idx2;
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	idx1 = dst_len;
	idx2 = 0;
	while (src[idx2] && idx1 + idx2 + 1 < size)
	{
		dst[idx1 + idx2] = src[idx2];
		idx2++;
	}
	dst[idx1 + idx2] = 0;
	if (dst_len > size)
		return (src_len + size);
	else
		return (src_len + dst_len);
}
