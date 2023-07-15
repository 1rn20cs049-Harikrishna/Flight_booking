#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 50

/****************************Structures******************************************/

struct profile
{
  char firstname[50];
  char lastname[50];
  char email[60];
  char password[30];
  char mobile[30];
  struct profile *link;
} ;
typedef struct profile nd;

struct reserve
{
    char passport[40];
    char name[50];
    int seat_num;
    char email[50];
    struct reserve *link;
}*stream,*begin,*cancelnode;
typedef struct reserve rs;

struct booking
{
  char name[60];
  char from[60];
  char to[60];
  char dept[100];
  char returntime[60];
  char traveller[50];
   int age;
  struct booking *link;
};
typedef struct booking bk;

struct flights
{
  char state[50];
  char name[300];
  struct flights *link;
};
typedef struct flights ft;


/*--------------------Functions-------------------------------------*/

/****************Header function ******************/

void page_1_display ()
{
    
  printf("*****************************************************************************************************************");
  printf("\n---------------------------------------------------------------------------------------------------------------");
  printf("\n");
  printf("✈️  Book your flights now  with Together.com");
   //printf(" _________________________________________\n");
   printf("\n\tFly Anywhere. Fly Everywhere❤️  \n\n ");
  printf("\t\t\t  Welcome ");
  printf("\n");
   printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s\n",__TIME__);
    printf("\t\t\t\t    To  "); 
  printf("\t\t\t\t\t\t\t\t\t%s\n",__DATE__);
 
  printf("\n\t\t\t\t\t\tOnline Flight Booking System\n");
  printf("\n\n\n");
  printf("\n\n\t\t\t\t\t\t\t\t\t\t\t1  Sign Up \n\n\t\t\t\t\t\t\t\t\t\t\t2  Already a member ? login in\t\t\t\t\t\n");  
   printf("\n---------------------------------------------------------------------------------------------------------------\n");
   printf("*****************************************************************************************************************");
 
  printf("\n\n");
  printf("Menu Bar ");
  printf("\n_______________________________________________________________________________________________________________________");
  //printf("\n\n\t\t\t\t\t\t1  Sign Up \n\t\t\t\t\t\t2  Already a member ? login in\t\t\t\t\t\n");
 printf("\n\n\t\t\t\t3  My Account  \t\t4   Flights Available\t\t5  New Booking\n\n\t\t\t\t6   Status\t\t 7 Cancellation");
  
  printf("\n______________________________________________________________________________________________________________________");
  
}

/***************************signup_page***************************************/

nd *signup_page (nd * head)
{
  nd *t = 0;
  
  FILE *fp = 0;
  fp = fopen("data.txt","a");
  t = (nd *) malloc (sizeof (nd));
  printf ("\n\tSIGN UP\n");
  printf ("\t\t\tFirst Name : ");
  scanf ("%s", t->firstname);
  printf("\n");
  printf ("\t\t\tLast Name  : ");
  scanf ("%s", t->lastname);
  printf("\n");
  printf ("\t\t\tE-mail\t   : ");
  scanf ("%s", t->email);
  printf("\n");
  printf ("\t\t\tPassword   : ");
  scanf ("%s", t->password);
  printf("\n");
  printf ("\t\t\tMobile\t   : ");
  scanf ("%s", t->mobile);
  printf("\n");
  t->link = 0;
  
  if(head!=0) {
      t->link = head;
  }
  
  //fprintf(fp,"\n%s :\n",strcat(t->firstname,t->lastname));
  fprintf (fp, "%s\n", t->firstname);
  fprintf (fp, "\t%s\n", t->lastname);
  fprintf (fp, "\t%s\n", t->email);
  fprintf (fp, "\t%s\n", t->password);
  fprintf (fp, "\t%s\n", t->mobile);
  printf("\n\n\t\t\t\t\t\t\t To Login and Proceed please type 2 ");
  fclose(fp);
  return t;
  
}


int login_page (nd * head)
{
  
   nd *t = 0;
    int c = 0;
    char first[50];
    char pass[50];
    
    if(head == 0)
    {
        printf("Please Create Your Account\n");
        head=signup_page (head);
    }
    //for(t=head; t!=0; t=t->link,cnt++);
    printf("\n\n\n\tLogin Page \n\n");
    printf ("\t\t\t\tE-mail    : ");
    scanf ("%s", first);
    printf ("\n\t\t\t\tPassword   : ");
    scanf ("%s", pass);
    t=head;
    while (t!= NULL)
    {
        if(strcmp(first,t->email) == 0 && strcmp(pass,t->password) == 0)
        {
          printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\tLogin Successfully !\n\n\n");
          return c;
        }
        else
        c=login_page(head);
        
        c++ ;
        t = t->link ;
    }
  
}

void my_account(nd *head,int x)
{
    nd *t;
    int c=0;
    //t=head;
    printf("\n\n\n\tDetails : \n");
    for(t=head,c;c!=x;t=t->link,c++);
     printf ("\t\tUser Name : %s", t->firstname);
      printf (" %s\n", t->lastname);
     printf ("\t\tE-mail : %s\n", t->email);
     printf ("\t\tMobile : %s\n", t->mobile);
 
}

/*********************Airport data stored in stack *****************************************************/

ft *   accept_data(ft* top,FILE *fd,int y)
{
     
    ft *val;
     val = (ft *)malloc(sizeof(ft));
    
    fscanf(fd, "%s %s", val->state, val->name);
    printf("\n\n\t %d\t%s\t\t%s\n", y,val->state, val->name);
     val->link = 0;
     if(top!=0)
     {
         val->link=top;
     }
   
     return val;
    
 }



void flight_menu()
 { 
  
     printf("\nAvailable flights : \n\n");
      printf("____________________________________________________________________________________________________\n");
     printf("\n\tSN no \t City\t  \t Airport Name");
  
 }
 
 
/************************************************************************************************************/

bk *  page_2_display(bk *book)
{
  bk *temp = NULL;
   temp=book;
   temp = (bk *)malloc(sizeof(temp));
   temp->link=0;
       printf("\t____________________________________________________________________________________________\n");
    printf("\n \t From  \t");
    printf("\t To \t");
    printf("\t Departure \t");
    printf("\t Return \t");
    printf("\t Travellers \n");
    printf("\t___________________________________________________________________________________________\n");
    printf("\n\n\tFrom\t\t: ");
    scanf("%s",temp ->from);
    printf("\n \tTo\t\t: ");
    scanf("%s",temp ->to);
    printf("\n");
    printf(" \tDeparture\t: ");
   
    scanf("%s",temp ->dept);
    printf("\n");
    printf(" \tReturn\t\t: ");
  
    scanf("%s",temp ->returntime);
    printf("\n");
    printf(" \tTravellers     : ");
   
    printf("\t Age > 12 : Adult");
    printf("\n\t\t\t\t Age < 11 and Age > 2 :  Children ");
    printf("\n\t\t\t\t Age < 2 : Infant");
    printf("\n\t");
    printf("Please provide Your age : ");
    scanf("%s",temp ->traveller);
   
       if(book!=0);
          temp->link=book;
     return temp;
    
}
/********************************Cancellation Module ************************************/
void cancel()
{
  stream = begin;   
  
  char passport[6];
  printf("\n\n Enter passort number to delete record?: "); 
  scanf("%s",passport); 
  if (strcmp(begin->passport, passport) == 0)
  {
    cancelnode= begin;
    begin = begin->link;
    free(cancelnode);   
    printf(" Booking has been deleted");
    return;

  }

  while (stream->link)         
   if (strcmp(stream->link->passport, passport) == 0)
    {
      cancelnode = stream->link;
      stream->link= stream->link->link;
      free(cancelnode); 
      printf("Booking has been deleted ");
      return;
    }
  //stream = stream->link;

  printf("\t\t\tPassport number is wrong please check your passport\n\n");

}


   
/*********Displaying Booking details After once it's done ****************/

 void after_booking()
 {
     
  printf("\n\n\n\n\tBOOKING CONFIRMATION\n\n");
  printf("\t Dear %s\n\n",stream->name);
  printf("\n\n\n\t\t\tCongratulations! Your flight Booking is Confirmed !\n\n");
  printf("\t\tPassport Number :%s",stream->passport);
  printf("\n\t\tYour seat number  %d",stream->seat_num);
  printf("\n\n\t\t\tReference Number : ");
  printf("%d\n",rand());
  printf("\n\t\t\tBooking Date     : ");
  printf("%s",__DATE__);
  printf("\n\n\tFlight details \n");
  printf("\n\n\t\tDuration  : %d hour\n",rand()%7);
  printf("\n\n Passenger Details :\n");
  printf("\n\t");
  printf("\n\t");
  printf("\n\t");
 }
 
 
 void details()
  {         
    stream = (struct reserve*)malloc(sizeof(struct reserve)); 
    printf("\n\t Enter your passport number:");
    scanf("%s",stream->passport);   //reads a line from stdin and stores it into the string pointed
    printf("\n\t Enter your  name:");
    scanf("%s",stream->name); 
    printf("\n\t Enter your email address:");
    scanf("%s",stream->email);
}

 void reserve(int x) 
 {
  stream = begin; 
  if (begin == NULL) 
  {
    
    begin = stream = (struct reserve*)malloc(sizeof(struct reserve));     
 
    details();
    stream->link= NULL;  
  
    stream->seat_num = x;
    return; 
  }
  else if (x > 25) // FULL SEATS
  {
    printf("\n\t\t Seat Full.");
    return;
  }
  else
  {                                   
    // next user                   
    while (stream->link)
      stream = stream->link;
    stream = (struct reserve*)malloc(sizeof(struct reserve));
    stream = stream->link;
    details();
    stream->link = NULL;
    stream->seat_num = x;
    return;
  }
}


 

int main ()
{

  page_1_display ();
  int cn,i,x,num=1,n= 0;
  int y;
  nd *head = 0;
  bk *book = 0;
  ft *flights = 0;

      
      FILE *fd;
      fd=fopen("airportdata.txt","r");
      if(fd == 0)  {
          printf("File is not opend\n");
      }

  for (int i = 0; i < 6; i++)
    { 
      printf("\n\n\tEnter the choice : ");
        scanf ("%d", &n);
        printf("\n.......................................................................\n");
     
         switch(n)
         {
           case 1 : //for(x=0;x<2;x++)
                     head=signup_page(head); break;
           case 2 : cn = login_page(head);
                    printf("\t\t\tTo view your Account details : type 3\n");
                    printf("\n\n\t\t\tTo view flights that are Available : Type 4 \n");
                    break; 
           case 3 : my_account(head,cn); 
                    printf("\n\n \t\t\tTo view Flights That are Available : type 4\n");                            
                      break;
           case 4 : flight_menu();
                      for( y=1;y<33;y++)
                     accept_data(flights,fd,y);
                    
                    
           printf("____________________________________________________________________________________________________\n\n\n");

                          break; 
           
           case 5  : printf("\n\n\t\tTo Book tickets : please type 5\n\n");
                        reserve(num);
                        book=page_2_display(book);
                        after_booking(book);
                           break;
            
         case 6 :     after_booking(book);
                     break;
         case 7: cancel(); break;
          default : printf("Invalid choice\n");
                    exit(0);

         }   


    } 

      return 0;
}
//Done by Harikrishna 
// 3rd SEM mini project