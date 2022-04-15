#include<winsock.h>
#include<stdlib.h>
#include<stdio.h>
#include<io.h>
#include<math.h>

#define SERVERPORT 2333
#define SERVERIP "127.0.0.1"
#define BUFF_SIZE 1024
#define filesize 1024
#define IMGNUM 20000 //图片所在文件夹中图片的最大数量
char img_files[IMGNUM][1000];


int getFiles(char* path){
    int num = 0;
    long hFile = 0;
    struct _finddata_t fileinfo;
    char p[700];
    memset(p,0,sizeof(p));
    strcpy(p,path);
    strcat(p,"\\*");
    if((hFile = _findfirst(p,&fileinfo))!=-1){
        do{
            if ((fileinfo.attrib&_A_SUBDIR)){
                if(strcmp(fileinfo.name,".")!=0&&strcmp(fileinfo.name,"..")!=0) continue;
            }
            else{
                strcpy(img_files[num],fileinfo.name);
                num++;
            }
        }while (_findnext(hFile,&fileinfo)==0);
        _findclose(hFile);
    }
    return num;
}


int main(){
    //addr
    struct sockaddr_in serverAddr,clientAddr;
    char filename[BUFF_SIZE];
    int length;
    char flag[BUFF_SIZE];
    char path[80];
    getcwd(path,sizeof(path));
    int size = getFiles(path);
    

    // WSAStartup();
    WORD wVersion = MAKEWORD(2,2);
    LPWSADATA lpwdata;
    WSAStartup(wVersion,&lpwdata);

    // socket();
    SOCKET s = socket(AF_INET,SOCK_STREAM,0);
    if (SOCKET_ERROR == s)
    {
        printf("Create Socket Error!");
        exit(1);
    }

    // bind();
    memset(&serverAddr,0,sizeof(struct sockaddr_in));

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVERPORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVERIP);

    if (SOCKET_ERROR == bind(s,(struct sockaddr*)&serverAddr,sizeof(struct sockaddr)))
	{
		printf("Server Bind Failed: %d", WSAGetLastError());
		exit(1);
	}

    // listen();
    if (SOCKET_ERROR == listen(s, 5))
	{
		printf("Server Listen Failed: %d", WSAGetLastError());
		exit(1);
	}
    while (1)
    {
        printf("---------------------------------------------------------------------------\n");
        printf("Listening...\n");
        // accept();
        int clientLength = sizeof(clientAddr);
        SOCKET g = accept(s,(LPSOCKADDR)&serverAddr,&clientLength);
        if (g == SOCKET_ERROR)
		{
			printf("Server Accept Failed: %d", WSAGetLastError());
			break;
		}
        printf("Connect successfully!\n");
        printf("Here are the vaild files:\n");
        int c;
        for(int i = 0;i<size;i++){
            send(g,img_files[i],sizeof(img_files[i]),0);
            c++;
            printf("%s ",img_files[i]);
            if(c%10==0)printf("\n");
            // int t = sin(100);
        }
        flag[0]=2;
        send(g,flag,sizeof(flag),0);


        //recv()
        char buffer[BUFF_SIZE];
        memset(&buffer,0,BUFF_SIZE);
        if (recv(g,&buffer,BUFF_SIZE,0) < 0)
		{
			printf("Server Receive Data Failed!");
			break;
		}
        strncpy(filename,buffer,BUFF_SIZE);
        printf("FILE:%s\n",filename);
        //open
        FILE *fp = fopen(filename,"rb");

        if(fp==NULL){
            printf("FILE NOT FOUND\n");
            flag[0] = 1;
            send(g,flag,sizeof(flag),0);
        }else{
            flag[0] = 'k';
            send(g,flag,sizeof(flag),0);
            memset(buffer,0,BUFF_SIZE);
            while ((length = fread(buffer, sizeof(char), BUFF_SIZE, fp)) > 0)
            {
                if (send(g, buffer, length, 0) < 0)
                {
                    printf("Send File: %s Failed\n", filename);
                    break;
                }
                printf("%s",buffer);
                memset(buffer, 0, BUFF_SIZE);
            }
            fclose(fp);
            printf("Success!\n");
        }
        closesocket(g);
    }
    // closesocket();
    closesocket(s);
    // WSACleanup();
    WSACleanup();
    return 0;
}