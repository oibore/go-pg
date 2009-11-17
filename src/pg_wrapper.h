/*
 * pg_wrapper.h
 */

#ifndef __PG_WRAPPER_H__
#define __PG_WRAPPER_H__

void *PgConnectDb(const char* conninfo);
void PgFinish(void *conn);
int  PgStatus(void *conn);
void *PgExec(void *conn, const char *command);
void *PgGetResult(void *conn);
int  PgNFields(const void *res);
int  PgNTuples(const void *res);
int  PgGetIsNull(const void *res, int row_number, int column_number);
char *PgGetValue(const void *res, int row_number, int column_number);
int  PgGetLength(const void *res, int row_number, int column_number);
char *PgFName(const void *res,  int column_number);
int  PgFNumber(const void *res, const char *column_name);
int  PgFType(const void *res,   int column_number);
int  PgFSize(const void *res,   int column_number);
int  PgFMod(const void *res,    int column_number);

#endif /* __PG_WRAPPER_H__ */

