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

    res = pg.Exec(conn, "select count(*) from users;");
    row := pg.FetchRow(res);
    values := strings.Join(row, ",");
    fmt.Printf("values = %s\n", values);

    pg.Close(conn);
}
