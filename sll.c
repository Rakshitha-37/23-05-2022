#include <stdio.h>
#include<stdlib.h>

#define SIZE 5

struct sll
{
    int data;
    struct sll *link;
};

struct sll *head = NULL;

void insert(int data);
void print();
void reverse();
void maximum();
void middle();

int main()
{
    int data, i = 0;
    while(i++ < SIZE)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(data);
    }
    print();
    reverse();
    print();
    maximum();
    middle();
}

void insert(int data)
{
  struct sll *temp;
  struct sll *new = (struct sll *)malloc(sizeof(struct sll));
  if(new == NULL)
  {
      printf("Memory not allocated\n");
  }
  else
  {
      new->data = data;
      new->link = NULL;
      if(head == NULL)
      {
          head = new;
      }
      else
      {
          temp = head;
          while(temp->link != NULL)
          {
              temp = temp->link;
          }
          temp->link = new;
       }
  }
}

void print()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct sll *temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void reverse()
{
    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        struct sll *temp = head;
        struct sll *prev = NULL;
        struct sll *next = NULL;
        while(temp != NULL)
        {
            next = temp->link;
            temp->link = prev;
            prev = temp;
            temp = next;
        }
        head = prev;   
    }
}

void maximum()
{
    struct sll *p=head;
    int max=0;
    while(p!=NULL)
    {
        if((p->data)>max)
        {
            max=p->data;
        }
        p=p->link;

   }
   printf("max=%d\n",max);
}

void middle()
{
    struct sll *fast=head;
    struct sll *slow=head;
    while(fast!=NULL&&fast->link!=NULL)
    {
         fast=fast->link->link;
         slow=slow->link;
    }
    printf("middle ele=%d\n",slow->data);
}