#pragma once

#define POLLIN		0x01
#define POLLPRI		0x02
#define POLLHUP		0x04 // unknown ???
#define POLLERR		0x08 // probably
#define POLLOUT		0x10
#define POLLNVAL	0x20

typedef unsigned int nfds_t;

struct pollfd
{
	int	fd;
	int	events;
	int	revents;
};

#ifdef __cplusplus
extern "C" {
#endif

	int	poll(struct pollfd *fds, nfds_t nfds, int timeout);
	int	poll2(struct pollfd *fds, nfds_t nfds, int timeout);

#ifdef __cplusplus
}
#endif
