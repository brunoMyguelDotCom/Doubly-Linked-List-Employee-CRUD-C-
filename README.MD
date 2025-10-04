# README

## Português

### Descrição

Este projeto implementa uma **Lista Duplamente Encadeada** em C, permitindo operações CRUD (Criar, Ler, Atualizar, Deletar) de forma dinâmica e eficiente. O código é multiplataforma, funcionando em Windows, Linux e macOS, pois utiliza apenas recursos padrão da linguagem C (bibliotecas `<stdio.h>`, `<stdlib.h>` e `<stdbool.h>`).

### Estrutura do Código

O núcleo do projeto é a estrutura de nó da lista:

```c
typedef struct Node {
  int dado;                // Campo de dados (inteiro)
  struct Node* next;       // Ponteiro para o próximo nó
  struct Node* prev;       // Ponteiro para o nó anterior
} Node;
```

A lista permite percorrer os elementos tanto do início ao fim quanto do fim ao início, facilitando operações em ambas as direções. Todas as funções de manipulação recebem ponteiros para o início (head) e/ou fim (tail) da lista.

### Funcionalidades Específicas

- **Inserção:**  
  - Inserir no início, no fim ou em uma posição específica da lista.
  - Atualiza corretamente os ponteiros `next` e `prev` dos nós vizinhos.
- **Remoção:**  
  - Remove um nó pelo valor do dado ou pela posição.
  - Ajusta os ponteiros dos nós vizinhos para manter a integridade da lista.
- **Busca:**  
  - Procura um elemento pelo valor do dado.
  - Retorna o ponteiro para o nó encontrado ou `NULL` se não existir.
- **Atualização:**  
  - Modifica o valor do campo `dado` de um nó encontrado pela busca.
- **Exibição:**  
  - Mostra todos os elementos da lista do início ao fim (ordem direta) e do fim ao início (ordem reversa), exibindo o valor de cada nó.

### Como funciona

Cada operação manipula explicitamente os ponteiros dos nós para garantir a integridade da lista:
- **Inserção:**  
  - Cria um novo nó com `malloc`.
  - Atualiza os ponteiros `next` e `prev` dos nós afetados.
  - Atualiza o ponteiro `head` ou `tail` se necessário.
- **Remoção:**  
  - Localiza o nó a ser removido.
  - Ajusta os ponteiros dos nós vizinhos para "pular" o nó removido.
  - Libera a memória do nó removido com `free`.
- **Busca:**  
  - Percorre a lista a partir do `head` até encontrar o valor desejado.
- **Atualização:**  
  - Após a busca, altera o campo `dado` do nó encontrado.
- **Exibição:**  
  - Percorre a lista do `head` ao `tail` e vice-versa, imprimindo o campo `dado` de cada nó.

### Como executar

1. **Clone o repositório:**
  ```bash
  git clone <URL_DO_REPOSITORIO>
  cd C_Colab_Cad_Doubly_Linked_List_CRUD
  ```

2. **Compile o projeto:**
  - **Linux/macOS:**
    ```bash
    gcc main.c -o lista
    ./lista
    ```
  - **Windows:**
    ```cmd
    gcc main.c -o lista.exe
    lista.exe
    ```

3. **Utilize o menu interativo exibido no terminal para acessar as operações:**
  - Inserir elemento (início, fim ou posição)
  - Remover elemento (por valor ou posição)
  - Buscar elemento (por valor)
  - Atualizar elemento (por valor)
  - Exibir lista (direta e reversa)

---

## English

### Description

This project implements a **Doubly Linked List** in C, supporting dynamic and efficient CRUD (Create, Read, Update, Delete) operations. The code is cross-platform, working on Windows, Linux, and macOS, as it uses only standard C libraries (`<stdio.h>`, `<stdlib.h>`, `<stdbool.h>`).

### Code Structure

The core of the project is the node structure:

```c
typedef struct Node {
  int data;                // Data field (integer)
  struct Node* next;       // Pointer to the next node
  struct Node* prev;       // Pointer to the previous node
} Node;
```

The list allows traversal from head to tail and from tail to head. All manipulation functions receive pointers to the head and/or tail of the list.

### Specific Features

- **Insertion:**  
  - Insert at the beginning, end, or at a specific position.
  - Correctly updates `next` and `prev` pointers of neighboring nodes.
- **Removal:**  
  - Remove a node by data value or by position.
  - Adjusts neighboring nodes' pointers to maintain list integrity.
- **Search:**  
  - Searches for an element by data value.
  - Returns a pointer to the found node or `NULL` if not found.
- **Update:**  
  - Modifies the `data` field of a node found by search.
- **Display:**  
  - Shows all elements from head to tail (forward order) and tail to head (reverse order), displaying each node's value.

### How it works

Each operation explicitly manipulates node pointers to maintain list integrity:
- **Insertion:**  
  - Allocates a new node with `malloc`.
  - Updates `next` and `prev` pointers of affected nodes.
  - Updates `head` or `tail` pointers if necessary.
- **Removal:**  
  - Locates the node to be removed.
  - Adjusts neighboring nodes' pointers to bypass the removed node.
  - Frees the removed node's memory with `free`.
- **Search:**  
  - Traverses the list from `head` to find the desired value.
- **Update:**  
  - After search, changes the `data` field of the found node.
- **Display:**  
  - Traverses the list from `head` to `tail` and vice versa, printing each node's `data` value.

### How to run

1. **Clone the repository:**
  ```bash
  git clone <REPOSITORY_URL>
  cd C_Colab_Cad_Doubly_Linked_List_CRUD
  ```

2. **Compile the project:**
  - **Linux/macOS:**
    ```bash
    gcc main.c -o lista
    ./lista
    ```
  - **Windows:**
    ```cmd
    gcc main.c -o lista.exe
    lista.exe
    ```

3. **Use the interactive menu in the terminal to access the operations:**
  - Insert element (beginning, end, or position)
  - Remove element (by value or position)
  - Search element (by value)
  - Update element (by value)
  - Display list (forward and reverse)