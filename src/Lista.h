#pragma once
#include <cstddef>

namespace Jogo::Listas {
template <class TL> class Lista {
public:
  Lista() = default;
  ~Lista();

  template <class TE> class Elemento;
  template <typename TI> class ListIterator;

  void incluir(TL *);
  void remover(TL *);

  Elemento<TL> *getPrimeiro() const { return pPrimeiro; }
  Elemento<TL> *getUltimo() const { return pUltimo; }

  std::size_t getTamanho() const { return tamanho; }

  ListIterator<TL> begin() { return ListIterator<TL>(pPrimeiro); }
  ListIterator<TL> end() { return ListIterator<TL>(nullptr); }

private:
  Elemento<TL> *pPrimeiro = nullptr;
  Elemento<TL> *pUltimo = nullptr;
  std::size_t tamanho = 0;

public:
  template <class TE> class Elemento {
  public:
    Elemento() = default;
    ~Elemento() = default;

    void setProximo(Elemento<TE> *p) { pProx = p; }
    Elemento<TE> *getProximo() { return pProx; }

    TE *getInfo() { return pinfo; }
    void setInfo(TE *p) { pinfo = p; }

  private:
    Elemento<TE> *pProx = nullptr;
    TE *pinfo = nullptr;
  };

  template <typename TI> class ListIterator {
    using ValueType = TI *;
    using PointerType = ValueType *;
    using Elemento = typename Lista<TI>::template Elemento<TI>;

    Elemento *pElemento;

  public:
    ListIterator(Elemento *ptr) : pElemento(ptr) {}
    ~ListIterator() { pElemento = nullptr; }

    ListIterator &operator++() {
      pElemento = pElemento->getProximo();
      return *this;
    }

    ListIterator operator++(int) {
      ListIterator it = *this;
      ++(*this);
      return it;
    }

    PointerType operator->() { return &pElemento->getInfo(); }
    ValueType operator*() { return pElemento->getInfo(); }

    bool operator==(const ListIterator &other) const {
      return pElemento == other.pElemento;
    }

    bool operator!=(const ListIterator &other) const {
      return !(*this == other);
    }
  };
};

template <class TL> Lista<TL>::~Lista() {
  Elemento<TL> *aux = pPrimeiro, *aux2 = aux;

  while (aux != nullptr) {
    aux2 = aux->getProximo();
    delete aux;
    aux = aux2;
  }
}

template <class TL> void Lista<TL>::incluir(TL *info) {
  Elemento<TL> *el = new Elemento<TL>;
  el->setInfo(info);

  if (pPrimeiro == nullptr) {
    pPrimeiro = el;
  } else {
    pUltimo->setProximo(el);
  }

  pUltimo = el;
  tamanho++;
}

template <class TL> void Lista<TL>::remover(TL *info) {
  Elemento<TL> *aux = pPrimeiro, *anteriorAux = pPrimeiro;

  while (aux != nullptr) {
    if (aux->getInfo() == info) {
      anteriorAux->setProximo(aux->getProximo());

      if (aux == pPrimeiro) {
        pPrimeiro = aux->getProximo();
      } else if (aux == pUltimo) {
        pUltimo = anteriorAux;
      }

      delete aux;
      tamanho--;

      break;
    }

    anteriorAux = aux;
    aux = aux->getProximo();
  }
}
} // namespace Jogo::Listas
