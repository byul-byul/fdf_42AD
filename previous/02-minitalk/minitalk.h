/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:35:33 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/27 12:47:57 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

# ifndef TRUE
#  define TRUE				1
# endif

# ifndef FALSE
#  define FALSE				0
# endif

# ifndef DEFAULT_WELCOME
#  define DEFAULT_WELCOME	TRUE
# endif

# ifndef BYTE_SIZE
#  define BYTE_SIZE			16
# endif

# ifndef MICROSECONDS
#  define MICROSECONDS		142
# endif

# ifndef WELCOME_MESSAGE
#  define WELCOME_MESSAGE	"Server's PID:"
# endif

# ifndef REQUEST_MESSAGE
#  define REQUEST_MESSAGE	"Sent:"
# endif

# ifndef RESPONSE_MESSAGE
#  define RESPONSE_MESSAGE	"Recieved:"
# endif

int	is_valid_variables(void);

#endif