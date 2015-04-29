/* Programmer: Alex Vincent (avincent@ucsc.edu)
 * hashTable header file - includes all the prototypes for 
 * the functions implemented in hashTable.c with clear
 * pre/post conditions and descriptions. */

/*These two provide a pointer and label to a pointer
 * for the HashStruct user-defined struct*/
typedef struct HashStruct HashStruct;

typedef struct HashStruct * HashHndl;


/* Functions */

/*Pre-condition: Client created a HashHndl pointer
  Post-condition: Will assign, to the pointer, a hashstruct
  Description: Creates and assigns a hash table struct of size maxSize */
HashHndl newHashTable(int maxSize);

/*Pre-condition: Client created hashTable with newHashTable()
  Post-condition: Will hash AND insert the key into the hash table
  Description: Hashes and inserts the key into the hash table
  Note: this function recursively passes down an insert function,
  passing down it's contents to be inserted in each list module*/
  
void insert(HashHndl h, char * title, int key);

/*Pre-condition: Client created hashTable with newHashTable()
  Post-condition: None
  Description: Returns the hash's maximum capacity*/
int getHashSize(HashHndl h);

/*Pre-condition: Client created hashTable with newHashTable()
  Post-condition: None
  Description: Prints the contents of the hash table*/
void printHash(HashHndl h);

/*Pre-condition: Client created hashTable with newHashTable()
 * Post-condition: None
 * Description: Prints the library ID's associated with passed title*/
void lookUp(HashHndl h, char * title);

/*Pre-condition: Client created hashTable with newHashTable()
  Post-condition: Completely freed hashTable
  Description: Frees the contents and the hash table itself.*/
void freeHashTable(HashHndl h);
