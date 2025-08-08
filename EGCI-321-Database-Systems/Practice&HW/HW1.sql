use yugonationalbank;

Select Customers.CustomerID, Customers.CustomerName, Sum(DepositAmount) as Total_Deposit
FROM (Customers Inner Join Deposits on Customers.CustomerID = Deposits.CustomerID) 
GROUP BY CustomerID;


Select TolDeposit.CustomerID, TolDeposit.CustomerName, TolDeposit.Total_Deposit , TolWithdraw.Total_Withdraw 
From (Select Customers.CustomerID, Customers.CustomerName, Sum(DepositAmount) as Total_Deposit
FROM (Customers Inner Join Deposits on Customers.CustomerID = Deposits.CustomerID) 
GROUP BY CustomerID
Order By CustomerID) as TolDeposit

Left Outer Join
(Select Customers.CustomerID, Customers.CustomerName, Sum(WithdrawalAmount) as Total_Withdraw
FROM (Customers Inner Join Withdrawals on Customers.CustomerID = Withdrawals.CustomerID) 
GROUP BY CustomerID
Order By CustomerID) as TolWithdraw 
on TolDeposit.CustomerID = TolWithdraw.CustomerID;

Select State, Count(*)
from customers
group by state
order by count(*) desc;