#ifndef __simpleBLE_cmd__
#define __simpleBLE_cmd__
#include "hal_types.h"

/*ÃüÁîÎª8 bit*/
#define CMD_PACKAGE(mode,val) ((((mode) & 0x7) << 5) | ((val) &0x1f))
#define CMD_GET_MODE(cmd) 	  (((cmd)>>5)&0x7)
#define CMD_GET_VAL(cmd)      ((cmd)&0x1f)
//0x00 is NULL cmd 
#define CMD_NULL         CMD_PACKAGE(0,0)
#define CMD_DISCOVER_START   CMD_PACKAGE(0,1) //start_discover
#define CMD_DISCOVER_STOP    CMD_PACKAGE(0,2)
#define CMD_CharValue_W      CMD_PACKAGE(0,3)
#define CMD_CharValue_R      CMD_PACKAGE(0,4)
#define CMD_LIST_DISCOVERY   CMD_PACKAGE(0,5)//list Display discovery
#define CMD_UPDATE_LINK      CMD_PACKAGE(0,6)//UpdateLink
#define CMD_CONNECT_START    CMD_PACKAGE(0,7) //Connect
#define CMD_CONNECT_STOP     CMD_PACKAGE(0,8) 

typedef struct
{	
	char *name;
	uint16 cmd;
	uint16 param;
}uart_cmd_t;


uart_cmd_t * uart_str2cmd(char *strcmd);


#endif
