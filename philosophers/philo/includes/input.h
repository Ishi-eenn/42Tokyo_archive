/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:58:17 by tsishika          #+#    #+#             */
/*   Updated: 2023/11/21 10:20:45 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <stdbool.h>

# include "utils.h"
# include "type.h"

# define ERR_AC_NUMBER "The number of arguments is incorrect.\n"
# define ERR_AC_NUMERIC "The argument contains non-numeric characters.\n"
# define ERR_AC_SMALL "The value entered is too small.\n"
# define ERR_AC_BIG "The value entered is too big.\n"

// input.c
bool	input_data_from_cmd_line(t_data *data, int argc, char **argv);

// is_arguments.c
bool	is_command_line_arguments(int argc, char **argv);

// is_below_threshold.c
bool	is_all_argcument_thresholds(int argc, char **argv);

// is_count.c
bool	is_argument_count(const int argc);

// is_eating_limit.c
bool	is_eating_limit_zero(int argc, char **argv);

// is_integer_arguments.c
bool	is_integer_arguments(int argc, char **argv);

// is_numeric.c
bool	is_all_argcument_numeric(const int argc, const char **argv);

#endif
