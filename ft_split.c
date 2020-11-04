/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:08:02 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/04 11:00:17 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cnt_len(char *str, char c)
{
	int cnt;

	cnt = 0;
	while (str[cnt])
	{
		if (str[cnt] == c)
			break ;
		else
			cnt++;
	}
	return (cnt);
}

int		cnt_str(char *str, char c)
{
	int idx;
	int cnt;

	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		if (str[idx] == c && str[idx + 1] == c)
			;
		else if (str[idx])
			cnt++;
		idx++;
	}
	if (str[idx - 1] != c)
		cnt++;
	return (cnt);
}

void	free_str(char **str, int idx)
{
	while (idx >= 0)
	{
		free(str[idx]);
		idx--;
	}
	free(str);
}

char	**put_value(char **str, char *src, char c)
{
	int idx;
	int total;
	int len;

	idx = 0;
	total = 0;
	while (src[total])
	{
		if (src[total] == c)
			total++;
		else
		{
			len = cnt_len(src + total, c);
			if (!(str[idx] = (char *)malloc(sizeof(char *) * len)))
			{
				free_str(str, idx);
				return (NULL);
			}
			str[idx] = ft_substr(src, total, len);
			total += len;
			idx++;
		}
	}
	str[idx] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	*cpy_s;
	int		idx;
	size_t	cnt;

	idx = 0;
	cnt = 0;
	if (!s)
		return (NULL);
	if (!(cpy_s = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	ft_strlcpy(cpy_s, s, ft_strlen(s) + 1);
	if (!(str = (char **)malloc(sizeof(char *) * (cnt_str(cpy_s, c) + 1))))
		return (NULL);
	put_value(str, cpy_s, c);
	return (str);
}
