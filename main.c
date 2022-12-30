//CONTACT 
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

 void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


struct contact
{
    int sno;
    char category[20];
    char name[20];
    char gender;
    int age;
    char address[50];
    char email[50];
    char phone[15];
}cont;



void main()
{
 void add_contact();
 void list_of_contact();
 void delete_contact();
 void edit();
 void search_contact();
 void change_password();
char pass[30],ch ,org[30],choice;
int i;
FILE*fp;
system("color 2f");
system("cls");
gotoxy(4,2);
// while(1)
// {
printf("Enter the password");
// sleep(2);
// system("cls");
// if(getch())
// break;
// }



// printf("\n you entered the password %s",pass);
fp=fopen("file.txt","r");
fgets(org,30,fp);
fclose(fp);
if(!strcmp(org,pass)==0)
{
     gotoxy(4,3);
printf("incorrect password");
gotoxy(4,4);
printf("press any key.............");
getch();
exit(1);
}
else
{
system("color 6f");
system("cls"); 
gotoxy(32,3);
system("color 68");
printf("C O N T A C T    M A N A G E R");
gotoxy(32,5);
printf("version no. : 1.0");
gotoxy(22,8);
printf("develop by............  : EKTA MEHTA");
gotoxy(15,15);
printf("please wait");
for(i=0;i<=50;i++)
{
    printf("%c",220);
    Sleep(200);
}
while(1)
{
system("cls");
system("color 83");
gotoxy(32,3);
printf("MAIN MENU");
gotoxy(5,4);
printf("-----------------------------------------------------------");
gotoxy(24,5);
printf("1  Add new contact");
gotoxy(24,6);
printf("2  Delete contact");
gotoxy(24,7);
printf("3  Editing");
gotoxy(24,8);
printf("4  Search contact");
gotoxy(24,9);
printf("5  List of contact");
gotoxy(24,10);
printf("6  Change password");
gotoxy(24,11);
printf("7  Exit");
gotoxy(5,12);
printf("-----------------------------------------------------------");
gotoxy(24,14);
printf(" ENTER YOUR CHOICE");
choice=getche();
switch(choice)
{
    case '1':
    add_contact();
    break;
    case '2':
    delete_contact();
    break;
    case '3':
    edit();
    break;
    case '4':
    search_contact();
    break;
    case'5':
    list_of_contact();
    break;
    case '6':
    change_password();
    break;
    case '7':
    exit(0);
}
getch();
}

}

}

void change_password()
{
    FILE*fp;
    char current_password[20];
    char original_password[20];
    char new_password[20];
    char conifrm_password[20];
    system("color 87");
    system("cls");
    printf("change password");
    printf("\n------------------------------------------");
    printf("enter current password");
    gets(current_password);
    fp=fopen("file.txt","r");
    fgets(original_password,30,fp);
    fclose(fp);
    if(strcmp(current_password,original_password)!=0)
    {
    printf("incorrect password");
    getch();
    return;
    }
    printf("\n enter new password");
    gets(new_password);
    printf("\n re-enter password");
    gets(conifrm_password);
    if(strcmp(new_password,conifrm_password)!=0)
    {
        printf("\nnot match, ...................press any key");
        getch();
        return;

    }

    fp=fopen("file.txt","w");
    fprintf(fp,"%s",new_password);
    fclose(fp);
    printf("\nsuccessfully updated");
    printf("\n press any key");
    getch();

}


int get_no()
{
    FILE*fp;
    int n,size; 
    fp=fopen("info.txt","r");
    size=sizeof(cont);
    fseek(fp,-size,SEEK_END);
    fread(&cont,sizeof(cont),1,fp);
    n=cont.sno;
    fclose(fp);
    n++;
    return(n);

}



void add_contact()
{
    FILE*fp;
    int get_no();
    system("color 34");
    system("cls");
    printf("add new contact\n");
    printf("---------------------------------------------------\n");
    fflush(stdin);
    cont.sno=get_no();
    printf("serial no :    ",cont.sno);
    fflush(stdin);
    printf("\nenter catefory(friend/pg/salesman/customer/student):     ");
    gets(cont.category);
    fflush(stdin);
    printf("enter name:    ");
    gets(cont.name);
    fflush(stdin);
    printf("enter gender( m/f):     ");
    scanf("%c",&cont.gender);
    fflush(stdin);
    printf("enter age:   ");
    scanf("%d",&cont.age);
    fflush(stdin);
    printf("enter address:    ");
    gets(cont.address);
    fflush(stdin);
    printf("enter email id:     ");
    gets(cont.email);
    fflush(stdin);
    printf("enter phone number");
    gets(cont.phone);
    fflush(stdin);
    fp=fopen("info.txt","ab");
    fwrite(&cont,sizeof(cont),1,fp);
    fclose(fp);
    printf("successfully saved:");
    getch();
}



void delete_contact()
{
    int n, found;
    char choice;
    FILE*fp,*fpp;
system("color c7");
system("cls");
printf("DELETE CONTACT");
printf("\n-----------------------------------------------------");
printf("\nenter serial no. to be deleted:");
scanf("%d",&n);
fp=fopen("info.txt","rb");
found=0;
while(fread(&cont,sizeof(cont),1,fp)!=NULL)
{
    if(cont.sno==n)
    {
        printf("\n categary : %s",cont.category);
        printf("\n name : %s",cont.name);
        printf("\n gender : %c",cont.gender);
        printf("\n age : %d",cont.age);
        printf("\n address : %s",cont.address);
        printf("\n email id : %s",cont.email);
        printf("\n phone :%s",cont.phone);
        printf("\n--------------------------------------------------");
        found=1;
        break;

    }
}
if(found==0)
{
    printf("not found");
    fclose(fp);
    return;
}

printf(("\n are you confirm to delete:    y  or n   "));
choice=getch();
if(choice=='y'||'Y')
{
rewind(fp);
fpp=fopen("temp.txt","wb");
while(fread(&cont,sizeof(cont),1,fp)!=NULL)
{
    if(cont.sno!=n)
    {
        fwrite(&cont,sizeof(cont),1,fpp);
    }
}
fclose(fp);
fclose(fpp);
remove("info.txt");
rename("temp.txt","info.txt");
printf("\n..............successfully deleted...............  , \n ...................  press any key............");
getch();
}
}



void edit()
{
    FILE*fp;
    int pos,n,found;
    system("color  8f");
    system("cls");
    printf("EDIT CONTACT\n");
    printf("--------------------------------------------------------\n");
    printf(" enter the serial no. to be edited:\n");
    scanf("%d",&n);
    fp=fopen("info.txt","r+b");
    found=0;
    while(fread(&cont,sizeof(cont),1,fp)!=NULL)
    {
        if(cont.sno==n)
        {
               printf("\n categary : %s",cont.category);
        printf("\n name : %s",cont.name);
        printf("\n gender : %c",cont.gender);
        printf("\n age : %d",cont.age);
        printf("\n address : %s",cont.address);
        printf("\n email id : %s",cont.email);
        printf("\n phone :%s",cont.phone);
        printf("\n--------------------------------------------------");
        found=1;
        break;
        }
    }
    if(found==0)
    {
        printf("\n");
        printf("\n .........not found..........\n.............press any key..............");
        fclose(fp);
        getch();
        return;

    }
    printf("\n  ENTER NEW DATA\n");
    pos=ftell(fp);
    fseek(fp,pos-sizeof(cont),SEEK_SET);
      fflush(stdin);
    printf("enter catefory(friend/pg/salesman/customer/student):     ");
    gets(cont.category);
    fflush(stdin);
    printf("enter name:    ");
    gets(cont.name);
    fflush(stdin);
    printf("enter gender( m/f):     ");
    scanf("%c",&cont.gender);
    fflush(stdin);
    printf("enter age:   ");
    scanf("%d",&cont.age);
    fflush(stdin);
    printf("enter address:    ");
    gets(cont.address);
    fflush(stdin);
    printf("enter email id:     ");
    gets(cont.email);
    fflush(stdin);
    printf("enter phone number");
    gets(cont.phone);
    fflush(stdin);
fwrite(&cont,sizeof(cont),1,fp);
fclose(fp);
printf("\n");
printf("****************successfully updated*******************");
}

void search_contact()
{
    char ch;

    void sno();
    void category();
    void name();
    void phone();

    system("color b0");
    system("cls");
    printf("SEARCH OPTION");
    printf("\n-----------------------------------------------------");
    printf("\n 1  search by serial number.");
    printf("\n 2  search by category.");
    printf("\n 3  search by name.");
    printf("\n 4  search by phone number. ");
    printf("\n 5  back to main menu.");
    printf("\n-----------------------------------------------------");
    printf("\n          ENTER YOUR CHOICE              ");
    ch=getch();
    switch(ch)
    {
        case '1':
        sno();
        break;
        case '2':
        category();
        break; 
        case '3':
        name();
        break;
        case '4':
        phone();
        break;
        case '5':
        return;

    }
}

void sno()
{
    FILE*fp;
    int n,found=0;
    system("cls");
    printf("enter the serial no.");
    scanf("%d",&n);
    fp= fopen("info.txt","r");
    while(fread(&cont,sizeof(cont),1,fp)!=NULL)
    {
        if(cont.sno==n)
        {
            printf("\n category:     %s",cont.category);
            printf("\n name :        %s",cont.name);
            printf("\n gender :      %c",cont.gender);
            printf("\n age :         %d",cont.age);
            printf("\n address :     %s",cont.address);
            printf("\n email id :    %s",cont.email);
            printf("\n phone no. :   %s",cont.phone);
            found=1;
            break;
            
        }
    }
    if(found==0)
    {
        printf("\n .........not found...........");
        fclose(fp);
        getch();
        return;
    }
    getch();
}



void category()
{
    system("color 78");
    system("cls");
     int i;
     char cat[20];
     printf("enter the category:\n");
     gets(cat);
    FILE*fp;
    gotoxy(34,1);
    printf("LIST OF CONTACT");
    printf("\n");
    for(i=0;i<=116;i++)
        printf("-");
        gotoxy(1,3);
        printf("SNO");
        gotoxy(5,3);
        printf("CATEGORY");
        gotoxy(20,3);
        printf("NAME");
        gotoxy(35,3);
        printf("GENDER");
        gotoxy(44,3);
        printf("AGE");
        gotoxy(50,3);
        printf("ADDRESS");
        gotoxy(68,3);
        printf("EMAIL ID");
        gotoxy(90,3);
        printf("PHONE");
        printf("\n");
        for(i=0;i<=116;i++)
        printf("-");
        fp=fopen("info.txt","rb");
        i=5;
        while(fread(&cont,sizeof(cont),1,fp)!=NULL)
        {
            if(strcmp(cat,cont.category)==0)
            {
            gotoxy(1,i);
            printf("%d",cont.sno);
            gotoxy(5,i);
            printf("%s",cont.category);
            gotoxy(20,i);
            printf("%s",cont.name);
            gotoxy(35,i);
            printf("%c",cont.gender);
            gotoxy(44,i);
            printf("%d",cont.age);
            gotoxy(50,i);
            printf("%s",cont.address);
            gotoxy(68,i);
            printf("%s",cont.email);
            gotoxy(90,i);
            printf("%s",cont.phone);
            i++;
            }
        }
        fclose(fp);
        printf("\n");
        printf("press any key");
        getch();
}


void name()
{
    system("color 78");
    system("cls");
     int i;
     char cat[20];
     printf("enter the name:\n");
     gets(cat);
    FILE*fp;
    gotoxy(34,1);
    printf("LIST OF CONTACT");
    printf("\n");
    for(i=0;i<=116;i++)
        printf("-");
        gotoxy(1,3);
        printf("SNO");
        gotoxy(5,3);
        printf("CATEGORY");
        gotoxy(20,3);
        printf("NAME");
        gotoxy(35,3);
        printf("GENDER");
        gotoxy(44,3);
        printf("AGE");
        gotoxy(50,3);
        printf("ADDRESS");
        gotoxy(68,3);
        printf("EMAIL ID");
        gotoxy(90,3);
        printf("PHONE");
        printf("\n");
        for(i=0;i<=116;i++)
        printf("-");
        fp=fopen("info.txt","rb");
        i=5;
        while(fread(&cont,sizeof(cont),1,fp)!=NULL)
        {
            if(strcmp(cat,cont.name)==0)
            {
            gotoxy(1,i);
            printf("%d",cont.sno);
            gotoxy(5,i);
            printf("%s",cont.category);
            gotoxy(20,i);
            printf("%s",cont.name);
            gotoxy(35,i);
            printf("%c",cont.gender);
            gotoxy(44,i);
            printf("%d",cont.age);
            gotoxy(50,i);
            printf("%s",cont.address);
            gotoxy(68,i);
            printf("%s",cont.email);
            gotoxy(90,i);
            printf("%s",cont.phone);
            i++;
            }
        }
        fclose(fp);
        printf("\n");
        printf("press any key");
        getch();
}




void phone()
{
    system("color 78");
    system("cls");
     int i;
     char cat[20];
     printf("enter the phone no.:\n");
     gets(cat);
    FILE*fp;
    gotoxy(34,1);
    printf("LIST OF CONTACT");
    printf("\n");
    for(i=0;i<=116;i++)
        printf("-");
        gotoxy(1,3);
        printf("SNO");
        gotoxy(5,3);
        printf("CATEGORY");
        gotoxy(20,3);
        printf("NAME");
        gotoxy(35,3);
        printf("GENDER");
        gotoxy(44,3);
        printf("AGE");
        gotoxy(50,3);
        printf("ADDRESS");
        gotoxy(68,3);
        printf("EMAIL ID");
        gotoxy(90,3);
        printf("PHONE");
        printf("\n");
        for(i=0;i<=116;i++)
        printf("-");
        fp=fopen("info.txt","rb");
        i=5;
        while(fread(&cont,sizeof(cont),1,fp)!=NULL)
        {
            if(strcmp(cat,cont.phone)==0)
            {
            gotoxy(1,i);
            printf("%d",cont.sno);
            gotoxy(5,i);
            printf("%s",cont.category);
            gotoxy(20,i);
            printf("%s",cont.name);
            gotoxy(35,i);
            printf("%c",cont.gender);
            gotoxy(44,i);
            printf("%d",cont.age);
            gotoxy(50,i);
            printf("%s",cont.address);
            gotoxy(68,i);
            printf("%s",cont.email);
            gotoxy(90,i);
            printf("%s",cont.phone);
            i++;
            }
        }
        fclose(fp);
        printf("\n");
        printf("press any key");
        getch();
}


void list_of_contact()
{
    system("color 6a");
    system("cls");
    int i;
    FILE*fp;
    gotoxy(34,1);
    printf("LIST OF CONTACT");
    printf("\n");
    for(i=0;i<=116;i++)
        printf("-");
        gotoxy(1,3);
        printf("SNO");
        gotoxy(5,3);
        printf("CATEGORY");
        gotoxy(20,3);
        printf("NAME");
        gotoxy(35,3);
        printf("GENDER");
        gotoxy(44,3);
        printf("AGE");
        gotoxy(50,3);
        printf("ADDRESS");
        gotoxy(68,3);
        printf("EMAIL ID");
        gotoxy(90,3);
        printf("PHONE");
        printf("\n");
        for(i=0;i<=116;i++)
        printf("-");
        fp=fopen("info.txt","rb");
        i=5;
        while(fread(&cont,sizeof(cont),1,fp)!=NULL)
        {
            gotoxy(1,i);
            printf("%d",cont.sno);
            gotoxy(5,i);
            printf("%s",cont.category);
            gotoxy(20,i);
            printf("%s",cont.name);
            gotoxy(35,i);
            printf("%c",cont.gender);
            gotoxy(44,i);
            printf("%d",cont.age);
            gotoxy(50,i);
            printf("%s",cont.address);
            gotoxy(68,i);
            printf("%s",cont.email);
            gotoxy(90,i);
            printf("%s",cont.phone);
            i++;
        }
        fclose(fp);
        printf("\n");
        printf("press any key");
        getch();
} 


