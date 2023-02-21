/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:45:53 by f██████           #+#    #+#             */
/*   Updated: 2023/02/21 01:07:54 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

// minimal color codes
# define TNRM  "\x1B[0m"
# define TRED  "\x1B[31m"
# define TGRN  "\x1B[32m"
# define TYEL  "\x1B[33m"
# define TBLU  "\x1B[34m"
# define TMAG  "\x1B[35m"
# define TCYN  "\x1B[36m"
# define TWHT  "\x1B[37m"

// chained list type
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

// chained list functions
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lst_push(t_list *lst, void *content);

// character functions
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

// memory functions
# ifndef MALLOC_LIMIT
#  define MALLOC_LIMIT 5
# endif

# ifdef __linux__
#  define OPEN_MAX 256
# endif

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_mint_free(int n, ...);
void	*ft_dmalloc(int size);

// conversion functions
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa(int n);

// file description functions
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(int n, int fd);

// character string functions
char	*ft_strchr(const char *s, int c);
int		ft_strchr_i(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, int j);
size_t	ft_strlcat(char *dst, const char *src, size_t dsts);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsts);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strnstr_i(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, int i);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_isnbr(char *nbr);
char	*ft_str_repl(char *str, char *old_word, char *new_word);
char	*ft_str_del(char *str, char *old_word);

// array functions
int		ft_arr2dlen(void **arr);
void	ft_arr2dfree(void **arr);
char	**ft_arradd_str(char **arr, char *str);

// printf and dprintf function
int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		putp_fd(unsigned long long pnt, int fd);
int		puts_fd(char *s, int fd);
int		putc_fd(char c, int fd);
int		putdi_fd(int n, int fd);
int		putu_fd(int n, int fd);
int		putx1_fd(int n, int fd);
int		putx2_fd(int n, int fd);
char	*ull_to_hex(uint64_t ull);
char	*i_to_hex(uint64_t ull);

// get next line functions
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

#endif