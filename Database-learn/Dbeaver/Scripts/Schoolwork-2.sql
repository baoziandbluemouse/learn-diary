CREATE TABLE `Employee`(
	employeeNo Char(8) PRIMARY KEY,
	employeeName Varchar(10),
	Sex Char(1),
	Department Varchar(30),
	Headship Varchar(6),
	Hiredate Datetime,
	Birthday Datetime,
	Salary NUMERIC(8, 2),
	Address Varchar(50),
	Telephone Varchar(20)
);

CREATE TABLE `Customer`(
	CustomerNo Char(9) PRIMARY KEY,
	customerName Varchar(40),
	Address Varchar(40),
	Telephone Varchar(20),
	Zip Char(6),
	Createdate datetime
);

CREATE TABLE `Product`(
	ProductNo Char(9) PRIMARY KEY,
	ProductName Varchar(40),
	ProductClass Varchar(20),
	ProductPrice NUMERIC(8, 2),
	Createdate datetime
);

CREATE TABLE `OrderMaster`(
	OrderNo Char(12) PRIMARY KEY,
	customerNo Char(9),
	SaleNo Char(8),
	Ordersum NUMERIC(8, 2),
	Orderdate Datetime,
	Shipdate Datetime,
	InvoiceNo Char(10),
	CONSTRAINT fk_ordermaster_customer FOREIGN KEY(customerNo) REFERENCES `Customer`(CustomerNo),
	CONSTRAINT fk_ordermaster_employee FOREIGN KEY(SaleNo) REFERENCES `Employee`(employeeNo)
);

CREATE TABLE `OrderDetail`(
	OrderNo Char(12),
	ProductNo Char(9),
	Qty Int,
	Price NUMERIC(8, 2),
	PRIMARY KEY(OrderNo, ProductNo),
	CONSTRAINT fk_orderdetail_ordermaster FOREIGN KEY(OrderNo) REFERENCES `OrderMaster`(OrderNo),
	CONSTRAINT fk_orderdetail_product FOREIGN KEY(ProductNo) REFERENCES `Product`(ProductNo)
);

ALTER TABLE `Customer` MODIFY COLUMN customerName Varchar(40) NOT NULL,
MODIFY COLUMN Telephone Varchar(20) NOT NULL;

ALTER TABLE `Employee` MODIFY COLUMN employeeName Varchar(10) NOT NULL,
MODIFY COLUMN Telephone Varchar(20) NOT NULL;

ALTER TABLE `ordermaster` MODIFY COLUMN InvoiceNo Char(10) NOT NULL;

CREATE INDEX salaryIdx ON
`Employee` (Salary);

SELECT
	INDEX_NAME,
	-- 索引名称
	COLUMN_NAME,
	-- 索引对应的列
	INDEX_TYPE,
	-- 索引类型（如 BTREE）
	NON_UNIQUE
	-- 是否为非唯一索引（1 表示非唯一，0 表示唯一）
FROM
	INFORMATION_SCHEMA.STATISTICS
WHERE
	TABLE_SCHEMA = 'orderDB'
	-- 替换为你的数据库名称
	AND TABLE_NAME = 'OrderMaster'
	-- 表名固定为
	AND INDEX_NAME = 'salenosumIdx';
-- 索引名固定为

CREATE INDEX salenosumIdx ON
`OrderMaster`(
	OrderSum ASC,
	SaleNo DESC
);

CREATE VIEW customerinfo AS
SELECT
	CustomerNo AS 客户号,
	customerName AS 客户姓名,
	Address AS 客户住址,
	Createdate AS 建立日期
FROM
	customer;
