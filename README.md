# NaryTree

**Projeto de Árvore Enária de Pesquisa (ANP)**

## Estrutura do projeto

Para a implementação da árvore enária foi decidido a criação de
2 classes: **NaryTree** (representação da árvore enária em si) e **Node** 
(nó de árvore enária).

Abaixo há a descrição dos métodos e atributos de cada uma, em forma de
um "pseudocódigo", isso pois, é util consultá-lo para entender a lógica
"em alto nível" dos métodos, que posteriormente deverá ser implementado
na linguagem desejada. 

### NaryTree

#### Atributos

- ordem (número máximo de ponteiros por nó)
- raiz (ponteiro para a raiz)

#### Métodos

```
inserirNaArvore(INFO) {    


}
```

```
deletarNaArvore(INFO) {    


}
```

```
printArvore(INFO) {    


}
```
*print em C++ seria overload do <<*


### Node

#### Atributos

- vetor de chaves (informações)
- vetor de nós filhos (vetor de ponteiros)
- ordem (igual ao da árvore em que o nó está)

##### estados
- éRaiz?
- éFolha?
- estáCheio?

#### Métodos



### Outros

**Ambas** as
classes utilizam-se de *templates* para deixar a árvore genérica.
Por uma questão de praticidade, foi implementado nos arquivos *headers*
os métodos, mas é evidente que o **ideal** é implementar em um arquivo
*.cpp*. [Possível solução alternativa](https://isocpp.org/wiki/faq/templates#templates-defn-vs-decl)