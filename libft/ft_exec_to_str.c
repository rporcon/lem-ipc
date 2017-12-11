/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 15:45:38 by rporcon           #+#    #+#             */
/*   Updated: 2017/08/19 18:40:27 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_binary_stdout(int fd, pid_t pid, char **tmp_ls_file,
			struct stat *st)
{
	wait4(pid, NULL, 0, NULL);
	if ((fd = open(TMP_FPATH, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		return (-1);
	fstat(fd, st);
	*tmp_ls_file = malloc((sizeof(char) * st->st_size) + 1);
	read(fd, *tmp_ls_file, st->st_size);
	close(fd);
	unlink(TMP_FPATH);
	return (0);
}

char	*ft_exec_to_str(char *bin_path)
{
	int				fd;
	int				saved_stdout;
	pid_t			pid;
	struct stat		st;
	char			*tmp_ls_file;

	tmp_ls_file = NULL;
	saved_stdout = 442;
	if ((fd = open(TMP_FPATH, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		return (NULL);
	saved_stdout = dup2(1, saved_stdout);
	dup2(fd, 1);
	pid = fork();
	if (pid == 0)
		execl(bin_path, bin_path, NULL);
	else if (read_binary_stdout(fd, pid, &tmp_ls_file, &st) == -1)
		return (NULL);
	tmp_ls_file[st.st_size] = '\0';
	dup2(saved_stdout, 1);
	close(saved_stdout);
	return (tmp_ls_file);
}
