#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h" //https://github.com/rxi/log.c

void init(LinkedList *list) {
	log_info("Inicializando a lista");
	log_trace("init ->");
	list->first = NULL;
	list->size = 0;	
	log_debug("list->first: %p", list->first);
	log_debug("list->size: %d", list->size);
	log_trace("init <-");
}

int enqueue(LinkedList *list, void *data) {
	log_info("Adicionando no final da fila");
	log_trace("enqueue ->");
	Node *no = (Node*)malloc(sizeof(Node));
	if (no == NULL) {
		log_debug("no: %p", no);
		log_error("Memória insuficiente para a operação");
		log_trace("enqueue <-");
		return 0;
	} else {
		no->data = data;
		no->next = NULL;
	}
	if (isEmpty(list)) {
		list->first = no;
	} else {
		Node *aux = list->first;
		log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
		while (aux->next != NULL) {
			aux = aux->next;
			log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);
		}
		aux->next = no;
		log_debug("(aux, aux->next): (%p, %p)", aux, aux->next);		
	}
	list->size += 1;
	log_info("Dado inserido com sucesso!");
	log_debug("no(data,next): %p(%p,%p)", no, no->data, no->next);
	log_trace("enqueue <-");
	
	return 1;	
}

void* dequeue(LinkedList *list) {
	log_info("Removendo o primeiro dado da fila");
	log_trace("dequeue ->");
	if (isEmpty(list)) {
		log_warn("Não há elementos na fila para serem removidos");
		return NULL;
	} else {
		log_debug("list->first: %p", list->first);
		Node *aux = list->first;
		void *data = aux->data;
		list->first = list->first->next;
		list->size -= 1;
		free(aux);
		log_info("Dado removido com sucesso!");
		log_debug("Nó removido: %p", aux);		
		log_debug("data returned: %p", data);
		log_trace("dequeue <-");
		return data;
	}
}

void* first(LinkedList *list) {
	log_info("Buscando o primeiro elemento da lista");
	log_trace("first ->");
	if (isEmpty(list)){
		log_warn("Lista encontra-se vazia!");
		log_trace("first <-");
		return NULL;
	} else {
		log_debug("first: %p", list->first);
		log_trace("first <-");
		return list->first;
	}
}

void* last(LinkedList *list) {
	log_info("Buscando o último elemento da lista");
	log_trace("last ->");
	if (isEmpty(list)){
		log_warn("Lista encontra-se vazia!");
		log_trace("last <-");
		return NULL;
	} else {
		Node *aux = list->first;
		while (aux->next != NULL) {
			log_debug("(aux,next): (%p, %p)");
			aux = aux->next;
		}
		log_trace("last <-");
		return aux->data;
	}
}

int push(LinkedList *list, void *data) {
	log_info("Adicionando no topo da pilha");
	log_trace("push ->");
	Node *no = (Node*)malloc(sizeof(Node));
	if (no == NULL) {
		log_debug("no: %p", no);
		log_error("Memória insuficiente para a operação");
		log_trace("push <-");
		return 0;
	} else {
		no->data = data;
		no->next = list->first;
	}
	list->first = no;
	list->size += 1;
	log_info("Dado inserido com sucesso!");
	log_debug("no(data,next): %p(%p,%p)", no, no->data, no->next);
	log_trace("push <-");
	
	return 1;	
}

void* pop(LinkedList *list) {
	log_info("Removendo o topo da pilha");
	log_trace("pop ->");
	Node *data = dequeue(list);
	log_trace("pop <-");
	return data;
}

void* top(LinkedList *list) {
	log_info("Consultando o topo da pilha");
	log_trace("top ->");
	Node *data = first(list);
	log_trace("top <-");
	return data;
}

bool isEmpty(LinkedList *list) {
	log_info("Verificando se a lista está vazia");
	log_trace("isEmpty ->");
	if (list == NULL) {
		log_error("Parâmetro inválido");
		log_debug("list: %p", list);
		return true;
	}
	log_debug("list->size: %d", list->size);
	log_trace("isEmpty <-");
	if (list->size == 0) {
		return true;
	} else {
		return false;
	}
}

int indexOf(LinkedList *list, void *data, compare equal) {
    log_info("Buscando posição do elemento");
    log_trace("indexOf ->");    
    if (isEmpty(list)) return -1;
    int count=0;
    Node *aux = list->first;
	log_debug("count, aux = %d, %p", count, aux);
    while(aux!=NULL && !equal(aux->data,data)) {
		log_debug("equal: %d", equal(aux->data, data));
        aux=aux->next;
        count++;
		log_debug("count, aux = %d, %p", count, aux);
    }
	log_debug("equal: %d", equal(aux->data, data));
	if (aux == NULL) {
		log_info("Elemento não foi localizado!");
	}
    log_trace("indexOf <-");    
    return (aux==NULL)?-1:count;
}

void* getPos(LinkedList *list, int pos) {
	return NULL;
}

Node* getNodeByPos(LinkedList *list, int pos) {
	return NULL;
}

int add(LinkedList *list, int pos, void *data) {
	return 0;
}

int addAll(LinkedList *listDest, int pos, LinkedList *listSource) {
	return 0;
}

void* removePos(LinkedList *list, int pos) {
	return NULL;
}

bool removeData(LinkedList *list, void *data, compare equal) {
	return false;
}
