#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// intercala duas listas ordenadas usando um nó sentinela chamado "temp"

static struct ListNode* mergeLists(struct ListNode* a, struct ListNode* b) {
    struct ListNode temp = (struct ListNode){0, NULL}; // sentinela local
    struct ListNode* novo = &temp;  // cabeça "fake"
    struct ListNode* pNovo = novo;  // cauda que vai avançando

    while (a && b) {
        if (a->val <= b->val) {
            pNovo->next = a;
            a = a->next;
        } else {
            pNovo->next = b;
            b = b->next;
        }
        pNovo = pNovo->next;
    }
    pNovo->next = (a ? a : b);
    return novo->next; // primeiro real depois do sentinela
}

struct ListNode* sortList(struct ListNode* head) {
    int ordenado = 1; (void)ordenado;
    struct ListNode* menorAnterior = NULL; (void)menorAnterior;

    if (!head || !head->next) return head;

    // split: slow/fast
    struct ListNode* anterior = head;        // slow
    struct ListNode* atual = head->next;     // fast

    while (atual && atual->next) {
        anterior = anterior->next;           // slow++
        atual = atual->next->next;           // fast+=2
    }

    // "menor" aponta para o início da 2ª metade
    struct ListNode* menor = anterior->next; // mid
    anterior->next = NULL;                   // corta a lista

    // ordena recursivamente as duas metades
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(menor);

    // intercala e retorna
    return mergeLists(left, right);
}
