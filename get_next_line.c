/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddallas <ddallas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:49:41 by ddallas           #+#    #+#             */
/*   Updated: 2019/06/25 18:53:31 by ddallas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_string(unsigned char *content, size_t i)
{
	char	*str;
	int		j;
	
	str = ft_strnew(i);
	str = (char *)malloc(sizeof(char) * i);
	j = 0;
	while (content[j] != '\n')
	{
		str[j] = content[j];
		j++;
	}
	str[j] = '\0';
	return(str);
}

int		get_next_line(const int fd, char **line)
{
	int 			bytes;
	size_t			i;
	static t_gnl	*strpart;
	static t_gnl	*tmp;
	
	if (fd < 0 || !line)
		return(-1);
	if (!(strpart = (t_gnl*)malloc(sizeof(t_gnl))))
		return(-1);
	tmp = strpart;
	while ((bytes = read(fd, tmp->content, BUFF_SIZE)))
	{
		i = 0;
		while (i < BUFF_SIZE)
		{
			if (tmp->content[i] == '\n')
			{
				*line = get_string(tmp->content, i);
				return (1);
			}
			else
			{
				/* code */
			}
			i++;
		}
	}
	return(0);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		//ft_putendl(line);
		free(line);
	}
	if (argc == 2)
		close(fd);
}
