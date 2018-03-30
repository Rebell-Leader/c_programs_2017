#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NODE struct node

NODE
{
    char word[100];
    NODE *next;
};

void print (NODE *head);
NODE* deleteWord (NODE *head, unsigned int k);

int main()
{
    unsigned int k = 0;
    NODE *head, *tail;
    NODE *p;
    head = NULL;
    tail = NULL;
    char newWord[40];

    while (*gets(newWord))
    {
        p = (NODE *) malloc (sizeof(NODE));

        strncpy(p->word, newWord, sizeof (newWord));
        p->next = NULL;

        if (!head)
        {
           head = p;
        }
        else
        {
            tail = head;
            while (tail->next != NULL)
            {
                tail = tail->next;
            };
            tail->next = p;
        };

        k++;
    };

    print (head);

    deleteWord (head, k);

    printf ("\n");
    print (head);

    return 0;
};

void print (NODE *head)
{
    NODE *p;
    p = head;
    while (p)
    {
        printf ("%s\n", p -> word);
        p = p -> next;
    };
};

NODE* deleteWord (NODE *head, unsigned int k)
{
    NODE *q, *p, *z;
    char buffer[150];
    q = head;
    z = head;

    strncpy (buffer, z->word, sizeof (z->word));
    while (z -> next)
    {
        while (q -> next)
        {
            if (!strcmp(q -> next -> word, buffer))
            {
                p = q -> next;
                q -> next = p -> next;

                free (p);
            }
            else
            {
                q = q -> next;
            };
        };
        z = z -> next;
        q = z;
        strncpy (buffer, z -> word, sizeof (z -> word));

        if (z == NULL)
            break;
    };
    return head;
};
