/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaoui <yzaoui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:26:18 by yzaoui            #+#    #+#             */
/*   Updated: 2023/03/28 18:55:07 by yzaoui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcutendl(char *str, char **after, register int i, int i_endl)
{
	char	*before;

	before = ft_calloc2((i_endl + 2), sizeof(char));
	if (!before)
		return (NULL);
	(*after) = ft_calloc2((ft_strlen_or_findendl(str, 0)) - i_endl + 1, \
	sizeof(char));
	if (!(*after))
		return (free(before), NULL);
	while (str[i])
	{
		if (i <= i_endl)
			before[i] = str[i];
		else if (i > i_endl)
			(*after)[i - i_endl - 1] = str[i];
		i++;
	}
	before[i_endl + 1] = '\0';
	(*after)[i - i_endl - 1] = '\0';
	return (before);
}

char	*get_line(int fd, char *reste)
{
	char	*all_read;
	char	*buff;
	int		nbr_read;
	char	*tmp;

	all_read = NULL;
	all_read = ft_strjoin2(all_read, reste);
	free(reste);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nbr_read = BUFFER_SIZE;
	while (nbr_read == BUFFER_SIZE && !ft_strlen_or_findendl(buff, 2))
	{
		nbr_read = read(fd, buff, BUFFER_SIZE);
		if (nbr_read <= 0)
			break ;
		buff[nbr_read] = '\0';
		tmp = ft_strdup2(all_read, 1);
		all_read = ft_strjoin2(tmp, buff);
		if (!all_read)
			return (free(buff), NULL);
	}
	return (free(buff), all_read);
}

char	*get_next_line(int fd)
{
	static char	*reste_fd[FOPEN_MAX];
	char		*lecture_buff;
	char		*ligne;
	int			i_endl;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	if (!reste_fd[fd])
		reste_fd[fd] = NULL;
	lecture_buff = get_line(fd, reste_fd[fd]);
	reste_fd[fd] = NULL;
	if (!lecture_buff)
		return (NULL);
	i_endl = ft_strlen_or_findendl(lecture_buff, 1);
	if (!lecture_buff[i_endl] || !lecture_buff[i_endl + 1])
		return (lecture_buff);
	ligne = ft_strcutendl(lecture_buff, &(reste_fd[fd]), 0, i_endl);
	return (free(lecture_buff), ligne);
}
