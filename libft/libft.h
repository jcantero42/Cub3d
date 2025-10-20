/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcolop <marcolop@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:28:33 by marcolop          #+#    #+#             */
/*   Updated: 2025/05/28 10:56:55 by marcolop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// calculate length of a string
size_t	ft_strlen(const char *s);

// fill first len bytes of b with constant byte c
void	*ft_memset(void *b, int c, size_t len);

// fill first n bytes of b with constant byte '\0'
void	ft_bzero(void *s, size_t n);

// copy n bytes from src to dst (areas must not overlap)
void	*ft_memcpy(void *dst, const void *src, size_t n);

// copy n bytes from src to dst (areas may overlap)
void	*ft_memmove(void *dst, const void *src, size_t len);

// copy src to dst
// at most dstsize -
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

// append src to dest
// at most size - strlen(dst) - 1
size_t	ft_strlcat(char *dest, char *src, size_t size);

// to uppercase letter
int		ft_toupper(int c);

// to lowercase letter
int		ft_tolower(int c);

// find first occurrence of c in s
char	*ft_strchr(const char *s, int c);

// find last occurrence of c in s
char	*ft_strrchr(const char *s, int c);

// compare first n bytes of two strings
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// scan n bytes of s for first instance of c
void	*ft_memchr(const void *s, int c, size_t n);

// compare first n bytes of memory areas
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// find first ocurrence of needle in haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// convert str to int
int		ft_atoi(const char *str);

// allocate count * size bytes and initialize to zero
void	*ft_calloc(size_t count, size_t size);

// allocate and duplicate string
char	*ft_strdup(const char *s1);

// allocate new substring
char	*ft_substr(char const *s, unsigned int start, size_t len);

// allocate and join s1 and s2
char	*ft_strjoin(char const *s1, char const *s2);

// allocate str and delete all chars in set from start and end
char	*ft_strtrim(char const *s1, char const *set);

// allocate array of str of splitting s using c as delimeter
char	**ft_split(char const *s, char c);

// allocate and convert int to str
char	*ft_itoa(int n);

// allocate and apply f to every char of s
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

// apply f to every char of s
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_printf(char const *format, ...);

char	*get_next_line(int fd);

int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_free_double_ptr(void **ptr);

#endif
