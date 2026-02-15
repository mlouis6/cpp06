# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/10 17:03:19 by mlouis            #+#    #+#              #
#    Updated: 2026/02/11 11:03:23 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := cast.out

CL_DIR := class/
SRCS_DIR := src/
OBJS_DIR := .build/

SCALAR_DIR := $(addprefix $(CL_DIR), scalar/)
SCALAR_CL := ScalarConverter.cpp

P_SCALAR := $(addprefix $(SCALAR_DIR), $(SCALAR_CL))

P_MAIN := $(addprefix $(SRCS_DIR), main.cpp)

SRCS := $(P_SCALAR) $(P_MAIN)
INCS := $(SCALAR_DIR)
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
