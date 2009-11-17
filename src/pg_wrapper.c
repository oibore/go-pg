/*
 * pg_wrapper.c
 */

#include <libpq-fe.h>
#include "pg_wrapper.h"

void *PgConnectDb(const char *conninfo)
{
    PGconn *conn = PQconnectdb(conninfo);
    return conn;
}

void PgFinish(void *conn)
{
    PQfinish(conn);
}

int PgStatus(void *conn)
{
    return PQstatus(conn);
}

void *PgExec(void *conn, const char *command)
{
    return PQexec(conn, command);
}

void *PgGetResult(void *conn)
{
    return PQgetResult(conn);
}

int PgNFields(const void *res)
{
    return PQnfields(res);
}

int PgNTuples(const void *res)
{
    return PQntuples(res);
}

int PgGetIsNull(const void *res, int row_number, int column_number)
{
    return PQgetisnull(res, row_number, column_number);
}

char *PgGetValue(const void *res, int row_number, int column_number)
{
    return PQgetvalue(res, row_number, column_number);
}

int PgGetLength(const void *res, int row_number, int column_number)
{
    return PQgetlength(res, row_number, column_number);
}

char *PgFName(const void *res, int column_number)
{
    return PQfname(res, column_number);
}

int PgFNumber(const void *res, const char *column_name)
{
    return PQfnumber(res, column_name);
}

int PgFType(const void *res, int column_number)
{
    return PQftype(res, column_number);
}

int PgFSize(const void *res, int column_number)
{
    return PQfsize(res, column_number);
}

int PgFMod(const void *res, int column_number)
{
    return PQfmod(res, column_number);
}
