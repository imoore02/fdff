/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:37:56 by imoore            #+#    #+#             */
/*   Updated: 2022/05/14 16:59:58 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*chopatendofline(char	*unchopped)
{
	char	*choppedoff;
	int		counter;

	counter = 0;
	while (unchopped[counter] != '\n' && unchopped[counter] != '\0')
		counter++;
	if (unchopped[counter] == '\0' || unchopped[1] == '\0')
		return (NULL);
	choppedoff = ft_substr(unchopped, counter + 1, ft_strlen(unchopped) - 1);
	if (*choppedoff == '\0')
	{
		free (choppedoff);
		choppedoff = NULL;
	}
	unchopped[counter + 1] = '\0';
	return (choppedoff);
}

char	*readtxtfile(int fd, char *bufferstring, char *staticholderstring)
{
	int		counter;
	char	*holderstring;

	counter = 1;
	while (counter != 0)
	{
		counter = read(fd, bufferstring, BUFFER_SIZE);
		if (counter == -1)
			return (NULL);
		else if (counter == 0)
			break ;
		bufferstring[counter] = '\0';
		if (!staticholderstring)
			staticholderstring = ft_strdup("");
		holderstring = staticholderstring;
		staticholderstring = ft_strjoin(holderstring, bufferstring);
		free (holderstring);
		holderstring = NULL;
		if (ft_strchr(bufferstring, '\n'))
			break ;
	}
	return (staticholderstring);
}

char	*get_next_line(int fd)
{
	char			*bufferstring;
	char			*thestringtoreturn;
	static char		*staticholderstring;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bufferstring = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!bufferstring)
		return (NULL);
	thestringtoreturn = readtxtfile(fd, bufferstring, staticholderstring);
	free(bufferstring);
	bufferstring = NULL;
	if (!thestringtoreturn)
		return (NULL);
	staticholderstring = chopatendofline(thestringtoreturn);
	return (thestringtoreturn);
}
