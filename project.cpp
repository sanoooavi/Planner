#include<iostream>
#include<stdlib.h>
#include "clui.h"
using namespace std;
int cols=get_window_cols();
int rows= get_window_rows();
void straightline(int rows)
{
    cursor_to_pos(rows,1);
    for(int i=1;i<=cols;i++)
      cout<<'-';
}
void line(int rows)
    {
       cursor_to_pos(rows-4,1);
       straightline(rows-4);
        cout<<endl;
    }
struct task {
    char* title;
    char* desc;
    int priority;
    int year;
    int month;
    int day;
    char* status="not finished";
};
task* new_task()
{
    task* t = new task;
    t->title = new char[100];
    t->desc = new char[400];
     cout<<"write the title:"<<endl;
        cin.ignore();
        cin.getline(t->title,100);
       clear_screen();
     cout<<"wanna add some more detail:"<<endl;
     cin.ignore();
        cin.getline(t->desc,400);
        clear_screen();
     cout<<"rate it by it's priority:"<<endl;
         cin>>t->priority;
         while(t->priority>10 ||t->priority<0||(int)t->priority!=t->priority){
             cout<<"invalid input,please try again:"<<endl;
              cin>>t->priority;
         }
         clear_screen();
     cout<<"when should it be finished?"<<endl<<"year:"<<endl;
        cin>>t->year;
        while((int)t->year!=t->year){
             cout<<"invalid input,please try again:"<<endl;
              cin>>t->year;
         }
        clear_screen();
     cout<<"month:"<<endl;
        cin>>t->month;
        while(t->month>12 ||t->month<1||(int)t->month!=t->month){
             cout<<"invalid input,please try again:"<<endl;
              cin>>t->month;
         }
        clear_screen();
     cout<<"day:"<<endl;
         cin>>t->day;
         while(t->day>31 ||t->day<1||(int)t->day!=t->day){
             cout<<"invalid input,please try again:"<<endl;
              cin>>t->day;
         }
         clear_screen();
          cursor_to_pos(10,70);
              change_color_rgb(0,204,0);
         cout<<"Your task added successfully!!";
         reset_color();
         delay(1000);
         clear_screen();
    return t;
}
void sort(task *tasks[],int size){
     //allocatin compeleted and now start sorting
       for (int i = 0; i < size; ++i) {
             task* key = tasks[i];
             int j = i - 1;
        // move key to its position in sorted area
         while (j >= 0 && tasks[j]->priority > key->priority) 
         {
             tasks[j + 1] = tasks[j];
             j = j - 1;
          }
        tasks[j + 1] = key;
    }
}
void print_task_table(task t)
{ 
    cout<<"title:"<<" "<< t.title<<endl;
    cout<<"  "<<"prior:"<<" "<<t.priority<<endl;
    cout<<"  "<<"deadline:"<<" "<<t.year<<"/"<<t.month<<"/"<<t.day<<endl;
    change_color_rgb(0, 255, 255);
    cout<<"  "<<"status:"<<t.status<<endl;
    reset_color();
    cout<<"******************************"<<endl;
}
void add(task** &tasks, int &size)
{
    size++;
    task**new_array=new task*[size];
         for(int i=0;i<size;i++)
         {
           new_array[i]=tasks[i];
             }
      delete[]tasks;
     tasks=new_array;
     tasks[size-1] =new_task();
}
void delete_one_task(task**&tasks,int &size,int input)
{
       size-=1;
         task**new_task=new task*[size];
         for(int i=0;i<input;i++)
         {
                 new_task[i]=tasks[i];
         }
         for(int i=input;i<size;i++)
         {
             new_task[i]=tasks[i+1];
         }
              delete[]tasks;
              tasks=new_task;
               cursor_to_pos(10,70);
              change_color_rgb(255,0,255);
          cout<<"your task is deleted successfully"<<endl;
             reset_color();

}
void delete_task(task**&tasks,int &size)
{
       int input;
       cout<<"so which task do you want to delete?enter it's number on the sort frum down to up"<<endl;
       cin>>input;
       while(input>size || input<0){
           cout<<"invalid input,try again!";
           cin>>input;
       }
       size-=1;
         task**new_task=new task*[size];
         for(int i=0;i<input;i++)
         {
                 new_task[i]=tasks[i];
         }
         for(int i=input;i<size;i++)
         {
             new_task[i]=tasks[i+1];
         }
              delete[]tasks;
              tasks=new_task;
               cursor_to_pos(10,70);
              change_color_rgb(255,0,255);
          cout<<"your task is deleted successfully"<<endl;
            reset_color();

}
void table(task** &, int &);
void show_task(task** &tasks,int size,task &t,int inputt)
{
    char input;
    cout<<"*******************************************************"<<endl;
    cout<<"title:"<<" "<< t.title<<endl;
    cout<<"descr:"<<" "<<t.desc<<endl;
    cout<<"prior:"<<" "<<t.priority<<endl;
    cout<<"deadline:"<<" "<<t.year<<"/"<<t.month<<"/"<<t.day<<endl;
    cout<<"status:"<<" "<<t.status<<endl;
    cout<<"*******************************************************"<<endl;
    cout<<"if you have done the task write 'c':"<<endl;
    cout<<"if you want to delete the task press d"<<endl;
    cout<<"else if you wanna go back to the table write 't':"<<endl;
    cin>>input;
    clear_screen();
    if(input=='c'){
         change_color_rgb(0,128, 0);
         cout<<"now the task is done";
         reset_color();
         clear_screen();
         t.year=0;
         t.month=0;
         t.day=0;
         t.status="done";
         print_task_table(t);
         delay(4000);
         clear_screen();
         table(tasks,size);
    }
    else if(input=='d'){
        delete_one_task(tasks,size,inputt);
         delay(2000);
         clear_screen();
         table(tasks,size);
    }
    else if(input=='t')
    {
        clear_screen();
     table(tasks,size);
    }
    else{
         cursor_to_pos(10,70);
        change_color_rgb(255,0,0);
        cout<<"invalid input,please try again";
        reset_color();
         delay(1000);
         clear_screen();
         show_task(tasks,size,t,input);
    }
}
void table(task** &, int& );
void main_menu(task** &tasks, int &size){
    int input;
       change_color_rgb(0,255, 0);
      cursor_to_pos(10,70);
      cout<<"Wow,look who is here"<<endl;
      cursor_to_pos(12,70);
     cout <<"Press'1'to add a new task "<<endl;
     cursor_to_pos(14,70);
     cout <<"Press'2'to show your tasks"<<endl;
     cursor_to_pos(16,70);
      cout<<"Press'0'to exit "<<endl;
    reset_color();
    line(rows);
    cin>>input;
     if(input==1)
         {
             clear_screen();
             add(tasks,size); 
             main_menu(tasks,size);
         }
         else if(input==2)
         {
             clear_screen();
             if(size==0)
               {
                    cursor_to_pos(10,70);
                   change_color_rgb(255,0,0);
                   cout<<"there is nothing to print";
                   reset_color();
                   delay(8000);
                   clear_screen();
                 main_menu(tasks,size);
                }
             else{
                 int vorudi_sort;
                 cout<<"do you want your tasks sorted?"<<endl<<"press '1' if you want"<<endl<<"else press '0'"<<endl;
                 cin>>vorudi_sort;
                 clear_screen();
                 if(vorudi_sort==1)
                 {
                      sort(tasks, size);
                     for (int i = 0; i < size; ++i)
                        {
                          cout<<(i+1)<<")";
                         print_task_table(*tasks[size-i-1]);
                       }
                  }
                  else {
                      for (int i = 0; i < size; ++i)
                        {
                          cout<<(i+1)<<")";
                         print_task_table(*tasks[size-i-1]);
                       }
                  }
                      delay(3000);
                      clear_screen();
              table(tasks,size);
             }
         }
         else if(input==0){
             clear_screen();
           for (int i = 0; i < size; ++i)
                  {
                 delete[] tasks[i]->title;
                 delete[] tasks[i]->desc;
                 delete tasks[i];
                        }
                 delete[] tasks;
                  cursor_to_pos(10,75);
             change_color_rgb(204,0, 0);
             cout<<"So Bye Bye";
             delay(2000);
              reset_color();
             exit(0);
         }
         else
         {  
              cursor_to_pos(10,70);
               change_color_rgb(255,0,0);
             cout<<" man?are you kidding me?try again!";
             reset_color();
             delay(2000);
             clear_screen();
             main_menu(tasks,size);
         }
}
void table(task** &tasks, int &size){
    char input;
    cout<<"to go back to the menu enter m"<<endl;
    cout<<"to delete a task enter d"<<endl;
    cout<<"if you wanna go through a task  enter t"<<endl;
       cin>>input;
           if(input=='d'){
               
               delete_task(tasks,size);
               delay(2000);
               clear_screen();
               main_menu(tasks,size);
           }
           else if(input=='t'){
               int input;
               cout<<"so which task do you want to see?enter it's number"<<endl;
               cin>>input;
               while(input>size ||input<0){
                   change_color_rgb(255,0,0);
                   cout<<"there is no task by this number,try again";
                   reset_color();
                    cin>>input;
               }
               clear_screen();
               show_task(tasks,size,*tasks[input],input);
           }
           else if(input=='m'){
               clear_screen();
             main_menu(tasks,size);
           }
           else{
               change_color_rgb(255,0,0);
               cout<<"invalid input haji!:|"<<endl;
               reset_color();
               delay(2000);
               clear_screen();
               table(tasks,size);
           }
       }
int main(){
    init_clui();
         task** tasks = new task*[0];
         int task=0;
         main_menu(tasks, task);
    return 0;
}
