#include<stdio.h>
#include<stdlib.h>
#include<winsock.h>

#define SERVERIP "125.216.248.112"
#define SERVERPORT 2333
#define BUFF_SIZE 1024
#define filenum 1000
#define filesize 1000
#define filenamesize 1000000


struct filenames
{
    char files[filenum][filesize];
};


int main(){
    char buffer[BUFF_SIZE];
    char flag[BUFF_SIZE];
    char filename[BUFF_SIZE];
    char NULLC[BUFF_SIZE];
    memset(&NULLC,0,BUFF_SIZE);
    memset(filename,0,BUFF_SIZE);
    memset(buffer,0,BUFF_SIZE);
    // WSAStartup();
    WORD wVersion = MAKEWORD(2,2);
    LPWSADATA lpwdata;
    int key;

    struct filenames *fn;
    char *fs;

    // socket();

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVERPORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVERIP);
    while (1)
    {
        //WSAStartup
        printf("---------------------------------------------------------------------------\nConnect Successfully!\n");
        if(WSAStartup(wVersion,&lpwdata) != 0)
        {
            printf("Init socket dll error!");
            exit(1);
        }
        //SOCKET
        SOCKET c_S = socket(AF_INET,SOCK_STREAM,0);
        if (SOCKET_ERROR == c_S)
        {
            printf("Create Socket Error!");
            system("pause");
            exit(1);
        }
        if (SOCKET_ERROR == connect(c_S, (LPSOCKADDR)&serverAddr, sizeof(serverAddr)))
        {
            printf("Can Not Connect To Server IP!\n");
            system("pause");
            exit(1);
        }
        printf("The files on the server are as follows:\n");
        int count = 0;
        while (1)
        {   
            memset(buffer,0,sizeof(buffer));
            recv(c_S,buffer,BUFF_SIZE,0);
            if(buffer[0] < 'a' || buffer[0] > 'z'){
                break;
            }
            count++;
            printf("%s ",buffer);
            if(!(count%10))printf("\n");
            memset(buffer,0,sizeof(buffer));
        }


        printf("\nPlease input the file's name needed to download: ");
        scanf("%s", &filename);

        strncpy(buffer,filename,BUFF_SIZE);        
        //send()

        if(send(c_S,buffer,BUFF_SIZE,0) < 0)
        {
            printf("Send File Name Failed\n");
            system("pause");
            exit(1);
        }
        
        // FILE* fp = fopen(filename,"wb");
        recv(c_S,flag,sizeof(flag),0);
        if(flag[0]==1)
        {
            printf("File: %s Can Not Open To Write\n", filename);
        }
        else
        {
            FILE* fp = fopen(filename,"wb");
            memset(buffer, 0, BUFF_SIZE);
            int length = 0;
            while ((length = recv(c_S, buffer, BUFF_SIZE, 0)) > 0)
            {   
                printf("%s",buffer);
                if (fwrite(buffer, sizeof(char), length, fp) < length)
                {
                    printf("File: %s Write Failed\n", filename);
                    break;
                }
                memset(buffer, 0, BUFF_SIZE);
            }

            printf("Receive File: %s From Server Successful!\n\n", filename);
            fclose(fp);
        }
        closesocket(c_S);
        
        WSACleanup();
    }
    return 0;
}