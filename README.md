# 🎮 Labirinto Recursivo

Projeto desenvolvido para a disciplina de **Estrutura de Dados** do curso de Tecnologia em Análise e Desenvolvimento de Sistemas da **Universidade Tecnológica Federal do Paraná - UTFPR**.

---

## 👥 Integrantes

- Gabriela de Oliveira Landgraf
- Rafaela de Oliveira Landgraf

## 📌 Sobre o projeto

O **Labirinto Recursivo** é um game desenvolvido em linguagem C no qual o jogador deve percorrer um labirinto até encontrar a saída.

A saída é representada pela letra `X`.

Durante o jogo, o usuário pode movimentar o personagem pelo labirinto e também utilizar uma opção de dica que executa um algoritmo recursivo para verificar se existe um caminho entre a posição atual e a saída.

---

## 🎯 Objetivo

O objetivo do jogador é sair da posição inicial e chegar até a saída do labirinto sem atravessar as paredes.

### Representação do mapa

- `P` - posição atual do jogador
- `#` - parede
- `X` - saída
- espaço vazio - caminho disponível

---

## 🕹️ Controles

| Tecla | Ação |
|------|------|
| `C` | Mover para cima |
| `B` | Mover para baixo |
| `D` | Mover para direita |
| `E` | Mover para esquerda |
| `H` | Verificar se existe um caminho até a saída |
| `Q` | Sair do jogo |

---

## 🧠 Recursividade

A recursividade é utilizada principalmente na função:

```c
encontrarSaida()
```

Essa função analisa uma posição do labirinto e chama a si mesma para explorar as quatro possíveis direções:

```text
          Cima
            ↑

Esquerda ← posição → Direita

            ↓
          Baixo
```

No código, essas chamadas são realizadas da seguinte maneira:

```c
encontrarSaida(linha - 1, coluna, visitado);
encontrarSaida(linha + 1, coluna, visitado);
encontrarSaida(linha, coluna - 1, visitado);
encontrarSaida(linha, coluna + 1, visitado);
```

Cada chamada representa a tentativa de continuar a busca por uma nova posição do labirinto.

---

## 🛑 Condições de parada

Uma função recursiva precisa possuir condições de parada para evitar chamadas infinitas.

No projeto, a busca é interrompida quando:

1. A posição está fora dos limites do labirinto.
2. A posição é uma parede.
3. A posição já foi visitada anteriormente.
4. A saída `X` é encontrada.

Quando a saída é encontrada, a função retorna:

```c
return 1;
```

Quando determinado caminho não pode levar até a saída, a função retorna:

```c
return 0;
```

---

## 🔄 Matriz de posições visitadas

O algoritmo utiliza uma matriz chamada:

```c
visitado
```

Ela registra quais posições já foram analisadas pelo algoritmo.

Isso impede situações como:

```text
C → B → C → B → C → B...
```

Sem esse controle, a função poderia continuar visitando as mesmas posições indefinidamente.

---

## ↩️ Backtracking

A busca também utiliza o conceito de **backtracking**.

Quando o algoritmo tenta seguir por determinado caminho e encontra uma parede ou uma posição sem saída, a chamada atual termina e a execução retorna para uma chamada anterior.

Assim, o algoritmo pode tentar outra direção.

Por exemplo:

```text
        #
        ↑
P → → →
    |
    ↓
outro caminho
```

Se a primeira alternativa não funcionar, o algoritmo retorna e tenta outra possibilidade.

---

## 💻 Tecnologias utilizadas

- Linguagem C
- GCC
- Visual Studio Code
- Git
- GitHub

---

## 📂 Estrutura do projeto

```text
labirinto-recursivo/
│
├── main.c
└── README.md
```

---

## ⚙️ Como compilar

É necessário possuir o compilador GCC instalado.

Abra o terminal dentro da pasta do projeto e execute:

```bash
gcc main.c -o labirinto
```

---

## ▶️ Como executar

### macOS ou Linux

Depois de compilar:

```bash
./labirinto
```

### Windows

Depois de compilar:

```bash
labirinto.exe
```

---

## 🏫 Informações acadêmicas

**Universidade:** UTFPR  
**Curso:** Tecnologia em Análise e Desenvolvimento de Sistemas  
**Disciplina:** Estrutura de Dados  
**Professor:** Clayton Kossoski  