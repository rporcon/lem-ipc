/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:07:27 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/02 15:27:53 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include <stdint.h>
# include <sys/mman.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <limits.h>

# define MAP_LEN 4
# define MAP_SIZE sizeof (t_cell) * (MAP_LEN * MAP_LEN)
# define ENEMY_SIZE MAP_SIZE / 2

typedef struct		s_enemy {
	int64_t			x;
	int64_t			y;
	pid_t			pid;
}					t_enemy;

typedef struct		s_cell {
	uint32_t		team_id;
	pid_t			pid;
	int64_t			x;
	int64_t			y;
	t_enemy			enemy;
	uint64_t		val;
	uint8_t			team_leader:1;
	uint8_t			enemy_set:1;
	uint8_t			played:1;
}					t_cell;

typedef struct		s_msgbuf {
	long			mtype;
	char			mtext[128];
}					t_msgbuf;

typedef struct		s_inc {
	int64_t			i;
	int64_t			j;
	int64_t			k;
}					t_inc;

typedef struct		s_coord {
	int64_t			x;
	int64_t			y;
}					t_coord;

#endif
