# README

## Português

### Descrição

Este projeto implementa uma **Lista Duplamente Encadeada** em C, permitindo operações CRUD (Criar, Ler, Atualizar, Deletar) de forma dinâmica e eficiente. O código é multiplataforma, funcionando em Windows, Linux e macOS, pois utiliza apenas recursos padrão da linguagem C (`<stdio.h>`, `<stdlib.h>`, `<stdbool.h>`), sem dependências externas.

### Estrutura do Código

O núcleo do projeto é a estrutura de nó da lista:

```c
typedef struct Node {
  int dado;                // Campo de dados (inteiro)
  struct Node* next;       // Ponteiro para o próximo nó
  struct Node* prev;       // Ponteiro para o nó anterior
} Node;
```

A lista permite percorrer os elementos tanto do início ao fim quanto do fim ao início, facilitando operações em ambas as direções. Todas as funções de manipulação recebem ponteiros para o início (`head`) e/ou fim (`tail`) da lista.

### Funcionalidades Específicas e Funções

- **Inserção**
  - `void inserir_inicio(Node** head, Node** tail, int valor);`
    - Cria um novo nó no início da lista. Atualiza o ponteiro `head` e, se a lista estava vazia, também o `tail`.
  - `void inserir_fim(Node** head, Node** tail, int valor);`
    - Adiciona um novo nó ao final da lista. Atualiza o ponteiro `tail`.
  - `void inserir_posicao(Node** head, Node** tail, int valor, int pos);`
    - Insere um nó em uma posição específica (base 0). Percorre a lista até a posição desejada e ajusta os ponteiros dos nós vizinhos.

- **Remoção**
  - `void remover_valor(Node** head, Node** tail, int valor);`
    - Busca e remove o primeiro nó que contém o valor informado. Ajusta os ponteiros dos nós vizinhos e libera a memória.
  - `void remover_posicao(Node** head, Node** tail, int pos);`
    - Remove o nó na posição especificada. Atualiza os ponteiros `head` ou `tail` se necessário.

- **Busca**
  - `Node* buscar_valor(Node* head, int valor);`
    - Percorre a lista a partir do `head` e retorna o ponteiro para o nó que contém o valor, ou `NULL` se não encontrar.

- **Atualização**
  - `int atualizar_valor(Node* head, int valor_antigo, int valor_novo);`
    - Busca o nó com o valor antigo e altera seu campo `dado` para o novo valor. Retorna 1 se atualizado, 0 se não encontrado.

- **Exibição**
  - `void exibir_direto(Node* head);`
    - Percorre do `head` ao `tail`, imprimindo o campo `dado` de cada nó.
  - `void exibir_reverso(Node* tail);`
    - Percorre do `tail` ao `head`, imprimindo o campo `dado` de cada nó.

### Detalhes Multiplataforma

O código é totalmente multiplataforma:
- Não utiliza bibliotecas específicas de sistema operacional.
- O menu interativo funciona em qualquer terminal (cmd, bash, zsh, etc.).
- O código-fonte pode ser compilado com qualquer compilador C padrão (GCC, Clang, MinGW, MSVC).
- Não há dependências externas, tornando fácil a portabilidade entre sistemas.

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
   git clone https://github.com/brunoMyguelDotCom/Doubly-Linked-List-Employee-CRUD-C-
   cd C_Colab_Cad_Doubly_Linked_List_CRUD
   ```

2. **Compile o projeto:**
   - **Linux/macOS:**
     ```bash
     gcc LisDuplaEncad.c -o lista
     ./lista
     ```
   - **Windows:**
     ```cmd
     gcc LisDuplaEncad.c -o lista.exe
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

This project implements a **Doubly Linked List** in C, supporting dynamic and efficient CRUD (Create, Read, Update, Delete) operations. The code is fully cross-platform, working on Windows, Linux, and macOS, as it uses only standard C libraries (`<stdio.h>`, `<stdlib.h>`, `<stdbool.h>`) and no external dependencies.

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

### Features and Functions

- **Insertion**
  - `void insert_begin(Node** head, Node** tail, int value);`
    - Creates a new node at the beginning. Updates `head` and, if the list was empty, also `tail`.
  - `void insert_end(Node** head, Node** tail, int value);`
    - Adds a new node at the end. Updates the `tail` pointer.
  - `void insert_at(Node** head, Node** tail, int value, int pos);`
    - Inserts a node at a specific position (0-based). Traverses to the desired position and adjusts neighboring pointers.

- **Removal**
  - `void remove_value(Node** head, Node** tail, int value);`
    - Searches and removes the first node containing the value. Adjusts neighboring pointers and frees memory.
  - `void remove_at(Node** head, Node** tail, int pos);`
    - Removes the node at the specified position. Updates `head` or `tail` if needed.

- **Search**
  - `Node* search_value(Node* head, int value);`
    - Traverses from `head` and returns a pointer to the node with the value, or `NULL` if not found.

- **Update**
  - `int update_value(Node* head, int old_value, int new_value);`
    - Searches for the node with `old_value` and updates its `data` field. Returns 1 if updated, 0 if not found.

- **Display**
  - `void display_forward(Node* head);`
    - Traverses from `head` to `tail`, printing each node's `data`.
  - `void display_reverse(Node* tail);`
    - Traverses from `tail` to `head`, printing each node's `data`.

### Cross-Platform Details

- No OS-specific libraries are used.
- The interactive menu works in any terminal (cmd, bash, zsh, etc.).
- The source code can be compiled with any standard C compiler (GCC, Clang, MinGW, MSVC).
- No external dependencies, making it easy to port between systems.

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
   git clone https://github.com/brunoMyguelDotCom/Doubly-Linked-List-Employee-CRUD-C-
   cd C_Colab_Cad_Doubly_Linked_List_CRUD
   ```

2. **Compile the project:**
   - **Linux/macOS:**
     ```bash
     gcc LisDuplaEncad.c -o lista
     ./lista
     ```
   - **Windows:**
     ```cmd
     gcc LisDuplaEncad.c -o lista.exe
     lista.exe
     ```

3. **Use the interactive menu in the terminal to access the operations:**
   - Insert element (beginning, end, or position)
   - Remove element (by value or position)
   - Search element (by value)
   - Update element (by value)
   - Display list (forward and reverse)