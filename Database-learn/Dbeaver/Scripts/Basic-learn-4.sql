-- 实战创建公司资料库表格

CREATE TABLE employee(
	emp_id int PRIMARY KEY,
	name varchar(20),
	birth_date date,
	sex varchar(5),
	salary int,
	branch_id int,
	sup_id int
);

CREATE TABLE branch(
	branch_id int PRIMARY KEY,
	branch_name varchar(10),
	manager_id int,
	FOREIGN KEY (manager_id) REFERENCES employee (emp_id) ON
DELETE
	SET
	NULL -- 如果说 对应的emp_id 被删了，相对的manager_id 就会置为NULL , 注意，假如外键同时是primary_key时，是不能设为NULL的，会直接出错
);

CREATE TABLE client(
	client_id int PRIMARY KEY,
	client_name varchar(20),
	phone varchar(30)
);

CREATE TABLE works_with(
	emp_id int,
	client_id int,
	total_sales int,
	PRIMARY KEY(emp_id, client_id),
	FOREIGN KEY(emp_id) REFERENCES employee (emp_id) ON DELETE CASCADE, -- 如果对应的emp_id删除，那么这里的也会一并删除，是级联删除
	FOREIGN KEY(client_id) REFERENCES client (client_id) ON DELETE CASCADE
	
);
-- 添加employee表格的外键
ALTER TABLE employee ADD FOREIGN KEY (branch_id) REFERENCES branch (branch_id) ON
DELETE
	SET
	NULL;

ALTER TABLE employee ADD FOREIGN KEY (sup_id) REFERENCES employee (emp_id) ON
DELETE
	SET
	NULL;
-- 添加资料
-- 注意，外键在添加时，被引用的表格一定要已经添加了对应的数据
-- 所以添加branch表格时，manager_id填写具体值会报错，因为没有填具体的employee表格
-- 但是employee表格也有对应branch的外键，这种循环的情况，我们要把外键都先写为null，这样就不会报错了
-- 等基础的数据添加完后，就可以填写外键了

INSERT
	INTO
	branch
VALUES(1, '研发', NULL);

INSERT
	INTO
	branch
VALUES(2, '行政', NULL);

INSERT
	INTO
	branch
VALUES(3, '咨询', NULL);

INSERT
	INTO
	employee
VALUES(206, '小黄', '1998-10-08', 'F', 50000, 1, NULL);

INSERT
	INTO
	employee
VALUES(207, '小绿', '1985-12-25', 'M', 28000, 2, 206);

INSERT
	INTO
	employee
VALUES(208, '小黑', '1934-05-05', 'F', 40200, 3, 206);

INSERT
	INTO
	employee
VALUES(209, '小红', '2018-11-08', 'M', 29800, 3, 207);

INSERT
	INTO
	employee
VALUES(210, '小蓝', '2008-01-28', 'F', 34000, 1, 207);

UPDATE
	branch
SET
	manager_id = 206
WHERE
	branch_id = 1;

UPDATE
	branch
SET
	manager_id = 207
WHERE
	branch_id = 2;

UPDATE
	branch
SET
	manager_id = 208
WHERE
	branch_id = 3;

INSERT
	INTO
	client
VALUES(400, '阿狗', '1561937792');

INSERT
	INTO
	client
VALUES(401, '阿猫', '5644562212');

INSERT
	INTO
	client
VALUES(402, '旺来', '4564565612');

INSERT
	INTO
	client
VALUES(403, '露西', '5645454545');

INSERT
	INTO
	client
VALUES(404, 'Eric', '2121212121');

INSERT
	INTO
	works_with
VALUES(206, 400, '70000');

INSERT
	INTO
	works_with
VALUES(207, 401, '24000');

INSERT
	INTO
	works_with
VALUES(208, 402, '9800');

INSERT
	INTO
	works_with
VALUES(208, 403, '24000');

INSERT
	INTO
	works_with
VALUES(210, 404, '87940');
