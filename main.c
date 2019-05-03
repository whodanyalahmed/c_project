/********************************************
Project Name:Medical Management System
Author: Danyal Ahmed,Bilal khan,abid hussain & Almas Shamim
Source filename:main.c
Date: 30th-April-2019.
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct items
{
  int quantity;
  char item[100];
  int price;
  int tprice;
}item;
struct cust
{
  char name[20];
}cust;


void post(){
  system("clear");
  printf("\n\t\t\t\t\t\tInvoice!\n\n");
  printf("\nEnter customer name: ");
  scanf("%s",&cust.name);
  printf("Enter item name: ");
  scanf("%s",&item.item);
  printf("Enter the quantity: ");
  scanf("%d",&item.quantity);
  printf("Enter the price of the product:");
  scanf("%d",&item.price);
  // FILE *fp;
  FILE *fn;
  FILE *ft;
  item.tprice = item.quantity * item.price;

  fn = fopen("customer_Detail.txt","a+");
  ft = fopen("time.txt","a+");
  fprintf(fn,"%s\t%s\t%d\t%d\t%d\t\n",item.item,cust.name,item.quantity,item.price,item.tprice);
  
char date[50] = __DATE__;
char todaytime[50] = __TIME__; 

  fprintf(ft,"%s\t%s\n",date,todaytime);
  fclose(fn);
  fclose(ft);
  // fclose(fp);  
}  

void getinfo(){

  char ch[10000];
  char str[2000];
  FILE *ft;
  FILE *fn;
  // printf("%s",fgetc(fo));
  system("clear");
printf("\n\t\t\t\t\t\tReading File....!\n\n");
// fo = fopen("products.csv", "r"); // read mode
char filename[20][20] = {"customer_Detail.txt","time.txt"};
fn = fopen(filename[0],"r");
ft = fopen(filename[1],"r");
   if  (fn == NULL || ft == NULL)
   {
      perror("Error wile opening the file.\n");
      exit(EXIT_FAILURE);
   }
 
  
  fscanf(fn,"%s",&item.item);
  fscanf(fn,"%s",&cust.name);
  fscanf(fn,"%d",&item.quantity);
  fscanf(fn,"%d",&item.price);
  fscanf(fn,"%d",&item.tprice);
  fscanf(fn,"%s",&item.item);
  fscanf(ft,"%[^\n]",&ch);
  printf("=================================================================================\n");
  printf("%d - %s of rupees %d buyed by %s total:Rs %d  on Date:%s\n",item.quantity,item.item,item.price,cust.name,item.tprice,ch);
  printf("=================================================================================\n");
  fclose(fn);

}


void main(void) {
 int op;
 
 start:  
system("clear");
  printf("\t\t\t\t\t\tMedical Managament System");
  printf("\n\t\t\t\t\t\t=========================");
  printf("\n\n\t1 - Administrator");
  printf("\n\t2 - Exit");
  printf("\n\nEnter operation: ");
  scanf("%d",&op);
  char password[10] = "password";
  char temp[10];
  
    int i;
    int operation;


  switch (op)
  {
    case 1:
    
    for (i = 0;i<8;i++){
        system("clear");
        printf("\t\t\t\t\nAdministrator\n\n");
        printf("=============\n");
        printf("\n");
        
        printf("Enter Password:");
        scanf("%s",&temp);
        
        if(strcmp(temp,password)){
          printf("Password is : %s ",password);
          printf("You entered : %s ",temp );
          printf("\n\nAccess Denied!\n");
          break;
                                  }
        else{
          printf("\n\nAccess Granted!\n");
          admin:

  printf("\t\t\t\t\t\tAdministrator");
  printf("\n\t\t\t\t\t\t============");
  printf("\n\t1 - Invoice");
  printf("\n\t2 - Reading Invoice");
  printf("\n\t3 - back to main menu");
  printf("\n\nEnter operation: ");
  scanf("%d",&operation);
  switch (operation)
{
    case 1:
      post();
      goto admin;
  
    case 2:
    getinfo();
    goto admin;
    case 3:
    goto start;
    default:
    printf("please! select the correct number...\n");
      goto admin;
  }
            }
    }
      goto start;
    case 2:
    printf("\n\t\t\t\t\t\tExiting......\n\n");
    system("clear");
    system("clear");
    break;
    default:
    printf("please! select the correct operation...");
      goto start;
  }
} 