#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
  struct node {
    int number;
    struct node *next;
};

struct node *insert (struct node *head) {
   // return new list pointer
    int b = 0;
    struct node *current;
    printf("Insert: ");
    if (1 != scanf("%d", &b) || b == -1)
        return head;
    current = malloc(sizeof(struct node));
    if (current == NULL) {
        printf("Bad malloc!\n");
        exit (1);
        }
    current->number = b;
    current->next = head;
    return insert(current);
}

void display (struct node *list) {
    if (list) {
        printf("%d \t", list->number);
        display(list->next);
    }
}

void free_list (struct node *list) {
    if (list) {
        free_list(list->next);
        free(list);
    }
}

int main(void) {
    struct node *head = NULL;
    head = insert (head);

    printf("List is: ");
    display(head);
    printf("\n");

    free_list (head);
    return 0;

}

int sum_squares (node * p)
{
    typedef struct node
{
   int value;
   struct node * next;
} node;

/* terminal node at the end of the list */
static node SENTINEL_node = { 0, 0 };
    
/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* squares a given integer */
int square (int x)
{
  return x * x;
}

int sum_squares (node * p)
{

    if (p == &SENTINEL_node) // if list is empty
      return 0;
    else
      return (square(p -> value) + sum_squares(p -> next));
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}
int main (void)
{
    int sum;
      node *ns = NULL;
        ns = make_node (1,
            make_node (2,
                   make_node (3,
                          make_node (4,
                              make_node (5,
                                    &SENTINEL_node)))));

    sum = sum_squares (ns); /* sum should equal 55 */
    printf("\n%d", sum);
    free_list(ns);
    return 0;
}


node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    return NULL;
}


int square (int x)
{
  return x * x;
}
