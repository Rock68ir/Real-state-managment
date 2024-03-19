#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include <conio.h>
#include <mmsystem.h>                  //include the HEADER file for PlaySound().
#pragma comment(lib,"Winmm.lib")

char g_access_lvl[11] = " No Access" , g_message[100] , g_property_id[7] , music=0;
void cleanHeader(char *access_level , char *message)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    system("cls");
    printf("                                        __..--==In the name of god==--..__\n");
    printf("                                      =======================================");
    printf("\n                              Welcome to ISIS real estate consultant management system\n");
    printf("========================================================================================================================\n");
    printf("|Date : %d-%02d-%02d|%*c |Access level : %s|\n%*cSystem message >> %s", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, 73, ' ',access_level, 3, ' ',message);
    printf("\n************************************************************************************************************************\n");
}
unsigned int date_to_sec(int year , int month , int day)
{
    int yday;
    day-=1;
    month -= 1 ;
    year -= 1900;
    if(month <= 6)
    {
        yday = day + month * 31 ;
    }else
    {
        yday = day + month * 31 - (month%6);
    }
    unsigned int seconds = yday*86400 + (year-70)*31536000 + ((year-69)/4)*86400 - ((year-1)/100)*86400 + ((year+299)/400)*86400;
    return seconds;
}
int numcheck(char *str)
{
    int index = 0;
    while(*(str + index) != '\n' )
    {
        if(*(str + index) == '\0')
        {
            break;
        }
        if(!isdigit(*(str + index)))
        {
            return 0;
        }
        index++;
    }
    return 1;
}
int lencheck(char* str , int length)
{
    if(strlen(str) > length
        || (strlen(str) == length && str[strlen(str) - 1] != '\n')
         || strlen(str) < 4)
    {
        return 0;
    }else{
        return 1;
    }
}
int lencheckalt(char* str , int length)
{
    if(strlen(str) > length
        || (strlen(str) == length && str[strlen(str) - 1] != '\n'))
    {
        return 0;
    }else{
        return 1;
    }
}
/* in tabe baraye hazf kardane character haye gheyr adad va harf dar shahr
va lower case kardane horofe an sakhte shode ta hengam search TEh ran va tehran
ra yeki dar nazar begirad*/
void normalizer(char *first)
{
    int loc = 0 , locout = 0;
    while(*(first+loc) != '\0')
    {
        //lowercase kardane har harf
        *(first+loc) = tolower(*(first+loc));
        //agar alphanumeric bashad anra be array khoroji ezafe mikonim
        if(*(first+loc) != ' ')
            {
                *(first+locout) = *(first+loc);
                locout++;
            }
        loc++;
    }
    //ezafe kardane \0 be entehaye khoroji mored nazar
    *(first+locout) = '\0';
}
typedef struct client
{
    char username[20];
    char name[25];
    char family[25];
    char id[12];
    char email[50];
    char phone_number[13];
    char password[30];
    char access_lvl[12];
    char submits[8];
    char last_activity[12];
    struct client *next;
}client;
client *active_user;
struct residental_sale_case
{
    char id[6];
    char type;
    char status[4];
    char district[5];
    char address[100];
    char building_type;
    char age[5];
    char built_area[50];
    char floor[5];
    char area[30];
    char parking_lot;
    char depot;
    char elevator;
    char air_conditioning_system;
    char accessibility;
    char owner_contact[13];
    char rooms[5];
    char sell_price_meter[13];
    char sell_price[20];
    char submit_user[20];
    unsigned int submit_time;
    unsigned int archive_time;
    char archive_user[20];
    struct residental_sale_case *next;
};
struct residental_rent_case
{
    char id[6];
    char type;
    char status[5];
    char district[5];
    char address[100];
    char building_type;
    char age[5];
    char built_area[50];
    char floor[5];
    char area[30];
    char parking_lot;
    char depot;
    char elevator;
    char air_conditioning_system;
    char accessibility;
    char owner_contact[13];
    char rooms[5];
    char mortgage_price[15];
    char rent_price[20];
    char submit_user[20];
    unsigned int submit_time;
    unsigned int archive_time;
    char archive_user[20];
    struct residental_rent_case *next;
};
struct office_sale_case
{
    char id[6];
    char type;
    char status[5];
    char district[5];
    char address[100];
    char building_type;
    char age[5];
    char built_area[50];
    char floor[5];
    char area[30];
    char parking_lot;
    char depot;
    char elevator;
    char air_conditioning_system;
    char accessibility;
    char owner_contact[13];
    char rooms[5];
    char sell_price_meter[13];
    char sell_price[20];
    char submit_user[20];
    unsigned int submit_time;
    unsigned int archive_time;
    char archive_user[20];
    struct office_sale_case *next;
};
struct office_rent_case
{
    char id[6];
    char type;
    char status[5];
    char district[5];
    char address[100];
    char building_type;
    char age[5];
    char built_area[50];
    char floor[5];
    char area[30];
    char parking_lot;
    char depot;
    char elevator;
    char air_conditioning_system;
    char accessibility;
    char owner_contact[13];
    char rooms[5];
    char mortgage_price[15];
    char rent_price[20];
    char submit_user[20];
    unsigned int submit_time;
    unsigned int archive_time;
    char archive_user[20];
    struct office_rent_case *next;
};
struct land_sale_case
{
    char id[6];
    char type;
    char status[4];
    char district[5];
    char address[50];
    char building_type;
    char construct_permit;
    char area[30];
    char accessibility;
    char distance_from_city[10];
    char owner_contact[13];
    char sell_price_meter[13];
    char sell_price[20];
    char submit_user[20];
    unsigned int submit_time;
    unsigned int archive_time;
    char archive_user[20];
    struct land_sale_case *next;
};
struct land_rent_case
{
    char id[6];
    char type;
    char status[4];
    char district[5];
    char address[50];
    char building_type;
    char construct_permit;
    char area[30];
    char accessibility;
    char distance_from_city[10];
    char owner_contact[13];
    char mortgage_price[13];
    char rent_price[20];
    char submit_user[20];
    unsigned int submit_time;
    unsigned int archive_time;
    char archive_user[20];
    struct land_rent_case *next;
};
client* initialize_profiles(client *start)
{
    FILE *user_profiles = fopen("user_profiles.txt" , "r+");
    client *temp , *end;
    end = start;
    rewind(user_profiles);
    while(feof(user_profiles) == 0)
    {
        fscanf(user_profiles , "username : %s ," , &end->username);
        fscanf(user_profiles , "name : %s ," , &end->name);
        fscanf(user_profiles , "family : %s ," , &end->family);
        fscanf(user_profiles , "id : %s ," , &end->id);
        fscanf(user_profiles , "email : %s ," , &end->email);
        fscanf(user_profiles , "phone number : %s ," , &end->phone_number);
        fscanf(user_profiles , "password : %s ," , &end->password);
        fscanf(user_profiles , "submits : %s ," , &end->submits);
        fscanf(user_profiles , "last_activity : %s\n " , &end->last_activity);
        fscanf(user_profiles , "Access_lvl : %s " , &end->access_lvl);
        temp = malloc(sizeof(client));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(user_profiles);
    return end;
}
void user_activity_count_update(char *username , int issubmit)
{
    FILE *user_profiles = fopen("user_profiles.txt" , "r+");
    client *end = malloc(sizeof(struct client));
    int pos;
    rewind(user_profiles);
    while(feof(user_profiles) == 0)
    {
        fscanf(user_profiles , "username : %s ," , &end->username);
        fscanf(user_profiles , "name : %s ," , &end->name);
        fscanf(user_profiles , "family : %s ," , &end->family);
        fscanf(user_profiles , "id : %s ," , &end->id);
        fscanf(user_profiles , "email : %s ," , &end->email);
        fscanf(user_profiles , "phone number : %s ," , &end->phone_number);
        fscanf(user_profiles , "password : %s ," , &end->password);
        pos = ftell(user_profiles);
        fscanf(user_profiles , "submits : %s ," , &end->submits);
        if(strcmp(end->username , username) == 0)
        {
            fseek(user_profiles , pos , SEEK_SET);
            if(issubmit)
            {
                sprintf(end->submits , "%d" , atoi(end->submits)+1);
            }
            fprintf(user_profiles , "submits : %s\n ,last_activity : %d\n " , end->submits , time(NULL));
            break;
        }
        fscanf(user_profiles , "last_activity : %s\n " , &end->submits);
        fscanf(user_profiles , "Access_lvl : %s " , &end->access_lvl);
    }
    free(end);
    fclose(user_profiles);
}
int usercheck(char* str)
{
    client *start , *slink;
    initialize_profiles(start);
    slink = start;
    str[strcspn(str, "\n")] = 0;
    while(1)
    {
        if(strcmp(slink->username , str) == 0)
        {
            return 1;
        }
        if(slink->next == NULL)
        {
            break;
        }
        slink = slink->next;
    }
    return 0;
}
int hasspace(char *str)
{
    int index = 0;
    while(*(str + index) != '\0')
    {
        if(*(str+index) == ' ')
        {
            return 1;
        }
        index++;
    }
    return 0;
}
int integrity_check(char *str)
{
    int index = 0 , upper = 0 , lower = 0 , special = 0;
    while(*(str+index) != '\0')
    {
        if(isupper(*(str+index)))
        {
            upper++;
        }
        if(islower(*(str+index)))
        {
            lower++;
        }
        if(!isalpha(*(str+index)) && !isdigit(*(str+index)))
        {
            special++;
        }
        if(*(str+index) == ' ')
        {
            strcpy(g_message , "spaces are not allowed in password");
            return 0;
        }
        index++;
    }
    if(lower>0 && upper>0 && special > 0 && index>8)
    {
        return 1;
    }
    else{
        return 0;
    }

}
int isalphabet(char *str)
{
    int index = 0;
    while(*(str + index) != '\n')
    {
        if(!isalpha(*(str+index)))
        {
            return 0;
        }
        index++;
    }
    return 1;
}
int isemail(char *input)
{
    int length = 0 , atSigncheck = 0 , dotcheck = 0, alphanum = 0;
    length = strlen(input) - 1;
    //barresi tak take character haye vorodi
    for(int index = 0 ; index < length ; index++)
    {
        //ba didane char @ dar sorati ke avalin bar bashad motabar ast
        if(input[index] == '@' && atSigncheck == 0 && alphanum >=1)
        {
            atSigncheck++;
            alphanum = 0;
        }
        //char . dar sorati motabar ast ke bade yek alphabet ya adad amade bashad
        else if(input[index] == '.' && alphanum >= 1 )
        {
            alphanum = 0;
            dotcheck++;
        }
        //barresi char haye number ya alphabet
        else if(isalpha(input[index]) || isdigit(input[index]))
        {
            alphanum++;
        }
        /*characteri ke hich kodam az shart haye bala ra nadashte bashad
        gheyr ghabel ghabol ast va be err mikhorim*/
        else
        {
            return 0;
        }
    }
    if(dotcheck != 0 && alphanum >= 1 && atSigncheck == 1)
    {
        return 1;
    }else
    {
        return 0;
    }
}
void fgetpass(char *str, int max)
{
    int index = 0 , end =0;
    int temp;
    while(index < max && end == 0)
    {
        switch(temp = getch())
        {
            case 8:
                if(index>0)
                {
                    printf("\b \b");
                    index--;
                }
                break;
            case 224:
                switch(getch())
                { // the real value
                default:
                    break;
                }
                break;
            case 0:
                switch(getch())
                { // the real value
                default:
                    break;
                }
                break;
            case 9:
                switch(getch())
                { // the real value
                default:
                    break;
                }
                break;
            case 13:
                {
                   *(str+index) = '\n';
                    index++;
                    *(str+index) = '\0';
                    end = 1;
                    break;
                }
            default:
                {
                    *(str+index) = temp;
                    index++;
                    printf("*");
                }

        }
    }
}
void fsgets(char *str, int max)
{
    fgets(str , max , stdin);
    str[strcspn(str, "\n")] = 0;

}
void signup(client *link , char *state)
{
    char verify[3]="no" ,input_password[20];
    FILE *user_profiles = fopen("user_profiles.txt" , "a");
    strcpy(g_message , "enter 0 to go back - minimum 3 characters");
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Sign up Page----\n\n%*c||Please enter the required information:\n%*c||Username :" , 45 , ' ',20 , ' ',20 , ' ');
        fgets(link->username , 20 , stdin);
        if(strcmp(link->username , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(link->username , 19)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        if(hasspace(link->username))
        {
            strcpy(g_message , "username can't contain space(s).");
            fflush(stdin);
            continue;
        }
        if(usercheck(link->username))
        {
            strcpy(g_message , "username already in use.");
            fflush(stdin);
            continue;
        }
        printf("%*c||Name :" ,20 , ' ');
        fgets(link->name , 25 , stdin);
        if(strcmp(link->name , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(link->name , 24)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        if (!isalphabet(link->name)) {
            strcpy(g_message , "name can only contain alphabet!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Family :",20 , ' ');
        fgets(link->family , 25 , stdin);
        if(strcmp(link->family , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(link->family , 19)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        if (!isalphabet(link->name)) {
            strcpy(g_message , "name can only contain alphabet!");
            fflush(stdin);
            continue;
        }
        printf("%*c||national ID number :" ,20 , ' ');
        fgets(link->id , 12 , stdin);
        if(strcmp(link->id , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(link->id) != 11 || !numcheck(link->id)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Email :" ,20 , ' ');
        fgets(link->email , 50 , stdin);
        if(strcmp(link->email , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(link->email , 49) || !isemail(link->email)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Phone Number :" ,20 , ' ');
        fgets(link->phone_number , 13 , stdin);
        if(strcmp(link->phone_number , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(link->phone_number) != 12 || !numcheck(link->phone_number)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 5);
        fflush(stdin);
    }
    strcpy(g_message , "Passwords must match and contain at least 8 characters and an upper and a special character");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Sign up Page----\n\n%*c||Please enter your password:\n" , 45 , ' ',20 , ' ');
        printf("%*c||Password :" ,20 , ' ');
        fgetpass(link->password , 30);
        if (!lencheck(link->password , 29)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        if(!integrity_check(link->password))
        {
            strcpy(g_message , "password too simple it should contain at least 8 characters and an upper and a special character");
            continue;
        }
        printf("\n%*c||Confirm your password :" ,20 , ' ');
        fgetpass(input_password ,30);
        if (!lencheck(input_password , 29)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        if(strcmp(input_password , link->password)==0)
        {
            break;
        }
    }
    fprintf(user_profiles , "username : %s\n ," , link->username);
    fprintf(user_profiles , "name : %s ," , link->name);
    fprintf(user_profiles , "family : %s ," , link->family);
    fprintf(user_profiles , "id : %s ," , link->id);
    fprintf(user_profiles , "email : %s ," , link->email);
    fprintf(user_profiles , "phone number : %s ," , link->phone_number);
    fprintf(user_profiles , "password : %s ," , link->password);
    fprintf(user_profiles , "submits : 0\n ,");
    fprintf(user_profiles , "last_activity : %d\n " , time(NULL));
    fprintf(user_profiles , "Access_lvl : Admin ");
    fputs("\n" , user_profiles);
    strcpy(g_message , "sign up successful!");
    fclose(user_profiles);
}
int signin()
{
    char input_username[20] , input_password[30];
    int found = 0 , result=0 , attempts;
    client *start = malloc(sizeof(client));
    initialize_profiles(start);
    client *slink = start;
    FILE *gf = fopen("global.txt" , "r");
    rewind(gf);
    fscanf(gf , "id : %s\nattempts : %d" ,stdin , &attempts);
    fflush(stdin);
    fclose(gf);
    strcpy(g_message , "enter 0 as password to go back.");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Sign in Page----\n\n%*c||Please enter your login credinals:\n%*c||Username :" , 45 , ' ', 20 , ' ', 20 , ' ');
        fgets(input_username , 20 , stdin);
        if(strcmp(input_username , "0\n") == 0)
        {
            result = 0;
            break;
        }
        if (!lencheck(input_username , 19)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Password :" ,  20 , ' ');
        fgetpass(input_password , 30);
        if (!lencheck(input_password , 29)) {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        if(strcmp(input_password , "0\n") == 0)
        {
            result = 0;
            break;
        }
        if((strlen(input_password) == 1 )|| (strlen(input_username)) == 1)
        {
            strcpy(g_message , "username or password can't be empty!");
            continue;
        }
        input_password[strcspn(input_password, "\n")] = 0;
        input_username[strcspn(input_username, "\n")] = 0;
        slink = start;
        while(1)
        {
            if(strcmp(slink->username , input_username) == 0)
            {
                if(strcmp(slink->password , input_password) == 0)
                {
                    found=1;
                    break;
                }
            }
            if(slink->next == NULL)
            {
                found = 0;
                break;
            }
            slink = slink->next;
        }
        if(found == 1)
        {
            active_user = slink;
            strcpy(g_access_lvl , active_user->access_lvl);
            result = 1;
            FILE *gf = fopen("global.txt" , "r+");
            fscanf(gf , "id : %s\nattempts : " ,stdin);
            fflush(stdin);
            fseek(gf , 0 , SEEK_CUR);
            fprintf(gf ,"0");
            fclose(gf);
            break;
        }else{
            attempts++;
            if(attempts == 5)
            {
                FILE *gf = fopen("global.txt" , "r+");
                fscanf(gf , "id : %s\n",stdin);
                fflush(stdin);
                fseek(gf , 0 , SEEK_CUR);
                fprintf(gf ,"attempts : 0\nbantime : %d" , time(NULL));
                fclose(gf);
                result = 0;
                strcpy(g_message , "5 wrong login attempts , you are banned for 15 minutes.");
                break;
            }
            FILE *gf = fopen("global.txt" , "r+");
            fscanf(gf , "id : %s\nattempts : " ,stdin);
            fflush(stdin);
            fseek(gf , 0 , SEEK_CUR);
            fprintf(gf ,"%d" , attempts);
            fclose(gf);
            strcpy(g_message , "Username and password don't match !(Enter 0 as password to go back)");
        }
    }
    return result;
}
void submit_residental_sale(){
    char verify[5]="no" ;
    strcpy(g_message , "Enter 0 as input to go back .");
    FILE *properties_file = fopen("residental_sale.txt" , "a+");
    struct residental_sale_case *residental_sale_struct;
    residental_sale_struct = malloc(sizeof(struct residental_sale_case));
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Submit new residental sale case----\n\n%*c||Please enter the required information:\n%*c||District :" , 45 , ' ',20 , ' ',20 , ' ');
        fsgets(residental_sale_struct->district , 5);
        if(strcmp(residental_sale_struct->district , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_sale_struct->district))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_sale_struct->district) == 0 || !lencheckalt(residental_sale_struct->district , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->district);
        /*----------------------------------------------*/
        printf("%*c||Address :" ,20 , ' ');
        fsgets(residental_sale_struct->address , 100);
        if(strcmp(residental_sale_struct->address , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(strlen(residental_sale_struct->address) == 0 || !lencheckalt(residental_sale_struct->address , 99))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/
        printf("%*c||Building type(1=villa , 2=Apartment) : ",20 , ' ');
        do
        {
            residental_sale_struct->building_type = getch();
        }while(residental_sale_struct->building_type != '1' && residental_sale_struct->building_type != '2');
        printf("%c\n" , residental_sale_struct->building_type);

        /*----------------------------------------------*/
        printf("%*c||Building age :" ,20 , ' ');
        fsgets(residental_sale_struct->age , 5);
        if(strcmp(residental_sale_struct->age , "0\n") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            break;
        }
        if(!numcheck(residental_sale_struct->age))
        {
            strcpy(g_message , "wrong format(age can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_sale_struct->age) == 0 || !lencheckalt(residental_sale_struct->age , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->age);
        /*----------------------------------------------*/

        printf("%*c||Built up area :" ,20 , ' ');
        fsgets(residental_sale_struct->built_area , 50);
        if(strcmp(residental_sale_struct->built_area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_sale_struct->built_area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_sale_struct->built_area) == 0 || !lencheckalt(residental_sale_struct->built_area , 49))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->built_area);
        /*----------------------------------------------*/
        printf("%*c||Floor :" ,20 , ' ');
        fsgets(residental_sale_struct->floor , 5);
        if(strcmp(residental_sale_struct->floor , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_sale_struct->floor))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_sale_struct->floor) == 0 || !lencheckalt(residental_sale_struct->floor , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->floor);
        /*----------------------------------------------*/

        printf("%*c||Area:" ,20 , ' ');
        fsgets(residental_sale_struct->area , 30);
        if(strcmp(residental_sale_struct->area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_sale_struct->area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_sale_struct->area) == 0 || !lencheckalt(residental_sale_struct->area , 29))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->area);
        /*----------------------------------------------*/

        printf("%*c||Has dedicated parking space (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            residental_sale_struct->parking_lot = getch();
        }while(residental_sale_struct->parking_lot != '1' && residental_sale_struct->parking_lot != '2');
        printf("%c\n" , residental_sale_struct->parking_lot);
        /*----------------------------------------------*/

        printf("%*c||Has dedicated depot (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            residental_sale_struct->depot = getch();
        }while(residental_sale_struct->depot != '1' && residental_sale_struct->depot != '2');
        printf("%c\n" , residental_sale_struct->depot);
        /*----------------------------------------------*/

        printf("%*c||Has elevator (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            residental_sale_struct->elevator = getch();
        }while(residental_sale_struct->elevator != '1' && residental_sale_struct->elevator != '2');
        printf("%c\n" , residental_sale_struct->elevator);
        /*----------------------------------------------*/

        printf("%*c||Has Air conditioning system (1 = no , 2 = only cooling , 3 = only heating , 4 = both) : ",20 , ' ');
        do
        {
            residental_sale_struct->air_conditioning_system = getch();
        }while(residental_sale_struct->air_conditioning_system != '1' && residental_sale_struct->air_conditioning_system != '2'
               && residental_sale_struct->air_conditioning_system != '3' && residental_sale_struct->air_conditioning_system != '4');
        printf("%c\n" , residental_sale_struct->air_conditioning_system);
        /*----------------------------------------------*/

        printf("%*c||Accessibility (1 = Bad , 2 = good, 3 = great) : ",20 , ' ');
        do
        {
            residental_sale_struct->accessibility = getch();
        }while(residental_sale_struct->accessibility != '1' && residental_sale_struct->accessibility != '2'
               && residental_sale_struct->accessibility != '3');
        printf("%c\n" , residental_sale_struct->accessibility);
        /*----------------------------------------------*/

        printf("%*c||Rooms :" ,20 , ' ');
        fsgets(residental_sale_struct->rooms , 5);
        if(strcmp(residental_sale_struct->rooms , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_sale_struct->rooms))
        {
            strcpy(g_message , "wrong format(room count can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_sale_struct->rooms) == 0 || !lencheckalt(residental_sale_struct->rooms , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->rooms);
        /*----------------------------------------------*/

        printf("%*c||Owner's phone number :" ,20 , ' ');
        fsgets(residental_sale_struct->owner_contact , 13);
        if(strcmp(residental_sale_struct->owner_contact , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(residental_sale_struct->owner_contact) != 11 || !numcheck(residental_sale_struct->owner_contact)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/

        printf("%*c||Sell price per meter:" ,20 , ' ');
        fsgets(residental_sale_struct->sell_price_meter , 15);
        if(strcmp(residental_sale_struct->sell_price_meter , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(residental_sale_struct->sell_price_meter) == 0 || !numcheck(residental_sale_struct->sell_price_meter)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->sell_price_meter);
        printf("%*c||Sell price :" ,20 , ' ');
        /*----------------------------------------------*/

        fsgets(residental_sale_struct->sell_price , 20);
        if(strcmp(residental_sale_struct->sell_price_meter , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(residental_sale_struct->sell_price) == 0 || !numcheck(residental_sale_struct->sell_price)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_sale_struct->sell_price);
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 4);
        fflush(stdin);
    }
    fprintf(properties_file , "id : %s ," , g_property_id);
    sprintf(g_property_id, "%d", (atoi(g_property_id)+1));
    fprintf(properties_file , "type : 1 ,");
    fprintf(properties_file , "activity_status : on ,");
    fprintf(properties_file , "District : %s ," , residental_sale_struct->district);
    fprintf(properties_file , "Address : %s\n ," , residental_sale_struct->address);
    fprintf(properties_file , "Building type : %c ," , residental_sale_struct->building_type);
    fprintf(properties_file , "Age : %s ," , residental_sale_struct->age);
    fprintf(properties_file , "Built area : %s ," , residental_sale_struct->built_area);
    fprintf(properties_file , "Floor : %s ," , residental_sale_struct->floor);
    fprintf(properties_file , "Area : %s ," , residental_sale_struct->area);
    fprintf(properties_file , "Parking lot : %c ," , residental_sale_struct->parking_lot);
    fprintf(properties_file , "Depot : %c ," , residental_sale_struct->depot);
    fprintf(properties_file , "Elevator : %c ," , residental_sale_struct->elevator);
    fprintf(properties_file , "Air conditioning system : %c ," , residental_sale_struct->air_conditioning_system);
    fprintf(properties_file , "Accessibility : %c ," , residental_sale_struct->accessibility);
    fprintf(properties_file , "Rooms : %s ," , residental_sale_struct->rooms);
    fprintf(properties_file , "owner contact : %s ," , residental_sale_struct->owner_contact);
    fprintf(properties_file , "Sell price meter : %s ," , residental_sale_struct->sell_price_meter);
    fprintf(properties_file , "Sell price : %s ," , residental_sale_struct->sell_price);
    fprintf(properties_file , "Submitted by : %s ," , active_user->username);
    fprintf(properties_file , "Submit time : %d ," , time(NULL));
    fprintf(properties_file , "Archive time : %d ," , time(NULL));
    fprintf(properties_file , "Archive user : %s" , "NaN");
    fputs("\n" , properties_file);
    user_activity_count_update(active_user->username , 1);
    FILE *idf = fopen("global.txt" , "r+");
    rewind(idf);
    fprintf(idf , "id : %s" , g_property_id);
    fclose(idf);
    strcpy(g_message , "submit successful!");
    free(residental_sale_struct);
    fclose(properties_file);
}
void submit_residental_rent(){
    char verify[5]="no" ,message[] = "(**input Spaces are ignored!**)";
    FILE *properties_file = fopen("residental_rent.txt" , "a+");
    struct residental_rent_case *residental_rent_struct;
    residental_rent_struct = malloc(sizeof(struct residental_rent_case));
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Submit new Residential rent case----\n\n%*c||Please enter the required information:\n%*c||District :" , 45 , ' ',20 , ' ',20 , ' ');
        fsgets(residental_rent_struct->district , 5);
        if(strcmp(residental_rent_struct->district , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_rent_struct->district))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->district) == 0 || !lencheckalt(residental_rent_struct->district , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->district);
        /*----------------------------------------------*/
        printf("%*c||Address :" ,20 , ' ');
        fsgets(residental_rent_struct->address , 100);
        if(strcmp(residental_rent_struct->address , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_rent_struct->address))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->address) == 0 || !lencheckalt(residental_rent_struct->address , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->address);
        /*----------------------------------------------*/

        printf("%*c||Building type(1=villa , 2=Apartment) : ",20 , ' ');
        do
        {
            residental_rent_struct->building_type = getch();
        }while(residental_rent_struct->building_type != '1' && residental_rent_struct->building_type != '2');
        printf("%c\n" , residental_rent_struct->building_type);
        /*----------------------------------------------*/

        printf("%*c||Building age :" ,20 , ' ');
        fsgets(residental_rent_struct->age , 5);
        if(strcmp(residental_rent_struct->age , "0\n") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            break;
        }
        if(!numcheck(residental_rent_struct->age))
        {
            strcpy(g_message , "wrong format(age can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->age) == 0 || !lencheckalt(residental_rent_struct->age , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->age);
        /*----------------------------------------------*/
        printf("%*c||Built up area :" ,20 , ' ');
        fsgets(residental_rent_struct->built_area , 50);
        if(strcmp(residental_rent_struct->built_area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_rent_struct->built_area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->built_area) == 0 || !lencheckalt(residental_rent_struct->built_area , 49))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->built_area);
        /*----------------------------------------------*/
        printf("%*c||Floor :" ,20 , ' ');
        fsgets(residental_rent_struct->floor , 5);
        if(strcmp(residental_rent_struct->floor , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_rent_struct->floor))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->floor) == 0 || !lencheckalt(residental_rent_struct->floor , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->floor);
        /*----------------------------------------------*/

        printf("%*c||Area:" ,20 , ' ');
        fsgets(residental_rent_struct->area , 30);
        if(strcmp(residental_rent_struct->area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_rent_struct->area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->area) == 0 || !lencheckalt(residental_rent_struct->area , 29))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->area);
        /*----------------------------------------------*/
        printf("%*c||Has dedicated parking space (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            residental_rent_struct->parking_lot = getch();
        }while(residental_rent_struct->parking_lot != '1' && residental_rent_struct->parking_lot != '2');
        printf("%c\n" , residental_rent_struct->parking_lot);
        /*----------------------------------------------*/
        printf("%*c||Has dedicated depot (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            residental_rent_struct->depot = getch();
        }while(residental_rent_struct->depot != '1' && residental_rent_struct->depot != '2');
        printf("%c\n" , residental_rent_struct->depot);
        /*----------------------------------------------*/
        printf("%*c||Has elevator (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            residental_rent_struct->elevator = getch();
        }while(residental_rent_struct->elevator != '1' && residental_rent_struct->elevator != '2');
        printf("%c\n" , residental_rent_struct->elevator);
        printf("%*c||Has Air conditioning system (1 = no , 2 = only cooling , 3 = only heating , 4 = both) : ",20 , ' ');
        do
        {
            residental_rent_struct->air_conditioning_system = getch();
        }while(residental_rent_struct->air_conditioning_system != '1' && residental_rent_struct->air_conditioning_system != '2'
               && residental_rent_struct->air_conditioning_system != '3' && residental_rent_struct->air_conditioning_system != '4');
        printf("%c\n" , residental_rent_struct->air_conditioning_system);
        /*----------------------------------------------*/
        printf("%*c||Accessibility (1 = Bad , 2 = good, 3 = great) : ",20 , ' ');
        do
        {
            residental_rent_struct->accessibility = getch();
        }while(residental_rent_struct->accessibility != '1' && residental_rent_struct->accessibility != '2'
               && residental_rent_struct->accessibility != '3');
        printf("%c\n" , residental_rent_struct->accessibility);
        /*----------------------------------------------*/
        printf("%*c||Rooms :" ,20 , ' ');
        fsgets(residental_rent_struct->rooms , 5);
        if(strcmp(residental_rent_struct->rooms , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(residental_rent_struct->rooms))
        {
            strcpy(g_message , "wrong format(room count can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(residental_rent_struct->rooms) == 0 || !lencheckalt(residental_rent_struct->rooms , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->rooms);
        /*----------------------------------------------*/
        printf("%*c||Owner's phone number :" ,20 , ' ');
        fsgets(residental_rent_struct->owner_contact , 13);
        if(strcmp(residental_rent_struct->owner_contact , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(residental_rent_struct->owner_contact) != 11 || !numcheck(residental_rent_struct->owner_contact)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/
        printf("%*c||Mortgage price:" ,20 , ' ');
        fsgets(residental_rent_struct->mortgage_price ,15);
        if(strcmp(residental_rent_struct->mortgage_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(residental_rent_struct->mortgage_price) == 0 || !numcheck(residental_rent_struct->mortgage_price) || !lencheckalt(residental_rent_struct->mortgage_price , 14)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->mortgage_price);
        /*----------------------------------------------*/
        printf("%*c||Rent price :" ,20 , ' ');
        fsgets(residental_rent_struct->rent_price , 20);
        if(strcmp(residental_rent_struct->rent_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(residental_rent_struct->rent_price) == 0 || !numcheck(residental_rent_struct->rent_price) || !lencheckalt(residental_rent_struct->rent_price , 19)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(residental_rent_struct->rent_price);
        /*----------------------------------------------*/
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 5);
        fflush(stdin);;
    }
    fprintf(properties_file , "id : %s ," , g_property_id);
    sprintf(g_property_id, "%d", (atoi(g_property_id)+1));
    fprintf(properties_file , "type : 4 ,");
    fprintf(properties_file , "activity_status : on ,");
    fprintf(properties_file , "District : %s ," , residental_rent_struct->district);
    fprintf(properties_file , "Address : %s\n ," , residental_rent_struct->address);
    fprintf(properties_file , "Building type : %c ," , residental_rent_struct->building_type);
    fprintf(properties_file , "Age : %s ," , residental_rent_struct->age);
    fprintf(properties_file , "Built area : %s ," , residental_rent_struct->built_area);
    fprintf(properties_file , "Floor : %s ," , residental_rent_struct->floor);
    fprintf(properties_file , "Area : %s ," , residental_rent_struct->area);
    fprintf(properties_file , "Parking lot : %c ," , residental_rent_struct->parking_lot);
    fprintf(properties_file , "Depot : %c ," , residental_rent_struct->depot);
    fprintf(properties_file , "Elevator : %c ," , residental_rent_struct->elevator);
    fprintf(properties_file , "Air conditioning system : %c ," , residental_rent_struct->air_conditioning_system);
    fprintf(properties_file , "Accessibility : %c ," , residental_rent_struct->accessibility);
    fprintf(properties_file , "Rooms : %s ," , residental_rent_struct->rooms);
    fprintf(properties_file , "owner contact : %s ," , residental_rent_struct->owner_contact);
    fprintf(properties_file , "Mortgage price : %s ," , residental_rent_struct->mortgage_price);
    fprintf(properties_file , "Rent price : %s ," , residental_rent_struct->rent_price);
    fprintf(properties_file , "Submitted by : %s ," , active_user->username);
    fprintf(properties_file , "Submit time : %d ," , time(NULL));
    fprintf(properties_file , "Archive time : %d ," , time(NULL));
    fprintf(properties_file , "Archive user : %s" , "NaN");
    fputs("\n" , properties_file);
    strcpy(message , "submit successful!");
    user_activity_count_update(active_user->username , 1);
    free(residental_rent_struct);
    fclose(properties_file);
}
void submit_office_sale(){
    char verify[3]="no";
    strcpy(g_message , "Enter 0 as input to go back");
    FILE *properties_file = fopen("office_sale.txt" , "a+");
    struct office_sale_case *office_sale_struct;
    office_sale_struct = malloc(sizeof(struct office_sale_case));
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Submit new office sale case----\n\n%*c||Please enter the required information:\n%*c||District :" , 45 , ' ',20 , ' ',20 , ' ');
        fsgets(office_sale_struct->district , 5);
        if(strcmp(office_sale_struct->district , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_sale_struct->district))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_sale_struct->district) == 0 || !lencheckalt(office_sale_struct->district , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->district);
        /*----------------------------------------------*/
        printf("%*c||Address :" ,20 , ' ');
        fsgets(office_sale_struct->address , 100);
        if(strcmp(office_sale_struct->address , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(strlen(office_sale_struct->address) == 0 || !lencheckalt(office_sale_struct->address , 99))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/
        printf("%*c||Building type(1=with official certificate , 2=only official location) : ",20 , ' ');
        do{
            office_sale_struct->building_type = getch();
        }while(office_sale_struct->building_type != '1' && office_sale_struct->building_type != '2');
        printf("%c\n" , office_sale_struct->building_type);
        printf("%*c||Building age :" ,20 , ' ');
        fsgets(office_sale_struct->age , 5);
        if(strcmp(office_sale_struct->age , "0\n") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            break;
        }
        if(!numcheck(office_sale_struct->age))
        {
            strcpy(g_message , "wrong format(age can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_sale_struct->age) == 0 || !lencheckalt(office_sale_struct->age , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->age);
        /*----------------------------------------------*/

        printf("%*c||Built up area :" ,20 , ' ');
        fsgets(office_sale_struct->built_area , 50);
        if(strcmp(office_sale_struct->built_area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_sale_struct->built_area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_sale_struct->built_area) == 0 || !lencheckalt(office_sale_struct->built_area , 49))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->built_area);
        /*----------------------------------------------*/
        printf("%*c||Floor :" ,20 , ' ');
        fsgets(office_sale_struct->floor , 5);
        if(strcmp(office_sale_struct->floor , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_sale_struct->floor))
        {
            strcpy(g_message , "wrong format(floor can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_sale_struct->floor) == 0 || !lencheckalt(office_sale_struct->floor , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->floor);
        /*----------------------------------------------*/

        printf("%*c||Area:" ,20 , ' ');
        fsgets(office_sale_struct->area , 30);
        if(strcmp(office_sale_struct->area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_sale_struct->area))
        {
            strcpy(g_message , "wrong format(area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_sale_struct->area) == 0 || !lencheckalt(office_sale_struct->area , 29))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->area);
        /*----------------------------------------------*/
        printf("%*c||Has dedicated parking space (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            office_sale_struct->parking_lot = getch();
        }while(office_sale_struct->parking_lot != '1' && office_sale_struct->parking_lot != '2');
        printf("%c\n" , office_sale_struct->parking_lot);
        printf("%*c||Has dedicated depot (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            office_sale_struct->depot = getch();
        }while(office_sale_struct->depot != '1' && office_sale_struct->depot != '2');
        printf("%c\n" , office_sale_struct->depot);
        printf("%*c||Has elevator (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            office_sale_struct->elevator = getch();
        }while(office_sale_struct->elevator != '1' && office_sale_struct->elevator != '2');
        printf("%c\n" , office_sale_struct->elevator);
        printf("%*c||Has Air conditioning system (1 = no , 2 = only cooling , 3 = only heating , 4 = both) : ",20 , ' ');
        do
        {
            office_sale_struct->air_conditioning_system = getch();
        }while(office_sale_struct->air_conditioning_system != '1' && office_sale_struct->air_conditioning_system != '2'
               && office_sale_struct->air_conditioning_system != '3' && office_sale_struct->air_conditioning_system != '4');
        printf("%c\n" , office_sale_struct->air_conditioning_system);
        printf("%*c||Accessibility (1 = Bad , 2 = good, 3 = great) : ",20 , ' ');
        do
        {
            office_sale_struct->accessibility = getch();
        }while(office_sale_struct->accessibility != '1' && office_sale_struct->accessibility != '2'
               && office_sale_struct->accessibility != '3');
        printf("%c\n" , office_sale_struct->accessibility);
        printf("%*c||Office rooms :" ,20 , ' ');
        fsgets(office_sale_struct->rooms , 5);
        if(strcmp(office_sale_struct->rooms , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_sale_struct->rooms))
        {
            strcpy(g_message , "wrong format(room count can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_sale_struct->rooms) == 0 || !lencheckalt(office_sale_struct->rooms , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->rooms);
        /*----------------------------------------------*/

        printf("%*c||Owner's phone number :" ,20 , ' ');
        fsgets(office_sale_struct->owner_contact , 13);
        if(strcmp(office_sale_struct->owner_contact , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(office_sale_struct->owner_contact) != 11 || !numcheck(office_sale_struct->owner_contact)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/

        printf("%*c||Sell price per meter:" ,20 , ' ');
        fsgets(office_sale_struct->sell_price_meter , 15);
        if(strcmp(office_sale_struct->sell_price_meter , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(office_sale_struct->sell_price_meter) == 0 || !numcheck(office_sale_struct->sell_price_meter) || !lencheckalt(office_sale_struct->sell_price_meter , 14)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->sell_price_meter);
        printf("%*c||Sell price :" ,20 , ' ');
        /*----------------------------------------------*/

        fsgets(office_sale_struct->sell_price , 20);
        if(strcmp(office_sale_struct->sell_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(office_sale_struct->sell_price) == 0 || !numcheck(office_sale_struct->sell_price) || !lencheckalt(office_sale_struct->sell_price , 19)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(office_sale_struct->sell_price);
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 5);
        fflush(stdin);;
    }
    fprintf(properties_file , "id : %s ," , g_property_id);
    sprintf(g_property_id, "%d", (atoi(g_property_id)+1));
    fprintf(properties_file , "type : 2 ,");
    fprintf(properties_file , "activity_status : on ,");
    fprintf(properties_file , "District : %s ," , office_sale_struct->district);
    fprintf(properties_file , "Address : %s\n ," , office_sale_struct->address);
    fprintf(properties_file , "Building type : %c ," , office_sale_struct->building_type);
    fprintf(properties_file , "Age : %s ," , office_sale_struct->age);
    fprintf(properties_file , "Built area : %s ," , office_sale_struct->built_area);
    fprintf(properties_file , "Floor : %s ," , office_sale_struct->floor);
    fprintf(properties_file , "Area : %s ," , office_sale_struct->area);
    fprintf(properties_file , "Parking lot : %c ," , office_sale_struct->parking_lot);
    fprintf(properties_file , "Depot : %c ," , office_sale_struct->depot);
    fprintf(properties_file , "Elevator : %c ," , office_sale_struct->elevator);
    fprintf(properties_file , "Air conditioning system : %c ," , office_sale_struct->air_conditioning_system);
    fprintf(properties_file , "Accessibility : %c ," , office_sale_struct->accessibility);
    fprintf(properties_file , "Rooms : %s ," , office_sale_struct->rooms);
    fprintf(properties_file , "owner contact : %s ," , office_sale_struct->owner_contact);
    fprintf(properties_file , "Sell price meter : %s ," , office_sale_struct->sell_price_meter);
    fprintf(properties_file , "Sell price : %s ," , office_sale_struct->sell_price);
    fprintf(properties_file , "Submitted by : %s ," , active_user->username);
    fprintf(properties_file , "Submit time : %d ," , time(NULL));
    fprintf(properties_file , "Archive time : %d ," , time(NULL));
    fprintf(properties_file , "Archive user : %s" , "NaN");
    fputs("\n" , properties_file);
    user_activity_count_update(active_user->username , 1);
    strcpy(g_message , "submit successful!");
    free(office_sale_struct);
    fclose(properties_file);
}
void submit_office_rent(){
    char verify[5]="no";
    FILE *properties_file = fopen("office_rent.txt" , "a+");
    strcpy(g_message , "enter 0 as password to go back.");
    struct office_rent_case *office_rent_struct;
    office_rent_struct = malloc(sizeof(struct office_rent_case));
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Submit new Office rent case----\n\n%*c||Please enter the required information:\n%*c||District :" , 45 , ' ',20 , ' ',20 , ' ');
        fsgets(office_rent_struct->district , 5);
        if(strcmp(office_rent_struct->district , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_rent_struct->district))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_rent_struct->district) == 0 || !lencheckalt(office_rent_struct->district , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->district);
        /*----------------------------------------------*/
        printf("%*c||Address :" ,20 , ' ');
        fsgets(office_rent_struct->address , 100);
        if(strcmp(office_rent_struct->address , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(strlen(office_rent_struct->address) == 0 || !lencheckalt(office_rent_struct->address , 99))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/
        printf("%*c||Building type(1=villa , 2=Apartment) : ",20 , ' ');
        do
        {
            office_rent_struct->building_type = getch();
        }while(office_rent_struct->building_type != '1' && office_rent_struct->building_type != '2');
        printf("%c\n" , office_rent_struct->building_type);
        /*----------------------------------------------*/


        printf("%*c||Building age :" ,20 , ' ');
        fsgets(office_rent_struct->age , 5);
        if(strcmp(office_rent_struct->age , "0\n") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            break;
        }
        if(!numcheck(office_rent_struct->age))
        {
            strcpy(g_message , "wrong format(age can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_rent_struct->age) == 0 || !lencheckalt(office_rent_struct->age , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->age);
        /*----------------------------------------------*/
        printf("%*c||Built up area :" ,20 , ' ');
        fsgets(office_rent_struct->built_area , 50);
        if(strcmp(office_rent_struct->built_area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_rent_struct->built_area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_rent_struct->built_area) == 0 || !lencheckalt(office_rent_struct->built_area , 49))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->built_area);
        /*----------------------------------------------*/
        printf("%*c||Floor :" ,20 , ' ');
        fsgets(office_rent_struct->floor , 5);
        if(strcmp(office_rent_struct->floor , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_rent_struct->floor))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_rent_struct->floor) == 0 || !lencheckalt(office_rent_struct->floor , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->floor);
        /*----------------------------------------------*/

        printf("%*c||Area:" ,20 , ' ');
        fsgets(office_rent_struct->area , 30);
        if(strcmp(office_rent_struct->area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_rent_struct->area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_rent_struct->area) == 0 || !lencheckalt(office_rent_struct->area , 29))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->area);
        /*----------------------------------------------*/
        printf("%*c||Has dedicated parking space (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            office_rent_struct->parking_lot = getch();
        }while(office_rent_struct->parking_lot != '1' && office_rent_struct->parking_lot != '2');
        printf("%c\n" , office_rent_struct->parking_lot);
        printf("%*c||Has dedicated depot (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            office_rent_struct->depot = getch();
        }while(office_rent_struct->depot != '1' && office_rent_struct->depot != '2');
        printf("%c\n" , office_rent_struct->depot);
        printf("%*c||Has elevator (1 = yes , 2 = no) : ",20 , ' ');
        do
        {
            office_rent_struct->elevator = getch();
        }while(office_rent_struct->elevator != '1' && office_rent_struct->elevator != '2');
        printf("%c\n" , office_rent_struct->elevator);
        printf("%*c||Has Air conditioning system (1 = no , 2 = only cooling , 3 = only heating , 4 = both) : ",20 , ' ');
        do
        {
            office_rent_struct->air_conditioning_system = getch();
        }while(office_rent_struct->air_conditioning_system != '1' && office_rent_struct->air_conditioning_system != '2'
               && office_rent_struct->air_conditioning_system != '3' && office_rent_struct->air_conditioning_system != '4');
        printf("%c\n" , office_rent_struct->air_conditioning_system);
        printf("%*c||Accessibility (1 = Bad , 2 = good, 3 = great) : ",20 , ' ');
        do
        {
            office_rent_struct->accessibility = getch();
        }while(office_rent_struct->accessibility != '1' && office_rent_struct->accessibility != '2'
               && office_rent_struct->accessibility != '3');
        printf("%c\n" , office_rent_struct->accessibility);

        printf("%*c||Rooms :" ,20 , ' ');
        fsgets(office_rent_struct->rooms , 5);
        if(strcmp(office_rent_struct->rooms , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(office_rent_struct->rooms))
        {
            strcpy(g_message , "wrong format(room count can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(office_rent_struct->rooms) == 0 || !lencheckalt(office_rent_struct->rooms , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->rooms);
        /*----------------------------------------------*/
        printf("%*c||Owner's phone number :" ,20 , ' ');
        fsgets(office_rent_struct->owner_contact , 13);
        if(strcmp(office_rent_struct->owner_contact , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(office_rent_struct->owner_contact) != 11 || !numcheck(office_rent_struct->owner_contact)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }

        /*----------------------------------------------*/
        printf("%*c||Mortgage price:" ,20 , ' ');
        fsgets(office_rent_struct->mortgage_price ,15);
        if(strcmp(office_rent_struct->mortgage_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(office_rent_struct->mortgage_price) == 0 || !numcheck(office_rent_struct->mortgage_price) || !lencheckalt(office_rent_struct->mortgage_price , 14)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->mortgage_price);
        /*----------------------------------------------*/
        printf("%*c||Rent price :" ,20 , ' ');
        fsgets(office_rent_struct->rent_price , 20);
        if(strcmp(office_rent_struct->rent_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(office_rent_struct->rent_price) == 0 || !numcheck(office_rent_struct->rent_price) || !lencheckalt(office_rent_struct->rent_price , 19)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(office_rent_struct->rent_price);
        /*----------------------------------------------*/
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 5);
        fflush(stdin);;
    }
    fprintf(properties_file , "id : %s ," , g_property_id);
    sprintf(g_property_id, "%d", (atoi(g_property_id)+1));
    fprintf(properties_file , "type : 5 ,");
    fprintf(properties_file , "activity_status : on ,");
    fprintf(properties_file , "District : %s ," , office_rent_struct->district);
    fprintf(properties_file , "Address : %s\n ," , office_rent_struct->address);
    fprintf(properties_file , "Building type : %c ," , office_rent_struct->building_type);
    fprintf(properties_file , "Age : %s ," , office_rent_struct->age);
    fprintf(properties_file , "Built area : %s ," , office_rent_struct->built_area);
    fprintf(properties_file , "Floor : %s ," , office_rent_struct->floor);
    fprintf(properties_file , "Area : %s ," , office_rent_struct->area);
    fprintf(properties_file , "Parking lot : %c ," , office_rent_struct->parking_lot);
    fprintf(properties_file , "Depot : %c ," , office_rent_struct->depot);
    fprintf(properties_file , "Elevator : %c ," , office_rent_struct->elevator);
    fprintf(properties_file , "Air conditioning system : %c ," , office_rent_struct->air_conditioning_system);
    fprintf(properties_file , "Accessibility : %c ," , office_rent_struct->accessibility);
    fprintf(properties_file , "Rooms : %s ," , office_rent_struct->rooms);
    fprintf(properties_file , "owner contact : %s ," , office_rent_struct->owner_contact);
    fprintf(properties_file , "Mortgage price : %s ," , office_rent_struct->mortgage_price);
    fprintf(properties_file , "Rent price : %s ," , office_rent_struct->rent_price);
    fprintf(properties_file , "Submitted by : %s ," , active_user->username);
    fprintf(properties_file , "Submit time : %d ," , time(NULL));
    fprintf(properties_file , "Archive time : %d ," , time(NULL));
    fprintf(properties_file , "Archive user : %s" , "NaN");
    fputs("\n" , properties_file);
    user_activity_count_update(active_user->username , 1);
    strcpy(g_message , "submit successful!");
    free(office_rent_struct);
    fclose(properties_file);
}
void submit_land_sale(){
    char verify[3]="no";
    FILE *properties_file = fopen("land_sale.txt" , "a+");
    struct land_sale_case *land_sale_struct;
    land_sale_struct = malloc(sizeof(struct land_sale_case));
    strcpy(g_message , "Enter 0 as input to go back");
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Submit new Land sale case----\n\n%*c||Please enter the required information:\n%*c||District :" , 45 , ' ',20 , ' ',20 , ' ');
        fsgets(land_sale_struct->district , 5);
        if(strcmp(land_sale_struct->district , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(land_sale_struct->district))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(land_sale_struct->district) == 0 || !lencheckalt(land_sale_struct->district , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(land_sale_struct->district);
        /*----------------------------------------------*/
        printf("%*c||Address :" ,20 , ' ');
        fsgets(land_sale_struct->address , 100);
        if(strcmp(land_sale_struct->address , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(strlen(land_sale_struct->address) == 0 || !lencheckalt(land_sale_struct->address , 99))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/

        printf("%*c||land type (1=farm , 2=city) : ",20 , ' ');
        do
        {
            land_sale_struct->building_type = getch();
        }while(land_sale_struct->building_type != '1' && land_sale_struct->building_type != '2');
        printf("%c\n" , land_sale_struct->building_type);
        printf("%*c||Has construction permittion (1=yes , 2=no) : " ,20 , ' ');
        do{
            land_sale_struct->construct_permit = getch();
        }while(land_sale_struct->construct_permit != '1' && land_sale_struct->construct_permit != '2');
        printf("%c\n" , land_sale_struct->construct_permit);
        printf("%*c||Accessibility (1 = Bad , 2 = good, 3 = great) : ",20 , ' ');
        do
        {
            land_sale_struct->accessibility = getch();
        }while(land_sale_struct->accessibility != '1' && land_sale_struct->accessibility != '2'
               && land_sale_struct->accessibility != '3');
        printf("%c\n" , land_sale_struct->accessibility);
        printf("%*c||Distance from nearest city:" ,20 , ' ');
        fsgets(land_sale_struct->distance_from_city , 20);
        normalizer(land_sale_struct->distance_from_city);
        if(strlen(land_sale_struct->distance_from_city) == 0 || !lencheckalt(land_sale_struct->distance_from_city , 19))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        /*-------------------------------------*/
        printf("%*c||Area:" ,20 , ' ');

        fsgets(land_sale_struct->area , 30);
        if(strcmp(land_sale_struct->area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(land_sale_struct->area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(land_sale_struct->area) == 0 || !lencheckalt(land_sale_struct->area , 29))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(land_sale_struct->area);
        /*----------------------------------------------*/
        printf("%*c||Owner's phone number :" ,20 , ' ');
        fsgets(land_sale_struct->owner_contact , 13);
        if(strcmp(land_sale_struct->owner_contact , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(land_sale_struct->owner_contact) != 11 || !numcheck(land_sale_struct->owner_contact)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/

        printf("%*c||Sell price per meter:" ,20 , ' ');
        fsgets(land_sale_struct->sell_price_meter , 15);
        if(strcmp(land_sale_struct->sell_price_meter , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(land_sale_struct->sell_price_meter) == 0 || !numcheck(land_sale_struct->sell_price_meter) || !lencheckalt(land_sale_struct->sell_price_meter , 14)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(land_sale_struct->sell_price_meter);
        printf("%*c||Sell price :" ,20 , ' ');
        /*----------------------------------------------*/

        fsgets(land_sale_struct->sell_price , 20);
        if(strcmp(land_sale_struct->sell_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(land_sale_struct->sell_price) == 0 || !numcheck(land_sale_struct->sell_price) || !lencheckalt(land_sale_struct->sell_price , 19)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(land_sale_struct->sell_price);
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 5);
        fflush(stdin);;
    }
    fprintf(properties_file , "id : %s ," , g_property_id);
    sprintf(g_property_id, "%d", (atoi(g_property_id)+1));
    fprintf(properties_file , "type : 3 ,");
    fprintf(properties_file , "activity_status : on ,");
    fprintf(properties_file , "District : %s ," , land_sale_struct->district);
    fprintf(properties_file , "Address : %s\n ," , land_sale_struct->address);
    fprintf(properties_file , "Building type : %c ," , land_sale_struct->building_type);
    fprintf(properties_file , "Construct permition : %c ," , land_sale_struct->construct_permit);
    fprintf(properties_file , "Accessibility : %c ," , land_sale_struct->accessibility);
    fprintf(properties_file , "Distance from city : %s ," , land_sale_struct->distance_from_city);
    fprintf(properties_file , "Area : %s ," , land_sale_struct->area);
    fprintf(properties_file , "owner contact : %s ," , land_sale_struct->owner_contact);
    fprintf(properties_file , "Sell price : %s ," , land_sale_struct->sell_price);
    fprintf(properties_file , "Sell price meter: %s ," , land_sale_struct->sell_price_meter);
    fprintf(properties_file , "Submitted by : %s ," , active_user->username);
    fprintf(properties_file , "Submit time : %d ," , time(NULL));
    fprintf(properties_file , "Archive time : %d ," , time(NULL));
    fprintf(properties_file , "Archive user : %s" , "NaN");
    fputs("\n" , properties_file);
    user_activity_count_update(active_user->username , 1);
    strcpy(g_message , "submit successful!");
    free(land_sale_struct);
    fclose(properties_file);
}
void submit_land_rent(){
    char verify[3]="no" ;
    FILE *properties_file = fopen("land_rent.txt" , "a+");
    strcpy(g_message , "enter 0 as input to go back.");
    struct land_rent_case *land_rent_struct;
    land_rent_struct = malloc(sizeof(struct land_rent_case));
    while(strcmp(strlwr(verify) , "yes") != 0 && strcmp(strlwr(verify) , "y") != 0)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Submit new Land rent case----\n\n%*c||Please enter the required information:\n%*c||District :" , 45 , ' ',20 , ' ',20 , ' ');
        fsgets(land_rent_struct->district , 5);
        if(strcmp(land_rent_struct->district , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(land_rent_struct->district))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(land_rent_struct->district) == 0 || !lencheckalt(land_rent_struct->district , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(land_rent_struct->district);
        /*----------------------------------------------*/
        printf("%*c||Address :" ,20 , ' ');
        fsgets(land_rent_struct->address , 100);
        if(strcmp(land_rent_struct->address , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(land_rent_struct->address))
        {
            strcpy(g_message , "wrong format(district can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(land_rent_struct->address) == 0 || !lencheckalt(land_rent_struct->address , 4))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        /*----------------------------------------------*/
        printf("%*c||land type (1=farm , 2=city) : ",20 , ' ');
        do
        {
            land_rent_struct->building_type = getch();
        }while(land_rent_struct->building_type != '1' && land_rent_struct->building_type != '2');
        printf("%c\n" , land_rent_struct->building_type);
        printf("%*c||Has construction permittion (1=yes , 2=no) : " ,20 , ' ');
        do{
            land_rent_struct->construct_permit = getch();
        }while(land_rent_struct->construct_permit != '1' && land_rent_struct->construct_permit != '2');
        printf("%c\n" , land_rent_struct->construct_permit);
        printf("%*c||Accessibility (1 = Bad , 2 = good, 3 = great) : ",20 , ' ');
        do
        {
            land_rent_struct->accessibility = getch();
        }while(land_rent_struct->accessibility != '1' && land_rent_struct->accessibility != '2'
               && land_rent_struct->accessibility != '3');
        printf("%c\n" , land_rent_struct->accessibility);
        printf("%*c||Distance from nearest city:" ,20 , ' ');
        fsgets(land_rent_struct->distance_from_city , 20);
        printf("%*c||Area:" ,20 , ' ');
        fsgets(land_rent_struct->area , 30);
        if(strcmp(land_rent_struct->area , "0") == 0)
        {
            strcpy(g_message , "Welcome!");
            fflush(stdin);
            return;
        }
        if(!numcheck(land_rent_struct->area))
        {
            strcpy(g_message , "wrong format(built area can't contain alphabet)!");
            fflush(stdin);
            continue;
        }
        if(strlen(land_rent_struct->area) == 0 || !lencheckalt(land_rent_struct->area , 29))
        {
            strcpy(g_message , "input length not allowed!");
            fflush(stdin);
            continue;
        }
        normalizer(land_rent_struct->area);
        /*----------------------------------------------*/
        printf("%*c||Owner's phone number :" ,20 , ' ');
        fsgets(land_rent_struct->owner_contact , 13);
        if(strcmp(land_rent_struct->owner_contact , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(land_rent_struct->owner_contact) != 11 || !numcheck(land_rent_struct->owner_contact)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }

        /*----------------------------------------------*/
        printf("%*c||Mortgage price:" ,20 , ' ');
        fsgets(land_rent_struct->mortgage_price ,15);
        if(strcmp(land_rent_struct->mortgage_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(land_rent_struct->mortgage_price) == 0 || !numcheck(land_rent_struct->mortgage_price) || !lencheckalt(land_rent_struct->mortgage_price , 14)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(land_rent_struct->mortgage_price);
        /*----------------------------------------------*/
        printf("%*c||Rent price :" ,20 , ' ');
        fsgets(land_rent_struct->rent_price , 20);
        if(strcmp(land_rent_struct->rent_price , "0") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (strlen(land_rent_struct->rent_price) == 0 || !numcheck(land_rent_struct->rent_price) || !lencheckalt(land_rent_struct->rent_price , 19)) {
            strcpy(g_message , "wrong format!");
            fflush(stdin);
            continue;
        }
        normalizer(land_rent_struct->rent_price);
        /*----------------------------------------------*/
        printf("%*c||is the information above verified by you ? (yes/no):",20 , ' ');
        fsgets(verify , 5);
        fflush(stdin);
    }
    fprintf(properties_file , "id : %s ," , g_property_id);
    sprintf(g_property_id, "%d", (atoi(g_property_id)+1));
    fprintf(properties_file , "type : 6 ,");
    fprintf(properties_file , "activity_status : on ,");
    fprintf(properties_file , "District : %s ," , land_rent_struct->district);
    fprintf(properties_file , "Address : %s\n ," , land_rent_struct->address);
    fprintf(properties_file , "Building type : %c ," , land_rent_struct->building_type);
    fprintf(properties_file , "Construct permition : %c ," , land_rent_struct->construct_permit);
    fprintf(properties_file , "Accessibility : %c ," , land_rent_struct->accessibility);
    fprintf(properties_file , "Distance from city : %s ," , land_rent_struct->distance_from_city);
    fprintf(properties_file , "Area : %s ," , land_rent_struct->area);
    fprintf(properties_file , "owner contact : %s ," , land_rent_struct->owner_contact);
    fprintf(properties_file , "Mortgage price : %s ," , land_rent_struct->mortgage_price);
    fprintf(properties_file , "Rent price : %s ," , land_rent_struct->rent_price);
    fprintf(properties_file , "Submitted by : %s ," , active_user->username);
    fprintf(properties_file , "Submit time : %u ," , time(NULL));
    fprintf(properties_file , "Archive time : %u ," , time(NULL));
    fprintf(properties_file , "Archive user : %s" , "NaN");
    fputs("\n" , properties_file);
    user_activity_count_update(active_user->username , 1);
    strcpy(g_message , "submit successful!");
    free(land_rent_struct);
    fclose(properties_file);
}
struct residental_sale_case* initialize_cases_resell(struct residental_sale_case *start)
{
    FILE *casefile = fopen("residental_sale.txt" , "r+");
    struct residental_sale_case *temp , *end;
    end = start;
    rewind(casefile);
    while(feof(casefile) == 0)
    {
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Sell price meter : %s ," , &end->sell_price_meter);
        fscanf(casefile , "Sell price : %s ," , &end->sell_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %u ," , &end->submit_time);
        fscanf(casefile , "Archive time : %u ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        fgetc(casefile);
        temp = malloc(sizeof(struct residental_sale_case));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(casefile);
    return end;
}
struct office_sale_case* initialize_cases_ofsell(struct office_sale_case *start)
{
    FILE *casefile = fopen("office_sale.txt" , "r");
    struct office_sale_case *temp , *end;
    end = start;
    rewind(casefile);
    while(feof(casefile) == 0)
    {
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Sell price meter : %s ," , &end->sell_price_meter);
        fscanf(casefile , "Sell price : %s ," , &end->sell_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %u ," , &end->submit_time);
        fscanf(casefile , "Archive time : %u ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        fgetc(casefile);
        temp = malloc(sizeof(struct office_sale_case));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(casefile);
    return end;
}
struct land_sale_case* initialize_cases_lasell(struct land_sale_case *start)
{
    FILE *casefile = fopen("land_sale.txt" , "r");
    struct land_sale_case *temp , *end;
    end = start;
    rewind(casefile);
    while(feof(casefile) == 0)
    {
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Construct permition : %c ," , &end->construct_permit);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Distance from city : %s ," , &end->distance_from_city);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Sell price : %s ," , &end->sell_price);
        fscanf(casefile , "Sell price meter : %s ," , &end->sell_price_meter);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %u ," , &end->submit_time);
        fscanf(casefile , "Archive time : %u ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        fgetc(casefile);
        temp = malloc(sizeof(struct land_sale_case));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(casefile);
    return end;
}
struct residental_rent_case* initialize_cases_rerent(struct residental_rent_case *start)
{
    FILE *casefile = fopen("residental_rent.txt" , "r");
    struct residental_rent_case *temp , *end;
    end = start;
    rewind(casefile);
    while(feof(casefile) == 0)
    {
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Mortgage price : %s ," , &end->mortgage_price);
        fscanf(casefile , "Rent price : %s ," , &end->rent_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %u ," , &end->submit_time);
        fscanf(casefile , "Archive time : %u ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        fgetc(casefile);
        temp = malloc(sizeof(struct residental_rent_case));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(casefile);
    return end;
}
struct office_rent_case* initialize_cases_ofrent(struct office_rent_case *start)
{
    FILE *casefile = fopen("office_rent.txt" , "r");
    struct office_rent_case *temp , *end;
    end = start;
    rewind(casefile);
    while(feof(casefile) == 0)
    {
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Mortgage price : %s ," , &end->mortgage_price);
        fscanf(casefile , "Rent price : %s ," , &end->rent_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %u ," , &end->submit_time);
        fscanf(casefile , "Archive time : %u ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        fgetc(casefile);
        temp = malloc(sizeof(struct office_rent_case));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(casefile);
    return end;
}
struct land_rent_case* initialize_cases_larent(struct land_rent_case *start)
{
    FILE *casefile = fopen("land_rent.txt" , "r");
    struct land_rent_case *temp , *end;
    end = start;
    rewind(casefile);
    while(feof(casefile) == 0)
    {
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Construct permition : %c ," , &end->construct_permit);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Distance from city : %s ," , &end->distance_from_city);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Mortgage price : %s ," , &end->mortgage_price);
        fscanf(casefile , "Rent price : %s ," , &end->rent_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %u ," , &end->submit_time);
        fscanf(casefile , "Archive time : %u ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        fgetc(casefile);
        temp = malloc(sizeof(struct land_rent_case));
        end->next = temp;
        temp->next = NULL;
        end=temp;
    }
    fclose(casefile);
    return end;
}
void active_case_counter()
{
    cleanHeader(g_access_lvl , g_message);
    int count = 0 , allcount= 0;
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    struct land_sale_case *start_lasell ,*slink5;
    struct land_rent_case *start_larent ,*slink6;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    while(1)
    {
        if(strcmp(slink1->status , "on") == 0)
        {
            count++;
        }
        free(slink1);
        slink1 = slink1->next;

        if(slink1  ->next == NULL)
        {
            break;
        }
    }
    allcount += count;
    printf("%*c----Active cases----\n\n%*c||residental for sell : %d" , 45 , ' ',20 , ' ',count);
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    count=0;
    while(1)
    {
        if(strcmp(slink2->status , "on") == 0)
        {
            count++;
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    allcount += count;
    printf("\n%*c||residental for rent : %d" , 20 , ' ' , count);
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    count=0;
    while(1)
    {
        if(strcmp(slink3->status , "on") == 0)
        {
            count++;
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    allcount += count;
    printf("\n%*c||office for sell : %d" ,  20 , ' ' , count);
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    count=0;
    while(1)
    {
        if(strcmp(slink4->status , "on") == 0)
        {
            count++;
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
    allcount += count;
    printf("\n%*c||office for rent : %d" , 20 , ' ' , count);
    start_lasell = malloc(sizeof(struct land_sale_case));
    slink5 = initialize_cases_lasell(start_lasell);
    slink5 = start_lasell;
    count=0;
    while(1)
    {
        if(strcmp(slink5->status , "on") == 0)
        {
            count++;
        }
        free(slink5);
        slink5 = slink5->next;
        if(slink5->next == NULL)
        {
            break;
        }
    }
    allcount += count;
    printf("\n%*c||land for sell : %d" ,  20 , ' ' , count);
    start_larent = malloc(sizeof(struct land_rent_case));
    slink6 = initialize_cases_larent(start_larent);
    slink6 = start_larent;
    count=0;
    while(1)
    {
        if(strcmp(slink6->status , "on") == 0)
        {
            count++;
        }
        free(slink6);
        slink6 = slink6->next;
        if(slink6->next == NULL)
        {
            break;
        }
    }
    allcount += count;
    printf("\n%*c||land for rent : %d" ,  20 , ' ' , count);
    printf("\n%*c||all propeties : %d" ,  20 , ' ' , allcount);
    getch();
}
void delete_residental_sale()
{
    char input_id[5];
    int pos;
    FILE *casefile = fopen("residental_sale.txt" , "r+");
    if(casefile == NULL)
    {
        printf("error");
    }
    rewind(casefile);
    struct residental_sale_case *end;
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Delete case by id----\n\n%*cEnter the case id you want to delete >>>"
                    , 45 , ' ', 40 , ' ');
    fsgets(input_id , 5);
    while(1)
    {
        end = malloc(sizeof(struct residental_sale_case));
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        pos = ftell(casefile);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Sell price meter : %s ," , &end->sell_price_meter);
        fscanf(casefile , "Sell price : %s ," , &end->sell_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %d ," , &end->submit_time);
        if(strcmp(end->id , input_id) == 0)
        {
            if(strcmp(end->status , "on") == 0)
            {
                fseek(casefile , 0 , SEEK_CUR);
                fprintf(casefile , "Archive time : %d ," , time(NULL));
                fprintf(casefile , "Archive user : %s" , active_user->username);
                fseek(casefile , pos , SEEK_SET);
                fprintf(casefile , "activity_status : of ,");
                fclose(casefile);
                strcpy(g_message , "Case removed successfully");
                user_activity_count_update(active_user->username , 0);
                break;
            }
        }
        fscanf(casefile , "Archive time : %d ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        if(feof(casefile))
        {
            strcpy(g_message , "Didn't find the case - check the id to be correct.");
            break;
        }
        free(end);
        fgetc(casefile);
    }
    fclose(casefile);
}
void delete_residental_rent()
{
    char input_id[5];
    int pos;
    FILE *casefile = fopen("residental_rent.txt" , "r+");
    if(casefile == NULL)
    {
        printf("error");
    }
    rewind(casefile);
    struct residental_rent_case *end;
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Delete case by id----\n\n%*cEnter the case id you want to delete >>>"
                    , 45 , ' ', 40 , ' ');
    fsgets(input_id , 5);
    fflush(stdin);
    while(1)
    {
        end = malloc(sizeof(struct residental_rent_case));
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        pos = ftell(casefile);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Mortgage price : %s ," , &end->mortgage_price);
        fscanf(casefile , "Rent price : %s ," , &end->rent_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %d ," , &end->submit_time);
        if(strcmp(end->id , input_id) == 0)
        {
            if(strcmp(end->status , "on") == 0)
            {
                fseek(casefile , 0 , SEEK_CUR);
                fprintf(casefile , "Archive time : %d ," , time(NULL));
                fprintf(casefile , "Archive user : %s" , active_user->username);
                fseek(casefile , pos , SEEK_SET);
                fprintf(casefile , "activity_status : of ,");
                user_activity_count_update(active_user->username , 0);
                fclose(casefile);
                strcpy(g_message , "Case removed successfully");
                break;
            }
        }
        fscanf(casefile , "Archive time : %d ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        if(feof(casefile) != 0)
        {
            strcpy(g_message , "Didn't find the case - check the id to be correct.");
            break;
        }
        free(end);
        fgetc(casefile);
    }
    fclose(casefile);
}
void delete_office_sale()
{
    char input_id[5];
    int pos;
    FILE *casefile = fopen("office_sale.txt" , "r+");
    if(casefile == NULL)
    {
        printf("error");
    }
    rewind(casefile);
    struct office_sale_case *end;
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Delete case by id----\n\n%*cEnter the case id you want to delete >>>"
                    , 45 , ' ', 40 , ' ');
    fsgets(input_id ,5);
    fflush(stdin);
    while(1)
    {
        end = malloc(sizeof(struct office_sale_case));
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        pos = ftell(casefile);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Sell price meter : %s ," , &end->sell_price_meter);
        fscanf(casefile , "Sell price : %s ," , &end->sell_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %d ," , &end->submit_time);
        if(strcmp(end->id , input_id) == 0)
        {
            if(strcmp(end->status , "on") == 0)
            {
                fseek(casefile , 0 , SEEK_CUR);
                fprintf(casefile , "Archive time : %d ," , time(NULL));
                fprintf(casefile , "Archive user : %s" , active_user->username);
                fseek(casefile , pos , SEEK_SET);
                fprintf(casefile , "activity_status : of ,");
                fclose(casefile);
                strcpy(g_message , "Case removed successfully");
                user_activity_count_update(active_user->username , 0);
                break;
            }
        }
        fscanf(casefile , "Archive time : %d ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        if(feof(casefile) != 0)
        {
            strcpy(g_message , "Didn't find the case - check the id to be correct.");
            break;
        }
        free(end);
        fgetc(casefile);
    }
    fclose(casefile);
}
void delete_office_rent()
{
    char input_id[5];
    int pos;
    FILE *casefile = fopen("office_rent.txt" , "r+");
    if(casefile == NULL)
    {
        printf("error");
    }
    rewind(casefile);
    struct office_rent_case *end;
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Delete case by id----\n\n%*cEnter the case id you want to delete >>>"
                    , 45 , ' ', 40 , ' ');
    fsgets(input_id , 5);
    fflush(stdin);
    while(1)
    {
        end = malloc(sizeof(struct office_rent_case));
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        pos = ftell(casefile);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Age : %s ," , &end->age);
        fscanf(casefile , "Built area : %s ," , &end->built_area);
        fscanf(casefile , "Floor : %s ," , &end->floor);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "Parking lot : %c ," , &end->parking_lot);
        fscanf(casefile , "Depot : %c ," , &end->depot);
        fscanf(casefile , "Elevator : %c ," , &end->elevator);
        fscanf(casefile , "Air conditioning system : %c ," , &end->air_conditioning_system);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Rooms : %s ," , &end->rooms);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Mortgage price : %s ," , &end->mortgage_price);
        fscanf(casefile , "Rent price : %s ," , &end->rent_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %d ," , &end->submit_time);
        if(strcmp(end->id , input_id) == 0)
        {
            if(strcmp(end->status , "on") == 0)
            {
                fseek(casefile , 0 , SEEK_CUR);
                fprintf(casefile , "Archive time : %d ," , time(NULL));
                fprintf(casefile , "Archive user : %s\n" , active_user->username);
                fseek(casefile , pos , SEEK_SET);
                fprintf(casefile , "activity_status : of ,");
                fclose(casefile);
                strcpy(g_message , "Case removed successfully");
                user_activity_count_update(active_user->username , 0);
                break;
            }
        }
        fscanf(casefile , "Archive time : %d ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        if(feof(casefile) != 0)
        {
            strcpy(g_message , "Didn't find the case - check the id to be correct.");
            break;
        }
        free(end);
        fgetc(casefile);
    }
    fclose(casefile);
}
void delete_land_sale()
{
    char input_id[5];
    int pos;
    FILE *casefile = fopen("land_sale.txt" , "r+");
    if(casefile == NULL)
    {
        printf("error");
    }
    rewind(casefile);
    struct land_sale_case *end;
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Delete case by id----\n\n%*cEnter the case id you want to delete >>>"
                    , 45 , ' ', 40 , ' ');
    fsgets(input_id , 5);
    fflush(stdin);
    while(1)
    {
        end = malloc(sizeof(struct land_sale_case));
        fscanf(casefile , "id : %s ," , &end->id);
        //printf("%s" , end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        pos = ftell(casefile);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Construct permition : %c ," , &end->construct_permit);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Distance from city : %s ," , &end->distance_from_city);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Sell price : %s ," , &end->sell_price_meter);
        fscanf(casefile , "Sell price meter: %s ," , &end->sell_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %d ," , &end->submit_time);
        if(strcmp(end->id , input_id) == 0)
        {
            if(strcmp(end->status , "on") == 0)
            {
                fseek(casefile , 0 , SEEK_CUR);
                fprintf(casefile , "Archive time : %d ," , time(NULL));
                fprintf(casefile , "Archive user : %s" , active_user->username);
                fseek(casefile , pos , SEEK_SET);
                fprintf(casefile , "activity_status : of ,");
                fclose(casefile);
                strcpy(g_message , "Case removed successfully");
                user_activity_count_update(active_user->username , 0);
                break;
            }
        }
        fscanf(casefile , "Archive time : %d ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        if(feof(casefile))
        {
            strcpy(g_message , "Didn't find the case - check the id to be correct.");
            break;
        }
        free(end);
        fgetc(casefile);
    }
    fclose(casefile);
}
void delete_land_rent()
{
    char input_id[5];
    int pos;
    FILE *casefile = fopen("land_rent.txt" , "r+");
    if(casefile == NULL)
    {
        printf("error");
    }
    rewind(casefile);
    struct land_rent_case *end;
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Delete case by id----\n\n%*cEnter the case id you want to delete >>>"
                    , 45 , ' ', 40 , ' ');
    fsgets(input_id , 5);
    fflush(stdin);
    while(1)
    {
        end = malloc(sizeof(struct land_rent_case));
        fscanf(casefile , "id : %s ," , &end->id);
        fscanf(casefile , "type : %c ," , &end->type);
        pos = ftell(casefile);
        fscanf(casefile , "activity_status : %s ," , &end->status);
        fscanf(casefile , "District : %s ," , &end->district);
        fseek(casefile , 10 , SEEK_CUR);
        fgets(end->address , 100 , casefile);
        fscanf(casefile , " ,Building type : %c ," , &end->building_type);
        fscanf(casefile , "Construct permition : %c ," , &end->construct_permit);
        fscanf(casefile , "Accessibility : %c ," , &end->accessibility);
        fscanf(casefile , "Distance from city : %s ," , &end->distance_from_city);
        fscanf(casefile , "Area : %s ," , &end->area);
        fscanf(casefile , "owner contact : %s ," , &end->owner_contact);
        fscanf(casefile , "Mortgage price : %s ," , &end->mortgage_price);
        fscanf(casefile , "Rent price : %s ," , &end->rent_price);
        fscanf(casefile , "Submitted by : %s ," , &end->submit_user);
        fscanf(casefile , "Submit time : %d ," , &end->submit_time);
        if(strcmp(end->id , input_id) == 0)
        {
            if(strcmp(end->status , "on") == 0)
            {
                fseek(casefile , 0 , SEEK_CUR);
                fprintf(casefile , "Archive time : %d ," , time(NULL));
                fprintf(casefile , "Archive user : %s" , active_user->username);
                fseek(casefile , pos , SEEK_SET);
                fprintf(casefile , "activity_status : of ,");
                fclose(casefile);
                strcpy(g_message , "Case removed successfully");
                user_activity_count_update(active_user->username , 0);
                break;
            }
        }
        fscanf(casefile , "Archive time : %d ," , &end->archive_time);
        fscanf(casefile , "Archive user : %s" , &end->archive_user);
        if(feof(casefile) != 0)
        {
            strcpy(g_message , "Didn't find the case - check the id to be correct.");
            break;
        }
        free(end);
        fgetc(casefile);
    }
    fclose(casefile);
}
void delete_by_id()
{
    while(1)
    {
        char choice = '9';
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Delete case by id----\n\n%*c..::[1]Delete residential sale property::..\n%*c..::[2]Delete office sale property::..\n%*c..::[3]Delete Land sale property::..\n"
                        , 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ');
        printf("%*c..::[4]Delete residential rent property::..\n%*c..::[5]Delete office rent property::..\n%*c..::[6]Delete Land rent property::..\n%*c..::[0]Back::..\n%*c>>>"
                        , 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ', 45 , ' ');
        choice = getche();
        if(choice == '1')
        {
            delete_residental_sale();
        }
        else if(choice == '2')
        {
            delete_office_sale();
        }
        else if(choice == '3')
        {
            delete_land_sale();
        }
        else if(choice == '4')
        {
            delete_residental_rent();
        }
        else if(choice == '5')
        {
            delete_office_rent();
        }
        else if(choice == '6')
        {
            delete_land_rent();
        }
        else if(choice == '0')
        {
            break;
        }
    }
}
void show_residental_sell(struct residental_sale_case *slink1)
{
    printf("%*c----residental sell property----\n" , 45 , ' ');
    printf("%*c||id : %s\n" ,20 , ' ' , slink1->id);
    printf("%*c||Address : %s\n" ,20 , ' ' , slink1->address);
    printf("%*c||District : %s\n" ,20 , ' ' , slink1->district);
    if(slink1->type == '1')
    {
        printf("%*c||Building type : villa\n" ,20 , ' ');
    }else{
        printf("%*c||Building type : apartment\n" ,20 , ' ' );
    }
    printf("%*c||Building age : %s\n" ,20 , ' ' , slink1->age);
    printf("%*c||Built up area : %s\n" ,20 , ' ' , slink1->built_area);
    printf("%*c||Floor : %s\n" ,20 , ' ' , slink1->floor);
    printf("%*c||Area: %s \n" ,20 , ' ' , slink1->area);
    if(slink1->parking_lot == '1')
    {
        printf("%*c||Has dedicated parking space : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated parking space : no \n",20 , ' ');
    }
    if(slink1->depot == '1')
    {
        printf("%*c||Has dedicated depot : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated depot : no \n",20 , ' ');
    }
    if(slink1->elevator == '1')
    {
        printf("%*c||Has elevator : yes \n",20 , ' ');
    }else{
        printf("%*c||Has elevator : no \n",20 , ' ');
    }
    if(slink1->air_conditioning_system == '1')
    {
        printf("%*c||Has Air conditioning system : no \n",20 , ' ');
    }else if(slink1->air_conditioning_system == '2')
    {
        printf("%*c||Has Air conditioning system : only cooling \n",20 , ' ');
    }else if(slink1->air_conditioning_system == '3')
    {
        printf("%*c||Has Air conditioning system : only heating \n",20 , ' ');
    }else{
        printf("%*c||Has Air conditioning system : both \n",20 , ' ');
    }
    if(slink1->accessibility == '1')
    {
        printf("%*c||Accessibility : Bad \n",20 , ' ');
    }else if (slink1->accessibility == '2')
    {
        printf("%*c||Accessibility : Good \n",20 , ' ');
    }else{
        printf("%*c||Accessibility : great \n",20 , ' ');
    }
    printf("%*c||Rooms : %s \n" ,20 , ' ' , slink1->rooms);
    printf("%*c||Owner's phone number : %s \n" ,20 , ' ' , slink1->owner_contact);
    printf("%*c||Sell price per meter: %s \n" ,20 , ' ' , slink1->sell_price_meter);
    printf("%*c||Sell price : %s \n" ,20 , ' ' , slink1->sell_price);
}
void show_residental_rent(struct residental_rent_case *slink2)
{
    printf("%*c----residental rent property----\n" , 45 , ' ');
    printf("%*c||id : %s\n" ,20 , ' ' , slink2->id);
    printf("%*c||Address : %s\n" ,20 , ' ' , slink2->address);
    printf("%*c||District : %s\n" ,20 , ' ' , slink2->district);
    if(slink2->type == '1')
    {
        printf("%*c||Building type : villa\n" ,20 , ' ');
    }else{
        printf("%*c||Building type : apartment\n" ,20 , ' ' );
    }
    printf("%*c||Building age : %s\n" ,20 , ' ' , slink2->age);
    printf("%*c||Built up area : %s\n" ,20 , ' ' , slink2->built_area);
    printf("%*c||Floor : %s\n" ,20 , ' ' , slink2->floor);
    printf("%*c||Area: %s \n" ,20 , ' ' , slink2->area);
    if(slink2->parking_lot == '1')
    {
        printf("%*c||Has dedicated parking space : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated parking space : no \n",20 , ' ');
    }
    if(slink2->depot == '1')
    {
        printf("%*c||Has dedicated depot : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated depot : no \n",20 , ' ');
    }
    if(slink2->elevator == '1')
    {
        printf("%*c||Has elevator : yes \n",20 , ' ');
    }else{
        printf("%*c||Has elevator : no \n",20 , ' ');
    }
    if(slink2->air_conditioning_system == '1')
    {
        printf("%*c||Has Air conditioning system : no \n",20 , ' ');
    }else if(slink2->air_conditioning_system == '2')
    {
        printf("%*c||Has Air conditioning system : only cooling \n",20 , ' ');
    }else if(slink2->air_conditioning_system == '3')
    {
        printf("%*c||Has Air conditioning system : only heating \n",20 , ' ');
    }else{
        printf("%*c||Has Air conditioning system : both \n",20 , ' ');
    }
    if(slink2->accessibility == '1')
    {
        printf("%*c||Accessibility : Bad \n",20 , ' ');
    }else if (slink2->accessibility == '2')
    {
        printf("%*c||Accessibility : Good \n",20 , ' ');
    }else{
        printf("%*c||Accessibility : great \n",20 , ' ');
    }
    printf("%*c||Rooms : %s \n" ,20 , ' ' , slink2->rooms);
    printf("%*c||Owner's phone number : %s \n" ,20 , ' ' , slink2->owner_contact);
    printf("%*c||mortgage price: %s \n" ,20 , ' ' , slink2->mortgage_price);
    printf("%*c||Rent price : %s \n" ,20 , ' ' , slink2->rent_price);
}
void show_office_sale(struct office_sale_case *slink3)
{
    printf("%*c----office sell property----\n" , 45 , ' ');
    printf("%*c||id : %s\n" ,20 , ' ' , slink3->id);
    printf("%*c||Address : %s\n" ,20 , ' ' , slink3->address);
    printf("%*c||District : %s\n" ,20 , ' ' , slink3->district);
    if(slink3->type == '1')
    {
        printf("%*c||Building type : villa\n" ,20 , ' ');
    }else{
        printf("%*c||Building type : apartment\n" ,20 , ' ' );
    }
    printf("%*c||Building age : %s\n" ,20 , ' ' , slink3->age);
    printf("%*c||Built up area : %s\n" ,20 , ' ' , slink3->built_area);
    printf("%*c||Floor : %s\n" ,20 , ' ' , slink3->floor);
    printf("%*c||Area: %s \n" ,20 , ' ' , slink3->area);
    if(slink3->parking_lot == '1')
    {
        printf("%*c||Has dedicated parking space : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated parking space : no \n",20 , ' ');
    }
    if(slink3->depot == '1')
    {
        printf("%*c||Has dedicated depot : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated depot : no \n",20 , ' ');
    }
    if(slink3->elevator == '1')
    {
        printf("%*c||Has elevator : yes \n",20 , ' ');
    }else{
        printf("%*c||Has elevator : no \n",20 , ' ');
    }
    if(slink3->air_conditioning_system == '1')
    {
        printf("%*c||Has Air conditioning system : no \n",20 , ' ');
    }else if(slink3->air_conditioning_system == '2')
    {
        printf("%*c||Has Air conditioning system : only cooling \n",20 , ' ');
    }else if(slink3->air_conditioning_system == '3')
    {
        printf("%*c||Has Air conditioning system : only heating \n",20 , ' ');
    }else{
        printf("%*c||Has Air conditioning system : both \n",20 , ' ');
    }
    if(slink3->accessibility == '1')
    {
        printf("%*c||Accessibility : Bad \n",20 , ' ');
    }else if (slink3->accessibility == '2')
    {
        printf("%*c||Accessibility : Good \n",20 , ' ');
    }else{
        printf("%*c||Accessibility : great \n",20 , ' ');
    }
    printf("%*c||Rooms : %s \n" ,20 , ' ' , slink3->rooms);
    printf("%*c||Owner's phone number : %s \n" ,20 , ' ' , slink3->owner_contact);
    printf("%*c||Sell price per meter: %s \n" ,20 , ' ' , slink3->sell_price_meter);
    printf("%*c||Sell price : %s \n" ,20 , ' ' , slink3->sell_price);
}
void show_office_rent(struct office_rent_case *slink4)
{
    printf("%*c----office rent property----\n" , 45 , ' ');
    printf("%*c||id : %s\n" ,20 , ' ' , slink4->id);
    printf("%*c||Address : %s\n" ,20 , ' ' , slink4->address);
    printf("%*c||District : %s\n" ,20 , ' ' , slink4->district);
    if(slink4->type == '1')
    {
        printf("%*c||Building type : villa\n" ,20 , ' ');
    }else{
        printf("%*c||Building type : apartment\n" ,20 , ' ' );
    }
    printf("%*c||Building age : %s\n" ,20 , ' ' , slink4->age);
    printf("%*c||Built up area : %s\n" ,20 , ' ' , slink4->built_area);
    printf("%*c||Floor : %s\n" ,20 , ' ' , slink4->floor);
    printf("%*c||Area: %s \n" ,20 , ' ' , slink4->area);
    if(slink4->parking_lot == '1')
    {
        printf("%*c||Has dedicated parking space : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated parking space : no \n",20 , ' ');
    }
    if(slink4->depot == '1')
    {
        printf("%*c||Has dedicated depot : yes \n",20 , ' ');
    }else{
        printf("%*c||Has dedicated depot : no \n",20 , ' ');
    }
    if(slink4->elevator == '1')
    {
        printf("%*c||Has elevator : yes \n",20 , ' ');
    }else{
        printf("%*c||Has elevator : no \n",20 , ' ');
    }
    if(slink4->air_conditioning_system == '1')
    {
        printf("%*c||Has Air conditioning system : no \n",20 , ' ');
    }else if(slink4->air_conditioning_system == '2')
    {
        printf("%*c||Has Air conditioning system : only cooling \n",20 , ' ');
    }else if(slink4->air_conditioning_system == '3')
    {
        printf("%*c||Has Air conditioning system : only heating \n",20 , ' ');
    }else{
        printf("%*c||Has Air conditioning system : both \n",20 , ' ');
    }
    if(slink4->accessibility == '1')
    {
        printf("%*c||Accessibility : Bad \n",20 , ' ');
    }else if (slink4->accessibility == '2')
    {
        printf("%*c||Accessibility : Good \n",20 , ' ');
    }else{
        printf("%*c||Accessibility : great \n",20 , ' ');
    }
    printf("%*c||Rooms : %s \n" ,20 , ' ' , slink4->rooms);
    printf("%*c||Owner's phone number : %s \n" ,20 , ' ' , slink4->owner_contact);
    printf("%*c||mortgage price: %s \n" ,20 , ' ' , slink4->mortgage_price);
    printf("%*c||Rent price : %s \n" ,20 , ' ' , slink4->rent_price);
}
void show_land_sale(struct land_sale_case *slink5)
{
    printf("%*c----land sell property----\n" , 45 , ' ');
    printf("%*c||id : %s\n" ,20 , ' ' , slink5->id);
    printf("%*c||Address : %s\n" ,20 , ' ' , slink5->address);
    printf("%*c||District : %s\n" ,20 , ' ' , slink5->district);
    if(slink5->type == '1')
    {
        printf("%*c||Building type : farm\n" ,20 , ' ');
    }else{
        printf("%*c||Building type : city\n" ,20 , ' ' );
    }
    if(slink5->construct_permit == '1')
    {
        printf("%*c||Has construct permission : Yes\n" ,20 , ' ');
    }else{
        printf("%*c||Has construct permission : No\n" ,20 , ' ' );
    }
    printf("%*c||Distance from nearest city : %s Km\n" ,20 , ' '  , slink5->distance_from_city);
    printf("%*c||Area: %s \n" ,20 , ' ' , slink5->area);
    if(slink5->accessibility == '1')
    {
        printf("%*c||Accessibility : Bad \n",20 , ' ');
    }else if (slink5->accessibility == '2')
    {
        printf("%*c||Accessibility : Good \n",20 , ' ');
    }else{
        printf("%*c||Accessibility : great \n",20 , ' ');
    }
    printf("%*c||Owner's phone number : %s \n" ,20 , ' ' , slink5->owner_contact);
    printf("%*c||Sell price per meter: %s \n" ,20 , ' ' , slink5->sell_price_meter);
    printf("%*c||Sell price : %s \n" ,20 , ' ' , slink5->sell_price);
}
void show_land_rent(struct land_rent_case *slink6)
{
    printf("%*c----land rent property----\n" , 45 , ' ');
    printf("%*c||id : %s\n" ,20 , ' ' , slink6->id);
    printf("%*c||Address : %s\n" ,20 , ' ' , slink6->address);
    printf("%*c||District : %s\n" ,20 , ' ' , slink6->district);
    if(slink6->type == '1')
    {
        printf("%*c||Building type : farm\n" ,20 , ' ');
    }else{
        printf("%*c||Building type : city\n" ,20 , ' ' );
    }
    if(slink6->construct_permit == '1')
    {
        printf("%*c||Has construct permission : Yes\n" ,20 , ' ');
    }else{
        printf("%*c||Has construct permission : No\n" ,20 , ' ' );
    }
    printf("%*c||Distance from nearest city : %s Km\n" ,20 , ' '  , slink6->distance_from_city);
    printf("%*c||Area: %s \n" ,20 , ' ' , slink6->area);
    if(slink6->accessibility == '1')
    {
        printf("%*c||Accessibility : Bad \n",20 , ' ');
    }else if (slink6->accessibility == '2')
    {
        printf("%*c||Accessibility : Good \n",20 , ' ');
    }else{
        printf("%*c||Accessibility : great \n",20 , ' ');
    }
    printf("%*c||Owner's phone number : %s \n" ,20 , ' ' , slink6->owner_contact);
    printf("%*c||Mortgage price: %s \n" ,20 , ' ' , slink6->mortgage_price);
    printf("%*c||Rent price: %s \n" ,20 , ' ' , slink6->rent_price);
}
void district_case_finder()
{
    char input_district[5];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases in a specific district----\n\n%*c||enter the district you are looking for : " , 45 , ' ',20 , ' ');
    fsgets(input_district , 5);
    fflush(stdin);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    struct land_sale_case *start_lasell ,*slink5;
    struct land_rent_case *start_larent ,*slink6;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(strcmp(slink1->district , input_district) == 0 && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_sell(slink1);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(strcmp(slink2->district , input_district) == 0 && strcmp(slink2->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_rent(slink2);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(strcmp(slink3->district , input_district) == 0 && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(strcmp(slink4->district , input_district) == 0 && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
    start_lasell = malloc(sizeof(struct land_sale_case));
    slink5 = initialize_cases_lasell(start_lasell);
    slink5 = start_lasell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(strcmp(slink5->district , input_district) == 0 && strcmp(slink5->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_sale(slink5);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink5);
        slink5 = slink5->next;
        if(slink5->next == NULL)
        {
            break;
        }
    }
    start_larent = malloc(sizeof(struct land_rent_case));
    slink6 = initialize_cases_larent(start_larent);
    slink6 = start_larent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(strcmp(slink6->district , input_district) == 0 && strcmp(slink6->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_rent(slink6);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink6);
        slink6 = slink6->next;
        if(slink6->next == NULL)
        {
            break;
        }
    }
}
void age_case_finder()
{
    char input_age_low[5] , input_age_up[5];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases within a specific building age----\n\n%*c||enter the range you are looking for - from(years): " , 45 , ' ',20 , ' ');
    fsgets(input_age_low , 5);
    fflush(stdin);
    printf("\n%*c||to(years): " , 45 , ' ',20 , ' ');
    fsgets(input_age_up , 5);
    fflush(stdin);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink1->age) >= atoi(input_age_low)) && (atoi(slink1->age) <= atoi(input_age_up)) && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_sell(slink1);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink2->age) >= atoi(input_age_low)) && (atoi(slink2->age) <= atoi(input_age_up)) && strcmp(slink2->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_rent(slink2);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink3->age) >= atoi(input_age_low)) && (atoi(slink3->age) <= atoi(input_age_up)) && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink4->age) >= atoi(input_age_low)) && (atoi(slink4->age) <= atoi(input_age_up)) && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
}
void built_up_case_finder()
{
    char input_built_low[20] , input_built_up[20];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases wth a specific building age----\n\n%*c||enter the range you are looking for - from(meters): " , 45 , ' ',20 , ' ');
    fsgets(input_built_low , 20);
    fflush(stdin);
    printf("\n%*c||to(meters): " , 45 , ' ',20 , ' ');
    fsgets(input_built_up , 20);
    fflush(stdin);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink1->built_area) >= atoi(input_built_low)) && (atoi(slink1->built_area) <= atoi(input_built_up)) && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_sell(slink1);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink2->built_area) >= atoi(input_built_low)) && (atoi(slink2->built_area) <= atoi(input_built_up)) && strcmp(slink2->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_rent(slink2);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink3->built_area) >= atoi(input_built_low)) && (atoi(slink3->built_area) <= atoi(input_built_up)) && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink4->built_area) >= atoi(input_built_low)) && (atoi(slink4->built_area) <= atoi(input_built_up)) && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
}
void sell_price_case_finder()
{
    char input_price_low[20] , input_price_up[20];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases whithin a specific sell price range----\n\n%*c||enter the range you are looking for - from(Tomans): " , 45 , ' ',20 , ' ');
    fsgets(input_price_low , 20);
    fflush(stdin);
    printf("\n%*c||to(Tomans): " , 45 , ' ',20 , ' ');
    fsgets(input_price_up , 20);
    fflush(stdin);
    struct residental_sale_case *start_resell ,*slink1;
    struct office_sale_case *start_ofsell ,*slink3;
    struct land_sale_case *start_lasell ,*slink5;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink1->sell_price) >= atoi(input_price_low)) && (atoi(slink1->sell_price) <= atoi(input_price_up)) && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_sell(slink1);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink3->sell_price) >= atoi(input_price_low)) && (atoi(slink3->sell_price) <= atoi(input_price_up)) && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_lasell = malloc(sizeof(struct land_sale_case));
    slink5 = initialize_cases_lasell(start_lasell);
    slink5 = start_lasell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if(atoi(slink5->sell_price) >= atoi(input_price_low) && atoi(slink5->sell_price) >= atoi(input_price_up) && strcmp(slink5->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_sale(slink5);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink5);
        slink5 = slink5->next;
        if(slink5->next == NULL)
        {
            break;
        }
    }
}
void room_case_finder()
{
    char input_room_up[5] , input_room_low[5];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases with a specific room count----\n\n%*c||enter the number of rooms you are looking for - from(rooms)>>> " , 45 , ' ',20 , ' ');
    fsgets(input_room_low , 5);
    fflush(stdin);
    printf("%*c||to(rooms)>>> " , 45 , ' ',20 , ' ');
    fsgets(input_room_up , 5);
    fflush(stdin);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink1->rooms) >= atoi(input_room_low)) && (atoi(slink1->rooms) <= atoi(input_room_up)) && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_sell(slink1);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink2->rooms) >= atoi(input_room_low)) && (atoi(slink2->rooms) <= atoi(input_room_up)) && strcmp(slink2->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_rent(slink2);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink3->rooms) >= atoi(input_room_low)) && (atoi(slink3->rooms) <= atoi(input_room_up)) && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink4->rooms) >= atoi(input_room_low)) && (atoi(slink4->rooms) <= atoi(input_room_up)) && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
}
void rent_price_case_finder()
{
    char input_rent_low[20] , input_rent_up[20] , input_mort_low[20] , input_mort_up[20];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases whithin a specific rent-mortgage price range----\n\n%*c||enter the rent price range you are looking for - from(Tomans): " , 45 , ' ',20 , ' ');
    fsgets(input_rent_low,20);
    fflush(stdin);
    printf("\n%*c||to(Tomans): " , 45 , ' ',20 , ' ');
    fsgets(input_rent_up,20);
    fflush(stdin);
    printf("\n%*c||mortgage price from(Tomans): " , 45 , ' ',20 , ' ');
    fsgets(input_mort_low ,20);
    fflush(stdin);
    printf("\n%*c||to(Tomans): " , 45 , ' ',20 , ' ');
    fsgets(input_mort_up , 20);
    fflush(stdin);
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_rent_case *start_ofrent ,*slink4 ;
    struct land_rent_case *start_larent ,*slink6;
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink2->rent_price) >= atoi(input_rent_low)) && (atoi(slink2->rent_price) <= atoi(input_rent_up)) &&
           (atoi(slink2->mortgage_price) >= atoi(input_mort_low)) && (atoi(slink2->mortgage_price) <= atoi(input_mort_up))
           && strcmp(slink2->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_rent(slink2);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink4->rent_price) >= atoi(input_rent_low)) && (atoi(slink4->rent_price) <= atoi(input_rent_up)) &&
           (atoi(slink4->mortgage_price) >= atoi(input_mort_low)) && (atoi(slink4->mortgage_price) <= atoi(input_mort_up))
                                                                      && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
    start_larent = malloc(sizeof(struct land_rent_case));
    slink6 = initialize_cases_larent(start_larent);
    slink6 = start_larent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink6->rent_price) >= atoi(input_rent_low)) && (atoi(slink6->rent_price) <= atoi(input_rent_up)) &&
           (atoi(slink6->mortgage_price) >= atoi(input_mort_low)) && (atoi(slink6->mortgage_price) <= atoi(input_mort_up))
                                                                      && strcmp(slink6->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_rent(slink6);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink6);
        slink6 = slink6->next;
        if(slink6->next == NULL)
        {
            break;
        }
    }
}
void floor_case_finder()
{
    char input_floor_low[5] , input_floor_up[5];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----Cases within a specific floor----\n\n%*c||enter the floor you are looking for - from: " , 45 , ' ',20 , ' ');
    fsgets(input_floor_low , 5);
    fflush(stdin);
    printf("\n%*c||to: " ,20 , ' ');
    fsgets(input_floor_up , 5);
    fflush(stdin);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink1->floor) >= atoi(input_floor_low)) && (atoi(slink1->floor) <= atoi(input_floor_up)) && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_sell(slink1);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink2->floor) >= atoi(input_floor_low)) && (atoi(slink2->floor) <= atoi(input_floor_up)) && strcmp(slink2->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_residental_rent(slink2);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink3->floor) >= atoi(input_floor_low)) && (atoi(slink3->floor) <= atoi(input_floor_up)) && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    cleanHeader(g_access_lvl , g_message);
    while(1)
    {
        if((atoi(slink4->floor) >= atoi(input_floor_low)) && (atoi(slink4->floor) <= atoi(input_floor_up)) && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            printf("%*c||press a key to go next : " ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
}
void changer(char *base , char *current , char *replace)
{
    FILE * fPtr;
    FILE * fTemp;
    char temp[50] , search[50];
    fPtr  = fopen("user_profiles.txt", "r");
    fTemp = fopen("replace.tmp", "w+");
    strcpy(search , base);
    strcat(search , current);
    strcat(search , "\n");
    while ((fgets(temp, 50, fPtr)) != NULL)
    {
        if (strcmp(temp , search) == 0)
        {
            strcpy(g_message , "changed successfully!");
            fprintf(fTemp , "%s%s" , base ,replace);
        }
        else
        {
            fputs(temp, fTemp);
        }
    }
    fclose(fPtr);
    fclose(fTemp);
    remove("user_profiles.txt");
    rename("replace.tmp", "user_profiles.txt");
}
void name_change()
{
    char input_password[20] , input_name[21];
    strcpy(g_message , "Enter 0 to go back.");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----------Settings-----------\n\n%*c||Please enter your password and new name\n%*c||Name :" , 45 , ' ', 20 , ' ', 20 , ' ');
        fgets(input_name , 20 , stdin);
        if (!lencheck(input_name , 19)) {
            strcpy(g_message , "input has prohibited length!");
            fflush(stdin);
            continue;
        }
        if(strcmp(input_name , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!isalphabet(input_name)) {
            strcpy(g_message , "name can only contain alphabet!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Password :" ,  20 , ' ');
        fgetpass(input_password , 20);
        if (!lencheck(input_password , 19)) {
            strcpy(g_message , "input password too long!");
            fflush(stdin);
            continue;
        }
        if(strlen(input_password) == 1 )
        {
            strcpy(g_message , "password can't be empty!");
            continue;
        }
        input_password[strcspn(input_password, "\n")] = 0;
        if(strcmp(input_password , "0") == 0)
        {
            strcpy(g_message , "Operation cancelled by user!");
            return;
        }
        if(strcmp(active_user->password , input_password) != 0)
        {
            strcpy(g_message , "wrong password!");
            continue;
        }
        break;
    }
    changer(" ,name : " , active_user->name , input_name);
    strcpy(active_user->name , input_name);
}
void family_change()
{
    char input_password[20] , input_family[25];
    strcpy(g_message , "Enter 0 to go back.");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----------Settings-----------\n\n%*c||Please enter your password and new family\n%*c||Name :" , 45 , ' ', 20 , ' ', 20 , ' ');
        fgets(input_family , 25 , stdin);
        if (!lencheck(input_family , 24)) {
            strcpy(g_message , "input has prohibited length!");
            fflush(stdin);
            continue;
        }
        if(strcmp(input_family , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!isalphabet(input_family)) {
            strcpy(g_message , "family can only contain alphabet!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Password :" ,  20 , ' ');
        fgetpass(input_password , 20);
        if (!lencheck(input_password , 19)) {
            strcpy(g_message , "input password too long!");
            fflush(stdin);
            continue;
        }
        if(strlen(input_password) == 1 )
        {
            strcpy(g_message , "password can't be empty!");
            continue;
        }
        input_password[strcspn(input_password, "\n")] = 0;
        if(strcmp(input_password , "0") == 0)
        {
            strcpy(g_message , "Operation cancelled by user!");
            return;
        }
        if(strcmp(active_user->password , input_password) != 0)
        {
            strcpy(g_message , "wrong password!");
            continue;
        }
        break;
    }
    changer(" ,family : " , active_user->family , input_family);
    strcpy(active_user->family , input_family);
}
void email_change()
{
    char input_password[20] , input_email[50];
    strcpy(g_message , "Enter 0 to go back.");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----------Settings-----------\n\n%*c||Please enter your password and new email\n%*c||Email :" , 45 , ' ', 20 , ' ', 20 , ' ');
        fgets(input_email , 50 , stdin);
        if(strcmp(input_email , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(input_email , 49)) {
            strcpy(g_message , "input has prohibited length!");
            fflush(stdin);
            continue;
        }
        if (!isemail(input_email)) {
            strcpy(g_message , "invalid format!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Password :" ,  20 , ' ');
        fgetpass(input_password , 20);
        if (!lencheck(input_password , 19)) {
            strcpy(g_message , "input password too long!");
            fflush(stdin);
            continue;
        }
        if(strlen(input_password) == 1 )
        {
            strcpy(g_message , "password can't be empty!");
            continue;
        }
        input_password[strcspn(input_password, "\n")] = 0;
        if(strcmp(input_password , "0") == 0)
        {
            strcpy(g_message , "Operation cancelled by user!");
            return;
        }
        if(strcmp(active_user->password , input_password) != 0)
        {
            strcpy(g_message , "wrong password!");
            continue;
        }
        break;
    }
    changer(" ,email : " , active_user->email , input_email);
    strcpy(active_user->email , input_email);
}
void phone_change()
{
    char input_password[20] , input_phone[13];
    strcpy(g_message , "Enter 0 to go back.");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----------Settings-----------\n\n%*c||Please enter your password and new phone number\n%*c||Phone number :" , 45 , ' ', 20 , ' ', 20 , ' ');
        fgets(input_phone , 13 , stdin);
        if(strcmp(input_phone , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(input_phone , 12) || strlen(input_phone) != 12) {
            strcpy(g_message , "input has prohibited length!");
            fflush(stdin);
            continue;
        }
        if (!numcheck(input_phone)) {
            strcpy(g_message , "invalid format!");
            fflush(stdin);
            continue;
        }
        printf("%*c||Password :" ,  20 , ' ');
        fgetpass(input_password , 20);
        if (!lencheck(input_password , 19)) {
            strcpy(g_message , "input password too long!");
            fflush(stdin);
            continue;
        }
        if(strlen(input_password) == 1 )
        {
            strcpy(g_message , "password can't be empty!");
            continue;
        }
        input_password[strcspn(input_password, "\n")] = 0;
        if(strcmp(input_password , "0") == 0)
        {
            strcpy(g_message , "Operation cancelled by user!");
            return;
        }
        if(strcmp(active_user->password , input_password) != 0)
        {
            strcpy(g_message , "wrong password!");
            continue;
        }
        break;
    }
    changer(" ,phone number : " , active_user->phone_number , input_phone);
    strcpy(active_user->phone_number , input_phone);
}
void password_change()
{
    char input_password[20] , input_new[20];
    strcpy(g_message , "Enter 0 to go back.");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----------Settings-----------\n\n%*c||Please enter your password and new password\n%*c||current password :" , 45 , ' ', 20 , ' ', 20 , ' ');
        fgetpass(input_password , 20);
        if(strcmp(input_password , "0\n") == 0)
        {
            strcpy(g_message , "Welcome !");
            return;
        }
        if (!lencheck(input_password , 19)) {
            strcpy(g_message , "input has prohibited length!");
            fflush(stdin);
            continue;
        }
        if(strlen(input_password) == 1 )
        {
            strcpy(g_message , "password can't be empty!");
            continue;
        }
        input_password[strcspn(input_password, "\n")] = 0;
        if(strcmp(active_user->password , input_password) != 0)
        {
            strcpy(g_message , "wrong password!");
            continue;
        }
        printf("\n");
        printf("%*c||new Password :" ,  20 , ' ');
        fgetpass(input_new , 20);
        if (!lencheck(input_new , 19)) {
            strcpy(g_message , "input password too long!");
            fflush(stdin);
            continue;
        }
        if(!integrity_check(input_new))
        {
            strcpy(g_message , "password too simple it should contain at least 8 characters and an upper and a special character");
            continue;
        }
        if(strlen(input_new) == 1 )
        {
            strcpy(g_message , "password can't be empty!");
            continue;
        }
        if(strcmp(input_new , "0\n") == 0)
        {
            strcpy(g_message , "Operation cancelled by user!");
            return;
        }
        break;
    }

    changer(" ,password : " , active_user->password , input_new);
    input_new[strcspn(input_new, "\n")] = 0;
    strcpy(active_user->password , input_new);
}
void increaseFontSize()

{

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = malloc(sizeof(CONSOLE_FONT_INFOEX));
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);
    if(lpConsoleCurrentFontEx->dwFontSize.X > 14)
    {
        strcpy(g_message , "maximum size reached!");
        return;
    }
    lpConsoleCurrentFontEx->dwFontSize.X += 1;
    lpConsoleCurrentFontEx->dwFontSize.Y += 1;
    SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

}
void decreaseFontSize()

{

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = malloc(sizeof(CONSOLE_FONT_INFOEX));
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);
    if(lpConsoleCurrentFontEx->dwFontSize.X <= 5)
    {
        strcpy(g_message , "minimum size reached!");
        return;
    }
    lpConsoleCurrentFontEx->dwFontSize.X -= 1;
    lpConsoleCurrentFontEx->dwFontSize.Y -= 1;
    SetCurrentConsoleFontEx(hStdOut, 0, lpConsoleCurrentFontEx);

}
void settings()
{
    char choice = '0';
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----------Settings-----------\n\n%*c..::[1] Change name   ::..\n%*c..::[2] Change family ::..\n%*c..::[3] Change email::..\n%*c..::[4] Change phone number::..\n%*c..::[5] Change password::..\n%*c..::[6] Change Theme::..\n%*c..::[7] My information::..\n%*c..::[0]back::..\n%*c>>>"
                , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ', 45 , ' ', 45 , ' ' ,45 , ' ',45 , ' ',45 , ' ');
        choice = getche();
        if(choice == '1')
        {
            name_change();
        }
        else if(choice == '2')
        {
            family_change();
        }
        else if(choice == '3')
        {
            email_change();
        }
        else if(choice == '4')
        {
            phone_change();
        }
        else if(choice == '5')
        {
            password_change();
        }
        else if(choice == '6')
        {
            while(1)
            {
                cleanHeader(g_access_lvl , g_message);
                printf("%*c----------Change Theme-----------\n\n%*c..::[1] Default Theme   ::..\n%*c..::[2] Gleaming light ::..\n%*c..::[3] Zenith Z-19 ::..\n%*c..::[4] Psycho ::..\n%*c..::[5] Font size[+]::..\n%*c..::[6] Font size[-]::..\n%*c..::[7] Toggle background music::..\n%*c..::[0]back::..\n%*c>>>"
                    , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ', 45 , ' ', 45 , ' ' ,45 , ' ',45 , ' ',45 , ' ');
                const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                choice = getche();
                if(choice == '1')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
                }
                else if(choice == '2')
                {
                    SetConsoleTextAttribute(hConsole, 0 | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE );
                }
                else if(choice == '3')
                {
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                }
                else if(choice == '4')
                {
                    SetConsoleTextAttribute(hConsole,  FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY);
                }
                else if(choice == '5')
                {
                    increaseFontSize();
                }
                else if(choice == '6')
                {
                    decreaseFontSize();
                }
                else if(choice == '7')
                {
                    if(music == 0)
                    {
                        strcpy(g_message , "Spirited Away 2001 - The Name of Life Instrumental Piano");
                        PlaySound("track1.wav",NULL,SND_ASYNC| SND_LOOP | SND_FILENAME);
                        music++;
                    }else{
                        strcpy(g_message , "Music stopped.");
                        PlaySound(NULL, NULL, 0);
                        music--;
                    }

                }
                else if(choice == '0')
                {
                    break;
                }
            }
        }
        else if(choice == '7')
        {
            cleanHeader(g_access_lvl , g_message);
            printf("%*c----Your current information----\n\n%*c||Username : %s" , 45 , ' ',20 , ' ' , active_user->username);
            printf("\n%*c||Name : %s" ,20 , ' ', active_user->name);
            printf("\n%*c||Family : %s" ,20 , ' ', active_user->family);
            printf("\n%*c||ID : %s" ,20 , ' ', active_user->id);
            printf("\n%*c||Email : %s" ,20 , ' ', active_user->email);
            printf("\n%*c||Phone number : %s" ,20 , ' ', active_user->phone_number);
            getch();
        }
        else if(choice == '0')
        {
            break;
        }
    }
}
void networth()
{
    cleanHeader(g_access_lvl , g_message);
    unsigned long long int num = 0 , nw=0;
    unsigned long long int total_nw = 0;
    struct residental_sale_case *start_resell ,*slink1;
    struct office_sale_case *start_ofsell ,*slink3;
    struct land_sale_case *start_lasell ,*slink5;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    while(1)
    {
        if(strcmp(slink1->status , "on") == 0)
        {
            sscanf(slink1->sell_price, "%llu" , &num);

            nw+=num;
        }
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    total_nw += nw;
    free(slink1);
    printf("%*c----Active cases----\n\n%*c||residental for sell networth: %llu" , 45 , ' ',20 , ' ',nw);
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    nw = 0;
    while(1)
    {
        if(strcmp(slink3->status , "on") == 0)
        {
            sscanf(slink3->sell_price, "%llu", &num);
            nw+=num;
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    total_nw += nw;
    printf("\n%*c||office for sell networth : %llu" ,  20 , ' ' , nw);
    start_lasell = malloc(sizeof(struct land_sale_case));
    slink5 = initialize_cases_lasell(start_lasell);
    slink5 = start_lasell;
    nw = 0;
    while(1)
    {
        if(strcmp(slink5->status , "on") == 0)
        {
            sscanf(slink5->sell_price, "%llu", &num);
            nw+=num;
        }
        free(slink5);
        slink5 = slink5->next;
        if(slink5->next == NULL)
        {
            break;
        }
    }
    total_nw += nw;
    printf("\n%*c||land for sell networth : %llu" ,  20 , ' ' , nw);
    printf("\n%*c||Total agency networth: %llu" ,  20 , ' ' , total_nw);
    getch();
}
void user_activity_sort()
{
    struct client *temp , *start , *link;
    char tempstr[20];
    temp = malloc(sizeof(struct client));
    start = malloc(sizeof(struct client));
    link = malloc(sizeof(struct client));
    temp = initialize_profiles(start);
    link = start;
    while(start != NULL)
    {
        temp=start;
        while ((temp->next->next) != NULL)//travel till the second last element
        {
            temp->submits[strcspn(temp->submits, "\n")] = 0;
            temp->next->submits[strcspn(temp->next->submits, "\n")] = 0;
            if(strtol(temp->submits , NULL , 10) < strtol(temp->next->submits , NULL , 10))// compare the data of the links
            {
                strcpy(tempstr , temp->username);
                strcpy(temp->username , temp->next->username);// swap the data
                strcpy(temp->next->username , tempstr);
                strcpy(tempstr , temp->submits);
                strcpy(temp->submits , temp->next->submits);// swap the data
                strcpy(temp->next->submits , tempstr);
            }
            temp = temp->next;    // move to the next element
        }
        link = link->next;// move to the next link
        if(link->next->next == NULL)
        {
            break;
        }
    }
    temp = start;
    cleanHeader(active_user->access_lvl , g_message);
    printf("%*c----users sorted by activity----\n" , 45 , ' ');
    int rank = 1;
    while(1)
    {
        printf("\n%*c | %d | %-10s : %4s submits |" ,45 ,' ', rank , temp->username , temp->submits);
        temp = temp->next;
        rank++;
        if(temp->next == NULL)
        {
            break;
        }
    }
    getch();
}
void submit_date_finder()
{
    unsigned long int start_sec , end_sec;
    char start_year[6] , start_month[6],start_day[6] , end_year[6] , end_month[6] , end_day[6];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----------find submit date-----------\n\n%*c||enter the start year: " , 45 ,' ', 45 ,' ');
    fgets(start_year , 6 , stdin);
    printf("%*c||enter the start month: ", 45 ,' ');
    fgets(start_month , 4 , stdin);
    printf("%*c||enter the start day: ", 45 ,' ');
    fgets(start_day , 4 ,stdin);
    printf("%*c||enter the end year: " , 45 ,' ');
    fgets(end_year , 6 , stdin);
    printf("%*c||enter the end month: ", 45 ,' ');
    fgets(end_month , 4 ,stdin);
    printf("%*c||enter the end day: ", 45 ,' ');
    fgets(end_day , 4 , stdin);
    start_sec = date_to_sec(atoi(start_year) , atoi(start_month) , atoi(start_day));
    end_sec = date_to_sec(atoi(end_year) , atoi(end_month) , atoi(end_day));
    cleanHeader(g_access_lvl , g_message);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    struct land_sale_case *start_lasell ,*slink5;
    struct land_rent_case *start_larent ,*slink6;
    time_t t;
    struct tm tm;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    while(1)
    {
        if((slink1->submit_time <= end_sec) && (slink1->submit_time >= start_sec) && strcmp(slink1->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            t = slink1->submit_time;
            tm = *localtime(&t);
            show_residental_sell(slink1);
            printf("%*c||Submit Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Submitted by : %s\n" ,20 , ' ' , slink1->submit_user);
            printf("%*cpress a key to go next >>> : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        if(slink2->submit_time < end_sec && slink2->submit_time >= start_sec && strcmp(slink2->status , "on") == 0)
        {
            t = slink2->submit_time;
            tm = *localtime(&t);
            show_residental_rent(slink2);
            printf("%*c||Submit Date : %d-%02d-%02d %02d:%02d:%02d" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Submitted by : %s" ,20 , ' ' , slink2->submit_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    while(1)
    {
        if(slink3->submit_time < end_sec && slink3->submit_time >= start_sec && strcmp(slink3->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_sale(slink3);
            t = slink3->submit_time;
            tm = *localtime(&t);
            printf("%*c||Submit Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Submitted by : %s\n" ,20 , ' ' , slink3->submit_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    while(1)
    {
        if(slink4->submit_time < end_sec && slink4->submit_time >= start_sec && strcmp(slink4->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_office_rent(slink4);
            t = slink4->submit_time;
            tm = *localtime(&t);
            printf("%*c||Submit Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Submitted by : %s\n" ,20 , ' ' , slink4->submit_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
    start_lasell = malloc(sizeof(struct land_sale_case));
    slink5 = initialize_cases_lasell(start_lasell);
    slink5 = start_lasell;
    while(1)
    {
        if(slink5->submit_time < end_sec && slink5->submit_time >= start_sec && strcmp(slink5->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_sale(slink5);
            t = slink5->submit_time;
            tm = *localtime(&t);
            printf("%*c||Submit Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Submitted by : %s\n" ,20 , ' ' , slink5->submit_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink5);
        slink5 = slink5->next;
        if(slink5->next == NULL)
        {
            break;
        }
    }
    start_larent = malloc(sizeof(struct land_rent_case));
    slink6 = initialize_cases_larent(start_larent);
    slink6 = start_larent;
    while(1)
    {
        if(slink6->submit_time < end_sec && slink6->submit_time >= start_sec && strcmp(slink6->status , "on") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_rent(slink6);
            t = slink6->submit_time;
            tm = *localtime(&t);
            printf("%*c||Submit Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Submitted by : %s\n" ,20 , ' ' , slink6->submit_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink6);
        slink6 = slink6->next;
        if(slink6->next == NULL)
        {
            break;
        }
    }
}
void archive_date_finder()
{
    unsigned long int start_sec , end_sec;
    char start_year[6] , start_month[6],start_day[6] , end_year[6] , end_month[6] , end_day[6];
    cleanHeader(g_access_lvl , g_message);
    printf("%*c----------find cases by archive date-----------\n\n%*c||enter the start year: " , 45 ,' ', 45 ,' ');
    fgets(start_year , 6 , stdin);
    printf("%*c||enter the start month: ", 45 ,' ');
    fgets(start_month , 4 , stdin);
    printf("%*c||enter the start day: ", 45 ,' ');
    fgets(start_day , 4 ,stdin);
    printf("%*c||enter the end year: " , 45 ,' ');
    fgets(end_year , 6 , stdin);
    printf("%*c||enter the end month: ", 45 ,' ');
    fgets(end_month , 4 ,stdin);
    printf("%*c||enter the end day: ", 45 ,' ');
    fgets(end_day , 4 , stdin);
    start_sec = date_to_sec(atoi(start_year) , atoi(start_month) , atoi(start_day));
    end_sec = date_to_sec(atoi(end_year) , atoi(end_month) , atoi(end_day));
    cleanHeader(g_access_lvl , g_message);
    struct residental_sale_case *start_resell ,*slink1;
    struct residental_rent_case *start_rerent ,*slink2;
    struct office_sale_case *start_ofsell ,*slink3;
    struct office_rent_case *start_ofrent ,*slink4;
    struct land_sale_case *start_lasell ,*slink5;
    struct land_rent_case *start_larent ,*slink6;
    time_t t;
    struct tm tm;
    start_resell = malloc(sizeof(struct residental_sale_case));
    slink1 = initialize_cases_resell(start_resell);
    slink1 = start_resell;
    while(1)
    {
        if((slink1->archive_time <= end_sec) && (slink1->archive_time >= start_sec) && strcmp(slink1->status , "of") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            t = slink1->archive_time;
            tm = *localtime(&t);
            show_residental_sell(slink1);
            printf("%*c||archive Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Archived by : %s\n" ,20 , ' ' , slink1->archive_user);
            printf("%*cpress a key to go next >>> : " ,20 , ' ');
            getch();
        }
        free(slink1);
        slink1 = slink1->next;
        if(slink1->next == NULL)
        {
            break;
        }
    }
    start_rerent = malloc(sizeof(struct residental_rent_case));
    slink2 = initialize_cases_rerent(start_rerent);
    slink2 = start_rerent;
    while(1)
    {
        if(slink2->archive_time < end_sec && slink2->archive_time >= start_sec && strcmp(slink2->status , "of") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            t = slink2->archive_time;
            tm = *localtime(&t);
            show_residental_rent(slink2);
            printf("%*c||Archive Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Archived by : %s\n" ,20 , ' ' , slink2->archive_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink2);
        slink2 = slink2->next;
        if(slink2->next == NULL)
        {
            break;
        }
    }
    start_ofsell = malloc(sizeof(struct office_sale_case));
    slink3 = initialize_cases_ofsell(start_ofsell);
    slink3 = start_ofsell;
    while(1)
    {
        if(slink3->archive_time < end_sec && slink3->archive_time >= start_sec && strcmp(slink3->status , "of") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            t = slink3->archive_time;
            tm = *localtime(&t);
            show_office_sale(slink3);
            printf("%*c||Archive Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Archived by : %s\n" ,20 , ' ' , slink3->archive_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink3);
        slink3 = slink3->next;
        if(slink3->next == NULL)
        {
            break;
        }
    }
    start_ofrent = malloc(sizeof(struct office_rent_case));
    slink4 = initialize_cases_ofrent(start_ofrent);
    slink4 = start_ofrent;
    while(1)
    {
        if(slink4->archive_time < end_sec && slink4->archive_time >= start_sec && strcmp(slink4->status , "of") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            t = slink4->archive_time;
            tm = *localtime(&t);
            show_office_rent    (slink4);
            printf("%*c||Archive Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Archived by : %s\n" ,20 , ' ' , slink4->archive_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink4);
        slink4 = slink4->next;
        if(slink4->next == NULL)
        {
            break;
        }
    }
    start_lasell = malloc(sizeof(struct land_sale_case));
    slink5 = initialize_cases_lasell(start_lasell);
    slink5 = start_lasell;
    while(1)
    {
        if(slink5->archive_time < end_sec && slink5->archive_time >= start_sec && strcmp(slink5->status , "of") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            t = slink5->archive_time;
            tm = *localtime(&t);
            show_land_sale(slink5);
            printf("%*c||Archive Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Archived by : %s\n" ,20 , ' ' , slink5->archive_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink5);
        slink5 = slink5->next;
        if(slink5->next == NULL)
        {
            break;
        }
    }
    start_larent = malloc(sizeof(struct land_rent_case));
    slink6 = initialize_cases_larent(start_larent);
    slink6 = start_larent;
    while(1)
    {
        if(slink6->archive_time < end_sec && slink6->archive_time >= start_sec && strcmp(slink6->status , "of") == 0)
        {
            cleanHeader(g_access_lvl , g_message);
            show_land_rent(slink6);
            t = slink6->archive_time;
            tm = *localtime(&t);
            printf("%*c||Archive Date : %d-%02d-%02d %02d:%02d:%02d\n" ,20 , ' ' , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
            printf("%*c||Archived by : %s\n" ,20 , ' ' , slink6->archive_user);
            printf("%*cpress a key to go next >>>" ,20 , ' ');
            getch();
        }
        free(slink6);
        slink6 = slink6->next;
        if(slink6->next == NULL)
        {
            break;
        }
    }
}
void user_activity_date()
{
    struct client *temp , *start , *link;
    char tempstr[20];
    temp = malloc(sizeof(struct client));
    start = malloc(sizeof(struct client));
    temp = initialize_profiles(start);
    time_t t;
    struct tm tm;
    link = start;
    while(start != NULL)
    {
        temp=start;
        while ((temp->next->next) != NULL)//travel till the second last element
        {
            temp->last_activity[strcspn(temp->last_activity, "\n")] = 0;
            temp->next->last_activity[strcspn(temp->next->last_activity, "\n")] = 0;
            if(strtol(temp->last_activity , NULL , 10) < strtol(temp->next->last_activity , NULL , 10))// compare the data of the links
            {
                strcpy(tempstr , temp->username);
                strcpy(temp->username , temp->next->username);// swap the data
                strcpy(temp->next->username , tempstr);
                strcpy(tempstr , temp->last_activity);
                strcpy(temp->last_activity , temp->next->last_activity);// swap the data
                strcpy(temp->next->last_activity , tempstr);
            }
            temp = temp->next;    // move to the next element
        }
        link = link->next;// move to the next link
        if(link->next->next == NULL)
        {
            break;
        }
    }
    temp = start;
    cleanHeader(active_user->access_lvl , g_message);
    printf("%*c----users whith their last activity----\n" , 45 , ' ');
    int rank = 1;
    while(1)
    {
        t = atoi(temp->last_activity);
        tm = *localtime(&t);
        printf("\n%*c | %d | %-10s : %d-%02d-%02d %02d:%02d:%02d|" ,45 ,' ', rank , temp->username , tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday , tm.tm_hour , tm.tm_min , tm.tm_sec);
        free(temp);
        temp = temp->next;
        rank++;
        if(temp->next == NULL)
        {
            break;
        }
    }
    getch();
}
void Dashboard()
{
    char choice = '0';
    while(1)
    {
        if(choice == '0')
        {
            strcpy(g_message , "Welcome mr/ms ");
            strcat(g_message , active_user->name);
            cleanHeader(g_access_lvl , g_message);
            printf("%*c----------Dashboard-----------\n\n%*c..::[1] Submit new case   ::..\n%*c..::[2] Delete saved case ::..\n%*c..::[3] Reports Page      ::..\n%*c..::[4] Account settings  ::..\n%*c..::[0]     Sign out      ::..\n%*c>>>"
                , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ', 45 , ' ', 45 , ' ');
        }
        choice = getch();
        if(choice == '1')
        {
            while(1)
            {
                if(choice == '0' || choice =='1')
                {
                    cleanHeader(g_access_lvl , g_message);
                    printf("%*c------Submit new case------\n\n%*c..::[1]Submit sale case::..\n%*c..::[2]Submit Rent case::..\n%*c..::[0]Back::..\n%*c>>>"
                    , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ');
                }
                choice = getch();
                if(choice == '1')
                {
                    while(1)
                    {
                        cleanHeader(g_access_lvl , g_message);
                        printf("%*c----Submit new sale case----\n\n%*c..::[1]Submit residential property::..\n%*c..::[2]Submit office property::..\n%*c..::[3]Submit Land property::..\n%*c..::[0]Back::..\n%*c>>>"
                        , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ');
                        choice = getch();
                        if(choice == '1')
                        {
                            submit_residental_sale();
                        }
                        else if(choice == '2')
                        {
                            submit_office_sale();
                        }
                        else if(choice == '3')
                        {
                            submit_land_sale();
                        }
                        else if(choice == '0')
                        {
                            break;
                        }
                    }
                }
                else if(choice == '2')
                {
                    while(1)
                    {
                        cleanHeader(g_access_lvl , g_message);
                        printf("%*c----Submit new rent case----\n\n%*c..::[1]Submit residential property::..\n%*c..::[2]Submit office property::..\n%*c..::[3]Submit Land property::..\n%*c..::[0]Back::..\n%*c>>>"
                        , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ');
                        choice = getch();
                        if(choice == '1')
                        {
                            submit_residental_rent();
                        }
                        else if(choice == '2')
                        {
                            submit_office_rent();
                        }
                        else if(choice == '3')
                        {
                            submit_land_rent();
                        }
                        else if(choice == '0')
                        {
                            break;
                        }
                    }
                }
                else if(choice == '0')
                {
                    break;
                }
            }
        }
        else if(choice == '2')
        {
            while(1)
            {
                cleanHeader(g_access_lvl , g_message);
                printf("%*c----Delete a property----\n\n%*c..::[1]Find by id::..\n%*c..::[2]Find by information::..\n%*c..::[0]Back::..\n%*c>>>"
                    , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ');
                choice = getch();
                if(choice == '1')
                {
                    delete_by_id();
                }
                else if(choice == '2')
                {
                    //
                }
                else if(choice == '0')
                {
                    break;
                }
            }
        }
        else if(choice == '3')
        {
            while(1)
            {
                cleanHeader(g_access_lvl , g_message);
                printf("%*c----Select a report to show----\n\n%*c..::[1]Number of active properties::..\n%*c..::[2]Properties in a specific district::..\n%*c..::[3]Properties with specific building age::..\n%*c..::[4]Properties in a specific bulit-up Area range::..\n"
                    , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ',45 , ' ');
                printf("%*c..::[5]Properties in a specific Sell-price Range::..\n%*c..::[6]Properties with a specific number of rooms::..\n%*c..::[7]Properties networth::..\n%*c..::[8]Next page::.."
                        ,45 , ' ' ,45 , ' ');
                if(strcmp(active_user->access_lvl , "Head_Admin") == 0)
                {
                    printf("\n%*c..::[9]Manager reports::..\n\n%*c..::[0]Back::..\n%*c>>>" , 45 , ' ', 45 , ' ',45 , ' ');
                }
                else
                {
                    printf("\n\n%*c..::[0]Back::..\n%*c>>>", 45 , ' ',45 , ' ');
                }
                choice = getch();
                if(choice == '1')
                {
                    active_case_counter();
                }
                else if(choice == '2')
                {
                    district_case_finder();
                }
                else if(choice == '3')
                {
                    age_case_finder();
                }
                else if(choice == '4')
                {
                    built_up_case_finder();
                }
                else if(choice == '5')
                {
                    sell_price_case_finder();
                }
                else if(choice == '6')
                {
                    room_case_finder();
                }
                else if(choice == '7')
                {
                    networth();
                }
                else if(choice == '8')
                {
                    while(1)
                    {
                        cleanHeader(g_access_lvl , g_message);
                        printf("%*c----Select a report to show----\n\n%*c..::[1]Properties in a specific rent-price Range::..\n%*c..::[2]Properties in a specific floor::..\n%*c..::[0]back::..\n%*c>>>"
                            , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ');
                        choice = getche();
                        if(choice == '1')
                        {
                            rent_price_case_finder();
                        }
                        else if(choice == '2')
                        {
                            floor_case_finder();
                        }
                        else if(choice == '0')
                        {
                            break;
                        }
                    }
                }
                else if(choice == '9' && strcmp(active_user->access_lvl , "Head_Admin") == 0)
                {
                    while(1)
                    {
                        cleanHeader(g_access_lvl , g_message);
                        printf("%*c----Select a report to show----\n\n%*c..::[1]Users sorted by activity::..\n%*c..::[2]Properties submitted whithin a specific date::..\n%*c..::[3]Properties Archived whithin a specific date::..\n%*c..::[4]Users activity::..\n"
                            , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ',45 , ' ');
                        printf("%*c..::[0]Back::..\n%*c>>>" , 45 , ' ', 45 , ' ');
                            choice = getche();
                        if(choice == '1')
                        {
                            user_activity_sort();
                        }
                        else if(choice == '2')
                        {
                            submit_date_finder();
                        }
                        else if(choice == '3')
                        {
                            archive_date_finder();
                        }
                        else if(choice == '4')
                        {
                            user_activity_date();
                        }
                        else if(choice == '0')
                        {
                            break;
                        }
                    }
                }
                else if(choice == '0')
                {
                    break;
                }
            }
        }
        else if(choice == '4')
        {
            settings();
            choice = '0';
        }
        else if(choice == '0')
        {
            strcpy(g_access_lvl , " No Access");
            break;
        }
    }
}
int bancheck()
{
    FILE *gf = fopen("global.txt" , "r");
    unsigned int initban;
    fscanf(gf , "id : %s\nattempts : %d\nbantime : %d" ,stdin , stdin , &initban);
    fflush(stdin);
    fclose(gf);
    if((initban + 900 )< time(NULL))
    {
        return 0;
    }else{
        return 1;
    }
}
void main(){
    char choice='9';
    client *profiles_start , *link;
    FILE *idf = fopen("global.txt" , "r");
    fscanf(idf , "id : %s" ,g_property_id);
    fclose(idf);
    profiles_start = malloc(sizeof(client));
    strcpy(g_message , "Welcome!");
    while(1)
    {
        cleanHeader(g_access_lvl , g_message);
        printf("%*c----Main Menu----\n\n%*c..::[1]Sign in::..\n%*c..::[2]Sign up::..\n%*c..::[0]Close app::..\n%*c>>>" , 45 , ' ', 45 , ' ', 45 , ' ', 45 , ' ' , 45 , ' ');
        choice = getche();
        link = initialize_profiles(profiles_start);
        if(choice == '0')
        {
            printf("dada");
            exit(1);
        }
        else if(choice == '1')
        {
            if(bancheck())
            {
                strcpy(g_message , "you are banned!");
                continue;
            }
            if(signin())
            {
                Dashboard();
            }
        }
        else if(choice =='2')
        {
            signup(link , g_message);
        }
    }
}
