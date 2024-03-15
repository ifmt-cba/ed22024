all: clear ponteiro ponteiro_duplo linkedlist dlinkedlist genlist hash blockchain

ola: clear
	@echo ==========================
	@echo      PROGRAMA OLA
	@echo ==========================
	@echo Compilando o programa olamundo
	@gcc olamundo.c -o ola > /dev/null 2>&1
	@echo Tornando o programa olamundo executável
	@chmod +x ola > /dev/null 2>&1
	@echo Executando o programa olamundo
	@./ola
	@echo ======================================================

ponteiro:
	@echo
	@echo ==========================
	@echo      PONTEIRO SIMPLES
	@echo ==========================
	@echo Compilando o programa ponteiros
	@gcc ponteiro.c -o ponteiro > /dev/null 2>&1
	@echo Tornando o arquivo executável
	@chmod +x ponteiro > /dev/null 2>&1
	@echo Executando o programa ponteiros
	@echo ======================================================
	@echo
	@./ponteiro

ponteiro_duplo:
	@echo
	@echo ==========================
	@echo      PONTEIRO DUPLO
	@echo ==========================
	@echo Compilando o programa ponteiro duplo
	@gcc ponteiro_duplo.c -o ponteiro_duplo > /dev/null 2>&1
	@echo Tornando o arquivo executável
	@chmod +x ponteiro_duplo > /dev/null 2>&1
	@echo Executando o programa ponteiro duplo
	@echo ======================================================
	@echo
	@./ponteiro_duplo

linkedlist:
	@echo
	@echo ==========================
	@echo      LISTA SIMPLES
	@echo ==========================
	@echo Compilando o programa linkedlist
	@gcc --std=c99 -DLOG_USE_COLOR log.h log.c LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	@echo Tornando o arquivo executável
	@chmod +x linkedlist
	@echo Executando o programa linkedlist
	@echo ======================================================
	@echo
	@./linkedlist

dlinkedlist:
	@echo
	@echo ==========================
	@echo      LISTA DUPLA
	@echo ==========================
	@echo Compilando o programa dlinkedlist
	@gcc --std=c99 -DLOG_USE_COLOR log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o dlinkedlist
	@echo Tornando o arquivo executável
	@chmod +x dlinkedlist
	@echo Executando o programa dlinkedlist
	@echo ======================================================
	@echo
	@./dlinkedlist

genlist:
	@echo
	@echo ==========================
	@echo    LISTA GENERALIZADA
	@echo ==========================
	@echo Compilando o programa genlist
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c GeneralizedList.h GeneralizedList.c GeneralizedListTest.c -o genlist
	@echo Tornando o arquivo executável
	chmod +x genlist
	@echo Executando o programa genlist
	@echo ======================================================
	@echo
	./genlist

hash:
	@echo
	@echo ==========================
	@echo    TABELA HASH
	@echo ==========================
	@echo Compilando o programa hash
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c DoublyLinkedList.h DoublyLinkedList.c Hash.h Hash.c HashTest.c -o hash
	@echo Tornando o arquivo executável
	chmod +x hash
	@echo Executando o programa hash
	@echo ======================================================
	@echo
	./hash

blockchain:
	@echo -e "\nCompilando Blockchain"
	gcc log.h log.c sha-256.h sha-256.c Blockchain.h Blockchain.c BlockchainTest.c -std=c99 -o blockchain
	@echo -e "\nHabilitando execução"
	chmod +x blockchain
	@echo Executando o programa blockchain
	@echo ======================================================
	@echo
	./blockchain

clear:
	@echo
	@echo ==========================
	@echo APAGANDO TODOS OS PROGRAMAS
	@echo ==========================
	@echo Removendo o programa ponteiro
	@rm -f ponteiro > /dev/null 2>&1
	@echo Removendo o programa ponteiro duplo
	@rm -f ponteiro_duplo > /dev/null 2>&1
	@echo Removendo o programa linkedlist
	@rm -f linkedlist > /dev/null 2>&1
	@rm -f program.log > /dev/null 2>&1
	@echo Removendo o programa dlinkedlist
	@rm -f dlinkedlist > /dev/null 2>&1
	@echo Removendo o programa genlist
	@rm -f genlist > /dev/null 2>&1
	@echo Removendo o programa hash
	@rm -f hash > /dev/null 2>&1
	@echo Removendo o programa blockchain
	@rm -f blockchain > /dev/null 2>&1

help:
	@echo
	@echo ==========================
	@echo      	   AJUDA
	@echo ==========================
	@echo "all              | Compila e executa tudo"
	@echo "ponteiro         | Ponteiro Simples"
	@echo "ponteiro_duplo   | Ponteiro Duplo"
	@echo "linkedlist       | Lista Simplesmente Ligada"
	@echo "dlinkedlist      | Lista Duplamente Ligada"
	@echo "genlist          | Lista Generalizada"
	@echo "hash             | Tabela Hash"
	@echo "blockchain       | Blockchain"
	@echo "clear            | Apaga todos os programas"
	@echo ======================================================
	@echo
