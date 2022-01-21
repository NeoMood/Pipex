/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_no_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgmira <sgmira@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:07:41 by sgmira            #+#    #+#             */
/*   Updated: 2022/01/20 18:45:25 by sgmira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	arg_no_err(void)
{
	// write(1, "error: Invalid number of arguments\n", 36);
	puts("error: Invalid number of arguments\n");
	exit(1);
}
