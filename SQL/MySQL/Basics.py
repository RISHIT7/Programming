import mysql.connector as mysql

mydb = mysql.connect(
    host="localhost",
    user="root",
    password="JEEAdv#633",
    auth_plugin='mysql_native_password',
    database = "sakila"
)

mycursor = mydb.cursor()

# mycursor.execute("CREATE DATABASE pythonprogram") # executing the database

# mycursor.execute("SHOW DATABASES")

# # checking the database
# for x in mycursor:
#     print(x)

# # making tables, and use SHOW TABLES to show the tables
# mycursor.execute("CREATE TABLE Customers (name VARCHAR(255), address VARCHAR(255))")

# select statement
# mycursor.execute("SELECT * FROM actor")
# myresult = mycursor.fetchall()

# for c in myresult:
#     print(c)

