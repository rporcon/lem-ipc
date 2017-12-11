/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:40:56 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/19 18:55:33 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cpy_tmp_to_file(char **file, char *file_tmp, int ret, size_t offset)
{
	if (*file != NULL)
		free(*file);
	if ((*file = malloc((sizeof(char) * ret) + offset + 1)) == NULL)
		return (-1);
	if (file_tmp != NULL)
	{
		ft_strncpy(*file, file_tmp, offset);
		free(file_tmp);
	}
	return (0);
}

void	buf_to_file(char *file, char *buf, int ret, size_t *offset)
{
	ft_strncpy(file + *offset, buf, ret);
	*offset += ret;
}

int		stdin_buf_to_file(char *file, char *buf, int ret, size_t *offset)
{
	int		nl_pos;

	nl_pos = 0;
	if ((nl_pos = ft_charnpos(buf, '\n', ret)) != -1)
	{
		ft_strncpy(file + *offset, buf, nl_pos);
		*offset += (nl_pos);
		return (1);
	}
	return (0);
}

void	init_ft_read_fd(char **file, char **file_tmp, size_t *offset)
{
	*file = NULL;
	*file_tmp = NULL;
	*offset = 0;
}

char	*ft_read_fd(int fd)
{
	char	buf[BUF_SIZE];
	int		ret;
	char	*file;
	char	*file_tmp;
	size_t	offset;

	init_ft_read_fd(&file, &file_tmp, &offset);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		if (ret == -1)
			break ;
		if (cpy_tmp_to_file(&file, file_tmp, ret, offset) == -1)
			return (NULL);
		if (fd == 0 && stdin_buf_to_file(file, buf, ret, &offset) == 1)
			break ;
		else
			buf_to_file(file, buf, ret, &offset);
		if ((file_tmp = malloc(sizeof(char) * (offset + 1))) == NULL)
			return (NULL);
		ft_strncpy(file_tmp, file, offset);
	}
	if (file_tmp != NULL)
		free(file_tmp);
	file != NULL ? file[offset] = '\0' : (void)0;
	return (file);
}
