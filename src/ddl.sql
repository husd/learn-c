CREATE TABLE IF NOT EXISTS `runoob_tbl`(
   `runoob_id` INT UNSIGNED AUTO_INCREMENT comment '主键',
      `runoob_title` VARCHAR(100) NOT NULL 'title',
         `runoob_author` VARCHAR(40) NOT NULL '作者',
            `submission_date` DATE '日期',
               PRIMARY KEY ( `runoob_id` )
               )ENGINE=InnoDB DEFAULT CHARSET=utf8 comment '表名字的注释';
