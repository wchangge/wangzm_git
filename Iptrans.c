#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<string.h>
#include<ctype.h>
long long IP_Trans(char *s);
int main()
{
   int imode;
   long long llIP=1;
   struct in_addr IpAddr;
   char ctemp[1024] = {0};
   printf("Input your translate mode:\n");
   printf("1:十进制转二进制地址\n");
   printf("2:二进制转十进制地址\n");
   scanf("%d",&imode);
   if(imode ==1 )
   {
     while(llIP != 0)
     {
       printf("输入十进制地址：\n");
       scanf("%ld",&llIP);
       IpAddr.s_addr = htonl(llIP);
       printf("time is %lld\n",IpAddr.s_addr);
       getchar();
       sprintf(ctemp, "%s", inet_ntoa(IpAddr));
       printf("%s\n",ctemp);
    }
   }
   else
       if(imode = 2)
       {
         printf("输入二进制地址：\n");
         scanf("%s",ctemp);
         while(strlen(ctemp) >=  7 )
         {
         	   llIP=IP_Trans(ctemp);
         	   printf("%ld\n",llIP);
             printf("输入二进制地址：\n");
             scanf("%s",ctemp);
         }
       }
   return 0;
}

long long IP_Trans(char *s)
{
  long long llIp[4];
  int inum=0,iIpnum=0;
  char stemp[4]={0};
  while(*s != '\0')
  {
    if(inum==0)
    {
      if(isdigit(*s))
      {
        stemp[inum]=*s;
        s++;
        inum++;
      }
      else
      {
        return -1;
      }
    }
    else
    if(inum > 3)
    {
      return -1;
    }
    else
    {
      if(*s == '.')
      {
        if(iIpnum >= 3)
          return -1;
        llIp[iIpnum++]=atol(stemp);
        memset(stemp,0,sizeof(stemp));
        s++;
        inum=0;
      }
      else
      {
        if(isdigit(*s))
        {
          stemp[inum]=*s;
          s++;
          inum++;
        }
        else
        {
          return -1;
        }
      }
    }
  }
  if(iIpnum == 3)
  {
    llIp[3]=atol(stemp);
    printf("the ip is %ld.%ld.%ld.%ld\n",llIp[0],llIp[1],llIp[2],llIp[3]);
	if(llIp[0]>255 || llIp[1]>255 || llIp[2]>255 || llIp[3]>255)
    	return -1;
    return llIp[0]*256*256*256+llIp[1]*256*256+llIp[2]*256+llIp[3];
  }
  else
    return -1;
}
