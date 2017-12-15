/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:18:21 by rporcon           #+#    #+#             */
/*   Updated: 2017/09/04 18:14:42 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>


/*
** ft_read_fd func
*/
# define BUF_SIZE 4096

/*
** ft_exec_to_str func
*/
# define TMP_FPATH "/tmp/exec_data"

/*
** lft list struct
*/
typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** personal list struct
*/
typedef struct		s_llist
{
	void			*content;
	struct s_llist	*next;
}					t_llist;

/*
** void** dynamic array struc
*/
typedef struct		s_dyn_array {
	size_t			size;
	size_t			len;
	void			**elems;
}					t_dyn_array;

/*
** lft str func
*/
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*strtrim(char const *s);
char				**strsplit(char const *s, char c);
char				*itoa(int n);
char				*itoa_base(int num, int base);

/*
** lft mem func
*/
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dst, void *src, size_t n);
void				*ft_memccpy(void *dst, void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** lft print func
*/
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** lft llist func
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
int					ft_list_size(t_list *begin_list);
void				ft_list_clear(t_list **begin_list);

/*
** personal llist func
*/
void				ft_ll_new(t_llist **elem, void *content);
void				ft_ll_append(t_llist **ll, void *content);
void				ft_ll_prepend(t_llist **ll, void *content);
void				ft_ll_print(t_llist *ll);

/*
** dynamic array func
*/
void				dynarray_init(t_dyn_array *array, size_t size,
						size_t len);
void				dynarray_add(t_dyn_array *array, void *new_elem);
void				dynarray_print(t_dyn_array array);

/*
** utils
*/
void				ft_swap(int *a, int *b);
int					ft_intarr_includes(int *arr, int arr_size, int tofind);
int					char_count(char const *s, char c);
void				ft_putnbr_u(unsigned int n);
void				ft_putnbr_llu(unsigned long long n);
void				ft_putnbr_max(size_t n);
void				ft_putnbr_max_fd(size_t n, int fd);
char				*itoa_ulong(unsigned long n);
char				*itoa_base_ulong(unsigned long num, int base);
void				ft_printf(char *fmt, ...);
void				ft_fprintf(int fd, char *fmt, ...);
void				puts_leading_zero(char *str, unsigned int nb);
char				*leading_char_before(char *str, char c, size_t len);
void				words_alpha_sort(char **sstr, size_t len);
void				swap_str(char **str1, char **str2);
void				putaddr(const void *addr);
void				putaddr_fd(const void *addr, int fd);
void				putaddr_byte(unsigned char dec_byte);
void				putaddr_byte_fd(unsigned char dec_byte, int fd);
size_t				next_powerchr(size_t num, size_t power);
void				hexdump(void *mem, size_t size);
void				xxd(void *mem, size_t size);
unsigned char		swap_u8b(unsigned char byte);
unsigned short		swap_u16b(unsigned short byte);
unsigned int		swap_u32b(unsigned int num);
unsigned long		swap_u64b(unsigned long num);
unsigned int		ft_pow(unsigned int nb, int power);
int					ft_isupper(unsigned char c);
int					ft_islower(unsigned char c);
int					natoi(const char *str, unsigned int len);
int					natoi_base(const char *str, unsigned int len, int base);
int					atoi_base(const char *str, int base);
size_t				atoi_base_max(const char *str, int base);
size_t				atoi_max(const char *str);
void				words_baseunum_sort(char **sstr, size_t len, int base);
size_t				ft_sstr_len(char **sstr);
void				rev_words(char **sstr, size_t len);
char				*ft_insert_str(char *src, char *dest, unsigned int pos);
char				*ft_insert_char(char *str, char c, unsigned int pos);
char				*syscmd_tostr(char *cmd);
int					charnpos(char *str, char c, size_t len);
int					charpos(char *str, char c);
char				*read_fd(int fd);
size_t				ulong_size(size_t number);
char				*ft_basename(char *path);
size_t				charlastpos(char *s, char c);
unsigned char		*memmemchr(const char *s1, const char *s2, size_t len);
void				*memsub(char *s, unsigned int start, size_t len);
char				*strreplace(char *str, char *torep, char *rep);
int					strisdigit(char *str);
int					strisalnum(char *str);
int					strisalpha(char *str);
void				*memcat(char *s1, size_t s1_size, char *s2, size_t s2_size);
void				sstrfree(char **sstr);
size_t				sstrlen(char **sstr);
unsigned char		sstrchr(char **sstr, char *chr);
void				perr_exit(const char *str);
void				err_exit(const char *err_msg, int status_code);



#endif
