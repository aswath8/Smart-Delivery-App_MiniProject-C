#include<stdio.h>
#include<string.h>

int validate_name(char *temp_name)
{
    int i;
    int flag=0;
    for (i = 0; temp_name[i] != '\0'; i++) {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')|| (temp_name[i] >= 'A' && temp_name[i] <= 'Z'))) 
        {
            printf("Please Enter the valid Name\n");
            return 0;
            break;
        }
        else
        {
            flag=1;
            return flag;
        }
    }
}
int validate_email(char *temp_email)
{
    int i,flag=0,count=0;
    for (i = 0;temp_email[i] != '\0'; i++) 
        {
            if (temp_email[i] == '@'|| temp_email[i] == '.')
                count++;
        }
        if (count >= 2 && strlen(temp_email) >= 5) 
        {
            flag=1;
            return flag;
        }
        else
        {
            printf("Please Enter Valid E-Mail\n");
            return 0;
        }
}

int validate_password(char *temp_password1,char *temp_password2)
{
    int flag=0;
    int caps = 0;
    int small = 0;
    int numbers = 0;
    int special = 0;
    int i;
    if (!strcmp(temp_password1,temp_password2)) 
    {
        if (strlen(temp_password1) >= 8 && strlen(temp_password1) <= 15) 
        {
                    for (i = 0;temp_password1[i]!= '\0';i++) {
                        if (temp_password1[i] >= 'A'
                            && temp_password1[i] <= 'Z')
                            caps++;
                        else if (temp_password1[i] >= 'a'
                                 && temp_password1[i]
                                        <= 'z')
                            small++;
                        else if (temp_password1[i] >= '0'
                                 && temp_password1[i]
                                        <= '9')
                            numbers++;
                        else if (temp_password1[i] == '@'
                                 || temp_password1[i] == '&'
                                 || temp_password1[i] == '#'
                                 || temp_password1[i]
                                        == '*')
                            special++;
                    }
        }
            if (caps >= 1 && small >= 1 && numbers >= 1 && special >= 1)
            {
                flag=1;
                return flag;
            }
            else{
                printf("Please Enter the strong password, Your password must contain atleast one uppercase Lowercase, Number and special character\n");
                return 0;
            }
    }
}

int validate_mobile(char *temp_mobile)
{
    int i,success=0,flag=0;
    if (strlen(temp_mobile) == 10) 
    {
        for (i = 0; i < 10; i++) 
            {
                if (temp_mobile[i]>= '0'&& temp_mobile[i] <= '9') 
                {
                    success = 1;
                }
            }
    }
    if (success == 1)
    {
        flag=1;
        return flag;
    }
    else{
        printf("Please Enter the valid mobile number\n");
        return 0;
    }
    
}



int validate(char *temp_name,char *temp_email,char *temp_password1,char *temp_password2,char *temp_mobile)
{
    // Validate the name
    
    int i,flag,count,success;
    for (i = 0; temp_name[i] != '\0'; i++) {
        if (!((temp_name[i] >= 'a' && temp_name[i] <= 'z')|| (temp_name[i] >= 'A' && temp_name[i] <= 'Z'))) 
        {
            printf("\nPlease Enter the valid Name\n");
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        count = 0;
  
        // Validate the Email ID
        for (i = 0;temp_email[i] != '\0'; i++) 
        {
            if (temp_email[i] == '@'|| temp_email[i] == '.')
                count++;
        }
        if (count >= 2
            && strlen(temp_email) >= 5) {
            // Validating the password
            // check if it matches with
            // correct password or not
            if (!strcmp(temp_password1,
                        temp_password2)) {
                if (strlen(temp_password1) >= 8
                    && strlen(temp_password1) <= 12) {
                    int caps = 0;
                    int small = 0;
                    int numbers = 0;
                    int special = 0;
                    for (i = 0;
                         temp_password1[i]
                         != '\0';
                         i++) {
                        if (temp_password1[i] >= 'A'
                            && temp_password1[i] <= 'Z')
                            caps++;
                        else if (temp_password1[i] >= 'a'
                                 && temp_password1[i]
                                        <= 'z')
                            small++;
                        else if (temp_password1[i] >= '0'
                                 && temp_password1[i]
                                        <= '9')
                            numbers++;
                        else if (temp_password1[i] == '@'
                                 || temp_password1[i] == '&'
                                 || temp_password1[i] == '#'
                                 || temp_password1[i]
                                        == '*')
                            special++;
                    }
                    if (caps >= 1 && small >= 1
                        && numbers >= 1 && special >= 1) {
                        // Validating the Input age
                            // Validating the Input mobile
                            // number
                            if (strlen(temp_mobile) == 10) {
                                for (i = 0; i < 10; i++) {
                                    if (temp_mobile[i]
                                            >= '0'
                                        && temp_mobile[i]
                                               <= '9') {
                                        success = 1;
                                    }
                                    else {
                                        printf("\n\nPlease");
                                        printf("Enter Valid ");
                                        printf("Mobile "
                                               "Number\n\n");
                                        return 0;
                                        break;
                                    }
                                }
  
                                // Success is assigned with
                                // value 1, Once every
                                // inputs are correct.
                                if (success == 1)
                                    return 1;
                            }
                            else {
                                printf("\n\nPlease Enter the");
                                printf("10 digit mobile");
                                printf("number\n\n");
                                return 0;
                            }
                            
                    }
                    else {
                        printf("\n\nPlease Enter the");
                        printf("strong password, Your ");
                        printf("password must contain ");
                        printf("atleast one uppercase, ");
                        printf("Lowercase, Number and ");
                        printf("special character\n\n");
                        return 0;
                    }
                }
                else {
                    printf("\nYour Password is very");
                    printf("short\nLength must ");
                    printf("between 8 to 12\n\n");
                    return 0;
                }
            }
            else {
                printf("\nPassword "
                       "Mismatch\n\n");
                return 0;
            }
        }
        else {
            printf("\nPlease Enter Valid E-Mail\n\n");
            return 0;
        }
    }
    return 1;
}
