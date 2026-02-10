# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 17:03:19 by mlouis            #+#    #+#              #
#    Updated: 2026/02/10 17:04:27 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := cast.out

CL_DIR := class/
SRCS_DIR := src/
OBJS_DIR := .build/

BUREAUCRAT_DIR := $(addprefix $(CL_DIR), bureaucrat/)
BUREAUCRAT_CL := Bureaucrat.cpp Intern.cpp

FORM_DIR := $(addprefix $(CL_DIR), form/)
FORM_CL := AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

P_BUREAUCRAT := $(addprefix $(BUREAUCRAT_DIR), $(BUREAUCRAT_CL))
P_FORM := $(addprefix $(FORM_DIR), $(FORM_CL))

P_MAIN := $(addprefix $(SRCS_DIR), main.cpp)

SRCS := $(P_BUREAUCRAT) $(P_FORM) $(P_MAIN)
INCS := $(BUREAUCRAT_DIR) $(FORM_DIR)
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS := $(addprefix $(OBJS_DIR), $(OBJS:.o=.d))

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := $(addprefix -I,$(INCS)) -MMD -MP
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -rf $(OBJS_DIR)
	rm -f $(NAME)

re: fclean
	$(MAKE) all
