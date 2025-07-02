/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:02:34 by rtodaro           #+#    #+#             */
/*   Updated: 2025/07/02 23:13:13 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# include "minirt.h"

// Reset
# define RESET "\x1b[0m"

// Bold colors
# define BOLD_BLACK "\x1b[1;30m"
# define BOLD_RED "\x1b[1;31m"
# define BOLD_GREEN "\x1b[1;32m"
# define BOLD_YELLOW "\x1b[1;33m"
# define BOLD_BLUE "\x1b[1;34m"
# define BOLD_MAGENTA "\x1b[1;35m"
# define BOLD_CYAN "\x1b[1;36m"
# define BOLD_WHITE "\x1b[1;37m"

// Errors (hardcoded colors for 42 norm)
# define MALLOC_ERROR "\x1b[1;31mMALLOC ERROR\x1b[0m"
# define GENERAL_ERROR "\x1b[1;31mError\n\x1b[0m"
# define ARGS_ERROR "\x1b[1;31mINVALID ARGUMENTS!\x1b[0m"
# define NOT_RT_FILE_ERROR "\x1b[1;31mNOT .rt or INVALID FILE!\x1b[0m"
# define NON_EXISTENT_FILE_ERROR "\x1b[1;31mTHE INDICATED FILE DOES \
NOT EXIST!\x1b[0m"
# define FILE_OPENING_ERROR "\x1b[1;31mERROR OPENING THE FILE!\x1b[0m"
# define EMPTY_FILE_ERROR "\x1b[1;31mTHE SELECTED FILE IS EMPTY!\x1b[0m"

// Syntax Errors
# define SYNTAX_ERROR "\x1b[1;31mError\nINVALID_SYNTAX!\n\x1b[0m"
# define MISSING_ERROR "\x1b[1;31m⬤ \x1b[0mMissing istance of "
# define TOO_MANY "\x1b[1;31m⬤ \x1b[0mToo many istances of "
# define INVALID_PARAMS "\x1b[1;31m⬤ \x1b[0mInvalid number of params for "
# define COORD_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid coords for "
# define NORMAL_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid normal for "
# define FOV_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid fov for "
# define RATIO_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid ratio for "
# define COLOR_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid color for "
# define DIAMETER_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid DIAMETER for "
# define HEIGHT_ERROR "\x1b[1;31m⬤ \x1b[0mInvalid HEIGHT for "

// Objs Messages
# define CAM_MSG "\x1b[1;36mCAMERA\x1b[0m object"
# define LIGHT_MSG "\x1b[1;32mLIGHT\x1b[0m object"
# define A_LIGHT_MSG "\x1b[1;35mAMBIENT LIGHT\x1b[0m object"
# define PL_MSG "\x1b[1;33mPLANE\x1b[0m object"
# define SP_MSG "\x1b[1;33mSPHERE\x1b[0m object"
# define CY_MSG "\x1b[1;33mCYLINDER\x1b[0m object"

// Objs Errors
# define CAM_ERROR "\x1b[1;36mCAMERA\x1b[1;31m object"
# define LIGHT_ERROR "\x1b[1;32mLIGHT\x1b[1;31m object"
# define A_LIGHT_ERROR "\x1b[1;35mAMBIENT LIGHT\x1b[1;31m object"
# define PL_ERROR "\x1b[1;33mPLANE\x1b[1;31m object"
# define SP_ERROR "\x1b[1;33mSPHERE\x1b[1;31m object"
# define CY_ERROR "\x1b[1;33mCYLINDER\x1b[1;31m object"

// Messages
# define VALID_FILE_MSG "\x1b[1;32m\nVALID FILE!\n\x1b[0m"

#endif
