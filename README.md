# Estrutura de Dados

Repositório contendo programas desenvolvidos durante as aulas de Estrutura de Dados utilizando C++.

## Descrição

Este repositório reúne os códigos implementados ao longo das aulas de Estrutura de Dados, abordando diversos tópicos fundamentais da disciplina, como listas, pilhas, filas, árvores, entre outros. Cada programa exemplifica a aplicação de conceitos teóricos na prática, utilizando a linguagem C++.

## Pré-requisitos

Para compilar e rodar os programas, você pode utilizar uma das seguintes ferramentas:

- **Compilador C++** (g++ ou outro)
- **CMake** (opcional, mas recomendado para gerenciamento de build)
- **Visual Studio** (com suporte a C++)
- **Visual Studio Code** (com extensões de C++)

## Compilação e Execução

### Usando g++

1. Clone o repositório:
   ```bash
   git clone https://github.com/leticia-pontes/EstruturaDeDados
   ```
   
2. Acesse o diretório do projeto:
    ```bash
    cd EstruturaDeDados
    ```
    
3. Compile o projeto:
    ```bash
    g++ -o bin/programa src/programa.cpp
    ./bin/programa
    ```

### Usando CMake
1. No diretório do projeto, crie uma pasta de build e execute os comandos:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ./bin/programa
    ```
    
### Usando Visual Studio
1. Abra o Visual Studio.
2. Selecione File > Open > Folder e abra a pasta raiz do projeto.
3. O Visual Studio deve detectar automaticamente os arquivos C++ e configurar o ambiente.
4. Para compilar e rodar o projeto, vá para Build > Build Solution e em seguida execute a aplicação com Debug > Start Without Debugging (Ctrl + F5).

### Usando Visual Studio Code
1. Abra o VSCode.
2. Instale as extensões:
   - C++ (Microsoft)
   - CMake Tools (se estiver usando CMake)
3. Abra a pasta do projeto em File > Open Folder.
4. Se estiver usando um task.json para builds com g++:
   - Pressione Ctrl + Shift + B para compilar o projeto.
   - Após a compilação, rode o programa com o terminal ou configure um arquivo launch.json para depuração.
5. Se estiver usando CMake, pressione F7 para compilar e F5 para depurar.
