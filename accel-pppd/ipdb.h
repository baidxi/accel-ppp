#ifndef IPDB_H
#define IPDB_H

#include <netinet/in.h>

#include "ppp.h"
#include "list.h"

struct ipv4db_item_t
{
	struct ipdb_t *owner;
	in_addr_t addr;
	in_addr_t peer_addr;
};

struct ipv6db_item_t
{
	struct ipdb_t *owner;
	struct in6_addr addr;
	struct in6_addr peer_addr;
};


struct ipdb_t
{
	struct list_head entry;
	struct ipv4db_item_t *(*get_ipv4)(struct ppp_t *ppp);
	void (*put_ipv4)(struct ppp_t *ppp, struct ipv4db_item_t *);
	struct ipv6db_item_t *(*get_ipv6)(struct ppp_t *ppp);
	void (*put_ipv6)(struct ppp_t *ppp, struct ipv6db_item_t *);
};

struct ipv4db_item_t *ipdb_get_ipv4(struct ppp_t *ppp);
void ipdb_put_ipv4(struct ppp_t *ppp, struct ipv4db_item_t *);
struct ipv6db_item_t *ipdb_get_ipv6(struct ppp_t *ppp);
void ipdb_put_ipv6(struct ppp_t *ppp, struct ipv6db_item_t *);

void ipdb_register(struct ipdb_t *);

#endif

