#include <string.h>
#include <stdlib.h>

#include "simpleBLE_cmd.h"
#include "npi.h"

//#define debug  NPI_printf
//for uart cmd test


static uart_cmd_t uart_cmd[]=
{
	[CMD_NULL]={
	.name = "cmd_null",
	.cmd = CMD_NULL,
	},
	[CMD_DISCOVER_START]={
	.name = "discover_start",
	.cmd = CMD_DISCOVER_START,
	},
	
	[CMD_DISCOVER_STOP]={
	.name = "discover_stop",
	.cmd = CMD_DISCOVER_STOP,
	},	
	
	[CMD_CharValue_W]={
	.name = "wirte_char",
	.cmd = CMD_CharValue_W,
	.param = 8,
	},	
	
	[CMD_CharValue_R]={
	.name = "read_char",
	.cmd = CMD_CharValue_R,
	},
	[CMD_LIST_DISCOVERY] = 
	{
	.name = "list_discovery",
	.cmd = CMD_LIST_DISCOVERY,
	},
	
	[CMD_UPDATE_LINK] = 
	{
	.name = "update_link",
	.cmd = CMD_UPDATE_LINK,
	},	
	[CMD_CONNECT_START]={
	.name = "connect_start",
	.cmd = CMD_CONNECT_START,
	},
	
	[CMD_CONNECT_STOP]={
	.name = "connect_stop",
	.cmd = CMD_CONNECT_STOP,
	},	
	
};
/*
 输入格式必须是 cmd  [xxx]
*/
int str_tok( char *string,char *seps,char **out )
{
  // NPI_printf( "%s\n\nTokens:\n", string );
   int i = 0;
   /* Establish string and get the first token: */
   char *token = strtok(string, seps);
   //out[0] = token;
   
   while(token != NULL)
   {
   	 if(i > 1)
   	 {
   	 	return 1;
   	 }
      /* While there are tokens in "string" */
      out[i]=token;
      /* Get next token: */
      token = strtok( NULL, seps );
      i++;
   }
   
   return 0;
}
#define arry_size(arry) (sizeof(arry)/sizeof(arry[0]))
uart_cmd_t *uart_str2cmd(char *strcmd)
{
	int i;
	char *name[2] = {(char*)0,(char*)0};
	int ret;	
	for(i = 0 ;i < arry_size(uart_cmd);i++)
	{
		//NPI_printf("string : %s %s\n",strcmd,uart_cmd[i].name);
		if(strncmp(uart_cmd[i].name,strcmd,strlen(uart_cmd[i].name))==0)
		{
			ret = str_tok(strcmd," ",name);
			if(ret)
			{
				return NULL;
			}
		
			if(name[1])
			{
			 uart_cmd[i].param = strtol(name[1],0,0);
			}
			//NPI_printf("name[0] = %s \n name[1] = %s 0x%x %d\n",name[0],name[1],uart_cmd[i].param,uart_cmd[i].param);
			return &uart_cmd[i];
		}
	}
	for(i = 0 ;i < arry_size(uart_cmd);i++){
		NPI_printf("%s\n",uart_cmd[i].name);
	}
	return NULL;
}






