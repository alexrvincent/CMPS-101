# Makefile for Asg 4 - by Alex Vincent (avincent@ucsc.edu)
# NOTE HERE: "make [file]" command will create the respective file
# "make clean" will remove unneeded executables and .o files created by this Makefile

catalog : catalog.o hashTable.o titleList.o IDList.o hashFunction.o
	 gcc -std=gnu99 -Wall -Wextra -pedantic -o catalog catalog.o hashTable.o titleList.o IDList.o hashFunction.o

hashDriver : hashDriver.o hashTable.o titleList.o IDList.o hashFunction.o
	gcc -std=gnu99 -Wall -Wextra -pedantic -o hashDriver hashDriver.o hashTable.o titleList.o IDList.o hashFunction.o
	
titleListDriver : titleListDriver.o titleList.o IDList.o
	gcc -std=gnu99 -Wall -Wextra -pedantic -o titleListDriver titleListDriver.o titleList.o IDList.o

IDListDriver : IDListDriver.o IDList.o
	gcc -std=gnu99 -Wall -Wextra -pedantic -o IDListDriver IDListDriver.o IDList.o

catalog.o : hashTable.h hashDriver.c
	 gcc -c -std=gnu99 -Wall -Wextra -pedantic catalog.c

hashDriver.o : hashTable.h hashDriver.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic hashDriver.c

titleListDriver.o : titleList.h titleList.c IDList.h IDList.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic titleListDriver.c

IDListDriver.o : IDList.h IDList.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic IDListDriver.c
    
hashTable.o : hashTable.h hashTable.c titleList.c titleList.h IDList.h IDList.c hashFunction.h hashFunction.c
	 gcc -c -std=gnu99 -Wall -Wextra -pedantic hashTable.c

titleList.o: titleList.h titleList.c IDList.h IDList.c hashFunction.c hashFunction.h
	gcc  -c -std=gnu99 -Wall -Wextra -pedantic titleList.c

IDList.o : IDList.h IDList.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic IDList.c

hashFunction.o : hashFunction.h hashFunction.c
	gcc -c -std=gnu99 -Wall -Wextra -pedantic hashFunction.c

clean :
	rm catalog.o hashTable.o catalog IDList.o titleList.o hashFunction.o hashDriver.o hashDriver IDListDriver IDListDriver.o titleListDriver titleListDriver.o
