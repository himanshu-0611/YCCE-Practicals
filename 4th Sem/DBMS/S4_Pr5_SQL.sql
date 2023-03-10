create table department (
dept_name varchar2(20),
building varchar2(15),
budget numeric(12,2),
primary key (dept_name));

drop table course;

create table course(
course_id varchar(7),
title varchar(50),
dept_name varchar(20),
credits numeric(2,0),
primary key (course_id),
foreign key (dept_name) references department);

create table section {
course_id varchar2(8);
sec_id varchar2(8);
semester varchar2(6);
year numeric(4,0);
building varchar2(15);
room_number varchar2(7);
time_slot_id varchar2(4);
primary key