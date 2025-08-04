// Meu recorde!! 17 minutos para um exercicio médio, sem uso de fontes externas.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    // Preciso rodar pela lista 1 até achar o valor a 
    // Eu vou ter que ir guardando o valor anterior, para quando eu achar eu ligar o outro com o inicio da lista 2
    // Depois disso, rodo por toda lista 2 ate achar o fim
    // Ligo o fim da lista dois com o valor posterior ao nodo que contem o int b

    struct ListNode* end = list1;
    struct ListNode* end2 = list1->next;
    struct ListNode* auxiliar;

    int contador = 1;

    while(end2->next != NULL) {

        if(contador == a) {
            end->next = list2;

            while(contador != b)
            {
                end2 = end2->next;
                contador++;
            }
            auxiliar = end2->next;

            while(list2->next != NULL)
            {
                list2 = list2->next;
            }

            list2->next = auxiliar;
            return list1;
            
        }

    

        contador++;
        end = end->next;
        end2 = end2->next;
    }

    return list1;

}