#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8888
#define BUFF_LEN 512
//#define SERVER_IP "172.17.0.2"
#define SERVER_IP "10.0.0.251"



void udp_msg_sender(int fd, struct sockaddr* dst)
{

    socklen_t addr_len;
    struct sockaddr_in src;
    struct timeval tv;
    fd_set readfds;
    int i = 0;
    int j = 0;
    int k = 0;
    int n =0;
    int total = 0;
    int succ = 0;
    float rate = 0.0;
    while(1)
    {
        char buf[BUFF_LEN];
        char pi[BUFF_LEN] = "pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726024914127372458700660631558817488152092096282925409171536436789259036001133053054882046652138414695194151160943305727036575959195309218611738193261179310511854807446237996274956735188575272489122793818301194912";
        addr_len = sizeof(*dst);
        for(k=0;k<2;k++)
        {
            sprintf(buf,"%d ",i);
            strcat(buf,pi);
            sendto(fd, buf, BUFF_LEN, 0, dst, addr_len);
            memset(buf, 0, BUFF_LEN);
            FD_ZERO(&readfds);
            FD_SET(fd,&readfds);
            tv.tv_sec = 2;
            tv.tv_usec = 0;
            select(fd+1,&readfds,NULL,NULL,&tv);
            if(FD_ISSET(fd,&readfds))
            {
                if((n = recvfrom(fd, buf, BUFF_LEN, 0, (struct sockaddr*)&src, &addr_len))>=0)
                {
                    sscanf(buf,"%d",&j);
                    printf("ACK of %dth packet received\n",j);
                    if(i == j)
                    {
                        succ++;
                        break;
                    }

                }
            }
        }
        if(k == 2)
        {
            printf("%dth packet time out\n",i);
        }
        i++;
        total = i;
        rate = (float)succ/total;
        printf("    success rate is %.2f%%\n",rate*100);
        sleep(1);
    }
}

/*
    client:
            socket-->sendto-->revcfrom-->close
*/

int main(int argc, char* argv[])
{
    int client_fd;
    struct sockaddr_in ser_addr;

    client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(client_fd < 0)
    {
        printf("create socket fail!\n");
        return -1;
    }

    memset(&ser_addr, 0, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
//    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ser_addr.sin_port = htons(SERVER_PORT);

    udp_msg_sender(client_fd, (struct sockaddr*)&ser_addr);

    close(client_fd);

    return 0;
}
