# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 22:24:07 by bahn              #+#    #+#              #
#    Updated: 2022/02/25 16:15:06 by bahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
INCFLAGS = -I. 

RM = rm -rf

SRCS_DIR = ./
SRCS_FILE = main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_FILE))
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

.cpp.o :
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $^ -o $@
	@ tabs -4

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) *_shrubbery

re : fclean all

.PHONY : all clean fclean re