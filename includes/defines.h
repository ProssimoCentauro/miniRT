#ifndef DEFINES_H
#define DEFINES_H

#include "minirt.h"

// Reset
#define RESET       "\x1b[0m"

// Bold colors
#define BOLD_BLACK  "\x1b[1;30m"
#define BOLD_RED    "\x1b[1;31m"
#define BOLD_GREEN  "\x1b[1;32m"
#define BOLD_YELLOW "\x1b[1;33m"
#define BOLD_BLUE   "\x1b[1;34m"
#define BOLD_MAGENTA "\x1b[1;35m"
#define BOLD_CYAN   "\x1b[1;36m"
#define BOLD_WHITE  "\x1b[1;37m"

//Errors
#define MALLOC_ERROR BOLD_RED"MALLOC ERROR"RESET
#define GENERAL_ERROR BOLD_RED"Error\n"RESET
#define ARGS_ERROR BOLD_RED"INVALID ARGUMENTS!"RESET
#define NOT_RT_FILE_ERROR BOLD_RED"NOT .rt or INVALID FILE!"RESET
#define NON_EXISTENT_FILE_ERROR BOLD_RED"THE INDICATED FILE DOES NOT EXIST!"RESET
#define FILE_OPENING_ERROR BOLD_RED"ERROR OPENING THE FILE!"RESET
#define EMPTY_FILE_ERROR BOLD_RED"THE SELECTED FILE IS EMPTY!"RESET

//Syntax Errors
#define SYNTAX_ERROR BOLD_RED"Error\nINVALID_SYNTAX!\n"RESET
#define MISSING_ERROR BOLD_RED "⬤ " RESET "Missing istance of "
#define TOO_MANY BOLD_RED "⬤ " RESET "Too many istances of "
#define INVALID_PARAMS BOLD_RED "⬤ " RESET "Invalid number of params for "
#define COORD_ERROR BOLD_RED "⬤ " RESET "Invalid coords for "
#define NORMAL_ERROR BOLD_RED "⬤ " RESET "Invalid normal for "
#define FOV_ERROR BOLD_RED "⬤ " RESET "Invalid fov for "
#define RATIO_ERROR BOLD_RED "⬤ " RESET "Invalid ratio for "
#define COLOR_ERROR BOLD_RED "⬤ " RESET "Invalid color for "
#define DIAMETER_ERROR BOLD_RED "⬤ " RESET "Invalid DIAMETER for "
#define HEIGHT_ERROR BOLD_RED "⬤ " RESET "Invalid HEIGHT for "

//Objs Messages
#define CAM_MSG BOLD_CYAN "CAMERA" RESET " object"	
#define LIGHT_MSG BOLD_GREEN "LIGHT" RESET " object"	
#define A_LIGHT_MSG BOLD_MAGENTA "AMBIENT LIGHT" RESET " object"	
#define PL_MSG BOLD_YELLOW "PLANE" RESET " object"	
#define SP_MSG BOLD_YELLOW "SPHERE" RESET " object"	
#define CY_MSG BOLD_YELLOW "CYLINDER" RESET " object"	

//Objs Errors
#define CAM_ERROR BOLD_CYAN "CAMERA" BOLD_RED " object"	
#define LIGHT_ERROR BOLD_GREEN "LIGHT" BOLD_RED " object"	
#define A_LIGHT_ERROR BOLD_MAGENTA "AMBIENT LIGHT" BOLD_RED " object"	
#define PL_ERROR BOLD_YELLOW "PLANE" BOLD_RED " object"	
#define SP_ERROR BOLD_YELLOW "SPHERE" BOLD_RED " object"	
#define CY_ERROR BOLD_YELLOW "CYLINDER" BOLD_RED " object"	

//Messages
#define VALID_FILE_MSG BOLD_GREEN"\nVALID FILE!\n"RESET
#endif
