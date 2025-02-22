NAME = fractol

CC = cc

# CFLAGS = -Wall -Wextra -Werror 

MINLIB_DIR = -L/usr/local/lib/ -lmlx

X11_LIBS = -lX11 -lXext

SRCS = main.c\
	manage_hooks.c\
	frame_drawing.c\
	mandelbrot_set.c\
	function_utils.c\
	zoom_in_out.c\
	julia_set.c\
	julia_parsing.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ${OBJS} $(MINLIB_DIR) ${X11_LIBS} -o ${NAME}

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all