# lem-ipc

**Work only on OS X**

The aim of this project is to learn more about <a href="https://en.wikipedia.org/wiki/Ipcs">ipcs</a> by using:
* <a href="https://en.wikipedia.org/wiki/Shared_memory">Shared memory</a>

* <a href="https://en.wikipedia.org/wiki/Message_queue">Message queues</a>

* <a href="https://en.wikipedia.org/wiki/Semaphore_(programming)">Semaphore</a>

lem-ipc is a game where processes are on a map and have to chase each other, when one process is surrounded by two other processes of the same team, he dies, the last team who survive win.

First launch the map: `./map` (size of the map can be personnalized in `include/map.h` with the define `MAP_LEN`)

then in other processes you have to launch the players: `./lemipc [player number]`

processes are organized by team, so if you launch `./lemipc 4` 3 times, you have 3 players of the team `4`

Example: `./lemipc 4`, then enter coordinates x, y of players, repeat the operation for as many players you want,
then add other teams: `./lemipc 5` etc...

When you are ready press enter in the map process to launch the game.

For more details read the file **lemipc.fr.pdf** (in french)
