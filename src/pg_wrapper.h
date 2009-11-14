#ifndef __PG_WRAPPER_H__
#define __PG_WRAPPER_H__

void *PgConnectDb(const char* conninfo);
void PgFinish(void *conn);
int  PgStatus(void *conn);
void *PgExec(void *conn, const char *command);
void *PgGetResult(void *conn);
int  PgNFields(void *res);
int  PgNTuples(void *res);
int  PgGetIsNull(void *res, int row_number, int column_number);
char *PgGetValue(void *res, int row_number, int column_number);

#endif /* __PG_WRAPPER_H__ */

