#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include<time.h>
//list of global variable
char choice;
FILE *login;
char findBook;
char password[10];
int x = 15;
COORD coord={0,0};
//-----------------------------Main Interface functions-----------------------------------------------------
void main(){
    SetConsoleTitle("Library Management System by winners");
    system("cls");
    window();
    gotoxy(34,6);printf("Login Area");
    gotoxy(20,8);printf("1.Admin Login");
    gotoxy(20,10);printf("2.User Login");
    gotoxy(20,12);printf("3.Developer Info");
    gotoxy(20,14);printf("4.Exit");
    gotoxy(15,17);printf("Enter Your Choice ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
    case 1:
        admin_pass();
        break;
   case 2:
        user_pass();
        break;
   // case 3:
   //     developer_info();
   //     break;
    case 4:
        finish();
        break;
    default:
        gotoxy(20,20);printf("Invalid Choice....Enter again");
    }
}
/*#######################  Main window  #########################*/
int window(){
    gotoxy(15,1); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(16,3);printf("Sardar Vallabhbhai National Institute of Technology");
    gotoxy(5,4);printf("______________________________________________________________________");
 }
int gotoxy(int x,int y)
 {
   coord.X=x;
 coord.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }
 int finish(){          // function to Exit Message
    system("cls"); window();
    gotoxy(16,11);printf("Are you sure wanna Exit (Y/N): ");
    choice  = getche();
    if(choice == 'n' || choice == 'N'){
    system("cls");window(); main();
    }
    else{
    system("cls"); window();
    gotoxy(15,9);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,14);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(33,11);printf("Thank You");
    gotoxy(30,12);printf("Central Library");
    gotoxy(10,15);exit(0);
    }
 }
int admin_pass()
{
    login=fopen("admin_password.dat","rb");
    if(login==NULL)
    {
       gotoxy(15,10); printf("Database not exist.Login as Admin to create database");
       admin_signup();
    }
    else
    admin_signIn();

}
int admin_signup()
{
    char temp_pass[10];
    login=fopen("admin_password.dat","wb");
    gotoxy(12,12);printf("Enter the password ");
    getadmin_password(password);
    gotoxy(12,14);printf("Re-Enter the password ");
    getadmin_password(temp_pass);
    while(strcmp(password,temp_pass)!=0)
    {
        gotoxy(12,16);printf("Password not matched...Enter again");
        getch();
        system("cls");
        window();
        gotoxy(12,12);printf("Enter the password ");
        getadmin_password(password);
        gotoxy(12,14);printf("Re-Enter the password ");
        getadmin_password(temp_pass);

    }
    fwrite(&password,sizeof(password),1,login);
    fclose(login);
    system("cls");
    window();
}
int getadmin_password(char *pass)
{
    char temp_pass[10];
    int i=0;
    while(1)
    {
        temp_pass[i]=getch();
        if(temp_pass[i]==13)
            break;
        else if(temp_pass[i]==8)   //ASCII CODE of BACKSPACE
        {
            if(i!=0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                printf("\a");
            }
        }
        else
        {
            printf("*");
            *(pass+i)=temp_pass[i];
            i++;
        }
        *(pass+i)='\0';
    }
}
int admin_signIn()
{
    system("cls");
    window();
    login=fopen("admin_password.dat","rb");
    char temp_pass[10];
    gotoxy(12,12);printf("Enter the Password ");
    getadmin_password(temp_pass);
    fread(&password,sizeof(password),1,login);
    while(strcmp(password,temp_pass)!=0)
    {
        system("cls");
        window();
        gotoxy(12,10);printf("Incorrect Password.....");
        gotoxy(12,12);printf("Enter again");
        getadmin_password(temp_pass);
    }
    gotoxy(12,14);printf("Password Matched");
    fclose(login);
    admin_main();
}
int admin_main()
{
    system("cls"); window();
    gotoxy(32,5);printf("Admin Workspace");
    gotoxy(15,10);printf("1. Book Info");
    gotoxy(15,12);printf("2. User Info");
    gotoxy(15,14);printf("3. Change User Password");
    gotoxy(15,16);printf("4. Back");
    gotoxy(15,18);printf("5. Exit");
    gotoxy(15,20);printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        adminMain_book();
        break;
    case 2:
        adminMain_user();
        break;
    case 3:
        change_pass();
        break;
    case 4:
        main();
        break;
    case 5:
        finish();
        break;
    default :
        admin_main();
    }
}
struct Book{
    char id[10];
    char name[35];
    char author[25];
    char category[15];
}book;
char categories[][20]={"Computer","Electronics","Electrical","Civil","Mechanical","Chemical"};
int adminMain_book()
{
        while(1){
        system("cls"); window();
        gotoxy(35,5);printf("Admin Area");
        gotoxy(x,9);printf("1. Add Book");
        gotoxy(x,11);printf("2. Search Book");
        gotoxy(x,13);printf("3. Delete Book Record");
        gotoxy(x,15);printf("4. View book list");
        gotoxy(x,17);printf("5. Back");
        gotoxy(x,19);printf("6. Exit");
        gotoxy(x,21);printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                add_books();
                break;
            case 2:
                search_books();
                break;
            case 3:
                delete_books();
                break;
            case 4:
                view_books();
                break;
            case 5:
                system("cls"); admin_main();
                break;
            case 6:
                finish();
                break;
            default:
                break;
        }
    }
}
int window_category()
{
    system("cls");
    window();
    gotoxy(32,5);printf("Admin Workspace");
    gotoxy(22,8);printf("********  SELECT CATEGORY  *********");
    gotoxy(x,10);printf("1. Computer");
    gotoxy(x,11);printf("2. Electronics");
    gotoxy(x,12);printf("3. Electrical");
    gotoxy(x,13);printf("4. Civil");
    gotoxy(x,14);printf("5. Mechanical");
    gotoxy(x,15);printf("6. Chemical");
    gotoxy(x,16);printf("7. Back");
}
int add_books()
{
    int x1=35;
    system("cls");
    window_category();
    gotoxy(32,5);printf("Admin Workspace");
    gotoxy(x,18);printf("Select the category ");
    scanf("%d",&choice);
    FILE *fp;
    if(choice==7)
        adminMain_book();
    fp=fopen("Add_book.dat","ab+");
    system("cls");
    window();
    fseek(fp,0,SEEK_END);
    strcpy(book.category,categories[choice-1]);
    gotoxy(x,8);printf("Enter the below entry");
    gotoxy(x,10);printf("Book-ID ");gotoxy(x1,10);scanf("%s",&book.id);
    fflush(stdin);
    gotoxy(x,11);printf("Book-Name ");gotoxy(x1,11);gets(book.name);
    gotoxy(x,12);printf("Book-Author ");gotoxy(x1,12);gets(book.author);
    fwrite(&book,sizeof(book),1,fp);
    fclose(fp);
    gotoxy(x,16);printf("Book Successfully added");
    gotoxy(x,17);printf("Do you want to add more books(y/n)");
    char temp;
    fflush(stdin);
    scanf("%c",&temp);
    if(temp=='y' || temp=='Y')
    {
        add_books();
    }
    else{
        adminMain_book();
    }
}
int search_books()
{
    system("cls"); window();
    gotoxy(32,6);printf("Admin Workspace");
    gotoxy(25,8);printf("******** Search Books ********");
    gotoxy(x,10);printf("1. Search By ID");
    gotoxy(x,12);printf("2. Search By Name");
    gotoxy(x,16);printf("Enter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            searchByID();
            break;
        case 2:
            searchByName();
            break;
        default :
            getch();search_books();
    }
    adminMain_book();
}
int searchByID()
{
    system("cls");
    window();
    int findBook=0;
    char bookId[10];
    FILE *fp;
    fp=fopen("Add_book.dat","rb");
    gotoxy(25,7);printf("******** Search Books By ID********");
    gotoxy(x,10);printf("Enter the Book-ID ");
    scanf("%s",&bookId);
    while(fread(&book,sizeof(book),1,fp)==1)
    {
        if(strcmp(book.id,bookId)==0)
        {
            gotoxy(x,13);printf("Book Record Available");
            gotoxy(x,15);printf("\xB2 ID:%d",book.id);
            gotoxy(x,16);printf("\xB2 Name:%s",book.name);
            gotoxy(x,17);printf("\xB2 Author:%s ",book.author);
            findBook = 1;
        }
    }
    if(findBook==0)
    {
        gotoxy(x,12);printf("No Book Found");
    }
    fclose(fp);
    gotoxy(x,18);printf("Search another book by Id(y/n)");
    if(getch()=='y' || getch()=='Y')
        searchByID();
}
int searchByName()
{
    system("cls");
    window();
    char bookname[20];
    int findBook=0;
    int y=15;
    FILE *fp;
    fp=fopen("Add_book.dat","rb");
    gotoxy(25,7);printf("******** Search Books By Name********");
    gotoxy(x,10);printf("Enter the Book-Name ");
    gets(bookname);
    while(fread(&book,sizeof(book),1,fp)==1)
    {
        if(strcmp(book.name,bookname)==0)
        {
            if(findBook==0)
            {
                gotoxy(x,y);printf("Book Record Available");
            }
            gotoxy(x,++y);printf("ID:%d",book.id);
            gotoxy(x,++y);printf("Name:%s",book.name);
            gotoxy(x,++y);printf("Author:%s ",book.author);
            findBook = 1;
            ++y;
        }
    }
    if(findBook==0)
    {
        gotoxy(x,12);printf("No Book Found");
    }
    fclose(fp);
    gotoxy(x,y+2);printf("Search another book by name(y/n)");
    if(getch()=='y' || getch()=='Y')
        searchByName();
}
int delete_books()
{
    int findBook=0;
    char bookId[10];
    FILE *fp;
    fp=fopen("Add_book.dat","rb");
    system("cls");
    window();
    gotoxy(x,10);printf("Enter the Book-Id to Delete the Book ");
    scanf("%s",&bookId);
    while(fread(&book,sizeof(book),1,fp)==1)
    {
        if(strcmp(book.id,bookId)==0)
        {
            gotoxy(x,13);printf("Book Record Available");
            gotoxy(x,15);printf("ID:%d",book.id);
            gotoxy(x,16);printf("Name:%s",book.name);
            gotoxy(x,17);printf("Author:%s ",book.author);
            findBook = 1;
        }
    }
    if(findBook==1)
    {
        rewind(fp);
        FILE *fpTemp;
        fpTemp=fopen("temp_addbook.dat","wb");
        while(fread(&book,sizeof(book),1,fp)==1)
        {
            if(strcmp(book.id,bookId)!=0)
            {
                fwrite(&book,sizeof(book),1,fpTemp);
            }
        }
        fclose(fp);
        fclose(fpTemp);
        remove("Add_book.dat");
        rename("temp_addbook.dat","Add_book.dat");
        gotoxy(x,20);printf("Book Successfully deleted");
    }
    else
    {
        gotoxy(x,12);printf("Book not found");
        fclose(fp);
    }
    gotoxy(x,22);printf("Do you want to delete another book(y/n)");
    if(getch()=='y')
        delete_books();
    else
        adminMain_book();
}
int view_books()
{
    int j;
    system("cls");
    window();
    FILE *fp;
    gotoxy(5,5);printf("*************************  Book List  *************************");
    gotoxy(5,6);printf(" CATEGORY      ID     BOOK NAME                AUTHOR       ");
    j=8;
    fp=fopen("Add_book.dat","rb");
    while(fread(&book,sizeof(book),1,fp)==1){
        gotoxy(6,j);printf("%s",book.category);
        gotoxy(20,j);printf("%s",book.id);
        gotoxy(25,j);printf("%s",book.name);
        gotoxy(50,j);printf("%s",book.author);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    getch();
    system("cls");
    window();
}
/**********************************  User Work by admin ***************************************8*/
struct User
{
    char id[15];
    char name[20];
    char pass[10];
    char issued;
}user;
char categories_user[][25]={"student","teacher","others"};
int adminMain_user()
{
    system("cls");
    window();
    gotoxy(32,6);printf("Admin Workspace");
    gotoxy(x,9);printf("1. Add New User");
    gotoxy(x,11);printf("2. Search User");
    gotoxy(x,13);printf("3. Delete User");
    gotoxy(x,15);printf("4. View all User");
    gotoxy(x,17);printf("5. Back");
    gotoxy(x,19);printf("6. Exit");
    gotoxy(x,21);printf("Enter your Choice "); scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add_New_user();
            break;
        case 2:
            search_user();
            break;
        case 3:
            delete_user();
            break;
        case 4:
            view_user();
            break;
        case 5:
            admin_main();
            break;
        case 6:
            finish();
            break;
        default:
            admin_main();
    }
}
int add_New_user()
{
    char ch;
    system("cls");
    window();
    gotoxy(32,5);printf("Admin workspace");
    gotoxy(20,7);printf("********* Select category *********");
    gotoxy(x,10);printf("1. Student");
    gotoxy(x,12);printf("2. Teacher");
    gotoxy(x,14);printf("3. Others");
    gotoxy(x,16);printf("4. Back");
    gotoxy(x,18);printf("Enter your choice "); scanf("%d",&choice);
    if(choice==4){
        adminMain_user();
    }
    FILE *userlogin;
    if(choice==1)
        userlogin=fopen("user_add_student.dat","ab+");
    else if(choice==2)
        userlogin=fopen("user_add_teacher.dat","ab+");
    else if(choice==3)
        userlogin=fopen("user_add_other.dat","ab+");

    //user.category_u=categories_user[choice-1];
   // fseek(userlogin,0,SEEK_END);
    system("cls");
    window();
    fflush(stdin);
    gotoxy(32,6);printf("Admin workspace");
    gotoxy(30,8);printf("Enter the below information");
    gotoxy(x,10);printf("Enter the User-Id ");gotoxy(35,10);scanf("%s",&user.id);
    gotoxy(x,12);printf("Enter the Name ");gotoxy(35,12);scanf("%s",&user.name);
    gotoxy(x,14);printf("Enter the Password ");gotoxy(35,14);getuser_password(user.pass);
    user.issued='0';
    //user.book_quantity=0;
    fwrite(&user,sizeof(user),1,userlogin);
  //  fprintf(userlogin,"%s ",user.id);
  //  fprintf(userlogin,"%s ",user.name);
  //  fprintf(userlogin,"%s\n",user.pass);
    fclose(userlogin);
    gotoxy(x,16);printf("The record is sucessfully saved");
    fflush(stdin);
        gotoxy(x,18);printf("Save any more?(y / n): ");scanf("%c",&ch);
        if(ch=='n' || ch=='N'){
            system("cls"); window(); adminMain_user();
        }else{
            add_New_user();
        }
}
int getuser_password(char *pass)
{
    char temp_pass[10];
    int i=0;
    while(1)
    {
        temp_pass[i]=getch();
        if(temp_pass[i]==13) //ASCII code of ENTER KEY
            break;
        else if(temp_pass[i]==8)   //ASCII CODE of BACKSPACE
        {
            if(i!=0)
            {
                printf("\b \b");
                i--;
            }
            else
            {
                printf("\a");
            }
        }
        else
        {
            printf("*");
            *(pass+i)=temp_pass[i];
            i++;
        }
        *(pass+i)='\0';
    }
}
int search_user()
{
    char ch;
    char temp_userid[10];
    int found=0;
    system("cls");
    window();
    gotoxy(32,6);printf("Admin Workspace");
    gotoxy(20,7);printf("********* Select category *********");
    gotoxy(x,10);printf("1. Student");
    gotoxy(x,11);printf("2. Teacher");
    gotoxy(x,12);printf("3. Others\n");
    gotoxy(x,13);scanf("%d",&choice);
    if(choice==1)
    {
        gotoxy(x,15);printf("Enter the User-Id to search for student ");scanf("%s",&temp_userid);
        FILE *userlogin;
        userlogin=fopen("user_add_student.dat","rb");
        while(fread(&user,sizeof(user),1,userlogin)==1)
        {
            if(strcmp(temp_userid,user.id)==0)
            {
                gotoxy(x,17);printf("User Found");
                gotoxy(x,19);printf("User-ID:%s",user.id);
                gotoxy(x,20);printf("Name:%s",user.name);
                found = 1;
            }
        }
       if(found==0)
        {
           gotoxy(x,17);printf("No User with this ID");
        }
        fflush(stdin);
        gotoxy(x,21);printf("Do you want to search another user(y/n)");
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            search_user();
        }
        else
        adminMain_user();
    }
    else if(choice==2)
    {
        gotoxy(x,14);printf("Enter the User-Id to search for teacher ");
        scanf("%s",&temp_userid);
        FILE *userlogin;
        userlogin=fopen("user_add_teacher.dat","rb");
        while(fread(&user,sizeof(user),1,userlogin)==1)
        {
            if(strcmp(temp_userid,user.id)==0)
            {
                gotoxy(x,16);printf("User Found");
                gotoxy(x,18);printf("User-ID:%s",user.id);
                gotoxy(x,20);printf("Name:%s",user.name);
                found = 1;
            }
        }
       if(found==0)
       {
           gotoxy(x,16);printf("No User with this ID");
        }
        fflush(stdin);
        gotoxy(x,22);printf("Do you want to search another user(y/n) ");scanf("%c",&ch);
           if(ch=='y' || ch=='Y')
           {
               search_user();
           }
           else
            adminMain_user();
    }
    else if(choice==3)
    {
        int exist=0;
        int y=16;
        gotoxy(x,14);printf("Enter the User-Id to search for other ");
        scanf("%s",&temp_userid);
        FILE *userlogin;
        userlogin=fopen("user_add_other.dat","rb");
        while(fread(&user,sizeof(user),1,userlogin)==1)
        {
            if(strcmp(temp_userid,user.id)==0)
            {
                gotoxy(x,y);printf("User Found");
                gotoxy(x,y+1);printf("User-ID:%s",user.id);
                gotoxy(x,y+2);printf("Name:%s",user.name);
                y++;
            }
        }
       if(found==0)
        {
           gotoxy(x,16);printf("No User with this ID");
        }
        fflush(stdin);
        gotoxy(x,22);printf("Do you want to search another user(y/n) ");scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            search_user();
        }
        else
        adminMain_user();
    }
    else
        adminMain_user();
}
int delete_user()
{
    system("cls");
    window();
    gotoxy(32,6);printf("Admin Workspace");
    gotoxy(20,7);printf("********* Select category *********");
    gotoxy(x,10);printf("1. Student");
    gotoxy(x,11);printf("2. Teacher");
    gotoxy(x,12);printf("3. Others");
    gotoxy(x,13);scanf("%d",&choice);
    if(choice==1)
    {
        delete_user_student();
    }
    else if(choice==2)
    {
        delete_user_teacher();
    }
    else if(choice==3)
        delete_user_other();
    else
     delete_user();
}
int delete_user_student()
{
    char temp_userid[10];
    int found=0;
    FILE *fp;
    fp=fopen("user_add_student.dat","rb");
    gotoxy(x,14);printf("Enter the User-Id to Delete the User Record ");
    scanf("%s",&temp_userid);
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user.id,temp_userid)==0)
        {
            gotoxy(x,16);printf("User Record Available");
            gotoxy(x,17);printf("ID:%s",user.id);
            gotoxy(x,18);printf("Name:%s",user.name);
            found = 1;
        }
    }
    if(found==1)
    {
        rewind(fp);
        FILE *fpTemp;
        fpTemp=fopen("add_user_temp.dat","wb");
        while(fread(&user,sizeof(user),1,fp)==1)
        {
            if(strcmp(user.id,temp_userid)!=0)
            {
                fwrite(&user,sizeof(user),1,fpTemp);
            }
        }
        fclose(fp);
        fclose(fpTemp);
    	remove("user_add_student.dat");
        getch();
        rename("add_user_temp.dat","user_add_student.dat");
        gotoxy(x,20);printf("User Successfully deleted");
    }
    else
    {
        gotoxy(x,16);printf("User not found");
        fclose(fp);
    }
    fflush(stdin);
    char ch;
    gotoxy(x,22);printf("Do you want to delete another user(y/n) ");scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
        delete_user();
    else
        adminMain_user();
}
int delete_user_teacher()
{
    char temp_userid[10];
    int found=0;
    FILE *fp;
    fp=fopen("user_add_teacher.dat","rb");
    gotoxy(x,14);printf("Enter the User-Id to Delete the User Record ");
    scanf("%s",&temp_userid);
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user.id,temp_userid)==0)
        {
            gotoxy(x,16);printf("User Record Available");
            gotoxy(x,17);printf("ID:%s",user.id);
            gotoxy(x,18);printf("Name:%s",user.name);
            found = 1;
        }
    }
    if(found==1)
    {
        rewind(fp);
        FILE *fpTemp;
        fpTemp=fopen("add_user_temp.dat","wb");
        while(fread(&user,sizeof(user),1,fp)==1)
        {
            if(strcmp(user.id,temp_userid)!=0)
            {
                fwrite(&user,sizeof(user),1,fpTemp);
            }
        }
        fclose(fp);
        fclose(fpTemp);
        remove("user_add_teacher.dat");
        rename("add_user_temp.dat","user_add_teacher.dat");
        gotoxy(x,20);printf("User Successfully deleted");
    }
    else
    {
        gotoxy(x,16);printf("User not found");
        fclose(fp);
    }
    fflush(stdin);
    char ch;
    gotoxy(x,22);printf("Do you want to delete another user(y/n) ");scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
        delete_user();
    else
        adminMain_user();

}
int delete_user_other()
{
    char temp_userid[10];
    int found=0;
    FILE *fp;
    fp=fopen("user_add_other.dat","rb");
    gotoxy(x,14);printf("Enter the User-Id to Delete the User Record ");
    scanf("%s",&temp_userid);
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user.id,temp_userid)==0)
        {
            gotoxy(x,16);printf("User Record Available");
            gotoxy(x,17);printf("ID:%s",user.id);
            gotoxy(x,18);printf("Name:%s",user.name);
            found = 1;
        }
    }
    if(found==1)
    {
        rewind(fp);
        FILE *fpTemp;
        fpTemp=fopen("add_user_temp.dat","wb");
        while(fread(&user,sizeof(user),1,fp)==1)
        {
            if(strcmp(user.id,temp_userid)!=0)
            {
                fwrite(&user,sizeof(user),1,fpTemp);
            }
        }
        fclose(fp);
        fclose(fpTemp);
        remove("user_add_other.dat");
        rename("add_user_temp.dat","user_add_other.dat");
        gotoxy(x,20);printf("User Successfully deleted");
    }
    else
    {
        gotoxy(x,16);printf("User not found");
        fclose(fp);
    }
    fflush(stdin);
    char ch;
    gotoxy(x,18);printf("Do you want to delete another user(y/n) ");scanf("%c",&ch);
    if(ch=='y' || ch=='Y')
    {
        delete_user();
    }
    else
        adminMain_user();
}
int view_user()
{
    system("cls");
    window();
    gotoxy(32,6);printf("Admin Workspace");
    gotoxy(20,8);printf("********* Select category *********");
    gotoxy(x,10);printf("1. Student");
    gotoxy(x,11);printf("2. Teacher");
    gotoxy(x,12);printf("3. Others\n");
    gotoxy(x,13);printf("3. Back\n");
    gotoxy(x,14);scanf("%d",&choice);
    if(choice==1)
    {
        view_student();
        adminMain_user();
    }
    else if(choice==2)
    {
        view_teacher();
        adminMain_user();
    }
    else if(choice==3)
    {
        view_other();
        adminMain_user();
    }
    else
        adminMain_user();
}
int view_student()
{
    system("cls");
    window();
    gotoxy(5,5);printf("*************************  Student List  *************************");
    gotoxy(5,6);printf("  ID        STUDENT NAME ");
    FILE *fp;
    int j=8;
    fp=fopen("user_add_student.dat","rb");
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        gotoxy(6,j);printf("%s",user.id);
        gotoxy(20,j);printf("%s",user.name);
        printf("\n");
        j++;
    }
    getch();
}
int view_teacher()
{
     system("cls");
    window();
    gotoxy(5,5);printf("*************************  Student List  *************************");
    gotoxy(5,6);printf("  ID        STUDENT NAME ");
    FILE *fp;
    int j=8;
    fp=fopen("user_add_teacher.dat","rb");
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        gotoxy(6,j);printf("%s",user.id);
        gotoxy(20,j);printf("%s",user.name);
        printf("\n");
        j++;
    }
    getch();
}
int view_other()
{
     system("cls");
    window();
    gotoxy(5,5);printf("*************************  Student List  *************************");
    gotoxy(5,6);printf("  ID        STUDENT NAME ");
    FILE *fp;
    int j=8;
    fp=fopen("user_add_other.dat","rb");
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        gotoxy(6,j);printf("%s",user.id);
        gotoxy(20,j);printf("%s",user.name);
        printf("\n");
        j++;
    }
    getch();
}
int change_pass()
{
    system("cls");
    window();
    gotoxy(34,6);printf("Admin Workspace");
    gotoxy(20,8);printf("********* Select category *********");
    gotoxy(x,10);printf("1. Student");
    gotoxy(x,11);printf("2. Teacher");
    gotoxy(x,12);printf("3. Others\n");
    gotoxy(x,13);printf("3. Back\n");
    gotoxy(x,14);scanf("%d",&choice);
    if(choice==1)
    {
        change_student();
    }
    else if(choice==2)
    {
        change_teacher();
    }
    else if(choice==3)
    {
        change_other();
    }
    adminMain_user();
}
int change_student()
{
    char old_pass[20];
    char new_pass[20];
    char user_name[20];
    char user_id[10];
    system("cls");
    int found=0;
    window();
    int user_id_correct=0;
    FILE *fp=fopen("user_add_student.dat","rb");
    gotoxy(34,6);printf("Admin Workspace");fflush(stdin);
    gotoxy(x,10);printf("Enter the user id to change password ");gets(user_id);
    while(fread(&user,sizeof(user),1,fp)==1)
    {

        if(strcmp(user_id,user.id)==0)
        {
            user_id_correct=1;
            gotoxy(x,12);printf("User Found");fflush(stdin);
            gotoxy(x,14);printf("Enter the Old Password ");getuser_password(old_pass);
            if(strcmp(old_pass,user.pass)==0)
            {
                gotoxy(x,16);printf("Password Matched");
                gotoxy(x,18);printf("Enter the New Password ");getuser_password(new_pass);
                found=1;
                strcpy(user_name,user.name);
                FILE *fp1;
                rewind(fp);
                fp1=fopen("add_user_temp.dat","wb");
                while(fread(&user,sizeof(user),1,fp)==1)
                {
                    if(strcmp(user.id,user_id)!=0)
                    {
                        fwrite(&user,sizeof(user),1,fp1);
                    }
                    else
                    {
                        strcpy(user.pass,new_pass);
                        strcpy(user.name,user_name);
                        strcpy(user.id,user_id);
                        fwrite(&user,sizeof(user),1,fp1);
                    }
                }
                fclose(fp1);
                fclose(fp);
                remove("user_add_student.dat");
                rename("add_user_temp.dat","user_add_student.dat");
                gotoxy(x,20);printf("Password Changed Successfully");
                getch();
            }
            if(found==0)
            {
                gotoxy(x,16);printf("User Password Incorrect");
            }
        }
    }
    if(user_id_correct==0)
        gotoxy(x,14);printf("Incorrect User-ID");

    adminMain_user();
}
int change_teacher()
{
    char old_pass[20];
    char new_pass[20];
    char user_name[20];
    char user_id[10];
    system("cls");
    int found=0;
    window();
    int user_id_correct=0;
    FILE *fp=fopen("user_add_teacher.dat","rb");
    gotoxy(34,6);printf("Admin Workspace");fflush(stdin);
    gotoxy(x,10);printf("Enter the user id to change password ");gets(user_id);
    while(fread(&user,sizeof(user),1,fp)==1)
    {

        if(strcmp(user_id,user.id)==0)
        {
            user_id_correct=1;
            gotoxy(x,12);printf("User Found");fflush(stdin);
            gotoxy(x,14);printf("Enter the Old Password ");getuser_password(old_pass);
            if(strcmp(old_pass,user.pass)==0)
            {
                gotoxy(x,16);printf("Password Matched");
                gotoxy(x,18);printf("Enter the New Password ");getuser_password(new_pass);
                found=1;
                strcpy(user_name,user.name);
                FILE *fp1;
                rewind(fp);
                fp1=fopen("add_user_temp.dat","wb");
                while(fread(&user,sizeof(user),1,fp)==1)
                {
                    if(strcmp(user.id,user_id)!=0)
                    {
                        fwrite(&user,sizeof(user),1,fp1);
                    }
                    else
                    {
                        strcpy(user.pass,new_pass);
                        strcpy(user.name,user_name);
                        strcpy(user.id,user_id);
                        fwrite(&user,sizeof(user),1,fp1);
                    }
                }
                fclose(fp1);
                fclose(fp);
                remove("user_add_teacher.dat");
                rename("add_user_temp.dat","user_add_teacher.dat");
                gotoxy(x,20);printf("Password Changed Successfully");
                getch();
            }
            if(found==0)
            {
                gotoxy(x,16);printf("User Password Incorrect");
            }
        }
    }
    if(user_id_correct==0)
        gotoxy(x,14);printf("Incorrect User-ID");

    adminMain_user();
}
int change_other()
{
    char old_pass[20];
    char new_pass[20];
    char user_name[20];
    char user_id[10];
    system("cls");
    int found=0;
    window();
    int user_id_correct=0;
    FILE *fp=fopen("user_add_other.dat","rb");
    gotoxy(34,6);printf("Admin Workspace");fflush(stdin);
    gotoxy(x,10);printf("Enter the user id to change password ");gets(user_id);
    while(fread(&user,sizeof(user),1,fp)==1)
    {

        if(strcmp(user_id,user.id)==0)
        {
            user_id_correct=1;
            gotoxy(x,12);printf("User Found");fflush(stdin);
            gotoxy(x,14);printf("Enter the Old Password ");getuser_password(old_pass);
            if(strcmp(old_pass,user.pass)==0)
            {
                gotoxy(x,16);printf("Password Matched");
                gotoxy(x,18);printf("Enter the New Password ");getuser_password(new_pass);
                found=1;
                strcpy(user_name,user.name);
                FILE *fp1;
                rewind(fp);
                fp1=fopen("add_user_temp.dat","wb");
                while(fread(&user,sizeof(user),1,fp)==1)
                {
                    if(strcmp(user.id,user_id)!=0)
                    {
                        fwrite(&user,sizeof(user),1,fp1);
                    }
                    else
                    {
                        strcpy(user.pass,new_pass);
                        strcpy(user.name,user_name);
                        strcpy(user.id,user_id);
                        fwrite(&user,sizeof(user),1,fp1);
                    }
                }
                fclose(fp1);
                fclose(fp);
                remove("user_add_other.dat");
                rename("add_user_temp.dat","user_add_other.dat");
                gotoxy(x,20);printf("Password Changed Successfully");
                getch();
            }
            if(found==0)
            {
                gotoxy(x,16);printf("User Password Incorrect");
            }
        }
    }
    if(user_id_correct==0)
        gotoxy(x,14);printf("Incorrect User-ID");

    adminMain_user();
}
int user_pass()
{
    system("cls");
    window();
    gotoxy(20,8);printf("********* Select category *********");
    gotoxy(x,10);printf("1. Student");
    gotoxy(x,11);printf("2. Teacher");
    gotoxy(x,12);printf("3. Others\n");
    gotoxy(x,13);printf("3. Back\n");
    gotoxy(x,14);scanf("%d",&choice);
    if(choice==1)
    {
        user_student();
    }
    else if(choice==2)
    {
        user_teacher();
    }
    else if(choice==3)
    {
        user_other();
    }
    admin_main();
}
int user_student()
{
    system("cls");
    window();
    char user_id[10];
    char user_password[20];
    int user_found=0;
    int pass_found=0;
    FILE *fp;
    fp=fopen("user_add_student.dat","rb");
    gotoxy(x,10);printf("Enter the User-id ");scanf("%s",&user_id);

    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user_id,user.id)==0)
        {
            user_found=1;
            fflush(stdin);
            gotoxy(x,12);printf("Enter the Password ");getadmin_password(user_password);
            if(strcmp(user_password,user.pass)==0)
            {
                pass_found=1;
            }
        }
    }
    fclose(fp);
    if(user_found==1 && pass_found==0)
    {
        gotoxy(x,15);printf("Password Incorrect");
        user_student();
    }
    else if(user_found==0)
    {
        gotoxy(x,12);printf("Invalid User-Id");
        user_student();
    }
    user_main();
}
int user_teacher()
{
    system("cls");
    window();
    char user_id[10];
    char user_password[20];
    int user_found=0;
    int pass_found=0;
    FILE *fp;
    fp=fopen("user_add_teacher.dat","rb");
    gotoxy(x,10);printf("Enter the User-id ");scanf("%s",&user_id);
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user_id,user.id)==0)
        {
            user_found=1;
            gotoxy(x,12);printf("Enter the Password ");getadmin_password(user_password);
            if(strcmp(user_password,user.pass)==0)
            {
                pass_found=1;

            }
        }
    }
    fclose(fp);
    if(user_found==1 && pass_found==0)
    {
        gotoxy(x,15);printf("Password Incorrect");
        user_teacher();
    }
    else if(user_found==0)
    {
        gotoxy(x,12);printf("Invalid User-Id");
        user_teacher();
    }
    user_main();
}
int user_other()
{
    system("cls");
    window();
    char user_id[10];
    char user_password[20];
    int user_found=0;
    int pass_found=0;
    FILE *fp;
    fp=fopen("user_add_other.dat","rb");
    gotoxy(x,10);printf("Enter the User-id ");scanf("%s",&user_id);
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user_id,user.id)==0)
        {
            user_found=1;
            gotoxy(x,12);printf("Enter the Password ");getadmin_password(user_password);
            if(strcmp(user_password,user.pass)==0)
            {
                pass_found=1;
            }
        }
    }
    fclose(fp);
    if(user_found==1 && pass_found==0)
    {
        gotoxy(x,15);printf("Password Incorrect");
        user_other();
    }
    else if(user_found==0)
    {
        gotoxy(x,12);printf("Invalid User-Id");
        user_other();
    }
    user_main();
}
int user_main()
{
        system("cls"); window();
        gotoxy(35,6);printf("User Area");
        gotoxy(x,9);printf("1. View Book List");
        gotoxy(x,10);printf("2. Search Book By ID");
        gotoxy(x,11);printf("3. Search Book By Name");
        gotoxy(x,12);printf("4. Issue Book");
        gotoxy(x,13);printf("5. Return Book");
        gotoxy(x,14);printf("6. Back");
        gotoxy(x,15);printf("7. Exit");
        gotoxy(x,17);printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                view_books();
                 user_main();
                break;
            case 2:
                searchByID();
                 user_main();
                break;
            case 3:
                searchByName();
                 user_main();
                break;
            case 4:
                issue_book();
                 user_main();
                break;
            case 5:
                return_book();
                 user_main();
                break;
            case 6:
                system("cls");
                user_main();
                break;
            case 7:
                finish();
                break;
            default:
                user_main();
                break;
        }

}
struct Book_Issued{
    char user_id[10];
    char book_ids[10];
    char book_name[35];
    char book_author[35];
    struct tm *t_issue;
 //   struct tm *t_due;
}book_issue;
int issue_book()
{
    system("cls");
    char user_id[10];
    char user_issue;
    char user_password[20];
    int pass_found=0;
    int issue_success=0;
    int user_found=0;
    char book_id[10];
    window();
    FILE *fp;
    fp=fopen("user_add_student.dat","rb");
    gotoxy(32,6);printf("User Area");fflush(stdin);
    gotoxy(x,8);printf("Enter the User-Id to Issue a book ");gets(user_id);
    while(fread(&user,sizeof(user),1,fp)==1)
    {
        if(strcmp(user_id,user.id)==0)
        {
            user_found=1;
            gotoxy(x,10);printf("Enter the Password ");getadmin_password(user_password);
            if(strcmp(user_password,user.pass)==0)
            {
                pass_found=1;
                user_issue=user.issued;
            }
        }
    }
    if(pass_found==1 && user_issue=='0')
    {
        gotoxy(x,12);printf("Enter the Book-Id to Issue a Book ");scanf("%s",&book_id);
        FILE *fbook,*temp;
        temp=fopen("temp.dat","ab+");
        fbook=fopen("Add_book.dat","rb");
        while(fread(&book,sizeof(book),1,fbook))
        {
            if(strcmp(book_id,book.id)==0)
            {
                    FILE *fissue;
                    struct tm *t_issue;
                    fissue=fopen("issued.txt","a+");
                    strcpy(book_issue.user_id,user_id);
                    time_t now = time(NULL);
                    t_issue=localtime(&now);
                    strcpy(book_issue.book_ids,book_id);
                    strcpy(book_issue.book_name,book.name);
                    fwrite(&book_issue.user_id,sizeof(book_issue.user_id),1,fissue);
                    fwrite(&book_issue.book_name,sizeof(book_issue.book_name),1,fissue);
                    fwrite(&book_issue.book_author,sizeof(book_issue.book_author),1,fissue);
                    fwrite(&book_issue.t_issue,sizeof(book_issue.t_issue),1,fissue);
                    fwrite(&book_issue.book_ids,sizeof(book_issue.book_ids),1,fissue);
                    fprintf(fissue,"%s", ctime(&now));
                    fclose(fissue);
                    issue_success=1;
                    gotoxy(x,16);printf("Book Issued Successfully");
                    getch();
            }
            else{
                fwrite(&book,sizeof(book),1,temp);
            }
        }
        if(issue_success==1)
        {
            FILE *fptemp;
            fptemp=fopen("tempfile.dat","ab+");
            rewind(fp);
            while(fread(&user,sizeof(user),1,fp))
            {
                if(strcmp(user_id,user.id)==0)
                {
                    user.issued='1';
                    fwrite(&user,sizeof(user),1,fptemp);
                }
                else{
                    fwrite(&user,sizeof(user),1,fptemp);
                }
            }
            fclose(fp);
            fclose(fptemp);
            remove("user_add_student.dat");
            rename("tempfile.dat","user_add_student.dat");
        }

        fclose(fbook);
        fclose(temp);
        fclose(fp);
        remove("Add_book.dat");
        rename("temp.dat","Add_book.dat");
    }
    else{
        gotoxy(x,14);printf("Incorrect Password or Book Already Issued");
        getch();
    }
}
int return_book()
{/*
    char user_id[10];
    char user_password[20];
    int book_found=0;
    char book_id[10];
    system("cls");
    window();
    FILE *fp;
    fp=fopen("issued,txt","r");
    gotoxy(32,6);printf("User Area");
    gotoxy(x,8);printf("Enter the User-Id to return the book ");scanf("%s",&user_id);
    FILE *fuser;
    fuser=fopen("user_add_student.dat","rb");
    while(fread(&user,sizeof(user),1,fuser))
    {
        if(strcmp(user_id,user.id)==0)
        {
            gotoxy(x,10);printf("Enter the password ");getadmin_password(user_password);
            if(strcmp(user_password,user.pass)==0)
            {
                gotoxy(x,12);printf("Enter the Book-Id to return ");scanf("%d",&book_id);
                FILE *fbook;
                fbook=fopen("Add_book.dat","ab+");
                while(fread(&book,sizeof(book),1,fbook))
                {
                    if(strcmp(book_id,book.id)==0)
                        book_found=1;
                }
                if(book_found==0)
                {
                    FILE *fissue;
                    fissue=fopen("issued.txt","rb");
                    while(fread(&book_issue,sizeof(book_issue),1,fissue))
                    {
                        if(strcmp(user_id,book_issue.user_id)==0 && strcmp(book_id,book_issue.book_ids)==0)
                        {
                                fwrite(&book,sizeof(book),1,fbook);
                                fclose(fbook);
                                FILE *f;
                                f=fopen("temp.txt","ab+");
                                while(fread())
                                {

                                }
                        }
                    }
                }
            }
        }
    }
*/}
