# Batalha Naval com Habilidades Especiais em C

Este projeto é uma implementação do clássico jogo **Batalha Naval** em C, com foco em **visualização de áreas de efeito de habilidades especiais**.  
O objetivo é posicionar navios em um tabuleiro 10x10 e demonstrar áreas de impacto de habilidades do tipo **Cone, Cruz e Octaedro**, utilizando matrizes e condicionais.

---

## 📝 Funcionalidades

- Criação de um **tabuleiro 10x10**, representando água (`~`) e navios (`#`).
- Posicionamento de **quatro navios**:
  - Dois navios posicionados horizontal e verticalmente.
  - Dois navios posicionados diagonalmente (`\` e `/`).
- Criação de **áreas de efeito de habilidades**:
  - **Cone**: forma triangular que se expande a partir do ponto de origem.
  - **Cruz**: forma de cruz centrada no ponto de origem.
  - **Octaedro**: forma de losango representando um octaedro visto de frente.
- Sobreposição das habilidades no tabuleiro, com **áreas afetadas marcadas com `*`**.
- Exibição clara e organizada do tabuleiro no console, usando caracteres distintos:
  - `~` = água  
  - `#` = navio  
  - `*` = área de habilidade  

---

## ⚙️ Estrutura do Código

O código está organizado em funções para facilitar a leitura e manutenção:

- `inicializarTabuleiro()` → Inicializa o tabuleiro com água.  
- `exibirTabuleiro()` → Mostra o tabuleiro no console com símbolos para água, navios e habilidades.  
- `posicionarNavioHorizontal()`, `posicionarNavioVertical()`, `posicionarNavioDiagonalDesc()`, `posicionarNavioDiagonalAsc()` → Posicionam os navios no tabuleiro, validando limites e sobreposição.  
- `aplicarHabilidadeCone()`, `aplicarHabilidadeCruz()`, `aplicarHabilidadeOctaedro()` → Criam as matrizes de habilidade dinamicamente e aplicam a área de efeito no tabuleiro.  

---

## 📌 Regras e Simplificações

- O tabuleiro é **fixo 10x10**.  
- Os navios têm **tamanho fixo 3** e suas posições são definidas diretamente no código.  
- As habilidades são aplicadas apenas para **visualização da área de efeito**, não causam dano aos navios.  
- A validação de sobreposição e limites é simplificada para facilitar a implementação.  

---

## 💻 Como Rodar

1. Clone o repositório:

```bash
git clone 
Entre na pasta do projeto:

bash
Copiar código
cd batalha-naval-habilidades
Compile o código com GCC:

bash
Copiar código
gcc batalha_naval.c -o batalha_naval
Execute o programa:

bash
Copiar código
./batalha_naval
Você verá o tabuleiro impresso no console, com navios e áreas de habilidade destacadas.

📚 Exemplo de Saída
bash
Copiar código
* ~ ~ # ~ ~ ~ * ~ ~
~ * # * ~ ~ ~ ~ * ~
# ~ * ~ ~ ~ ~ ~ ~ *
~ ~ # ~ ~ ~ ~ ~ ~ ~
~ ~ ~ ~ ~ # ~ ~ ~ ~
~ * ~ * ~ # * ~ * ~
~ ~ ~ ~ ~ * ~ ~ ~ ~
~ ~ * * * ~ ~ * ~ ~
~ ~ ~ ~ ~ ~ ~ ~ ~ ~
~ # ~ ~ * ~ ~ ~ ~ ~
# → navios

* → áreas de habilidade

~ → água

🔧 Tecnologias
Linguagem: C

Compilador: GCC (ou equivalente)