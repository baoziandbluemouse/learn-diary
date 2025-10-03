-- constraints 限制
-- NOT NULL //值不能为空
-- UNIQUE //值唯一
-- DEFAULT 对应数据类型的值 //如果不写值的话默认填写的值
-- 注意，如果在insert时要用default，一定得在表名后加()标注我们添加的值属于哪几列
-- AUTO_INCREMENT 自动增长，一般用在id类似的属性上，会自动增加数字，和default用法同理，得准确表明添加哪些属性


CREATE TABLE `student`(
	`student_id` int AUTO_INCREMENT, 
	`name` varchar(20) NOT NULL,
	`major` varchar(20) DEFAULT '历史',
	PRIMARY KEY(`student_id`)
);

DROP TABLE `student`;

INSERT
	INTO
	`students`(`name`,
	`major`)
VALUES('小白', '英语');

INSERT
	INTO
	`students`(`name`,
	`major`)
VALUES('小黑', '历史');

INSERT
	INTO
	`students`(`student_id`,
	`name`)
VALUES(3, '小红');

INSERT
	INTO
	`students`(`student_id`,
	`name`)
VALUES (4,
'小蓝');

SELECT
	*
FROM
	`student`;
