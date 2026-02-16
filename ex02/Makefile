# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 10:36:06 by mlouis            #+#    #+#              #
#    Updated: 2026/02/16 11:49:52 by mlouis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := cast.out

CL_DIR := class/
SRCS_DIR := src/
INCS_DIR := inc/
OBJS_DIR := .build/

GEN_DIR := $(addprefix $(CL_DIR), generic/)
GEN_CL := Base.cpp

P_GEN := $(addprefix $(GEN_DIR), $(GEN_CL))

P_MAIN := $(addprefix $(SRCS_DIR), main.cpp)

SRCS := $(P_GEN) $(P_MAIN)
INCS := $(GEN_DIR) $(INCS_DIR)
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:%.cpp=%.o))
DEPS := $(OBJS:.o=.d)

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
