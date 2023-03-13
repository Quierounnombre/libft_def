# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicgarci <vicgarci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/18 00:04:51 by vicgarci          #+#    #+#              #
#    Updated: 2022/09/19 18:39:08 by vicgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

BLACK = \033[0;30m
RED =   \033[0;31m
GREEN = \033[0;32m
YELLOW =    \033[0;33m
BLUE  = \033[0;34m
MAGENTA =   \033[0;35m
CYAN =  \033[0;36m
LGRAY = \033[0;37m
DGRAY = \033[1;30m
LBLUE = \033[1;34m
LGREEN = \033[1;32m
LCYAN = \033[1;36m
LRED = \033[1;31m
LMAGENTA =\033[1;35m
LYELLOW = \033[1;33m
WHITE = \033[1;37m
RESET = \033[0m

FILES_STRFUNS = ft_strchr \
		ft_strrchr \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strncmp \
		ft_strnstr \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_tolower \
		ft_toupper \
		ft_atoi \
		ft_itoa \
		ft_striteri \
		ft_strmapi \
		ft_atoi_base \
		ft_itoa_base \

STR_DIR = ./strfuns/
SRCS_STR = $(addprefix $(STR_DIR), $(addsuffix .c, $(FILES_STRFUNS)))
OBJS_STR = $(addprefix $(STR_DIR), $(addsuffix .o, $(FILES_STRFUNS)))

FILES_TESTING = ft_test_output \

TESTING_DIR = ./testing/
SRCS_TESTING = $(addprefix $(TESTING_DIR), $(addsuffix .c, $(FILES_TESTING)))
OBJS_TESTING = $(addprefix $(TESTING_DIR), $(addsuffix .o, $(FILES_TESTING)))

FILES_CONTROL = ft_ishexa \
			ft_isalpha \
			ft_isdigit \
			ft_isalnum \
			ft_isascii \
			ft_isspace \
			ft_isprint \

CONTROL_DIR = ./is_control/
SRCS_CONTROL = $(addprefix $(CONTROL_DIR), $(addsuffix .c, $(FILES_CONTROL)))
OBJS_CONTROL = $(addprefix $(CONTROL_DIR), $(addsuffix .o, $(FILES_CONTROL)))

FILES_GNL =	get_next_line_bonus \

GNL_DIR = ./gnl/
SRCS_GNL = $(addprefix $(GNL_DIR), $(addsuffix .c, $(FILES_GNL)))
OBJS_GNL = $(addprefix $(GNL_DIR), $(addsuffix .o, $(FILES_GNL)))

FILES_LST =	ft_lstnew \
	 	ft_lstadd_front \
	 	ft_lstsize \
	  	ft_lstlast \
	  	ft_lstadd_back \
	  	ft_lstdelone \
	  	ft_lstclear \
	  	ft_lstiter \
	  	ft_lstmap \

LST_DIR = ./lstfuns/
SRCS_LST = $(addprefix $(LST_DIR), $(addsuffix .c, $(FILES_LST)))
OBJS_LST = $(addprefix $(LST_DIR), $(addsuffix .o, $(FILES_LST)))

FILES_MATHFUNS = load_vector3D \
		ft_wrap \

MATHFUNS_DIR = ./mathfuns/
SRCS_MATHFUNS = $(addprefix $(MATHFUNS_DIR), $(addsuffix .c, $(FILES_MATHFUNS)))
OBJS_MATHFUNS = $(addprefix $(MATHFUNS_DIR), $(addsuffix .o, $(FILES_MATHFUNS)))

FILES_MEMSFUNS = ft_calloc \
		ft_memset \
		ft_memcpy \
		ft_memmove \
		ft_bzero \
		ft_memchr \
		ft_memcmp \
		ft_2dcalloc \
		ft_store_file \

MEMSFUNS_DIR = ./memsfuns/
SRCS_MEMSFUNS = $(addprefix $(MEMSFUNS_DIR), $(addsuffix .c, $(FILES_MEMSFUNS)))
OBJS_MEMSFUNS = $(addprefix $(MEMSFUNS_DIR), $(addsuffix .o, $(FILES_MEMSFUNS)))

FILES_PRINTF = Cases \
		c_case \
		di_case \
		p_case \
		s_case \
		xmin_case \
		xmax_case \
		u_case \
		printf \

PRINTF_DIR = ./printf/
SRCS_PRINTF = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(FILES_PRINTF)))
OBJS_PRINTF = $(addprefix $(PRINTF_DIR), $(addsuffix .o, $(FILES_PRINTF)))

FILES_PUTFUNS = ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putunbr_fd \
		ft_putuhexa_fd \
		ft_putnbr_base \

PUTFUNS_DIR = ./putfuns/
SRCS_PUTFUNS = $(addprefix $(PUTFUNS_DIR), $(addsuffix .c, $(FILES_PUTFUNS)))
OBJS_PUTFUNS = $(addprefix $(PUTFUNS_DIR), $(addsuffix .o, $(FILES_PUTFUNS)))

OBJS = $(OBJS_CONTROL) $(OBJS_GNL) $(OBJS_LST) $(OBJS_MATHFUNS) $(OBJS_MEMSFUNS) $(OBJS_PUTFUNS) $(OBJS_STR) $(OBJS_TESTING) $(OBJS_PRINTF)
SRCS = $(SRCS_CONTROL) $(SRCS_GNL) $(SRCS_LST) $(SRCS_MATHFUNS) $(SRCS_MEMSFUNS) $(SRCS_PUTFUNS) $(SRCS_STR) $(SRCS_TESTING) $(SRCS_PRINTF)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(GREEN)\nLibreria compilada\n$(RESET)" 

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)\nArchivos .o limpiados\n$(RESET)"

fclean: clean
	@$(RM) $(NAME) 
	@echo "$(RED)\nLibreria limpiada\n$(RESET)"

re: fclean all

.PHONY: all clean fclean re

.SILENT:

coffee:
	@clear
	@echo ""
	@echo "                   ("
	@echo "	                     )     ("
	@echo "               ___...(-------)-....___"
	@echo '           .-""       )    (          ""-.'
	@echo "      .-''''|-._             )         _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "                 ("
	@echo "	                  )      ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""       )   (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "               ("
	@echo "	                  )     ("
	@echo "               ___..(.------)--....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'
	@sleep 0.5
	@clear
	@echo ""
	@echo "             (         ) "
	@echo "	              )        ("
	@echo "               ___)...----)----....___"
	@echo '           .-""      )    (           ""-.'
	@echo "      .-''''|-._      (       )        _.-|"
	@echo '     /  .--.|   `""---...........---""`   |'
	@echo "    /  /    |                             |"
	@echo "    |  |    |                             |"
	@echo "     \  \   |                             |"
	@echo "      '\ '\ |                             |"
	@echo "        '\ '|                             |"
	@echo "        _/ /\                             /"
	@echo "       (__/  \                           /"
	@echo '    _..---""` \                         /`""---.._'
	@echo " .-'           \                       /          '-."
	@echo ":               '-.__             __.-'              :"
	@echo ':                  ) ""---...---"" (                :'
	@echo "\'._                '"--...___...--"'              _.'"
	@echo '   \""--..__                              __..--""/'
	@echo "     '._     """----.....______.....----"""         _.'"
	@echo '         ""--..,,_____            _____,,..--"""'''
	@echo '                      """------"""'