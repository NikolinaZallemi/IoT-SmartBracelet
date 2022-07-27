#ifndef SMART_BRACELET_H
#define SMART_BRACELET_H

//////////////////////////////////////////////
//GLOBAL VARS

//pre-defined random keys
#define FOREACH_KEY(KEY) \
	KEY(PaP13ErI7N9oOniRepAp) \
	KEY(xr3gBthvdhvFhvB6iHUH) \
        KEY(ygxbbBb7UUYUYGiubiuh) \
        KEY(sacuycagb7Nun0u90m9I) \
        KEY(IMIMi09i9ioinhbvdc5c) \
        KEY(q65v76tb8n98u09mu9n8) \
        KEY(nuyb8byn98uiyi8u9uBF) \
        KEY(BD2d3VsBNIsfJO68dIby) \
        
#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,
enum KEY_ENUM {
    FOREACH_KEY(GENERATE_ENUM)
};
static const char *RANDOM_KEY[] = {
    FOREACH_KEY(GENERATE_STRING)
};

//maximum number of supported couples (total nodes = couples*2)
#define C_MAX 4
#define N_MAX C_MAX*2

//timers values
#define T_1 15000
#define T_2 10000
#define T_3 60000
//#define T_4 120000


//////////////////////////////////////////////
//DATAGRAM TYPES

//datagram type
#define BROADCAST 0
#define UNICAST 1
#define INFO 2

//info datagram status code
#define STANDING 10
#define WALKING 20
#define RUNNING 30
#define FALLING 40

//////////////////////////////////////////////
//DATA STRUCTURES

//informative datagram (unicast)
typedef nx_struct info_datagram{
	nx_uint8_t type;
	nx_uint16_t posX;
	nx_uint16_t posY;
	nx_uint8_t status;
	nx_uint16_t identifier;
} info_datagram_t;

//pairing datagram (broadcast)
typedef nx_struct pairing_datagram{
	nx_uint8_t type;
	nx_uint8_t key[K_LEN];
	nx_uint16_t address;
	nx_uint8_t identifier;
}pairing_datagram_t;

//pairing acknowledgement datagram (unicast)
typedef nx_struct pairing_datagram_ack{
	nx_uint8_t type;
	nx_uint8_t acknowledgement;
}pairing_datagram_ack_t;

//datagram sender
enum{
	AM_DATAGRAM = N_MAX,
};

#endif
