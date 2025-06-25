/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    
    int contador = 0;
    struct ListNode* temp = head;
    struct ListNode* temp2 = head;

    while(head->next != NULL)
    {
        contador++;
        head = head->next;
    }

    int valor = contador/2;

    for(int i = 0; i < floor(valor); i ++)
    {
        temp2 = temp2->next;
    }

    if(contador % 2 != 0)
    {
        temp2 = temp2->next;
    }

    return temp2;

}