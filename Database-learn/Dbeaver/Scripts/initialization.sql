-- 初始化students表格



CREATE TABLE `students`(
	`student_id` int PRIMARY KEY,
	`name` varchar(20),
	`major` varchar(20),
	`score` int
);

INSERT
	INTO
	students
VALUES(1, '小红', '历史', 90);

INSERT
	INTO
	students
VALUES(2, '小绿', '物理', 20);

INSERT
	INTO
	students
VALUES(3, '小黑', '哲学', 5);

INSERT
	INTO
	students
VALUES(4, 'pop', '数学', 150);

INSERT
	INTO
	students
VALUES(5, 'pipi', '生物', 88);