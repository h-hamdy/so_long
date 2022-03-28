/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:54:11 by hhamdy            #+#    #+#             */
/*   Updated: 2022/03/24 00:05:13 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* This function checks for invalid components 
	and the map lenght */
int	check_components(char **lines, int len)
{
	int	i;
	int	j;

	i = -1;
	while (lines[++i])
	{
		if (len != (int)ft_strlen(lines[i]) || ft_strlen(lines[i]) < 3)
			raise_error('l');
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] != '0' && lines[i][j] != '1'
				&& lines[i][j] != 'P' && lines[i][j] != 'C'
				&& lines[i][j] != 'E' && lines[i][j] != 'H')
				raise_error('c');
		}
	}
	return (1);
}

// check if the map serrounded by walls
int	check_walls(char **lines, int len)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	j = -1;
	flag = 1;
	while (lines[++i])
	{
		if (lines[i][len - 1] != '1' || lines[i][0] != '1')
			flag = 0;
	}
	i--;
	while (lines[i][++j])
	{
		if (lines[i][j] != '1' || lines[0][j] != '1')
			flag = 0;
	}
	if (flag == 0)
		raise_error('w');
	return (1);
}

// This fuction checks if the file map end with .ber
void	check_name(char *av)
{
	int	len;

	len = ft_strlen(av) - 4;
	if (ft_strcmp(&av[len], ".ber"))
		raise_error('f');
}

// This map check if there are lines between 
void	check_lines(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (str[i] == '\n')
		raise_error('m');
	while (str[i])
	{
		if (str[i] == 'P')
			flag++;
		if (str[i] == '\n' && str[i + 1] == '\n')
			raise_error('m');
		i++;
	}
	i--;
	if (str[i] == '\n')
		raise_error('m');
	if (flag > 1 || flag == 0)
		raise_error('p');
}

char	**check_map(char *av)
{
	int		fd;
	char	*str;
	char	**lines;

	str = NULL;
	check_name(av);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		raise_error('F');
	str = read_file(fd);
	check_lines(str);
	lines = ft_split(str, '\n');
	free(str);
	check_components(lines, (int)ft_strlen(lines[0]));
	check_walls(lines, (int)ft_strlen(lines[0]));
	return (lines);
}
