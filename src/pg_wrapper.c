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

int PgNFields(void *res)
{
    return PQnfields(res);
}

int PgNTuples(void *res)
{
    return PQntuples(res);
}

int PgGetIsNull(void *res, int row_number, int column_number)
{
    return PQgetisnull(res, row_number, column_number);
}

char *PgGetValue(void *res, int row_number, int column_number)
{
    return PQgetvalue(res, row_number, column_number);
}
