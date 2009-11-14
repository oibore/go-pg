package pg

// #include "pg_wrapper.h"
import "C"

import (
    "unsafe";
)

func Connect(conninfo string) unsafe.Pointer {
    conn := C.PgConnectDb(C.CString(conninfo));
    return conn;
}

func Close(conn unsafe.Pointer) {
    C.PgFinish(conn);
}

func Status(conn unsafe.Pointer) int {
    status := C.PgStatus(conn);
    return int(status);
}

func Exec(conn unsafe.Pointer, command string) unsafe.Pointer {
    res := C.PgExec(conn, C.CString(command));
    return res;
}

func GetResult(conn unsafe.Pointer) unsafe.Pointer {
    return C.PgGetResult(conn);
}

func NFields(res unsafe.Pointer) int {
    return int(C.PgNFields(res));
}

func NTuples(res unsafe.Pointer) int {
    return int(C.PgNTuples(res));
}

func GetIsNull(res unsafe.Pointer, row_number int, column_number int) int {
    return int(C.PgGetIsNull(res, _C_int(row_number), 
                                  _C_int(column_number)));
}

func GetValue(res unsafe.Pointer, row_number int, column_number int) string {
    value := C.GoString(C.PgGetValue(res, _C_int(row_number), 
                                        _C_int(column_number)));
    return value;
}

