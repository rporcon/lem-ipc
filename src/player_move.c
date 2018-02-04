/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rporcon <rporcon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:46:34 by rporcon           #+#    #+#             */
/*   Updated: 2018/02/03 18:27:28 by rporcon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemipc.h"

void	init_teamleader(t_cell *current)
{
	while (enemies_alive() == 0)
	{
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
		usleep(100000);
	}
	current->enemy = enemy_chr(*current);
	current->enemy_set = 1;
	if (DBG == 1)
		printf("[TL] g_data.pid: {%u} send ennemy[%lld][%lld] pid: %u\n",
				g_data.pid, current->enemy.y, current->enemy.x,
				current->enemy.pid);
	send_target(current->enemy);
}

void	init_enemy(t_cell *current)
{
	if (DBG == 1)
		printf("[non TL], pid: {%u} waiting for ennemy pid\n",
			current->enemy.pid);
	if (msgrcv(g_data.msgq_id, &g_data.msgbuf, sizeof(g_data.msgbuf.mtext),
			g_data.team_id, 0) == -1)
		perr_exit("move_player msgrcv");
	current->enemy = *((t_enemy *)g_data.msgbuf.mtext);
	if (DBG == 1)
		printf("[non TL], pid: {%u} received ennemy pid: %d\n",
			g_data.pid, current->enemy.pid);
	current->enemy_set = 1;
}

void	set_new_currentpos(t_cell *current)
{
	t_cell	new_pos;

	new_pos = nearest_pos_toenemy(*current);
	if (DBG == 1)
	{
		printf("{pid: %u} new_pos: [%lld][%lld], val: %llu\n",
			g_data.pid, new_pos.y, new_pos.x, new_pos.val);
		printf("enemy: [%lld][%lld] (pid: %u)\n",
			current->enemy.y, current->enemy.x, current->enemy.pid);
	}
	set_newenemy_pos(new_pos);
	g_data.cells[new_pos.y][new_pos.x] = new_pos;
	ft_memset(current, 0, sizeof(*current));
	g_data.cells[new_pos.y][new_pos.x].played = 1;
}

void	clear_current(t_cell *current)
{
	if (DBG == 1)
		printf("clear current: [%lld][%lld]\n", current->y, current->x);
	ft_memset(current, 0, sizeof(*current));
	ally_clear_tlenemyset();
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
	if (oneteam_alive() == 1)
	{
		g_data.msgbuf.mtype = INT_MAX;
		ft_strcpy(g_data.msgbuf.mtext, "EndOfGame");
		if (msgsnd(g_data.msgq_id, &g_data.msgbuf,
				sizeof(g_data.msgbuf.mtext), 0) == -1)
			perr_exit("[msgsnd] endOfGame");
		sleep(3);
		ressources_erase();
	}
	if (sem_post(g_data.sem) == -1)
		perr_exit("communicate sem_post");
	exit(0);
}

void	move_player(void)
{
	t_cell		*current;

	map_currentcell(&current);
	if (teamleader_exist() == 0)
	{
		current->team_leader = 1;
		ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
	}
	if (current->enemy_set == 0 && current->team_leader == 1)
		init_teamleader(current);
	else if (current->enemy_set == 0)
		init_enemy(current);
	set_currentval(*current);
	if (two_enemies_near(*current) == 1)
		clear_current(current);
	set_to_enemyval(*current);
	printf("playedNb==: %d\n", players_played_nb());
	if (current->val != 1)
		set_new_currentpos(current);
	else
		current->played = 1;
	if (DBG == 1)
		printf("{pid: %u} currentPos: [%lld][%lld], val: %llu\n---------------"
				"-\n", g_data.pid, current->y, current->x, current->val);
	printf("playedNb==: %d\n", players_played_nb());
	ft_memcpy(g_data.map_mem, g_data.cells, MAP_SIZE);
}
