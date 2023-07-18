#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>

struct Student
{
    int rollnumber;
    char name[100];
    char course[100];
    int ce_marks,lpw_marks,see_marks;
    float percentage;
    int attendance;
    struct Student *next;

}* head, *start;

void insert(int rollnumber, char* name, char* course, int ce_marks,int lpw_marks,int see_marks,float percentage, int attendance)
{
    struct Student * student = (struct Student *) malloc(sizeof(struct Student));
    student->rollnumber = rollnumber;
    strcpy(student->name, name);
    strcpy(student->course, course);
    student->ce_marks = ce_marks;
    student->lpw_marks = lpw_marks;
    student->see_marks = see_marks;
    student->percentage=percentage;
    student->attendance=attendance;
    student->next = NULL;

    if(start==NULL){
        start = student;
        head = start;
        start->next = NULL;
    }
    else{
        start->next = student;
        start = student;
        start->next = NULL;
    }

}

void search(int rollnumber)
{
    struct Student * temp = head;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber){
            printf("\n\tThe Record is: ");
            printf("\n\n");
            printf("\tRoll Number: %d\n", temp->rollnumber);
            printf("\tName: %s\n", temp->name);
            printf("\tCourse: %s\n", temp->course);
            printf("\tCE component Marks: %d\n", temp->ce_marks);
            int ce=temp->ce_marks;
            printf("\tLPW component Marks: %d\n", temp->lpw_marks);
            int lpw=temp->lpw_marks;
            printf("\tSEE component Marks: %d\n", temp->see_marks);
            int see=temp->see_marks;
            return;

        }
        temp = temp->next;
    }
    printf("\n\tStudent with roll number %d is NOT found !!\n", rollnumber);
}

void update(int rollnumber)
{
    int totallecture, presentlecture;
    struct Student * temp = head;
    while(temp!=NULL){

        if(temp->rollnumber==rollnumber){
            printf("\n\tEnter new name: ");
            scanf("%s", temp->name);
            printf("\tEnter new marks in CE: ");
            scanf("%d",&temp->ce_marks);
            printf("\tEnter new marks in LPW: ");
            scanf("%d",&temp->lpw_marks);
            printf("\tEnter new marks in SEE: ");
            scanf("%d",&temp->see_marks);
            printf("\tEnter new Course:");
            scanf("%s",temp->course);
            printf("\tEnter new total number of lectures: ");
            scanf("%d",&totallecture);
            printf("\tEnter new number of lectures attended by student: ");
            scanf("%d",&presentlecture);
            int attend = presentlecture*100/totallecture;
            temp->attendance = attend;
            printf("\n\tUpdation Successful!!\n");
            return;
        }
        temp = temp->next;

    }
    printf("\n\tStudent with roll number %d is not found !!\n", rollnumber);

}

void Delete(int rollnumber)
{
    struct Student * ptr = head;
    struct Student * preptr = head;
    while(ptr!=NULL)
    {
        if(ptr->rollnumber==rollnumber)
        {
            if(ptr==preptr)
            {
                head = head->next;
                free(ptr);
            }
            else
            {
                preptr->next = ptr->next;
                free(ptr);
            }
            printf("\n\tRecord is been successfully deleted !!\n");
            return;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    printf("\n\tStudent with roll number %d is not found in the record!!\n", rollnumber);
    //if record not found
}

void swap(struct Student *a, struct Student *b)
{
    int temp_rollnumber = a->rollnumber;
    a->rollnumber = b->rollnumber;
    b->rollnumber = temp_rollnumber;

    char temp_name[100];
    strcpy(temp_name,a->name);
    strcpy(a->name,b->name);
    strcpy(b->name,temp_name);

    char temp_course[100];
    strcpy(temp_course,a->course);
    strcpy(a->course,b->course);
    strcpy(b->course,temp_course);

    int temp_ce_marks = a->ce_marks;
    a->ce_marks = b->ce_marks;
    b->ce_marks = temp_ce_marks;

    int temp_lpw_marks = a->lpw_marks;
    a->lpw_marks = b->lpw_marks;
    b->lpw_marks = temp_lpw_marks;

    int temp_see_marks = a->see_marks;
    a->see_marks = b->see_marks;
    b->see_marks = temp_see_marks;

    float temp_perc = a->percentage;
    a->percentage = b->percentage;
    b->percentage = temp_perc;

    int temp_attendance = a->attendance;
    a->attendance = b->attendance;
    b->attendance = temp_attendance;
}

void sort_asc()
{
    int flag;
    struct Student *ptr;
    struct Student *lptr = NULL;

    if (head == NULL)
    {
        printf("\n\tList is empty");
    }
    do
    {
        flag = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->rollnumber > ptr->next->rollnumber)
            {
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
    while (flag);
}

void sort_desc()
{
    int flag;
    struct Student *ptr;
    struct Student *lptr = NULL;

    if (head == NULL)
    {
        printf("\n\tList is empty");
    }

    do
    {
        flag = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->rollnumber < ptr->next->rollnumber)
            {
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
    while (flag);
}

void display_asc()
{
    printf("\n\tRecords in Ascending order of Roll Numbers\n");
    struct Student * temp = head;
    if(head==NULL)
    {
        printf("\nList is empty!");
        return ;
    }
    sort_asc();
    while(temp!=NULL){
        printf("\n\tRoll Number: %d\n", temp->rollnumber);
        printf("\tName: %s\n", temp->name);
        printf("\tCourse: %s\n", temp->course);
        printf("\tCE Component Marks: %d\n", temp->ce_marks);
        printf("\tLPW Component Marks: %d\n", temp->lpw_marks);
        printf("\tSEE Component Marks: %d\n", temp->see_marks);
        temp = temp->next;
    }
}

void display_desc()
{
    printf("\n\tRecords in Descending order of Roll Numbers\n");
    struct Student * temp = head;
    if(head==NULL)
    {
        printf("\n\tList is empty!");
        return ;
    }
    sort_desc();
    while(temp!=NULL){
        printf("\n\tRoll Number: %d\n", temp->rollnumber);
        printf("\tName: %s\n", temp->name);
        printf("\tCourse: %s\n", temp->course);
        printf("\tCE component Marks: %d\n", temp->ce_marks);
        printf("\tLPW component Marks: %d\n", temp->lpw_marks);
        printf("\tSEE component Marks: %d\n", temp->see_marks);
        temp = temp->next;
    }
}

float findingpercent(int rollnumber)
{
    struct Student * temp = head;
    int ce,lpw,see;
    while(temp!=NULL){
        if(temp->rollnumber==rollnumber)
        {
            ce=temp->ce_marks;
            lpw=temp->lpw_marks;
            see=temp->see_marks;
            float percent=(float) 0.4*ce + 0.2*lpw + 0.4*see;
            return percent;
        }
        temp = temp->next;
    }
    //printf("Student with roll number %d is NOT found !!\n", rollnumber);
    return 0;
}

float findingattendance(int rollnumber)
{
    struct Student * temp = head;

    while(temp!=NULL){
        if(temp->rollnumber==rollnumber)
        {
            return temp->attendance;
        }
        temp = temp->next;
    }
    //printf("Student with roll number %d is NOT found !!\n", rollnumber);
    return 0;
}

void display_attendance()
{
    printf("\tRoll Number\t\tName\t\tAttendance\n");
    struct Student * temp = head;
    if(head==NULL)
    {
        printf("\nList is empty!");
        return ;
    }
    sort_asc();
    while(temp!=NULL){
        printf("\n\t\t%d", temp->rollnumber);
        printf("\t\t%s", temp->name);
        printf("\t\t %d",temp->attendance);
        printf("%%\n");
        if(temp->attendance<85){
            printf("\n\tNOTE : ATTENDANCE OF STUDENT BELOW 85");
            printf("%%\n");
        }
        temp = temp->next;
    }
}

void sort_percent(){
   int flag;
    struct Student *ptr;
    struct Student *lptr = NULL;

    if (head == NULL)
    {
        printf("\n\tList is empty");
    }

    do
    {
        flag = 0;
        ptr = head;

        while (ptr->next != lptr)
        {
            if (ptr->percentage < ptr->next->percentage)
            {
                swap(ptr, ptr->next);
                flag = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    }
    while (flag);
}

void display_sortpercent()
{
    printf("\n\tRecords as per Percentage\n");
    struct Student * temp = head;
    if(head==NULL)
    {
        printf("\n\tList is empty!");
        return ;
    }
    sort_percent();
    while(temp!=NULL){
        printf("\n\tRoll Number: %d\n", temp->rollnumber);
        printf("\tName: %s\n", temp->name);
        printf("\tCourse: %s\n", temp->course);
        printf("\tPercentage:%f\n",temp->percentage);
        temp = temp->next;
    }
}

void gradestudents()
{
    printf("\tRoll Number\t\tName\t\tGrade\n");
    struct Student * temp = head;
    if(head==NULL)
    {
        printf("\nList is empty!");
        return ;
    }
    sort_asc();
    while(temp!=NULL)
        {
        printf("\n\t\t %d", temp->rollnumber);
        printf("\t\t%s", temp->name);

        printf("\t\t");
        if(temp->percentage<40.0) {
        printf("IF");
        }
    else if(temp->percentage>=50.0 && temp->percentage<60.0) {
        printf("C+");
        }
    else if(temp->percentage>=60.0 && temp->percentage<70.0) {
       printf("B");

        }
    else if(temp->percentage>=70.0 && temp->percentage<80.0) {
        printf("B+");

        }
    else if(temp->percentage>=80.0 && temp->percentage<90.0) {
        printf("A");

        }
    else {
        printf("A+");

        }
        printf("\n");
        temp = temp->next;
        }
}

int login()
{
    int attempts=0;
    char systemUsername[10];
    char systemPassword[10];
    char inputUsername[10] = "admin";
    char inputPassword[10] = "1234";
    do {
        printf("\n  **************************  LOGIN FORM  **************************  \n");
        printf(" \n                       ENTER FACULTY USERNAME: ");
        scanf("%s",&systemUsername);
        printf(" \n                       ENTER PASSWORD: ");
        int p=0;
        do{
            systemPassword[p]=getch();
            if(systemPassword[p]!='\r'){
                printf("*");
            }
            p++;
        }while(systemPassword[p-1]!='\r');
        systemPassword[p-1]='\0';
        //scanf("%s",&systemPassword);
        if(strcmp(systemUsername,inputUsername)==0 && strcmp(systemPassword,inputPassword)==0){
            printf("  \n\n       Welcome to student management system !! Your login was successful");
            printf("\n\n\t\t      Press any key to continue..");
            getch();
            system("cls");
            return 1;
        }
        else{
            printf("\n        Invalid Credentials !! Please Check Username and password\n");
            attempts++;
        }
    }while(attempts<=2);
    if(attempts>2){
        printf("\nYou have reached maximum number of attempts !! Please try later.\n");
    }
    return 0;
}

int main()
{
    system("COLOR 0B");
    head = NULL;
    int choice1,choice2,choice3;
    char name[100];
    char course[100];
    int rollnumber;
    int totallecture,presentlecture;
    int ce_marks,see_marks,lpw_marks;
    float percentage;
    int attendance;
    printf("\n\n\t************************************\n");
    printf("\t     *STUDENT MANAGEMENT SYSTEM*\n");
    printf("\t************************************");
    while(1)
    {
    outer :
    printf("\n\n\t\t      MAIN MENU:");
    printf("\n\n\tTeacher Login\t[1]");
    printf("\n\tStudent Login\t[2]");
    printf("\n\tExit Portal\t[3]");
    printf("\n\n\tEnter your choice: ");
    scanf("%d",&choice1);
    system("cls");
    if(choice1==1){
        int check=login();
        if(check==1){
        do{
        printf("\n\n\t\t         FACULTY MENU:");
        printf("\n\n\tInsert Record\t\t\t\t[1]");
        printf("\n\tSearch Record\t\t\t\t[2]");
        printf("\n\tDelete Record\t\t\t\t[3]");
        printf("\n\tDisplay Records In Ascending Order\t[4]");
        printf("\n\tDisplay Records In Descending Order\t[5]");
        printf("\n\tUpdate Record\t\t\t\t[6]");
        printf("\n\tFinding Percentage of Student\t\t[7]");
        printf("\n\tSorting Records According To Percentage\t[8]");
        printf("\n\tGrade Records Of Students\t\t[9]");
        printf("\n\tAttendance Records Of Students\t\t[10]");
        printf("\n\tExit\t\t\t\t\t[11]");
        printf("\n\n\tEnter Your Choice: ");
        scanf("%d", &choice2);
        system("cls");
        switch (choice2)
        {
            case 1:
                printf("\n\n\t************************************\n");
                printf("\t\t   *INSERT MENU*");
                printf("\n\t************************************\n\n");
                printf("\tEnter Roll Number: ");
                scanf("%d", &rollnumber);
                printf("\tEnter Name: ");
                scanf("%s", name);
                printf("\tEnter Course : ");
                scanf("%s", course);
                printf("\tEnter CE component marks: ");
                scanf("%d", &ce_marks);
                printf("\tEnter LPW component marks: ");
                scanf("%d", &lpw_marks);
                printf("\tEnter SEE component marks: ");
                scanf("%d", &see_marks);
                printf("\tEnter total number of lectures: ");
                scanf("%d",&totallecture);
                printf("\tEnter number of lectures attended by student: ");
                scanf("%d",&presentlecture);
                attendance=presentlecture*100/totallecture;
                percentage=(float) 0.4*ce_marks + 0.2*lpw_marks + 0.4*see_marks;
                insert(rollnumber, name, course, ce_marks,lpw_marks,see_marks,percentage,attendance);
                system("cls");
                break;
            case 2:
                printf("\n\n\t************************************\n");
                printf("\t\t   *SEARCH MENU*");
                printf("\n\t************************************\n\n");
                printf("\tEnter the Roll Number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                //system("cls");
                break;
            case 3:
                printf("\n\n\t************************************\n");
                printf("\t\t   *DELETE MENU*");
                printf("\n\t************************************\n\n");
                printf("\tEnter roll number to delete: ");
                scanf("%d", &rollnumber);
                Delete(rollnumber);
                //system("cls");
                break;
            case 4:
                printf("\n\n\t************************************\n");
                printf("\t      *DISPLAY ASCENDING MENU*");
                printf("\n\t************************************\n\n");
                display_asc();
                //system("cls");
                break;
            case 5:
                printf("\n\n\t************************************\n");
                printf("\t      *DISPLAY DESCENDING MENU*");
                printf("\n\t************************************\n\n");
                display_desc();
                //system("cls");
                break;
            case 6:
                printf("\n\n\t************************************\n");
                printf("\t\t   *UPDATE MENU*");
                printf("\n\t************************************\n\n");
                printf("\tEnter roll number whose details have to be updated: ");
                scanf("%d",&rollnumber);
                update(rollnumber);
                //system("cls");
                break;
            case 7:
                printf("\n\n\t************************************\n");
                printf("\t\t  *PERCENTAGE MENU*");
                printf("\n\t************************************\n\n");
                printf("\tEnter roll number whose total percentage you want to calculate: ");
                scanf("%d",&rollnumber);
                float x=findingpercent(rollnumber);
                printf("\n\tTotal percentage :%f",x);
                //system("cls");
                break;
             case 8:
                printf("\n\n\t************************************\n");
                printf("\t\t   *DISPLAY MENU*");
                printf("\n\t************************************\n\n");
                display_sortpercent();
                //system("cls");
                break;
             case 9:
                printf("\n\n\t************************************\n");
                printf("\t\t   *GRADE MENU*");
                printf("\n\t************************************\n\n");
                gradestudents();
                break;
            case 10:
                printf("\n\n\t************************************\n");
                printf("\t\t   *ATTENDANCE MENU*");
                printf("\n\t************************************\n\n");
                display_attendance();
                break;
            case 11:
                 goto outer;
                 break;
            default:printf("\n\tEnter a valid choice.\n");
            break;
        }
        //system("cls");
    } while (choice2 != 0);
        }

}
    else if(choice1==2){
    do{
        printf("\n\n\t\t    STUDENT MENU:");
        printf("\n\n\tSearch Your Details\t [1]");
        printf("\n\tFinding Total Percentage [2]");
        printf("\n\tFinding Your Attendance  [3]");
        printf("\n\tExit \t\t\t [4]");
        printf("\n\n\tEnter Your Choice: ");
        scanf("%d", &choice3);
        system("cls");
        switch (choice3)
        {

            case 1:
                printf("\n\n\t************************************\n");
                printf("\t\t   *SEARCH MENU*");
                printf("\n\t************************************\n\n");
                printf("\n\tEnter the Roll Number to search: ");
                scanf("%d", &rollnumber);
                search(rollnumber);
                break;

            case 2:
                printf("\n\n\t************************************\n");
                printf("\t\t  *PERCENTAGE MENU*");
                printf("\n\t************************************\n\n");
                printf("\n\tEnter roll number whose total percentage you want to calculate: ");
                scanf("%d",&rollnumber);
                float x=findingpercent(rollnumber);
                printf("\n\tTotal percentage :%f",x);
                break;

            case 3:
                printf("\n\n\t************************************\n");
                printf("\t\t  *ATTENDANCE MENU*");
                printf("\n\t************************************\n\n");
                printf("\n\tEnter your roll number to check attendance: ");
                scanf("%d",&rollnumber);
                int attend=findingattendance(rollnumber);
                printf("\n\tYour attendance is: %d",attend);
                printf("%%");
                if(attend<85)
                {
                    printf("\n\tNOTE : YOUR ATTENDANCE IS BELOW 85");
                    printf("%%\n");
                }
                break;

            case 4:
                 goto outer;
                 break;

            default:printf("\n\tEnter a valid choice.\n");
            break;
        }
    } while (choice3 != 0);
}
    else{
        break;
    }

  }
return 0;
}
