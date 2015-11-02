/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harar <harar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 15:44:17 by harar             #+#    #+#             */
/*   Updated: 2015/03/24 18:53:04 by harar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

/*
**	make fclean -j && make test -j && ./test
*/

# define USE_FT_MIN
# define USE_FT_MAX
# define USE_FT_ABS
# define USE_FT_ISUPPER
# define USE_FT_ISLOWER
# define USE_FT_BZERO
# define USE_FT_ISALPHA
# define USE_FT_ISDIGIT
# define USE_FT_ISALNUM
# define USE_FT_ISASCII
# define USE_FT_ISPRINT
# define USE_FT_TOUPPER
# define USE_FT_TOLOWER
# define USE_FT_STRLEN
# define USE_FT_STRCAT
# define USE_FT_PUTS
# define USE_FT_MEMSET
# define USE_FT_MEMCPY
# define USE_FT_STRDUP
# define USE_FT_CAT

# ifdef USE_FT_MIN

extern int		ft_min(int a, int b);
# endif
# ifdef USE_FT_MAX

extern int		ft_max(int a, int b);
# endif
# ifdef USE_FT_BZERO

extern void		ft_bzero(void *s, size_t n);
# endif
# ifdef USE_FT_ABS

extern int		ft_abs(int n);
# endif
# ifdef USE_FT_ISUPPER

extern int		ft_isupper(int c);
# endif
# ifdef USE_FT_ISLOWER

extern int		ft_islower(int c);
# endif
# ifdef USE_FT_ISALPHA

extern int		ft_isalpha(int c);
# endif
# ifdef USE_FT_ISDIGIT

extern int		ft_isdigit(int c);
# endif
# ifdef USE_FT_ISALNUM

extern int		ft_isalnum(int c);
# endif
# ifdef USE_FT_ISASCII

extern int		ft_isascii(int c);
# endif
# ifdef USE_FT_ISPRINT

extern int		ft_isprint(int c);
# endif
# ifdef USE_FT_TOLOWER

extern int		ft_tolower(int c);
# endif
# ifdef USE_FT_TOUPPER

extern int		ft_toupper(int c);
# endif
# ifdef USE_FT_STRLEN

extern size_t	ft_strlen(char const *s);
# endif
# ifdef USE_FT_STRCAT

extern char		*ft_strcat(char *s1, char const *s2);
# endif
# ifdef USE_FT_PUTS

extern int		ft_puts(char const *s);
# endif

# ifdef USE_FT_MEMSET

extern void		*ft_memset(void *b, int c, size_t len);
# endif
# ifdef USE_FT_MEMCPY

extern void		*ft_memcpy(void *dst, void const *src, size_t n);
# endif
# ifdef USE_FT_STRDUP

extern char		*ft_strdup(char const *s);
# endif
# ifdef USE_FT_CAT

extern void		ft_cat(int fd);
# endif

#endif
