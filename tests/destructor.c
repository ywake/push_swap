/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:43:04 by ywake             #+#    #+#             */
/*   Updated: 2021/10/21 16:01:54 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define END			"\033[0m"
#define RED			"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"

void	destructor(void)__attribute__((destructor));

void	destructor(void)
{
	int		status;
	char	buf[50];

	snprintf(buf, 50, "leaks -q %d &> leaksout", getpid());
	status = system(buf);
	if (status)
	{
		fprintf(stderr, RED"leak!!!\n"YELLOW);
		system("cat leaksout >/dev/stderr");
		fprintf(stderr, END);
		exit(1);
	}
}
