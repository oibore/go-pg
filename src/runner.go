//
// runner.go
//
package main

import (
    "fmt";
    "strings";
    "pg";
)

func main() {
    conninfo := "dbname=testdb";
    conn := pg.Connect(conninfo);

    status := pg.Status(conn);
    fmt.Printf("conninfo=%s, status=%d\n", conninfo, status);

    res := pg.Exec(conn, "select * from users;");

    fileds := pg.NFields(res);
    fmt.Printf("fields = %d\n", fileds);

    value := pg.GetValue(res, 0, 0);
    fmt.Printf("value = %s\n", value);

    for {
        row := pg.FetchRow(res);
        if row == nil {
            break
        }
        values := strings.Join(row, ",");
        fmt.Printf("values = %s\n", values);
    }

    res = pg.Exec(conn, "select * from users;");
    len := pg.GetLength(res, 0, 0);
    fmt.Printf("length = %d\n", len);
    fname   := pg.FName(res,   0);
    ftype   := pg.FType(res,   0);
    fnumber := pg.FNumber(res, "name");
    fsize   := pg.FSize(res,   0);
    fmod    := pg.FMod(res,    0);
    fmt.Printf("fname=%s, ftype=%d, fnumber=%d, fsize=%d, fmod=%d\n", 
               fname, ftype, fnumber, fsize, fmod);

    pg.Close(conn);
}
