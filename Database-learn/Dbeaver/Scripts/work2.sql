CREATE TABLE S (
    Sno CHAR(10) PRIMARY KEY,
-- 学号
Sname VARCHAR(20),
-- 姓名
Sage INT,
-- 年龄
Sdept VARCHAR(30)
-- 所在专业
);

CREATE TABLE C (
    Cno CHAR(6) PRIMARY KEY,
-- 课程号
Cname VARCHAR(30),
-- 课程名
Cpno CHAR(6),
-- 先修课程号
    FOREIGN KEY (Cpno) REFERENCES C(Cno)
-- 外键约束：关联课程表自身的主键
);

CREATE TABLE SC (
    Sno CHAR(10),
-- 学号
Cno CHAR(6),
-- 课程号
G INT,
-- 成绩
    PRIMARY KEY (Sno,
Cno),
-- 主键
    FOREIGN KEY (Sno) REFERENCES S(Sno),
-- 外键约束
    FOREIGN KEY (Cno) REFERENCES C(Cno)
-- 外键约束
);

SELECT
	Sno,
	Sname,
	Sage
FROM
	s
WHERE
	Sname LIKE '王%';

SELECT
	Sname
FROM
	s
WHERE
	Sno IN (
	SELECT
		sc.Sno
	FROM
		sc
	WHERE
		Cno = '1'
		OR Cno = '2');

SELECT
	Sno,
	COUNT(Cno)
FROM
	sc
GROUP BY
	Sno
HAVING
	COUNT(Cno)>3;

SELECT
	Sname
FROM
	s
WHERE
	Sno IN (
	SELECT
		sc1.Sno
	FROM
		sc sc1
	JOIN sc sc2 ON
		sc1.Sno = sc2.Sno
	WHERE
		sc1.Cno = '2'
		AND sc2.Cno = '3');

CREATE VIEW grade AS
SELECT
	s.Sno,
	s.Sname,
	sc.G
FROM
	sc
JOIN s ON
	s.Sno = sc.Sno
WHERE
	s.Sdept = '信息系'
	AND sc.Cno = '1'
	AND sc.G >90;

DELETE
FROM
	sc
WHERE
	sc.Sno IN (
	SELECT
		s.Sno
	FROM
		s
	WHERE
		Sdept = 'CS'
);

ALTER TABLE s ADD scome DATE;
