-- 账户信息
create table account
(
    id      int primary key auto_increment,
    name    varchar(16),
    balance decimal(9,2)
);

insert into account values(1,'alice',10000);
insert into account values(2,'bob',10000);
insert into account values(3,'jiack',10000),(4,'rose',10000);

create table 'log'
(
    'id'      int primary key auto_increment,
    'from'    int,
    'to'      int,
    'amount'  int,
    'time'    int
)