/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Crir um novo nodo iniciado em zero
//  Achar o menor numero da linked list e apontar o zero para ele
//  Rodar a lista novamente, achar o nodo com o menor valor da lista, apontar o
//  item que guardamos para ele
struct ListNode* sortList(struct ListNode* head) {

    struct ListNode* novo = malloc(sizeof(struct ListNode));
    novo->val = 0;
    novo->next = NULL;

    struct ListNode* pNovo = novo;

    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* atual = head->next;
    struct ListNode* anterior = head;
    struct ListNode* menorAnterior = NULL;
    int ordenado = 1;
    struct ListNode* menor = anterior;

    for(int i = 0; i< 4; i++) {

        while (atual != NULL) {

            if (menor->val > atual->val) {
                menorAnterior = anterior;
                menor = atual;
                
            }
            atual = atual->next;
            anterior = anterior->next;
        }

        

        while(pNovo->next != NULL)
        {
            pNovo = pNovo->next;
        }
        pNovo->next = menor;
        if(menor != NULL)
            menorAnterior->next = menor->next;
        menor->next = NULL;

        anterior = head;
        atual = head->next; 
        menor = anterior;
        pNovo = novo;
    }

    return novo->next;
}