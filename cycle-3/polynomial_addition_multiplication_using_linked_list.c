#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int expo;
    struct node *next;
} Node;

// to create a new node
Node *create(int coeff, int expo)
{
    Node *newe = (Node *)malloc(sizeof(Node));
    newe->coeff = coeff;
    newe->expo = expo;
    newe->next = NULL;
}

Node *head1 = NULL, *head2 = NULL, *head3 = NULL, *head4 = NULL, *head5 = NULL;
Node *ptr;

// to insert a new node
void insert(int coeff, int expo, Node **head)
{
    Node *newe = create(coeff, expo);
    if (*head == NULL)
    {
        *head = newe;
        ptr = newe;
    }
    else
    {
        ptr->next = newe;
        ptr = newe;
    }
}

// to create polynomials 1 and 2
void polynomial(int terms, Node **head)
{
    int c, e;
    Node *temp;
    for (int i = 0; i < terms; i++)
    {
        printf("enter coeff of term %d : ", i + 1);
        scanf("%d", &c);
        printf("enter expo of term %d : ", i + 1);
        scanf("%d", &e);
        insert(c, e, head);
    }
}

// remove duplicate eelments from list based on their power
void remove_duplicates(Node *head)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        // Compare the picked element
        // with rest of the elements
        while (ptr2->next != NULL)
        {

            // If powerer of two elements are same
            if (ptr1->expo == ptr2->next->expo)
            {

                // Add their coefficients and put it in 1st element
                ptr1->coeff = ptr1->coeff + ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;

                // remove the 2nd element
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

/*Function to swap the nodes */
Node *swap(Node *ptr1, Node *ptr2)
{
    Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

/* Function to sort the list */
void bubble_sort(Node **head, int count)
{
    Node **h;
    int i, j, swapped;

    for (i = 0; i <= count; i++)
    {

        h = head;
        swapped = 0;

        for (j = 0; j < count - i - 1; j++)
        {

            Node *p1 = *h;
            Node *p2 = p1->next;

            if (p1->expo < p2->expo)
            {

                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }

            h = &(*h)->next;
        }

        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}

// multiply the 2 polynomials
Node *multiply(Node *head1, Node *head2,
               Node *head5)
{

    // Create two pointer and store the
    // address of 1st and 2nd polynomials
    Node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            int coeff, power;

            // Multiply the coefficient of both
            // polynomials and store it in coeff
            coeff = ptr1->coeff * ptr2->coeff;

            // Add the powerer of both polynomials
            // and store it in power
            power = ptr1->expo + ptr2->expo;

            // insert
            insert(coeff, power, &head5);

            // move the pointer of 2nd polynomial
            // two get its next term
            ptr2 = ptr2->next;
        }

        // Move the 2nd pointer to the
        // starting point of 2nd polynomial
        ptr2 = head2;

        // move the pointer of 1st polynomial
        ptr1 = ptr1->next;
    }

    // this function will be invoke to add
    // the coefficient of the elements
    // having same powerer from the resultant linked list
    remove_duplicates(head5);
    ptr = head5;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    bubble_sort(&head5, count);
    return head5;
}

// adding 2 polynomials
Node *add(Node *head1, Node *head2, Node *head3)
{
    Node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo > ptr2->expo)
        {
            insert(ptr1->coeff, ptr1->expo, &head3);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            insert(ptr2->coeff, ptr2->expo, &head3);
            ptr2 = ptr2->next;
        }
        else
        {
            insert(ptr2->coeff + ptr1->coeff, ptr2->expo, &head3);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        insert(ptr1->coeff, ptr1->expo, &head3);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        insert(ptr2->coeff, ptr2->expo, &head3);
        ptr2 = ptr2->next;
    }
    return head3;
}

// subtracting 2 polynomials
Node *sub(Node *head1, Node *head2, Node *head4)
{
    Node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->expo > ptr2->expo)
        {
            insert(ptr1->coeff, ptr1->expo, &head4);
            ptr1 = ptr1->next;
        }
        else if (ptr1->expo < ptr2->expo)
        {
            insert(-ptr2->coeff, ptr2->expo, &head4);
            ptr2 = ptr2->next;
        }
        else
        {
            insert(ptr1->coeff - ptr2->coeff, ptr2->expo, &head4);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    while (ptr1 != NULL)
    {
        insert(ptr1->coeff, ptr1->expo, &head4);
        ptr1 = ptr1->next;
    }
    while (ptr2 != NULL)
    {
        insert(-ptr2->coeff, ptr2->expo, &head4);
        ptr2 = ptr2->next;
    }
    return head4;
}

// driver fxn /main method
int main()
{
    Node *ptr;
    int terms1, terms2;
    // entering terms of polynomials
    printf("Enter no. of terms of polynomial 1: ");
    scanf("%d", &terms1);
    polynomial(terms1, &head1);
    printf("Enter no. of terms of polynomial 2: ");
    scanf("%d", &terms2);
    polynomial(terms2, &head2);
    ptr = head1;
    printf("\n");
    printf("OUTPUT \n------------\n------------ \n \n");
    // printing poly1
    printf("Polynomial 1: \n---------\n");

    while (ptr->next != NULL)
    {
        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }
    printf("%dx^%d \n", ptr->coeff, ptr->expo);
    ptr = head2;
    // printing poly2
    printf("Polynomial 2: \n----------\n");
    while (ptr->next != NULL)
    {
        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }
    printf("%dx^%d \n", ptr->coeff, ptr->expo);

    // Addition
    head3 = add(head1, head2, head3);

    ptr = head3;
    printf("The Sum is: \n-----------\n");
    while (ptr->next != NULL)
    {
        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }
    printf("%dx^%d ", ptr->coeff, ptr->expo);
    printf("\n");

    // Subtraction

    head4 = sub(head1, head2, head4);

    ptr = head4;
    printf("the Difference is: \n-------------\n");
    while (ptr->next != NULL)
    {
        //+ve coefficient
        if (ptr->next->coeff >= 0)
        {
            printf("%dx^%d + ", ptr->coeff, ptr->expo);
            ptr = ptr->next;
        }
        //-ve coefficient
        else
        {
            printf("%dx^%d ", ptr->coeff, ptr->expo);
            ptr = ptr->next;
        }
    }
    printf("%dx^%d ", ptr->coeff, ptr->expo);
    printf("\n");
    // Multipilication
    head5 = multiply(head1, head2, head5);

    ptr = head5;
    printf("Product is : \n--------------\n");
    while (ptr->next != NULL)
    {
        printf("%dx^%d + ", ptr->coeff, ptr->expo);
        ptr = ptr->next;
    }
    printf("%dx^%d \n", ptr->coeff, ptr->expo);
}
