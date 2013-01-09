/***** This file contains automatically generated code ******
**
** The code in this file has been automatically generated by
**
**     $Header: //depot/PlatformSDK/external/sqlite/3.6/src/keywordhash.h#1 $
**
** The code in this file implements a function that determines whether
** or not a given identifier is really an SQL keyword.  The same thing
** might be implemented more directly using a hand-written hash table.
** But by using this automatically generated code, the size of the code
** is substantially reduced.  This is important for embedded applications
** on platforms with limited memory.
*/
/* Hash score: 167 */
static int keywordCode(const char *z, int n){
  /* zText[] encodes 783 bytes of keywords in 528 bytes */
  /*   REINDEXEDESCAPEACHECKEYBEFOREIGNOREGEXPLAINSTEADDATABASELECT       */
  /*   ABLEFTHENDEFERRABLELSEXCEPTRANSACTIONATURALTERAISEXCLUSIVE         */
  /*   XISTSCONSTRAINTERSECTRIGGEREFERENCESUNIQUERYATTACHAVINGROUP        */
  /*   DATEMPORARYBEGINNERENAMEBETWEENOTNULLIKECASCADELETECASECOLLATE     */
  /*   CREATECURRENT_DATEDETACHIMMEDIATEJOINSERTMATCHPLANALYZEPRAGMA      */
  /*   BORTVALUESVIRTUALIMITWHENWHEREPLACEAFTERESTRICTANDEFAULT           */
  /*   AUTOINCREMENTCASTCOLUMNCOMMITCONFLICTCROSSCURRENT_TIMESTAMP        */
  /*   RIMARYDEFERREDISTINCTDROPFAILFROMFULLGLOBYIFINTOFFSETISNULL        */
  /*   ORDERIGHTOUTEROLLBACKROWUNIONUSINGVACUUMVIEWINITIALLY              */
  static const char zText[528] = {
    'R','E','I','N','D','E','X','E','D','E','S','C','A','P','E','A','C','H',
    'E','C','K','E','Y','B','E','F','O','R','E','I','G','N','O','R','E','G',
    'E','X','P','L','A','I','N','S','T','E','A','D','D','A','T','A','B','A',
    'S','E','L','E','C','T','A','B','L','E','F','T','H','E','N','D','E','F',
    'E','R','R','A','B','L','E','L','S','E','X','C','E','P','T','R','A','N',
    'S','A','C','T','I','O','N','A','T','U','R','A','L','T','E','R','A','I',
    'S','E','X','C','L','U','S','I','V','E','X','I','S','T','S','C','O','N',
    'S','T','R','A','I','N','T','E','R','S','E','C','T','R','I','G','G','E',
    'R','E','F','E','R','E','N','C','E','S','U','N','I','Q','U','E','R','Y',
    'A','T','T','A','C','H','A','V','I','N','G','R','O','U','P','D','A','T',
    'E','M','P','O','R','A','R','Y','B','E','G','I','N','N','E','R','E','N',
    'A','M','E','B','E','T','W','E','E','N','O','T','N','U','L','L','I','K',
    'E','C','A','S','C','A','D','E','L','E','T','E','C','A','S','E','C','O',
    'L','L','A','T','E','C','R','E','A','T','E','C','U','R','R','E','N','T',
    '_','D','A','T','E','D','E','T','A','C','H','I','M','M','E','D','I','A',
    'T','E','J','O','I','N','S','E','R','T','M','A','T','C','H','P','L','A',
    'N','A','L','Y','Z','E','P','R','A','G','M','A','B','O','R','T','V','A',
    'L','U','E','S','V','I','R','T','U','A','L','I','M','I','T','W','H','E',
    'N','W','H','E','R','E','P','L','A','C','E','A','F','T','E','R','E','S',
    'T','R','I','C','T','A','N','D','E','F','A','U','L','T','A','U','T','O',
    'I','N','C','R','E','M','E','N','T','C','A','S','T','C','O','L','U','M',
    'N','C','O','M','M','I','T','C','O','N','F','L','I','C','T','C','R','O',
    'S','S','C','U','R','R','E','N','T','_','T','I','M','E','S','T','A','M',
    'P','R','I','M','A','R','Y','D','E','F','E','R','R','E','D','I','S','T',
    'I','N','C','T','D','R','O','P','F','A','I','L','F','R','O','M','F','U',
    'L','L','G','L','O','B','Y','I','F','I','N','T','O','F','F','S','E','T',
    'I','S','N','U','L','L','O','R','D','E','R','I','G','H','T','O','U','T',
    'E','R','O','L','L','B','A','C','K','R','O','W','U','N','I','O','N','U',
    'S','I','N','G','V','A','C','U','U','M','V','I','E','W','I','N','I','T',
    'I','A','L','L','Y',0
  };
  static const unsigned char aHash[127] = {
      65,  94, 110,  63,   0,  44,   0,   0,  71,   0,  66,   0,   0,
     104,  12,  67,  15,   0, 108,  74, 105, 101,   0,  19,   0,   0,
     114,   0, 112,  78,   0,  22,  82,   0,   9,   0,   0,  59,  60,
       0,  58,   6,   0,  39,  79,  91,   0, 111,  90,   0,   0,  45,
       0,  92,  24,   0,  17,   0, 115,  40,  23,   0,   5,  99,  25,
      85,   0,   0, 117,  95,  50, 116,  47,   7,  42,   0,  80,   0,
      89,  26,   0,  88,   0,   0,   0,  84,  81,  86,  77,  98,  14,
      34,  97,   0,  70,   0,  18,  76, 100,  31,   0, 113,  69, 106,
      52,  46,  73,   0,   0,  83, 102,   0, 109,   0,  35,   0,   0,
      28,   0,  75,  48,  53,   0,  20,  51,   0,  43,
  };
  static const unsigned char aNext[117] = {
       0,   0,   0,   0,   4,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   2,   0,   0,   0,   0,   0,   0,  13,   0,   0,   0,   0,
       0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
       0,   0,   3,  38,   0,  32,  21,   0,   0,   0,   0,  29,   0,
       0,  37,   0,   0,   0,   1,  55,   0,   0,  56,   0,   0,   0,
       0,   0,   0,   0,   0,   0,  54,   0,   0,   0,   0,  30,   0,
      16,  33,  10,   0,   0,   0,   0,   0,   0,   0,  11,  61,  68,
       0,   8,   0,  93,  87,   0,  96,   0,  49,   0,   0,  64,   0,
      41, 103,   0,  27, 107,  36,  62,  72,   0,   0,  57,   0,   0,
  };
  static const unsigned char aLen[117] = {
       7,   7,   5,   4,   6,   4,   5,   3,   6,   7,   3,   6,   6,
       7,   7,   3,   8,   2,   6,   5,   4,   4,   3,  10,   4,   6,
      11,   2,   7,   5,   5,   9,   6,  10,   9,   7,  10,   6,   5,
       6,   6,   5,   6,   4,   9,   2,   5,   5,   6,   7,   7,   3,
       4,   4,   7,   3,   6,   4,   7,   6,  12,   6,   9,   4,   6,
       5,   4,   7,   6,   5,   6,   7,   5,   4,   5,   7,   5,   8,
       3,   7,  13,   2,   2,   4,   6,   6,   8,   5,  17,  12,   7,
       8,   8,   2,   4,   4,   4,   4,   4,   2,   2,   4,   6,   2,
       3,   6,   5,   5,   5,   8,   3,   5,   5,   6,   4,   9,   3,
  };
  static const unsigned short int aOffset[117] = {
       0,   2,   2,   8,   9,  14,  16,  20,  23,  25,  25,  29,  33,
      36,  41,  46,  48,  53,  54,  59,  62,  65,  67,  69,  78,  81,
      86,  95,  96, 101, 105, 109, 117, 123, 130, 138, 144, 154, 157,
     162, 167, 172, 175, 179, 179, 183, 188, 191, 195, 201, 207, 207,
     210, 213, 217, 218, 222, 228, 232, 239, 245, 257, 263, 272, 274,
     280, 285, 287, 294, 299, 304, 310, 316, 321, 325, 328, 335, 339,
     347, 349, 356, 358, 360, 369, 373, 379, 385, 393, 398, 398, 414,
     421, 428, 429, 436, 440, 444, 448, 452, 455, 457, 459, 462, 462,
     465, 468, 474, 478, 483, 487, 495, 498, 503, 508, 514, 518, 523,
  };
  static const unsigned char aCode[117] = {
    TK_REINDEX,    TK_INDEXED,    TK_INDEX,      TK_DESC,       TK_ESCAPE,     
    TK_EACH,       TK_CHECK,      TK_KEY,        TK_BEFORE,     TK_FOREIGN,    
    TK_FOR,        TK_IGNORE,     TK_LIKE_KW,    TK_EXPLAIN,    TK_INSTEAD,    
    TK_ADD,        TK_DATABASE,   TK_AS,         TK_SELECT,     TK_TABLE,      
    TK_JOIN_KW,    TK_THEN,       TK_END,        TK_DEFERRABLE, TK_ELSE,       
    TK_EXCEPT,     TK_TRANSACTION,TK_ON,         TK_JOIN_KW,    TK_ALTER,      
    TK_RAISE,      TK_EXCLUSIVE,  TK_EXISTS,     TK_CONSTRAINT, TK_INTERSECT,  
    TK_TRIGGER,    TK_REFERENCES, TK_UNIQUE,     TK_QUERY,      TK_ATTACH,     
    TK_HAVING,     TK_GROUP,      TK_UPDATE,     TK_TEMP,       TK_TEMP,       
    TK_OR,         TK_BEGIN,      TK_JOIN_KW,    TK_RENAME,     TK_BETWEEN,    
    TK_NOTNULL,    TK_NOT,        TK_NULL,       TK_LIKE_KW,    TK_CASCADE,    
    TK_ASC,        TK_DELETE,     TK_CASE,       TK_COLLATE,    TK_CREATE,     
    TK_CTIME_KW,   TK_DETACH,     TK_IMMEDIATE,  TK_JOIN,       TK_INSERT,     
    TK_MATCH,      TK_PLAN,       TK_ANALYZE,    TK_PRAGMA,     TK_ABORT,      
    TK_VALUES,     TK_VIRTUAL,    TK_LIMIT,      TK_WHEN,       TK_WHERE,      
    TK_REPLACE,    TK_AFTER,      TK_RESTRICT,   TK_AND,        TK_DEFAULT,    
    TK_AUTOINCR,   TK_TO,         TK_IN,         TK_CAST,       TK_COLUMNKW,   
    TK_COMMIT,     TK_CONFLICT,   TK_JOIN_KW,    TK_CTIME_KW,   TK_CTIME_KW,   
    TK_PRIMARY,    TK_DEFERRED,   TK_DISTINCT,   TK_IS,         TK_DROP,       
    TK_FAIL,       TK_FROM,       TK_JOIN_KW,    TK_LIKE_KW,    TK_BY,         
    TK_IF,         TK_INTO,       TK_OFFSET,     TK_OF,         TK_SET,        
    TK_ISNULL,     TK_ORDER,      TK_JOIN_KW,    TK_JOIN_KW,    TK_ROLLBACK,   
    TK_ROW,        TK_UNION,      TK_USING,      TK_VACUUM,     TK_VIEW,       
    TK_INITIALLY,  TK_ALL,        
  };
  int h, i;
  if( n<2 ) return TK_ID;
  h = ((charMap(z[0])*4) ^
      (charMap(z[n-1])*3) ^
      n) % 127;
  for(i=((int)aHash[h])-1; i>=0; i=((int)aNext[i])-1){
    if( aLen[i]==n && sqlite3StrNICmp(&zText[aOffset[i]],z,n)==0 ){
      return aCode[i];
    }
  }
  return TK_ID;
}
int sqlite3KeywordCode(const unsigned char *z, int n){
  return keywordCode((char*)z, n);
}
