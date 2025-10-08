CREATE DATABASE orderdb;
---------------------------
CREATE TABLE employee
(
employeeno varchar(8) PRIMARY KEY,
employeename varchar(10),
sex varchar(2),
birthday datetime,
address varchar(50),
telephone varchar(20),
hiredate datetime,
department varchar(30),
headship varchar(10),
salary NUMERIC(8, 2)
);
---------------------------
CREATE TABLE customer
(
customerno varchar(9) PRIMARY KEY,
customername varchar(40),
telephone varchar(20),
address varchar(40),
zip varchar(6)
);
---------------------------
CREATE TABLE product
(
productno varchar(9) PRIMARY KEY,
productname varchar(40),
productclass varchar(20),
productprice NUMERIC(7, 2),
);
---------------------------
CREATE TABLE ordermaster
(
orderno varchar(12) PRIMARY KEY,
customerno varchar(9),
salerno varchar(8),
orderdate datetime,
ordersum NUMERIC(9, 2),
invoiceno char(10),
FOREIGN KEY (customerno) REFERENCES customer(customerno)
);
-----------------------------
CREATE TABLE orderdetail
(
orderno varchar(12),
productno varchar(9),
quantity int,
price NUMERIC(7, 2),
PRIMARY KEY(orderno, productno),
FOREIGN KEY (orderno) REFERENCES ordermaster(orderno),
FOREIGN KEY (productno) REFERENCES product(productno)
);
--------------------------------------------------------
BULK
INSERT
	employee
FROM
	'E:\test\employee.txt'
WITH (
    FIELDTERMINATOR = ',',
	ROWTERMINATOR = '\n'
);

BULK
INSERT
	customer
FROM
	'E:\test\customer.txt'
WITH (
    FIELDTERMINATOR = ',',
	ROWTERMINATOR = '\n'
);

BULK
INSERT
	product
FROM
	'E:\test\product.txt'
WITH (
    FIELDTERMINATOR = ',',
	ROWTERMINATOR = '\n'
);

BULK
INSERT
	ordermaster
FROM
	'E:\test\ordermaster.txt'
WITH (
    FIELDTERMINATOR = ',',
	ROWTERMINATOR = '\n'
);

BULK
INSERT
	orderdetail
FROM
	'E:\test\orderdetail.txt'
WITH (
    FIELDTERMINATOR = ',',
	ROWTERMINATOR = '\n'
);
--------------------------------------------------------
--- 计算订单金额
UPDATE
	ordermaster
SET
	ordersum = (
	-- 计算该订单所有明细的金额总和
	SELECT
		SUM(quantity * price)
	FROM
		orderdetail
	WHERE
		orderdetail.orderno = ordermaster.orderno
)
WHERE
	EXISTS (
	SELECT
		1
	FROM
		orderdetail
	WHERE
		orderdetail.orderno = ordermaster.orderno
);

-- 查询所有业务部门的员工姓名，职称，薪水
SELECT
	employeename,
	headship,
	salary
FROM
	employee;
-- 查询名字中含有“有限”的客户姓名和所在地
SELECT
	customername,
	address
FROM
	customer
WHERE
	customername LIKE '%有限%';
-- 查询姓“王”并且姓名的最后一个字为“成”的员工
SELECT
	*
FROM
	employee
WHERE
	employeename LIKE '王%成';
-- 查询住址中含有上海或南昌的女员工，并显示其姓名，所属部门，职称，住址，其中性别用“男”和“女”显示。
SELECT
	employeename,
	department,
	headship,
	address,
	CASE
		WHEN sex = 'F' THEN '女'
		WHEN sex = 'M' THEN '男'
		ELSE '未知'
	END
FROM
		employee
WHERE
		sex = 'F'
	AND (address LIKE '%上海%'
		OR address LIKE '%南昌%');
--- 查询订单金额高于8000的所有客户编号

SELECT
	customerno
FROM
	ordermaster
WHERE
	orderno IN (
	SELECT
		orderno
	FROM
		orderdetail
	WHERE
		quantity * price >8000);
--- 选取编号界于C0001~C0004的客户编号，客户名称，客户地址
SELECT
	customerno,
	customername,
	address
FROM
	customer
WHERE
	customerno >= 'C0001'
	AND customerno <= 'C0004';
--- 找出同一天进入公司服务的员工
SELECT
	*
FROM
	employee
WHERE
	hiredate IN (
	SELECT
		hiredate
	FROM
		employee
	GROUP BY
		hiredate
	HAVING
		COUNT(*) > 1)
ORDER BY
	hiredate,
	employeeno;
-- 在订单主表中查询订单金额大于“E2005002”业务员在2008-1-9这天所接的任一张订单的金额”的所有订单信息。

SELECT
	*
FROM
	ordermaster
WHERE
	ordersum > ANY(SELECT ordersum FROM ordermaster WHERE ordermaster.salerno = 'E2005002' AND orderdate = '2008-01-09');
-- 查询既订购了“52倍速光驱”商品，又订购了“17寸显示器”商品的客户编号、订单编号和订单金额。

SELECT
	orderno,
	customerno,
	ordersum
FROM
	ordermaster
WHERE
	EXISTS (
	SELECT
		1
	FROM
		orderdetail od1
	JOIN product p1 ON
		od1.productno = p1.productno
	WHERE
		od1.orderno = ordermaster.orderno
		AND p1.productname = '52倍速光驱')
	AND EXISTS (
	SELECT
		1
	FROM
		orderdetail od2
	JOIN product p2 ON
		od2.productno = p2.productno
	WHERE
		od2.orderno = ordermaster.orderno
		AND p2.productname = '17寸显示器')
ORDER BY
	ordermaster.customerno ,
	ordermaster.orderno ;
-- 查找与“陈诗杰”在同一个单位工作的员工姓名、性别、部门和职务。

SELECT
	employeename,
	sex,
	department,
	headship
FROM
	employee
WHERE
	department = (
	SELECT
		department
	FROM
		employee
	WHERE
		employeename = '陈诗杰');
-- 查询单价高于400元的商品编号、商品名称、订货数量和订货单价。

SELECT
	orderdetail.productno,
	productname,
	quantity,
	price
FROM
	orderdetail
JOIN product ON
	orderdetail.productno = product.productno
WHERE
	product.productprice > 400
ORDER BY
	orderdetail.productno,
	productname
	-- 分别使用左外连接、右外连接、完整外部连接查询单价高于400元的商品编号、商品名称、订货数量和订货单价，并分析比较检索的结果。
	
SELECT
	p.productno,
	p.productname,
	od.quantity,
	od.price
FROM
	product p
LEFT JOIN
    orderdetail od ON
	p.productno = od.productno
WHERE
	p.productprice > 400;

SELECT
	p.productno ,
	p.productname ,
	od.quantity ,
	od.price
FROM
	product p
RIGHT JOIN
    orderdetail od ON
	p.productno = od.productno
WHERE
	p.productprice > 400;

SELECT
	p.productno,
	p.productname,
	od.quantity,
	od.price
FROM
	product p
FULL OUTER JOIN
    orderdetail od ON
	p.productno = od.productno
WHERE
	p.productprice > 400;
-- 查找每个员工的销售记录，要求显示销售员的编号、姓名、性别、商品名称、数量、单价、金额和销售日期，其中性别使用“男”和“女”表示，日期使用yyyy-mm-dd格式显示。

SELECT
	e.employeeno,
	e.employeename,
	CASE
		WHEN e.sex = 'M' THEN '男'
		WHEN e.sex = 'F' THEN '女'
		ELSE '未知'
	END,
	p.productname,
	od.quantity,
	od.price,
	od.quantity * od.price AS total_price, 
	om.orderdate
FROM
	employee e
JOIN 
    ordermaster om ON
	e.employeeno = om.salerno
JOIN 
    orderdetail od ON
	om.orderno = od.orderno
JOIN 
    product p ON
	od.productno = p.productno
ORDER BY
	e.employeeno,
	e.employeename ;
-- 查找在2008年3月中有销售记录的客户编号、名称和订单总额。

SELECT
	c.customerno,
	c.customername,
	SUM(om.ordersum) AS 订单总额
FROM
	customer c
JOIN 
    ordermaster om ON
	c.customerno = om.customerno
WHERE
	YEAR(om.orderdate) = 2008
	AND MONTH(om.orderdate) = 3
GROUP BY
	c.customerno,
	c.customername;
-- 使用左外连接查找每个客户的客户编号、名称、订单日期、订货金额，其中订货日期不要显示时间，日期格式为yyyy-mm-dd，按客户编号排序，同一客户再按订单金额降序排序输出。
SELECT
	c.customerno,
	c.customername,
	CONVERT(varchar(10), om.orderdate, 23) AS date,
	om.ordersum
FROM
	customer c
LEFT JOIN 
    ordermaster om ON
	c.customerno = om.customerno
ORDER BY
	c.customerno,
	om.ordersum DESC;
-- 查找16M DRAM的销售情况，要求显示相应的销售员的姓名，性别，销售日期、销售数量和金额，其中性别用“男”，“女”表示。
SELECT
	e.employeename,
	CASE
		WHEN e.sex = '男' THEN '男'
		WHEN e.sex = '女' THEN '女'
		ELSE '未知'
	END AS 性别,
	CONVERT(varchar(10), om.orderdate, 23) AS date,
	od.quantity,
	od.quantity * od.price AS total_price
FROM
	product p
JOIN 
    orderdetail od ON
	p.productno = od.productno
JOIN 
    ordermaster om ON
	od.orderno = om.orderno
JOIN 
    employee e ON
	om.salerno = e.employeeno
WHERE
	p.productname = '16M DRAM'
ORDER BY
	om.orderdate ,
	e.employeename ;
-- 查找公司男业务员所接且订单金额超过2000元的订单号及订单金额。

SELECT
	om.orderno,
	om.ordersum
FROM
	ordermaster om
JOIN 
    employee e ON
	om.salerno = e.employeeno
WHERE
	e.sex = 'M'
	AND om.ordersum > 2000
ORDER BY
	om.ordersum DESC;
-- 查找来自上海市的客户的姓名，电话，订单号及订单金额。

SELECT
	cm.customername,
	cm.telephone,
	om.orderno,
	om.ordersum
FROM
	ordermaster om
JOIN customer cm ON
	om.customerno = cm.customerno
WHERE
	cm.address = '上海市'
ORDER BY
	cm.customername 
;
