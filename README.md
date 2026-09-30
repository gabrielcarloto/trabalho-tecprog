# SunnyLand++

Jogo de plataforma 2D em C++17 + SFML, trabalho da disciplina Técnicas de Programação. 1 ou 2 jogadores locais (até 2), 2 fases encadeadas carregadas de tilemap ASCII.

## Pré-requisitos

- `g++` com suporte a C++17
- GNU Make
- SFML 2.x (módulos `graphics`, `window`, `system`)

## Build

O `Makefile` inclui `build/vars.mk` (`Makefile:1`) para achar o SFML. Esse arquivo não está versionado — crie-o antes da primeira compilação, apontando `SFMLDIR` para o prefixo onde ficam `include/` e `lib/` do SFML.

Depois:

```sh
make        # gera build/main.exe
make clean  # remove build/objects
```

## Rodar

Sempre a partir da raiz do repo (os assets são carregados por caminho relativo `./assets` e `./data`):

```sh
./build/main.exe
```

## Controles

| Ação | Jogador 1 | Jogador 2 |
| --- | --- | --- |
| Mover | `A` / `D` | Setas Esquerda / Direita |
| Pular | Espaço | Seta Cima |

Menu: Setas Cima/Baixo navegam, `Return` seleciona. Opções: jogar primeira fase, jogar segunda fase, adicionar jogador (máx. 2), sair. `Escape` fecha o jogo.

## Estrutura

```
src/            código (main, Jogo, Menu, gerenciadores, listas, Observer)
src/entidades/  jogador, inimigos, obstáculos, projétil
src/fases/      as 2 fases + carregador de tilemap
assets/         fonts/ e images/
data/           fases/*/tilemap.txt (tilemaps ASCII)
Makefile        build GNU Make
```

## Tecnologias e padrões

- C++17, SFML 2.x, GNU Make
- Singleton (`Gerenciador_Grafico`), Observer (`src/Observer.h`), listas próprias (`src/Lista.h`)

---

Gráficos do pacote de assets "SunnyLand".
