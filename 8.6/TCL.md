# 数据库

## 回顾
- SQL：DDL，DML、TCL
- 数据对象：表，索引，视图，过程，函数，触发器，约束
DDL：Data Definition Language数据定义语言
DML:Data Manipulation Language数据操纵语言  CEUD 增删改查
TCL:Transaction Control Language事务控制语言
- 表连接：
    - 内连接（等值连接）交集
    - 外连接
    - 左连接:保留左表 staff 全部员工，没有匹配部门的员工，部门字段填充NULL（marry 的 dept_id 是 null 也会显示出来）
    - 右连接：保留右表dept全部部门，没有员工的部门，员工字段填NULL
    - 全连接 并集
```sql
-- 示例
select name 
from staff
left join dept
on name1 = name2
where name = alice
group by address
order by 分组
having 过滤分组数据
limit
```
## 事务 TCL

- 事务：事务是一组 DML（增删改）SQL 语句组成的逻辑单元，这一组操作要么全部成功执行，要么全部失败回滚，不会出现部分成功部分失败的中间状态

- ACID
1.A 原子性 Atomicity
一个事务是不可分割最小单元，操作全部成功，或者全部失败回滚，不能只做一半。
例子：转账，A 扣钱，B 加钱；不能 A 扣了钱 B 没加上。
2.C 一致性 Consistency
事务执行前后，数据整体完整性约束不变。转账前后总金额不变。
3.I 隔离性 Isolation
多个事务并发操作同一份数据，事务之间互相隔离，互不干扰。会出现脏读、不可重复读、幻读问题，对应 4 种隔离级别：读已提交，读未提交，可重复读，串行化
4.D 持久性 Durability
事务一旦commit提交成功，修改永久保存到磁盘，即使数据库宕机重启，数据依然保留。

- TCL
1.'BEGIN'       开启手动事务模式
```sql
BEGIN

update account set balance = balance-5 where id =1;
update account set balance = balance+5 where id =2;
insert into log('from','to','amount')values(1,2,5);
commit;
```

2.'COMMIT'      
3.'RILLBACK'

## 隔离级别
|||||
|--|--|--|--|
|隔离级别|`脏读`|`不可重复读`|`幻读`|
|读未提交| + | + | + |
|读已提交| - | + | + |
|可重复读`*`| - | - | + |
|串行化| - | - | - |

- 问题
1.脏读：一个事务读到了另一个事务还没有提交的修改数据
2.不可重复读：同一个事务内，两次读取同一行数据，中间被别的事务 commit 修改，两次查询结果不一样。
3.同一个事务，两次范围查询，别的事务插入 / 删除并且提交，导致返回的行数发生变化，像出现幻影。
## 索引

- 本质：有序的数据结构（B + 树），相当于书的目录，目的是避免全表扫描，加快查询速度。
- 代价：占用磁盘空间；增、删、改变慢（修改数据时要同步维护索引），索引不是越多越好。

自动创建索引：主键列、外键列、唯一约束
手动创建索引：
## 视图