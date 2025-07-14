// extern unsigned int sleep(unsigned int s);
extern unsigned int time_lapse(unsigned int *handle, unsigned int time_out);
extern char *str_find(const char *str, const char *find);
// extern int asprintf(char **ret, const char *format, ...);
extern unsigned int OSGetTime();
extern void netdev_rx_register(void (*fun)(void *priv, void *data, unsigned int len), void *priv);
extern void *netdev_alloc_output_buf(unsigned char **buf, unsigned int len);
extern  int netdev_send_data(void *priv, void *skb);
extern int errno;
extern unsigned int random32(int type);

/*********************************************************************************************************
**-------------------------------Socket²ÎÊýÅäÖÃ£ºSocket options----------------------------
*********************************************************************************************************/
#ifdef ETIMEDOUT
#undef ETIMEDOUT
#endif

#include <errno.h>
//#define LWIP_PROVIDE_ERRNO

#ifdef ETIMEDOUT
#undef ETIMEDOUT
#endif

// #include "system/crypto_toolbox/endian.h"
// #define LWIP_DONT_PROVIDE_BYTEORDER_FUNCTIONS
#define LWIP_NO_CTYPE_H 1

#include "sys/time.h"
#define LWIP_TIMEVAL_PRIVATE 0

#define LWIP_SOCKET                     1
#define LWIP_COMPAT_SOCKETS             1
#define LWIP_NETCONN                    0
#define LWIP_SO_RCVTIMEO                1
#define LWIP_SO_SNDTIMEO                1
#define LWIP_SO_SNDRCVTIMEO_NONSTANDARD 1
#define DHCPS_UNICAST_ENABLE            0
#if DHCPS_UNICAST_ENABLE
#define ETHARP_SUPPORT_STATIC_ENTRIES   1
#endif

#define LWIP_IGMP_TIMERS_FLEXIBLE           1
#define LWIP_DNS_TIMERS_FLEXIBLE            1
#define LWIP_IP4_REASSEMBLY_TIMERS_FLEXIBLE 1
#define LWIP_DHCP_FINE_TIMERS_FLEXIBLE      1
#define LWIP_MLD6_TIMERS_FLEXIBLE           1
#define LWIP_ARP_TIMERS_FLEXIBLE            1

//注意:在windows下codeblock的sfc版本必须定义LIWP_USE_SMALL_MEMORY
/*
   -----------------------------------------------
   ---------- Platform specific locking ----------
   -----------------------------------------------
*/
#define DEFAULT_ACCEPTMBOX_SIZE   16
#define DEFAULT_RAW_RECVMBOX_SIZE 17
#define DEFAULT_UDP_RECVMBOX_SIZE 18
#define DEFAULT_TCP_RECVMBOX_SIZE 19
#define TCPIP_MBOX_SIZE          20

#define MEMP_NUM_TCPIP_MSG_INPKT  16
#define MEMP_NUM_TCPIP_MSG_API    8
#define MEMP_NUM_NETCONN          (MEMP_NUM_TCP_PCB+MEMP_NUM_TCP_PCB_LISTEN+MEMP_NUM_UDP_PCB+MEMP_NUM_RAW_PCB)
#define MEMP_NUM_NETBUF           16

#define SYS_LIGHTWEIGHT_PROT            1
#define NO_SYS                          0	 //0:Ê¹ÓÃ²Ù×÷ÏµÍ³,1:²»Ê¹ÓÃ²Ù×÷ÏµÍ³
#define NO_SYS_NO_TIMERS                1

#define LWIP_TCPIP_TIMEOUT              1

/*---------- netif options ----------*/
#define LWIP_NETIF_REMOVE_CALLBACK      1

/*---------- ARP options ----------*/
#define ARP_TABLE_SIZE          8
#define ARP_QUEUEING            0
#define MEMP_NUM_ARP_QUEUE      32

/*
   --------------------------------
   ---------- IP options ----------
   --------------------------------
*/
#define IP_NAPT                         0
#define IP_FORWARD                      IP_NAPT
#define IP_NAPT_EXT                     IP_NAPT
#define IP_REASSEMBLY                   1
#define IP_FRAG                         1
#define IP_REASS_MAX_PBUFS             20
#define IP_REASS_MAXAGE                15

//TODO
//#define LWIP_HOOK_IP4_ROUTE_SRC(dest,src) \
ip4_route2(src, dest)
#if IP_NAPT
#define LWIP_HOOK_IP4_ROUTE_SRC         ip4_route_src_hook
#endif

#define LWIP_TCPIP_CORE_LOCKING         0
#define LWIP_NETCONN_FULLDUPLEX         1
#define LWIP_NETCONN_SEM_PER_THREAD     1

#define LWIP_RANDOMIZE_INITIAL_LOCAL_PORTS 1
#define LWIP_RAND()             (random32(0)+0xc000)

//#define LWIP_DHCP_MAX_NTP_SERVERS       8
//#define LWIP_DHCP_GET_NTP_SRV           1

#if IP_NAPT
#define NETIF_MTU 1500
#else
#define NETIF_MTU 1240 // 虽然以太网标准是1500 ,但是会导致某些网关丢弃数据包,当发现数据包发不出去网关就降低该值测试
#endif

/*---------- TCP options ----------*/
#define TCP_QUEUE_OOSEQ         1
#define TCP_MSS                 (NETIF_MTU - 40)	/* TCP_MSS = (Ethernet MTU - IP header size - TCP header size) */
#define TCP_WND                 (8*TCP_MSS)
#define TCP_SND_BUF             (8*TCP_MSS)
// #define TCP_WND                 (2*TCP_MSS)
// #define TCP_SND_BUF             (2*TCP_MSS)
#define TCP_SND_QUEUELEN        ((4 * (TCP_SND_BUF) + (TCP_MSS - 1))/(TCP_MSS))
#define TCP_LISTEN_BACKLOG       0
#define TCP_QUICKACK_ENABLE     1
#define TCP_DEFAULT_LISTEN_BACKLOG      0xff

//#define TCP_MAXRTX                      12
//#define TCP_SYNMAXRTX                   6

/*---------- RAW options ----------*/
#define LWIP_RAW                0

#ifdef CONFIG_LWIP_IPV6_ENABLE
#define LWIP_IPV6               1
#define LWIP_IPV6_DHCP6         1
#else
#define LWIP_IPV6               0
#define LWIP_IPV6_DHCP6         0
#endif

/* ---------- Memory options ---------- */
//ÄÚ´æ¹ÜÀí±»Å²µ½Íâ²¿Ê¹ÓÃ
#define MEM_LIBC_MALLOC                 1
#define MEM_ALIGNMENT                   4

#define MEMCPY(dst,src,len)             memcpy((void *)dst,(void *)src,len)
#define SMEMCPY(dst,src,len)            memcpy((void *)dst,(void *)src,len)

#define MEMP_NUM_PBUF           2
#define MEMP_NUM_UDP_PCB        6
#define MEMP_NUM_TCP_PCB        8
#define MEMP_NUM_TCP_PCB_LISTEN 6
#define MEMP_NUM_TCP_SEG       TCP_SND_QUEUELEN//((4 * (TCP_SND_BUF) + (TCP_MSS - 1))/(TCP_MSS))
#define MEMP_NUM_SYS_TIMEOUT    10

/*---------- Internal Memory Pool Sizes ----------*/
#if LWIP_RAW
#define MEMP_NUM_RAW_PCB                3
#else
#define MEMP_NUM_RAW_PCB                0
#endif
#define MEMP_NUM_REASSDATA              16
#define MEMP_NUM_FRAG_PBUF              16

/* ---------- Pbuf options ---------- */
#define PBUF_POOL_SIZE         30
// #define PBUF_POOL_SIZE          12
#define PBUF_POOL_BUFSIZE       LWIP_MEM_ALIGN_SIZE(TCP_MSS+40+PBUF_LINK_ENCAPSULATION_HLEN+PBUF_LINK_HLEN)




extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x")))  memp_memory_NETBUF_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_NETCONN_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_PBUF_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_NETDB_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x")))memp_memory_REASSDATA_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x")))memp_memory_TCP_PCB_LISTEN_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_SYS_TIMEOUT_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_UDP_PCB_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_TCPIP_MSG_INPKT_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_FRAG_PBUF_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_TCP_PCB_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_PBUF_POOL_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_TCPIP_MSG_API_base[]  ;
extern unsigned char __attribute__((aligned(4)))  __attribute__((section(".memp_memory_x"))) memp_memory_TCP_SEG_base[]  ;




#define MEMP_OVERFLOW_CHECK             0//2
#define MEMP_SANITY_CHECK               0//1


#define LWIP_SO_RCVBUF                  1
#define RECV_BUFSIZE_DEFAULT            65535

/* ---------- TCP options ---------- */
#define LWIP_TCP                1
#define TCP_TTL                 255

#define LWIP_TCP_KEEPALIVE              0

#define SO_REUSE                        1 //not suggest use

/*Don't change this unless you know what you're doing */
/* The maximum segment lifetime in milliseconds */
#define  TCP_MSL 0//60000UL

/* ---------- UDP options ---------- */
#define LWIP_UDP                1
#define LWIP_UDPLITE            0
#define UDP_TTL                 255
#define CHECKSUM_GEN_UDP                1
#define CHECKSUM_CHECK_UDP               0

/* ---------- ICMP options ---------- */
#define LWIP_ICMP                 1
#define ICMP_TTL                255


/*  ---------- IGMP options ----------*/
#define LWIP_IGMP                  1
#define MEMP_NUM_IGMP_GROUP             2

/*---------- DHCP options ----------*/
#define LWIP_DHCP                       1
/*---------- AUTOIP options ----------*/
#define LWIP_AUTOIP                     0
#define LWIP_DHCP_AUTOIP_COOP           0
#define LWIP_DHCP_AUTOIP_COOP_TRIES     20
/*---------- DNS options -----------*/
#define MEMP_NUM_NETDB                  2
#define LWIP_DNS                        1
#define DNS_TABLE_SIZE                  8
#define DNS_MAX_NAME_LENGTH             256
#define DNS_MAX_SERVERS                 2
#define DNS_LOCAL_HOSTLIST              1
#define DNS_LOCAL_HOSTLIST_IS_DYNAMIC   1
#define MEMP_NUM_LOCALHOSTLIST          8   //2
#define LOCAL_WIRELESS_HOST_NAME "lwip_wireless_host"
#define LOCAL_WIRE_HOST_NAME "lwip_wire_host"
#define LOCAL_BT_HOST_NAME "lwip_bt_host"
#define LOCAL_LTE_HOST_NAME "lwip_lte_host"
#define LOCAL_EXT_WIRELESS_HOST_NAME "lwip_ext_wireless_host"
//#define DNS_LOCAL_HOSTLIST_INIT {{LOCAL_WIRELESS_HOST_NAME, 0x0101a8c0},{LOCAL_WIRE_HOST_NAME, 0x0201a8c0},}

#define LWIP_NETIF_HOSTNAME             1 //AP端显示名称 netif->hostname

extern void dns_set_server(unsigned int *dnsserver);
#define DNS_SERVER_ADDRESS dns_set_server

/*---------- Statistics options ----------*/
#define LWIP_STATS                      1

#define LWIP_STATS_DISPLAY              1
#define LINK_STATS                      1
#define ETHARP_STATS                    (LWIP_ARP)
#define IP_STATS                        1
#define IPFRAG_STATS                    (IP_REASSEMBLY || IP_FRAG)
#define ICMP_STATS                      (LWIP_ICMP)
#define IGMP_STATS                      (LWIP_IGMP)
#define UDP_STATS                       (LWIP_UDP)
#define TCP_STATS                       (LWIP_TCP)
#define MEM_STATS                       0//((MEM_LIBC_MALLOC == 0) && (MEM_USE_POOLS == 0)) ÄÚ´æ¹ÜÀí±»Å²µ½Íâ²¿Ê¹ÓÃ?
#define MEMP_STATS                      (MEMP_MEM_MALLOC == 0)
#define SYS_STATS                       0//(NO_SYS == 0)
#define IP6_STATS                       0
#define ICMP6_STATS                     0
#define IP6_FRAG_STATS                  0
#define MLD6_STATS                      0
#define ND6_STATS                       0
#define MIB2_STATS                      0

/*---------- Checksum options ----------*/
// #include "eth/ethmac.h"
//#define LWIP_CHKSUM                     ethernet_checksum    //Ê¹ÓÃÓ²¼þËãchecksum

/*
   ---------------------------------------
   ---------- Debugging options ----------
   ---------------------------------------
*/
//#define LWIP_NOASSERT

#define LWIP_DEBUG  1

#ifdef LWIP_DEBUG

#define LWIP_DBG_TYPES_ON              LWIP_DBG_STATE|LWIP_DBG_FRESH //LWIP_DBG_TRACE LWIP_DBG_STATE LWIP_DBG_FRESH

#define LWIP_DBG_MIN_LEVEL             LWIP_DBG_LEVEL_ALL//LWIP_DBG_LEVEL_ALL LWIP_DBG_LEVEL_WARNING LWIP_DBG_LEVEL_SERIOUS  LWIP_DBG_LEVEL_SEVERE

#define ETHARP_DEBUG                   LWIP_DBG_ON
#define NETIF_DEBUG                    LWIP_DBG_ON
#define PBUF_DEBUG                     LWIP_DBG_ON
#define API_LIB_DEBUG                  LWIP_DBG_ON
#define API_MSG_DEBUG                  LWIP_DBG_ON
#define SOCKETS_DEBUG                  LWIP_DBG_ON
#define ICMP_DEBUG                     LWIP_DBG_ON
#define IGMP_DEBUG                     LWIP_DBG_ON
#define INET_DEBUG                     LWIP_DBG_ON
#define IP_DEBUG                       LWIP_DBG_ON//|LWIP_DBG_TYPES_ON
#define IP_REASS_DEBUG                 LWIP_DBG_ON
#define RAW_DEBUG                      LWIP_DBG_ON
#define MEM_DEBUG                      LWIP_DBG_ON|LWIP_DBG_TYPES_ON
#define MEMP_DEBUG                     LWIP_DBG_ON|LWIP_DBG_TYPES_ON
#define SYS_DEBUG                      LWIP_DBG_ON
#define TIMERS_DEBUG                   LWIP_DBG_ON
#define TCP_DEBUG                      LWIP_DBG_ON
#define TCP_INPUT_DEBUG                LWIP_DBG_ON
#define TCP_FR_DEBUG                   LWIP_DBG_ON
#define TCP_RTO_DEBUG                  LWIP_DBG_ON
#define TCP_CWND_DEBUG                 LWIP_DBG_ON
#define TCP_WND_DEBUG                  LWIP_DBG_ON
#define TCP_OUTPUT_DEBUG               LWIP_DBG_ON
#define TCP_RST_DEBUG                  LWIP_DBG_ON
#define TCP_QLEN_DEBUG                 LWIP_DBG_ON
#define UDP_DEBUG                      LWIP_DBG_ON
#define TCPIP_DEBUG                    LWIP_DBG_ON
#define PPP_DEBUG                      LWIP_DBG_ON
#define SLIP_DEBUG                     LWIP_DBG_ON
#define DHCP_DEBUG                     LWIP_DBG_ON
#define AUTOIP_DEBUG                   LWIP_DBG_ON
#define SNMP_MSG_DEBUG                 LWIP_DBG_ON
#define SNMP_MIB_DEBUG                 LWIP_DBG_ON
#define DNS_DEBUG                      LWIP_DBG_ON
#define IP6_DEBUG                      LWIP_DBG_ON
#define DHCP6_DEBUG                    LWIP_DBG_ON

#define SMTP_DEBUG                     LWIP_DBG_ON
#define HTTPD_DEBUG                    LWIP_DBG_ON
#define HTTPD_DEBUG_TIMING		       LWIP_DBG_ON
#define SNTP_DEBUG                     LWIP_DBG_ON
#define RTP_DEBUG                      LWIP_DBG_ON
#define PING_DEBUG                     LWIP_DBG_ON
#define NAPT_DEBUG                     LWIP_DBG_ON//|LWIP_DBG_TYPES_ON

#endif
