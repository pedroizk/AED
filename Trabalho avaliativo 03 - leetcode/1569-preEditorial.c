

struct TreeNode* construtor();

int numOfWays(int* nums, int numsSize) {
    
    // possivel estratégia: primeiro montar a binary tree padrão a partir do array ordenado
    // depois disso: alterarando todas os elementos menos o primeiro, comparar com o inicial
    
    struct TreeNode* inicial = construtor();
    builder(inicial, nums, numsSize);
}

void builder(struct TreeNode* nodo, int* array, int tamanho) {


    for(int i = 0; i < numSize; i++) {
        nodo->val = array[i];

        if(array[i+1] > nodo->val) {
            nodo = nodo->
        }

    }

}


struct TreeNode* construtor() {

    struct TreeNode* novo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novo->val = 0;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}


