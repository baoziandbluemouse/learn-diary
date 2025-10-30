CREATE TABLE department(
	department_id int PRIMARY KEY,
	name varchar(30),
	charge_id varchar(30),
	phonenum varchar(20)
);

CREATE TABLE employee(
	employeeid varchar(30) PRIMARY KEY,
	name varchar(30),
	bir_day date,
	sex varchar(10),
	salary int,
	department_id int,
	headship varchar(15)
);

ALTER TABLE employee ADD CONSTRAINT fk_department_id FOREIGN KEY (department_id) REFERENCES department (department_id);

ALTER TABLE department ADD CONSTRAINT fk_charge_id FOREIGN KEY (charge_id) REFERENCES employee (employeeid);

CREATE TABLE medical (
	employeeid varchar(30),
	medi_date date,
	medi_cost int,
	hospital varchar(50),
	medi_res varchar(50),
	PRIMARY KEY(employeeid, medi_date, hospital),
	FOREIGN KEY(employeeid) REFERENCES employee (employeeid)
);
-- 首先要在部门内添加部门编号为5的部门
INSERT
	INTO
	employee
VALUES('007', '张三', '1983-9-9', '男', 3000, 5, '技工');

SELECT
	m.employeeid ,
	em.name ,
	SUM(m.medi_cost)
FROM
	medical m
JOIN employee em ON
	m.employeeid = em.department_id
GROUP BY
	em.employeeid,
	em.name;

SELECT
	d.name,
	d.phonenum
FROM
	department d
JOIN employee em ON
	d.charge_id = em.employeeid
WHERE
	em.name = '卢仪';

SELECT
	em.employeeid,
	em.name,
	d.department_id
FROM
	employee em
JOIN department d ON
	em.department_id = d.department_id
WHERE
	em.employeeid NOT IN (
	SELECT
		medical.employeeid
	FROM
		medical
	WHERE
		hospital = '红会医院');

UPDATE
	medical m
JOIN employee em ON
	m.employeeid = em.employeeid SET
	medi_cost = medi_cost / 2
WHERE
	em.sex = '女'
	AND em.headship = '工程师';

CREATE VIEW AAA AS
SELECT
	employeeid,
	name
FROM
	employee
WHERE
	sex = '男'
	AND employee.employeeid NOT IN (
	SELECT
		medical.employeeid
	FROM
		medical );
-- 后续

SELECT
	AVG(m.medi_cost)
FROM
	medical m
JOIN employee em ON
	m.employeeid = em.employeeid
WHERE
	em.headship = '工程师';

UPDATE
	employee e
JOIN department d ON
	e.department_id = d.department_id
SET
	e.salary = e.salary * 1.1
WHERE
	d.name = '人事部门';

DELETE
	m
FROM
	medical m
JOIN employee e ON
	m.employeeid = e.employeeid
JOIN department d ON
	e.department_id = d.department_id
WHERE
	d.name = '财务部';

CREATE INDEX idx_medical_employeeid ON
medical(employeeid);
