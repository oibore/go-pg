package main

import (
  "fmt";
  "pg";
)

func main() {
  conninfo := "dbname=testdb";
  conn := pg.Connect(conninfo);

  status := pg.Status(conn);
  fmt.Printf("conninfo=%s, status=%d\n", conninfo, status);

  res := pg.Exec(conn, "select * from users;");
  //res := pg.GetResult(conn);

  fileds := pg.NFields(res);
  fmt.Printf("fields = %d\n", fileds);

  value := pg.GetValue(res, 0, 0);
  fmt.Printf("value = %s\n", value);

  pg.Close(conn);
}
