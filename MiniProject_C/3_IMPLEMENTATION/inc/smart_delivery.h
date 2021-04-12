#ifndef SMART_DELIVERY_H
#define SMART_DELIVERY_H

typedef struct details{
 char name[50];
 char username[50];
 char password[50];
 char mobile[10];
 char mail_id[50];
}detail;

typedef struct hotels {
    char hotel[100];
    char first_food[20];
    char second_food[20];
    char third_food[20];
    char fourth_food[25];
    int first, second, third, fourth;
}hotel;

typedef struct medicine {
    char shop[100];
    char first_medicine[20];
    char second_medicine[20];
    char third_medicine[20];
    char fourth_medicine[25];
    int first, second, third, fourth;
}medicine;

hotel m[5];
detail s[50];
medicine m1[5];

int cart();
int Login_Singup();
int choosing_delivery_system();
int location();
int cart_details();
int otp_authentication();



int validate(char *temp_name,char *temp_email,char *temp_password1,char *temp_password2,char *temp_mobile);
int validate_name(char *temp_name);
int validate_email(char *temp_email);
int validate_password(char *temp_password1,char *temp_password2);
int validate_mobile(char *temp_mobile);

int location();
int account_check(char* temp_email,char* temp_password1,char* temp_name,char* temp_mobile);
void otpauthentication();

int Food();
int Medicine();
int File();
#endif