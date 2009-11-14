#include <libpq-fe.h>

int main(void) 
{
	char *feedback;

	//char *conninfo = "host = localhost dbname = testdb";
	char *conninfo = "dbname=testdb";
	PGconn *conn = PQconnectdb(conninfo);
	switch(PQstatus(conn))
	{
		case CONNECTION_OK:
			feedback = "Connected to server...\n";
			break;
		case CONNECTION_BAD:
			feedback = "Failed...\n";
			break;
	}

	printf( "%s\n", feedback);
	PQfinish(conn);
}

