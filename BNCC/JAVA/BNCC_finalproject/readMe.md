Before starting the application you need to this for the mysqlDatabase:

Start MySql and Apache in XAMMP
Open MySql Admin 
Create Database pudding_db, or use sql ​```CREATE DATABASE pudding_db;```
Inside pudding_db, use this sql to create the properties
```USE pudding_db;

CREATE TABLE menu (
   code VARCHAR(10) PRIMARY KEY,
   name VARCHAR(50) NOT NULL,
   price DECIMAL(10, 2) NOT NULL,
   stock INT NOT NULL
);



```
Now the Java app should work, hopefully I got good grades for this :)


