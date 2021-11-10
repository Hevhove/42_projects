/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:37:02 by hvan-hov          #+#    #+#             */
/*   Updated: 2021/11/10 13:06:42 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{
	static char	*strg;
	char		*buff;
	char		*ret;
	size_t		read_out;

	if ((read(fd, 0, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	read_out = 1;
	ret = NULL;
	buff = ft_strchr(strg, '\n');
	if (!buff)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		while (ret == NULL && i > 0)
		{
			read_out = read(fd, buff, BUFFER_SIZE);
			ret = feed_storage(&storage, &buf, i);
		}
	}
	ret = valid_storage(&storage, (buff - storage) + 1);
	return (ret);
}

static char *feed_storage(char **storage, char **buff, size_t read_out)
{
	char *tmp;
	char *ret;

	ret = NULL;
	if (read_out <= 0)
	{
		if (read_out == 0 && *strg)
		{
			ret = *storage;
			*strg = NULL;
		}
		return (ret);
	}
	(*buff)[i] = '\0';
	tmp = ft_strchr(*buff, '\n');
	if (tmp)
		ret = valid_buffer(strg, buff, (tmp - *buff) + 1);
	else
	{
		tmp = ft_strjoin(*strg, *buff);
		if (*strg)
			free(strg);
		*strg = tmp;
	}
	return (ret);
}
