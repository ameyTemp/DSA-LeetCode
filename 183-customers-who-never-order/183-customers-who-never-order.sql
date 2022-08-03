# Write your MySQL query statement below
select name as customers from customers left join orders on customers.id = customerid where orders.customerid is null;