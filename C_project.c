#include <stdio.h>
#include <stdlib.h>
#define pp printf
#define ss scanf
#define sleep usleep(99990);
#define forc(y) for(int i =0;i<y;i++)

struct phone
{
    char brand[59];
    char model[59];
    int stock;
    int price;
};
struct phone dev[40];
//number of phones data == count
int count = 0;


//take data from file
void read()
{
    int i,price;
    char brand[20], model[20];
    FILE *cnt;
    cnt=fopen("count.txt", "r");
    fscanf(cnt,"%d",&count);
    fclose(cnt);

    FILE *fp;
    fp=fopen("start.txt", "r");
    for(i =1; i<=count; i++)
    {
        fscanf(fp,"%s",dev[i].brand );
        //fgets(dev[i].model,100,fp);
        fscanf(fp,"%s",dev[i].model );
        fscanf(fp,"%d",&dev[i].price);
        fscanf(fp,"%d",&dev[i].stock);

    }
    fclose(fp);
};

//show
void show(int i)
{
       system("color 60");

   // printf("____________________________________________________________________________________\n");
    pp("\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    sleep;
    printf("\t\t%c Brand : %s",220,dev[i].brand);
    sleep;
    printf("\n\t\t%c Model : %s",220,dev[i].model);
    sleep;
    printf("\n\t\t%c Price : %d",220,dev[i].price);
    sleep;
    printf("\n\t\t%c Stock : %d\n",220,dev[i].stock);
   // pp("\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
    //printf("____________________________________________________________________________________\n");

}
//write data to file
void write()
{
    FILE *cnt;
    cnt=fopen("count.txt", "w");
    fprintf(cnt,"%d\n",count);
    fclose(cnt);
    FILE *fp;
    int i;
    fp=fopen("start.txt", "w");
    for(i =1; i<=count; i++)
    {
        fputs(dev[i].brand,fp);
        fprintf(fp,"\n");
        fputs(dev[i].model,fp);
        fprintf(fp,"\n");
        fprintf(fp,"%d\n",dev[i].price);
        fprintf(fp,"%d\n",dev[i].stock);
    }
    fclose(fp);

};
void quit()
   {
     char choice[10];
     pp("\n\t\t\t Enter any number for exit: ");
     ss("%s",choice);
     system("cls");
   }


//option 1 from main menu
void take_new()
{
     system("color 75");
    system("cls");
    char choice[10],brand[20],model[20];
    int price;

    printf("\n\n\t\t %c Enter Phone Brand: ", 207);
    fflush(stdin);
    gets(dev[count+1].brand);
    printf("\t\t %c Enter Phone Model: ", 207);
    fflush(stdin);
    gets(dev[count+1].model);
    printf("\t\t %c Enter Phone price: ", 207);
    fflush(stdin);
    scanf("%d",&dev[count+1].price);
    printf("\t\t %c Enter Phone stock: ", 207);
    fflush(stdin);
    scanf("%d",&dev[count+1].stock);
    count++;
    write();
    quit();


};
//option 2 from main menu
void search()
{
           system("color 0b");

    char choice[10];
    int i;
    system("cls");
    printf("\n\t\t%c Enter 1 for Search by Brand.", 254);
    printf("\n\t\t%c Enter 2 for Search by Model.", 254);
    printf("\n\t\t%c Enter 3 for Search by price.\n\n\t\t", 254);
    ss("%s",choice);
    if(strcmp(choice,"1") == 0)
    {

        system("cls");
        char name[20];
        printf("\n\t\t Enter Brand: ");
        ss("%s",name);
        for(i =1; i<=count; i++)
        {
            if(strcmp(dev[i].brand,name)==0)
                show(i);
        }
    }
    else if(strcmp(choice,"2") == 0)
    {

        system("cls");
        char name[20];
        printf("\n\t\t Enter Model: ");
        ss("%s",name);
        for(i =1; i<=count; i++)
        {
            if(strcmp(dev[i].model,name)==0)
                show(i);
        }
    }
    else if(strcmp(choice,"3") == 0)
    {

        system("cls");
        int name;
        printf("\n\t\t Enter Price: ");
        ss("%d",&name);
        for(i =1; i<=count; i++)
        {
            if(dev[i].price == name)
                show(i);
        }
    }
  quit();
};

//option 3 from main menu
void selling()
    {
        system("color 7c");
      char brand[59],model[59];
      int unit,flag =0;
      system("cls");
       pp("\n\t\t =>Enter Brand name for sell: ");
       ss("%s",brand);
       pp("\n\t\t =>Enter model name for sell: ");
       ss("%s",model);
       for(int i = 1;i<=count ;i++)
       {
           if(strcmp(dev[i].brand,brand) == 0 && strcmp(dev[i].model,model) == 0  )
            {  flag =1;
               show(i);
               pp("\n\t\t =>Enter Unit value for sell: ");
               ss("%d",&unit);
               system("cls");
               pp("\n\t\t Successfully sold %d unit of %s %s\n",unit,brand,model);
               pp("\n\t\t Past stocks : %d",dev[i].stock);sleep;
               dev[i].stock-=unit;
               write();
               pp("\n\t\t Current stocks : %d\n",dev[i].stock);

            }
       }
       if(flag == 0){
       system("cls");
       pp("\n\t\t Nothing found");
       }

       quit();
    }
//option 4 from main menu
void deletee()
    {
        system("cls");
        char brand[50],model[50];
        int index=0;
        pp("\n\t\t Enter Brand name to delete: ");
        ss("%s",brand);
        fflush(stdout);
        fflush(stdin);
        pp("\n\t\t Enter Model name to delete: ");
        ss("%s",model);
        fflush(stdout);
        fflush(stdin);
        for(int i = 1;i<=count ;i++)
       {
           if(strcmp(dev[i].brand,brand) == 0 && strcmp(dev[i].model,model) == 0  )
            {
                index =i;
                break;
            }
       }
       if(index)
       {
           for(int i = index;i<count;i++)
           {
               dev[i]=dev[i+1];
           }
           count--;
           write();
           read();
           pp("\n\t\t Successfull!\n");
       }
       else
       {
           pp("\n\t\t Nothing found\n");
       }
     quit();
    }

//option 5 from main menu
void show_all()
{
    system("cls");
    int i;
    for(i=1; i<=count; i++)
        {sleep;
            show(i);
        }
quit();
}

int main()
{
    //write();
    read();
    char input[10];
    for(;;)
    {
        system("color 70");
        pp("\n\n\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205);
        pp("\n\t\t%c Enter 1 to Take New Phone(s);\n",254);
        sleep;
        pp("\t\t%c Enter 2 for Search;\n", 254);
        sleep;
        pp("\t\t%c Enter 3 Selling\n", 254);
        sleep;
        pp("\t\t%c Enter 4 Delete\n", 254);
        sleep;
        pp("\t\t%c Enter 5 show all\n\n\t\t ==>", 254);
        sleep;
        ss("%s",input);
        if(strcmp(input,"1") == 0)
        {
            take_new();
        }
        else if(strcmp(input,"2") == 0)
        {
            search();
        }
        else if(strcmp(input,"3") == 0)
        {
            selling();
        }
        else if(strcmp(input,"4") == 0)
        {
            deletee();
        }
        else if(strcmp(input,"5") == 0)
        {
            show_all();
        }
        else
            {
            system("cls");
            printf("\n\n\t\t\t#error\n");
            quit();
            }
    }
}
