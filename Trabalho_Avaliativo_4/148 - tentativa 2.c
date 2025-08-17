/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* sortList(struct ListNode* head) {

    struct ListNode* novo = malloc(sizeof(struct ListNode));
    novo->val = 0;
    novo->next = NULL;

    struct ListNode* pNovo = novo;

    if (head == NULL || head->next == NULL)
        return head;

    while (head != NULL) {
        struct ListNode* atual = head->next;
        struct ListNode* anterior = head;
        struct ListNode* menorAnterior = NULL;
        struct ListNode* menor = head;

        while (atual != NULL) {
            if (menor->val > atual->val) {
                menorAnterior = anterior;
                menor = atual;
            }
            atual = atual->next;
            anterior = anterior->next;
        }

        if (menor == head) {
            head = head->next; 
        } else {
            menorAnterior->next = menor->next;
        }
        menor->next = NULL;

        pNovo->next = menor;
        pNovo = pNovo->next;
    }

    return novo->next;
}
