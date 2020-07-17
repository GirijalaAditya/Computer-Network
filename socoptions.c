#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/tcp.h>
void main()
{
	int sockopt,sockid,optlen,gs;
	sockid=socket(AF_INET,SOCK_STREAM,0);
	if(sockid==-1)
	{
		perror("SOCK-CRE-ERR:");
		exit(1);
	}
/*LEVEL-SOCKET OPTION-SOCKET TYPE*/
	optlen=sizeof(sockopt);
	gs=getsockopt(sockid,SOL_SOCKET,SO_TYPE,&sockopt,&optlen);
	if(gs==-1)
	{
		perror("GETSOCK-ERR:");
		close(sockid);
		exit(1);
	}
	switch(sockopt)
	{
		case SOCK_DGRAM:printf("\nDatagram Socket\n");
				break;
		case SOCK_STREAM:printf("\nStream Socket\n");
				break;
		case SOCK_RAW:printf("\nRaw Socket\n");
				break;
		default:printf("\nUnknown Socket type\n");
	}
/*LEVEL-SOCKET OPTION-SEND QUEUE BUFFER SIZE*/
	/*optlen=sizeof(sockopt);
	gs=getsockopt(sockid,SOL_SOCKET,SO_SNDBUF,&sockopt,&optlen);
	if(gs!=-1)
	printf("\nSend buffer size is %d\n",sockopt);
	else
	perror("SND-BUF-ERR:");*/
//Usage of setsockopt function
//LEVEL-SOCKET OPTION-SEND QUEUE BUFFER SIZE setting size of 2048 Note Default size is 4096
	sockopt=2048;
	optlen=sizeof(sockopt);
	gs=setsockopt(sockid,SOL_SOCKET,SO_SNDBUF,&sockopt,optlen);
	if(gs!=-1)
	printf("\nSend Buffer size is %d\n",sockopt);
	else
	perror("SND-BUF-ERR:");

	optlen=sizeof(sockopt);
	gs=getsockopt(sockid,SOL_SOCKET,SO_SNDBUF,&sockopt,&optlen);
	if(gs!=-1)
	printf("\nSend buffer size is %d\n",sockopt);
	else
	perror("SND-BUF-ERR:");
/*LEVEL-SOCKET OPTION-RECEIVE QUEUE BUFFER SIZE*/
	/*optlen=sizeof(sockopt);
	gs=getsockopt(sockid,SOL_SOCKET,SO_RCVBUF,&sockopt,&optlen);
	if(gs!=-1)
	printf("\nReceive Buffer size is %d\n",sockopt);
	else
	perror("RCV-BUF-ERR:");*/
	
	sockopt=2048;
	optlen=sizeof(sockopt);
	gs=setsockopt(sockid,SOL_SOCKET,SO_RCVBUF,&sockopt,optlen);
	if(gs!=-1)
	printf("\nReceive Buffer size is %d\n",sockopt);
	else
	perror("RCV-BUF-ERR:");

	optlen=sizeof(sockopt);
	gs=getsockopt(sockid,SOL_SOCKET,SO_RCVBUF,&sockopt,&optlen);
	if(gs!=-1)
	printf("\nReceive Buffer size is %d\n",sockopt);
	else
	perror("RCV-BUF-ERR:");
/*LEVEL-TCP OPTION-TCP MAX SEGMENT SIZE*/
	optlen=sizeof(sockopt);
	gs=getsockopt(sockid,IPPROTO_TCP,TCP_MAXSEG,&sockopt,&optlen);
	if(gs!=-1)
	printf("\nTCP MAX Segment size is %d\n",sockopt);
	else
	perror("TCP-SEG-ERR:");
/*LEVEL-TCP OPTION-TCP NO-DELAY*/
	optlen=sizeof(sockopt);
	sockopt=1;
	gs=setsockopt(sockid,IPPROTO_TCP,TCP_NODELAY,&sockopt,optlen);
	if(gs!=-1)
	printf("\nNODELAY FLAG is set\n");
	else
	perror("TCP-NODELAY-ERR:");
//Usage of setsockopt function
/*LEVEL-TCP OPTION-TCP NODELAY*/
	optlen=sizeof(sockopt);
	gs=getsockopt(sockid,IPPROTO_TCP,TCP_NODELAY,&sockopt,&optlen);
	if(gs!=-1)
	if(sockopt==1)
	printf("\nNODELAY flag is set\n");
	else
	printf("\nNODELAY flag not set\n");
	else
	perror("TCP-NODELAY-ERR:");
	close(sockid);
}
