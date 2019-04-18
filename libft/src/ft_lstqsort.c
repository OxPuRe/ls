#include "libft.h"

int     ft_cmp_ls_name()
{
    return
}

t_list  *partition(t_list *head, t_list *end, t_list **newHead, t_list **newEnd,
                int (*compar)(const void *, const void *))
{
    t_list  *pivot;
    t_list  *prev;
    t_list  *cur;
    t_list  *tail;
 
    pivot = end;
    prev = NULL;
    cur = head;
    tail = pivot;
    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->content < pivot->content)
        {
            // First node that has a value less than the pivot - becomes
            // the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;  
            cur = cur->next;
        }
        else // If cur t_list is greater than pivot
        {
            // Move cur t_list to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            t_list *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot content is the smallest element in the current list,
    // pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot t_list
    return pivot;
}

//here the sorting happens exclusive of the end node
t_list *ft_lstqsort_rec(t_list *head, t_list *end,
            int (*compar)(const void *, const void *))
{
    t_list  *newHead;
    t_list  *newEnd;

    newHead = NULL;
    newEnd = NULL;
    // base condition
    if (!head || head == end)
        return head;
 
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    t_list *pivot = partition(head, end, &newHead, &newEnd, compar);
 
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the t_list before the pivot t_list as NULL
        t_list *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 
        // Recur for the list before pivot
        newHead = ft_lstqsort_rec(newHead, tmp, compar);
 
        // Change next of last t_list of the left half to pivot
        tmp = ft_lstend(newHead);
        tmp->next =  pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = ft_lstqsort_rec(pivot->next, newEnd, compar);
 
    return newHead;
}

void ft_lstqsort(t_list **lsthead, int (*compar)(const void *, const void *))
{
    (*lsthead) = ft_lstqsort_rec(*lsthead, ft_lstend(*lsthead), compar);
    return;
}