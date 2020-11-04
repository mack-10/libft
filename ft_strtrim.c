/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:13:59 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/03 14:38:04 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		search_begin(char *str, char const *set)
{
	int cnt;
	int idx1;
	int idx2;

	cnt = 0;
	idx1 = 0;
	while (str[idx1])
	{
		idx2 = 0;
		while (set[idx2])
		{
			if (str[idx1] == set[idx2])
			{
				cnt++;
				break ;
			}
			idx2++;
		}
		if (idx2 == (int)ft_strlen(set))
			break ;
		idx1++;
	}
	return (cnt);
}

int		search_end(char *str, char const *set)
{
	int cnt;
	int end;
	int idx;

	end = ft_strlen(str) - 1;
	cnt = 0;
	while (end)
	{
		idx = 0;
		while (set[idx])
		{
			if (str[end] == set[idx])
			{
				cnt++;
				break ;
			}
			idx++;
		}
		if (idx == (int)ft_strlen(set))
			break ;
		end--;
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trim;
	int		cnt_b;
	int		cnt_e;

	if (!s1 || !set)
		return (NULL);
	if (!(str_trim = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (0);
	ft_strlcpy(str_trim, s1, ft_strlen(s1) + 1);
	cnt_b = search_begin(str_trim, set);
	if (cnt_b == (int)ft_strlen(s1))
		return ("");
	cnt_e = search_end(str_trim, set);
	str_trim = ft_substr(str_trim, cnt_b,
			ft_strlen(str_trim) - (cnt_b + cnt_e));
	return (str_trim);
}
